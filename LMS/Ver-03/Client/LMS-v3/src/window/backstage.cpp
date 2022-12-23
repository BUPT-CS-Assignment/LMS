#include "header/Basic.h"
using namespace std;

BackStage::BackStage(QWidget *parent, MainService* ms) :
    QWidget(parent),
    ui(new Ui::BackStage)
{
    _ms = ms;
    //设置UI
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_packet);   //设置当前界面

    //packet list
    ui->packet_list->setSelectionMode(QAbstractItemView::NoSelection);
    ui->packet_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->packet_list->setColumnCount(10);
    ui->packet_list->setHorizontalHeaderLabels(QStringList() << "运单号" << "运单状态" << "物品类型" << "重量/数量" << "揽收人" << "发件人" << "收件人" << "发件时间" << "收件时间" << "详情");

    //collecting list
    ui->collecting_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->collecting_list->setColumnCount(1);
    ui->collecting_list->setHorizontalHeaderLabels(QStringList() << "运单号");

    //option
    ui->option_packet_id->clear();
    ui->packet_alloc->setEnabled(false);
    ui->packet_alloc_choose->setEnabled(false);

    //user list
    ui->user_list->setSelectionMode(QAbstractItemView::NoSelection);
    ui->user_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->user_list->setColumnCount(6);
    ui->user_list->setHorizontalHeaderLabels(QStringList() << "用户名" <<"权限" << "余额" << "姓名" << "联系方式" << "地址");
    ui->packet_search_choose->setCurrentIndex(5);
}

BackStage::~BackStage()
{
    delete ui;
}

Ui::BackStage* BackStage::GetUI(){
    return ui;
}

void BackStage::Init(){
    //初始化刷新
    PacketTableRefresh();
    CollectingRefresh();
    UserTableRefresh();
    CourierChooseRefresh();
    //获取自动分配状态
    _ms->GetAutoAlloc();
    ui->packet_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);    //自适应宽度
    //ui->packet_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->user_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //自适应宽度
    //ui->user_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

void BackStage::AddToPacket(QTableWidget* table, std::vector<QStringList> packets){
    //表格重置
    table->clearContents();
    table->setRowCount(0);
    //遍历信息
    auto itr = packets.begin();
    while(itr != packets.end()){
        if((*itr).size() != 11){
            itr++;
            continue;
        }
        //添加到表格
        int row = table->rowCount();
        table->setRowCount(row + 1);
        table->setItem(row,0,new QTableWidgetItem((*itr)[(int)PACK_RECV::ID]));
        table->setItem(row,1,new QTableWidgetItem(PacketStatusText[(*itr)[(int)PACK_RECV::STATUS].toInt()]));
        table->setItem(row,2,new QTableWidgetItem(PacketTypeText[(*itr)[(int)PACK_RECV::TYPE].toInt()]));
        table->setItem(row,3,new QTableWidgetItem((*itr)[(int)PACK_RECV::PRICE]));
        if((*itr)[(int)PACK_RECV::COURIER] != "0"){
            table->setItem(row,4,new QTableWidgetItem((*itr)[(int)PACK_RECV::COURIER]));
        }else{
            table->setItem(row,4,new QTableWidgetItem(QString("未指定")));
        }
        table->setItem(row,5,new QTableWidgetItem((*itr)[(int)PACK_RECV::FROM]));
        table->setItem(row,6,new QTableWidgetItem((*itr)[(int)PACK_RECV::DEST]));
        table->setItem(row,7,new QTableWidgetItem((*itr)[(int)PACK_RECV::SEND_TIME]));
        table->setItem(row,8,new QTableWidgetItem((*itr)[(int)PACK_RECV::RECV_TIME]));
        table->setItem(row,9,new QTableWidgetItem((*itr)[(int)PACK_RECV::DESCRIBE]));
        itr ++;
    }
}

void BackStage::AddToUser(QTableWidget* table,std::vector<QStringList> users){
    //表格重置
    table->clearContents();
    table->setRowCount(0);
    //遍历信息
    auto itr = users.begin();
    while(itr != users.end()){
        if((*itr).size() != 6){
            itr++;
            continue;
        }
        //添加到表格
        int row = table->rowCount();
        table->setRowCount(row + 1);
        table->setItem(row,0,new QTableWidgetItem((*itr)[(int)USER_RECV::ID]));
        table->setItem(row,1,new QTableWidgetItem(UserAuthText[(*itr)[(int)USER_RECV::AUTH].toInt()]));
        table->setItem(row,2,new QTableWidgetItem((*itr)[(int)USER_RECV::BALANCE]));
        table->setItem(row,3,new QTableWidgetItem((*itr)[(int)USER_RECV::NAME]));
        table->setItem(row,4,new QTableWidgetItem((*itr)[(int)USER_RECV::TEL]));
        table->setItem(row,5,new QTableWidgetItem((*itr)[(int)USER_RECV::ADDRESS]));
        itr ++;
    }
}

void BackStage::CollectingRefresh(){
    QTableWidget* table = ui->collecting_list;
    //取消信号连接
    disconnect(table,&QTableWidget::cellClicked,0,0);
    //表格重置
    table->clearContents();
    table->setRowCount(0);
    //提取快递员列表
    PacketMatchField f[]={PacketMatchField::COURIER};
    QString input[]={"0"};
    vector<QStringList> list;
    if(_ms->PacketSearch(f,input,1,list) == SUCCESS){
        auto itr = list.begin();
        while(itr != list.end()){
            if((*itr).size() == 11){
                //添加到表格
                int row = table->rowCount();
                table->setRowCount(row + 1);
                table->setItem(row,0,new QTableWidgetItem((*itr)[(int)PACK_RECV::ID]));
            }
            itr++;
        }
        //连接信号
        connect(table,&QTableWidget::cellClicked,this,&BackStage::option_set);
    }
}

void BackStage::option_set(int row){
    //设置按钮点击
    ui->option_packet_id->setText(ui->collecting_list->item(row,0)->text());
    ui->packet_alloc->setEnabled(true);
    ui->packet_alloc_choose->setEnabled(true);
}

void BackStage::OptionRefresh(){
    //列表刷新
    ui->option_packet_id->clear();
    ui->packet_alloc->setEnabled(false);
    ui->packet_alloc_choose->setEnabled(false);
}

void BackStage::UserTableRefresh(){
    //用户表格刷新
    vector<QStringList> list;
    ui->user_option_choose->clear();
    //用户搜索
    if(_ms->UserSearch(nullptr,nullptr,0,list) == SUCCESS){
        AddToUser(ui->user_list,list);
        auto itr = list.begin();
        itr++;
        while(itr != list.end()){
            if((*itr).size() == 6){
                //添加对象
                ui->user_option_choose->addItem((*itr)[(int)USER_RECV::ID]);
            }
            itr++;
        }
    }
}

void BackStage::PacketTableRefresh(){
    //包裹表格刷新
    vector<QStringList> list;
    if(_ms->PacketSearch(nullptr,nullptr,0,list) == SUCCESS){
        AddToPacket(ui->packet_list,list);  //包裹搜索
        ui->packet_search_choose->setCurrentIndex(5);
        ui->search_courier_choose->setCurrentIndex(0);
    }
}

void BackStage::CourierChooseRefresh(){
    //快递员选择列表刷新
    ui->packet_alloc_choose->clear();
    ui->search_courier_choose->clear();
    ui->search_courier_choose->addItem(QString("ALL"));
    vector<QStringList> list;
    //搜索快递员
    if(_ms->CourierSearch(list) == SUCCESS){
        auto itr = list.begin();
        while(itr != list.end()){
            //添加到列表
            ui->packet_alloc_choose->addItem((*itr)[(int)USER_RECV::ID]);
            ui->search_courier_choose->addItem((*itr)[(int)USER_RECV::ID]);
            itr++;
        }
    }
}

void BackStage::on_packet_page_select_clicked()
{
    //按钮图标切换
    ui->user_page_select->setStyleSheet("");
    ui->packet_page_select->setStyleSheet("background-color:rgb(66,181,130);color:rgb(255,255,255);");
    ui->stackedWidget->setCurrentWidget(ui->page_packet);   //当前页面切换
}


void BackStage::on_user_page_select_clicked()
{
    //按钮图标切换
    ui->packet_page_select->setStyleSheet("");
    ui->user_page_select->setStyleSheet("background-color:rgb(66,181,130);color:rgb(255,255,255);");
    ui->stackedWidget->setCurrentWidget(ui->page_user);     //当前页面切换
}


void BackStage::on_packet_search_click_clicked()
{
    int ret;
    //搜索内容检测
    int idx =ui->packet_search_choose->currentIndex();
    QString input = ui->packet_search_input->text();
    if(idx != 2 && idx  != 3 && idx != 5){
        bool ok = false;
        input.toInt(&ok);
        if(!ok){
            QMessageBox::critical(this,"ERROR","非法的输入值");
            return;
        }
    }
    vector<QStringList> list;
    int courier_idx = ui->search_courier_choose->currentIndex();

    //包裹搜索
    if(courier_idx == 0){
        PacketMatchField f[] = {(PacketMatchField)idx};
        QString inputs[]={input};
        ret = _ms->PacketSearch(f,inputs,(idx==5?0:1),list);
    }else{
        PacketMatchField fs[]{PacketMatchField::COURIER,(PacketMatchField)idx};
        QString courier_id = ui->search_courier_choose->currentText();
        QString inputs[]={courier_id,input};
        ret = _ms->PacketSearch(fs,inputs,(idx==5?1:2),list);
    }
    if(ret == SUCCESS){
        //添加到列表
        AddToPacket(ui->packet_list,list);
        ui->packet_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);    //自适应宽度
        //ui->packet_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    }
}


void BackStage::on_packet_search_refresh_clicked()
{
    //刷新
    PacketTableRefresh();
    CollectingRefresh();
    OptionRefresh();
    ui->packet_search_input->clear();
}


void BackStage::on_user_search_click_clicked()
{
    int idx_t = ui->user_search_choose->currentIndex();
    QString input = ui->user_search_input->text();
    //输入检测
    if(idx_t == 0){
        bool ok;
        input.toInt(&ok);
        if(!ok){
            QMessageBox::critical(this,"ERROR","非法的输入值");
            return;
        }
    }else{
        if(input.length() == 0){
            QMessageBox::critical(this,"ERROR","输入为空");
            return;
        }
    }
    UserMatchField idx;
    if(idx_t == 0) idx = UserMatchField::ID;
    else if(idx_t == 1) idx = UserMatchField::NAME;
    else if(idx_t == 2) idx = UserMatchField::TEL;
    else idx = UserMatchField::ADDRESS;
    vector<QStringList> list;
    UserMatchField f[]={idx};
    QString inputs[] = {input};
    //用户搜索
    if(_ms->UserSearch(f,inputs,1,list) == SUCCESS){
        //添加到表格
        AddToUser(ui->user_list,list);
        ui->user_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //自适应宽度
        //ui->user_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    }
}


void BackStage::on_sign_out_click_clicked()
{
    _ms->Signout();
    emit SignoutSignal();   //登出信号发起
}


void BackStage::on_packet_alloc_clicked()
{
    QList<QTableWidgetItem*>items = ui->collecting_list->selectedItems();
    if(items.count() == 1){
        QString packet = ui->option_packet_id->text();
        QString id = ui->packet_alloc_choose->currentText();
        //分配快递员
        if(_ms->AllocateCourier(packet,id) == SUCCESS){
            //页面刷新
            ui->collecting_list->removeRow(items[0]->row());
            OptionRefresh();
            if(ui->collecting_list->rowCount() == 0){
                PacketTableRefresh();
            }
        }
    }
}



void BackStage::on_auto_allocation_stateChanged(int arg1)
{
    int ret;
    //转换自动分配状态
    if(arg1 == Qt::Checked){
        ret = _ms->SetAutoAlloc(true);
        if(ret != SUCCESS)  return;
        QString list = "";
        //遍历未分配快递自动分配
        for(int i = 0; i < ui->collecting_list->rowCount();i++){
            list += ui->collecting_list->item(i,0)->text();
        }
        if(_ms->AutoAlloc(list) == SUCCESS){
            //页面刷新
            PacketTableRefresh();
            ui->collecting_list->clearContents();
            ui->collecting_list->setRowCount(0);
            OptionRefresh();
        }else{
            ui->auto_allocation->setCheckState(Qt::Unchecked);
        }
    }else{
        _ms->SetAutoAlloc(false);
    }
}


void BackStage::on_user_delete_clicked()
{
    if(ui->user_option_choose->count() == 0){
        return;
    }
    QString id = ui->user_option_choose->currentText();
    //删除用户
    if(_ms->DelUser(id) == SUCCESS){
        QMessageBox::information(this,"TIPS","删除用户成功");
        PacketTableRefresh();
        CollectingRefresh();
        UserTableRefresh();
        CourierChooseRefresh();
    }
}


void BackStage::on_user_add_clicked()
{
    bool ok = 0;
    //输入检测
    if(ui->add_user_id->text().isEmpty()){
        QMessageBox::critical(this,"ERROR","输入值为空");
        return;
    }
    QString userid = ui->add_user_id->text();
    userid.toInt(&ok);
    if(!ok){
        QMessageBox::information(this,"ERROR","非法的输入值");
        ui->add_user_id->clear();
        return;
    }
    int auth = ui->add_user_auth->currentIndex();
    int balance = ui->add_user_balance->value();
    //添加用户
    int ret = _ms->AddUser(userid,"123",auth,balance);
    if(ret != SUCCESS)  return;

    //添加到表格
    QTableWidget * table = ui->user_list;
    int row = table->rowCount();
    table->setRowCount(row + 1);
    table->setItem(row,0,new QTableWidgetItem(userid));
    table->setItem(row,1,new QTableWidgetItem(UserAuthText[auth]));
    table->setItem(row,2,new QTableWidgetItem(QString::number(balance)));
    table->setItem(row,3,new QTableWidgetItem(QString("null")));
    table->setItem(row,4,new QTableWidgetItem(QString("null")));
    table->setItem(row,5,new QTableWidgetItem(QString("null")));
    QMessageBox::information(this,"TIPS","添加用户成功");
    //页面刷新
    UserTableRefresh();
    CourierChooseRefresh();
    ui->add_user_id->clear();
    ui->add_user_auth->setCurrentIndex(0);
    ui->add_user_balance->setValue(0);
}


void BackStage::on_user_search_refresh_clicked()
{
    UserTableRefresh();
    CourierChooseRefresh();
    ui->add_user_id->clear();
    ui->add_user_auth->setCurrentIndex(0);
    ui->add_user_balance->setValue(0);
}


void BackStage::on_store_data_click_clicked()
{
    //数据保存
    if(_ms->StoreData() == SUCCESS){
        QMessageBox::information(this,"TIPS","保存成功");
    }
}

