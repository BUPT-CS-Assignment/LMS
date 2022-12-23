#include "header/Basic.h"
using namespace std;

BackStage::BackStage(QWidget *parent, MainService* ms) :
    QWidget(parent),
    ui(new Ui::BackStage)
{
    _ms = ms;
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_packet);

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
    UserChooseRefresh();
    CourierChooseRefresh();
}

BackStage::~BackStage()
{
    delete ui;
}

Ui::BackStage* BackStage::GetUI(){
    return ui;
}

void BackStage::Init(){
    //界面刷新
    PacketTableRefresh();
    CollectingRefresh();
    UserTableRefresh();
    UserChooseRefresh();
    CourierChooseRefresh();
    ui->packet_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);    //自适应宽度
    //ui->packet_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->user_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //自适应宽度
    //ui->user_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

void BackStage::AddToTable(QTableWidget* table, std::vector<PacketBase*> packets){
    //清空表格
    table->clearContents();
    table->setRowCount(0);
    auto itr = packets.begin();
    while(itr != packets.end()){
        //添加新信息
        int row = table->rowCount();
        table->setRowCount(row + 1);
        table->setItem(row,0,new QTableWidgetItem(QString::number((*itr)->getID())));
        table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(PacketStatusText[(*itr)->getStatus()])));
        table->setItem(row,2,new QTableWidgetItem(QString::fromStdString(PacketTypeText[(*itr)->getType()])));
        table->setItem(row,3,new QTableWidgetItem(QString::number((*itr)->getCount(),'f',((*itr)->getType()==2?0:2))));
        if((*itr)->getCourier() != 0){
            table->setItem(row,4,new QTableWidgetItem(QString::number((*itr)->getCourier())));
        }else{
            table->setItem(row,4,new QTableWidgetItem(QString("未指定")));
        }
        table->setItem(row,5,new QTableWidgetItem(QString::number((*itr)->getFromUser())));
        table->setItem(row,6,new QTableWidgetItem(QString::number((*itr)->getDestUser())));
        table->setItem(row,7,new QTableWidgetItem(QString::fromStdString((*itr)->getSendTime())));
        table->setItem(row,8,new QTableWidgetItem(QString::fromStdString((*itr)->getRecvTime())));
        table->setItem(row,9,new QTableWidgetItem(QString::fromStdString((*itr)->getDescription())));
        itr ++;
    }
}

void BackStage::AddToTable(QTableWidget* table,std::vector<User*> users){
    //表格清空
    table->clearContents();
    table->setRowCount(0);
    auto itr = users.begin();
    while(itr != users.end()){
        //添加新行
        int row = table->rowCount();
        table->setRowCount(row + 1);
        table->setItem(row,0,new QTableWidgetItem(QString::number((*itr)->getID())));
        table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(UserAuthText[(*itr)->getAuth()])));
        table->setItem(row,2,new QTableWidgetItem(QString::number((*itr)->getBalance(),'f',2)));
        table->setItem(row,3,new QTableWidgetItem(QString::fromStdString((*itr)->getName())));
        table->setItem(row,4,new QTableWidgetItem(QString::fromStdString((*itr)->getTel())));
        table->setItem(row,5,new QTableWidgetItem(QString::fromStdString((*itr)->getAddr())));
        itr ++;
    }
}

void BackStage::CollectingRefresh(){
    QTableWidget* table = ui->collecting_list;
    //取消信号连接
    disconnect(table,&QTableWidget::cellClicked,0,0);
    //清空表格
    table->clearContents();
    table->setRowCount(0);
    //提取快递员列表
    PacketMatchField f[]{PacketMatchField::COURIER};
    int input = 0;
    void* inputs[]{&input};
    vector<PacketBase*> list = _ms->PacketSearch(f,inputs,1);
    auto itr = list.begin();
    while(itr != list.end()){
        //添加新行
        int row = table->rowCount();
        table->setRowCount(row + 1);
        table->setItem(row,0,new QTableWidgetItem(QString::number((*itr)->getID())));
        itr++;
    }
    //连接信号槽
    connect(table,&QTableWidget::cellClicked,this,&BackStage::option_set);

}

void BackStage::option_set(int row){
    ui->option_packet_id->setText(ui->collecting_list->item(row,0)->text());
    ui->packet_alloc->setEnabled(true);
    ui->packet_alloc_choose->setEnabled(true);
}

void BackStage::OptionRefresh(){
    ui->option_packet_id->clear();
    ui->packet_alloc->setEnabled(false);
    ui->packet_alloc_choose->setEnabled(false);
}

void BackStage::UserTableRefresh(){
    vector<User*> list = _ms->UserSearch(nullptr,nullptr,0);
    AddToTable(ui->user_list,list);
}

void BackStage::PacketTableRefresh(){
    vector<PacketBase*> list = _ms->PacketSearch(nullptr,nullptr,0);
    AddToTable(ui->packet_list,list);
    ui->packet_search_choose->setCurrentIndex(5);
    ui->search_courier_choose->setCurrentIndex(0);
}

void BackStage::CourierChooseRefresh(){
    //选择列表刷新
    ui->packet_alloc_choose->clear();
    ui->search_courier_choose->clear();
    ui->search_courier_choose->addItem(QString("ALL"));
    vector<User*>* list = _ms->COURIERS();
    auto itr = list->begin();
    while(itr != list->end()){
        ui->packet_alloc_choose->addItem(QString::number((*itr)->getID()));
        ui->search_courier_choose->addItem(QString::number((*itr)->getID()));
        itr++;
    }
}

void BackStage::UserChooseRefresh(){
    ui->user_option_choose->clear();
    //搜索用户
    vector<User*> list = _ms->UserSearch(nullptr,nullptr,0);
    auto itr = list.begin();
    itr++;
    while(itr != list.end()){
        //添加到列表
        ui->user_option_choose->addItem(QString::number((*itr)->getID()));
        itr++;
    }
}

/* 页面切换 */
void BackStage::on_packet_page_select_clicked()
{
    ui->user_page_select->setStyleSheet("");
    ui->packet_page_select->setStyleSheet("background-color:rgb(66,181,130);color:rgb(255,255,255);");
    ui->stackedWidget->setCurrentWidget(ui->page_packet);
}


void BackStage::on_user_page_select_clicked()
{
    ui->packet_page_select->setStyleSheet("");
    ui->user_page_select->setStyleSheet("background-color:rgb(66,181,130);color:rgb(255,255,255);");
    ui->stackedWidget->setCurrentWidget(ui->page_user);
}

/* 搜索包裹 */
void BackStage::on_packet_search_click_clicked()
{
    int idx =ui->packet_search_choose->currentIndex();
    void* input = nullptr;
    bool ok;
    if(idx == 5);
    //输入检测
    else if((PacketMatchField)idx == PacketMatchField::RECVTIME || (PacketMatchField)idx == PacketMatchField::SENDTIME){
        std::string str = ui->packet_search_input->text().toStdString();
        input = &str;
    }else{
        int temp = ui->packet_search_input->text().toInt(&ok);
        if(ok)  input = &temp;
        else{
            QMessageBox::critical(this,"error","Invalid Input");
            return;
        }
    }
    vector<PacketBase*> list;
    int courier_idx = ui->search_courier_choose->currentIndex();
    PacketMatchField f = (PacketMatchField)idx;
    //搜索参数字段构建
    if(courier_idx == 0){
        list = _ms->PacketSearch(&f,&input,(idx==5?0:1));
    }else{
        PacketMatchField fs[]{PacketMatchField::COURIER,f};
        int courier_id = ui->search_courier_choose->currentText().toInt();
        void* inputs[]{&courier_id,input};
        list = _ms->PacketSearch(fs,inputs,(idx==5?1:2));
    }
    //添加到表格
    AddToTable(ui->packet_list,list);
    ui->packet_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);    //自适应宽度
    //ui->packet_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}


void BackStage::on_packet_search_refresh_clicked()
{
     PacketTableRefresh();
     CollectingRefresh();
     OptionRefresh();
     ui->packet_search_input->clear();
}


void BackStage::on_user_search_click_clicked()
{
    UserMatchField idx = (UserMatchField)ui->user_search_choose->currentIndex();
    void* input = nullptr;
    bool ok;
    //输入检测
    if(idx == UserMatchField::ID){
        int temp = ui->user_search_input->text().toInt(&ok);
        if(ok)  input = &temp;
        else{
            QMessageBox::critical(this,"error","Invalid Input");
            return;
        }
    }else{
        std::string str = ui->user_search_input->text().toStdString();
        input = &str;
    }
    //用户搜索
    vector<User*> list = _ms->UserSearch(&idx,&input,1);
    //添加到表格
    AddToTable(ui->user_list,list);
    ui->user_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //自适应宽度
    //ui->user_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

}


void BackStage::on_sign_out_click_clicked()
{
    _ms->Signout();
    emit SignoutSignal();
}


void BackStage::on_packet_alloc_clicked()
{
    //分配快递员
    QList<QTableWidgetItem*>items = ui->collecting_list->selectedItems();
    if(items.count() == 1){
        unsigned long long packet = ui->option_packet_id->text().toULongLong();
        int id = ui->packet_alloc_choose->currentText().toInt();
        _ms->AllocateCourier(packet,id);
        ui->collecting_list->removeRow(items[0]->row());
        OptionRefresh();
        if(ui->collecting_list->rowCount() == 0){
            PacketTableRefresh();
        }
    }
}



void BackStage::on_auto_allocation_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        //设置自动分配状态
        _ms->setAllocStatus(true);
        bool flag = true;
        //随机分配所有包裹
        for(int i = 0; i < ui->collecting_list->rowCount() && flag;i++){
            flag = _ms->RandomAlloc(ui->collecting_list->item(i,0)->text().toULongLong());
        }
        if(flag){
            //界面刷新
            PacketTableRefresh();
            ui->collecting_list->clearContents();
            ui->collecting_list->setRowCount(0);
            OptionRefresh();
        }
    }else{
        _ms->setAllocStatus(false);
    }
}


void BackStage::on_user_delete_clicked()
{
    if(ui->user_option_choose->count() == 0){
        return;
    }
    int id = ui->user_option_choose->currentText().toInt();
    User* user = _ms->UserSearch(id);
    if(user == nullptr) return;
    //快递员检测
    if(user->getAuth() == (int)UserAuth::COURIER){
        PacketMatchField f[]{PacketMatchField::COURIER,PacketMatchField::STATUS};
        PacketStatus s = PacketStatus::COLLECTING;
        void* inputs[]{&id,&s};
        //搜索所有未揽收包裹
        vector<PacketBase*> list = _ms->PacketSearch(f,inputs,2);
        auto itr = list.begin();
        while(itr != list.end()){
            //重置未揽收包裹
            (*itr)->setCourier(0);
            itr++;
        }
        //界面刷新
        PacketTableRefresh();
        CollectingRefresh();
    }
    int err = _ms->DelUser(id); //删除用户
    if(err!=0)  return;
    QMessageBox::information(this,"Msg","Delete User Success");
    //界面刷新
    UserTableRefresh();
    UserChooseRefresh();
    CourierChooseRefresh();
}


void BackStage::on_user_add_clicked()
{
    bool ok = 0;
    //输入检测
    if(ui->add_user_id->text().isEmpty()){
        QMessageBox::critical(this,"Error","Empty Input");
        return;
    }
    int userid = ui->add_user_id->text().toInt(&ok);
    if(!ok){
        QMessageBox::information(this,"Error","Invalid Input");
        ui->add_user_id->clear();
        return;
    }
    //重复检测
    if(_ms->UserSearch(userid) != nullptr){
        QMessageBox::information(this,"Error","Userid Existed");
        ui->add_user_id->clear();
        return;
    }
    string passwd = "123";
    int auth = ui->add_user_auth->currentIndex();
    int balance = ui->add_user_balance->value();
    User* user = new User(userid,passwd,auth);
    user->setBalance(balance);
    _ms->AddUser(user);
    //添加到表格
    QTableWidget * table = ui->user_list;
    int row = table->rowCount();
    table->setRowCount(row + 1);
    table->setItem(row,0,new QTableWidgetItem(QString::number(userid)));
    table->setItem(row,1,new QTableWidgetItem(QString::fromStdString(UserAuthText[auth])));
    table->setItem(row,2,new QTableWidgetItem(QString::number(balance)));
    table->setItem(row,3,new QTableWidgetItem(QString("null")));
    table->setItem(row,4,new QTableWidgetItem(QString("null")));
    table->setItem(row,5,new QTableWidgetItem(QString("null")));
    QMessageBox::information(this,"Msg","Add User Succcess");
    UserChooseRefresh();
    CourierChooseRefresh();
    ui->add_user_id->clear();
    ui->add_user_auth->setCurrentIndex(0);
    ui->add_user_balance->setValue(0);
}


void BackStage::on_user_search_refresh_clicked()
{
    UserTableRefresh();
    UserChooseRefresh();
    CourierChooseRefresh();
    ui->add_user_id->clear();
    ui->add_user_auth->setCurrentIndex(0);
    ui->add_user_balance->setValue(0);
}

