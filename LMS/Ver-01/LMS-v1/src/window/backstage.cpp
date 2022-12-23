#include "header/Basic.h"

BackStage::BackStage(QWidget *parent, MainService* ms) :
    QWidget(parent),
    ui(new Ui::BackStage)
{
    _ms = ms;
    ui->setupUi(this);
    //设置首次进入页面
    ui->stackedWidget->setCurrentWidget(ui->page_packet);
    //设置表格状态和表头
    ui->packet_list->setSelectionMode(QAbstractItemView::NoSelection);
    ui->packet_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->packet_list->setColumnCount(7);
    ui->packet_list->setHorizontalHeaderLabels(QStringList() << "运单号" << "运单状态" << "发件人" << "收件人" << "发件时间" << "收件时间" << "详情");
    ui->user_list->setSelectionMode(QAbstractItemView::NoSelection);
    ui->user_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->user_list->setColumnCount(6);
    ui->user_list->setHorizontalHeaderLabels(QStringList() << "用户名" <<"权限" << "余额" << "姓名" << "联系方式" << "地址");

}

BackStage::~BackStage()
{
    delete ui;
}

Ui::BackStage* BackStage::GetUI(){
    return ui;
}

//后台页面初始化
void BackStage::Init(){
    //获取所有包裹信息
    _ms->GetPacketController()->CheckPackets(PCheck::ALL,ui->packet_list);
    //获取所有用户信息
    _ms->GetUserController()->CheckUsers(UCheck::ALL,ui->user_list,BACKSTAGE_MODE,nullptr);
    ui->packet_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->packet_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列
    ui->user_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->user_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列
}

//选择包裹信息页面
void BackStage::on_packet_page_select_clicked()
{
    ui->user_page_select->setStyleSheet("");
    ui->packet_page_select->setStyleSheet("background-color:rgb(66,181,130);color:rgb(255,255,255);");
    ui->stackedWidget->setCurrentWidget(ui->page_packet);

}

//选择用户信息页面
void BackStage::on_user_page_select_clicked()
{
    ui->packet_page_select->setStyleSheet("");
    ui->user_page_select->setStyleSheet("background-color:rgb(66,181,130);color:rgb(255,255,255);");
    ui->stackedWidget->setCurrentWidget(ui->page_user);
}

//点击搜索按钮
void BackStage::on_packet_search_click_clicked()
{
    int id = ui->packet_search_choose->currentIndex();
    void* input;
    bool ok;
    //检查判定搜索模式，转换输入
    if((PCheck)id == PCheck::RECV_TIME || (PCheck)id == PCheck::SEND_TIME){
        std::string str = ui->packet_search_input->text().toStdString();
        input = &str;
    }else if((PCheck)id == PCheck::PACKET_PEND || (PCheck)id == PCheck::PACKET_RECV){
        input = nullptr;
    }else{
        int temp = ui->packet_search_input->text().toInt(&ok);
        if(ok){
            input = &temp;
        }else{
            QMessageBox::critical(this,"error","Invalid Input");
            return;
        }
    }
    _ms->GetPacketController()->CheckPackets((PCheck)id,ui->packet_list,input);
    ui->packet_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->packet_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列
}

//点击刷新按钮
void BackStage::on_packet_search_refresh_clicked()
{
     //重新搜索包裹信息
     _ms->GetPacketController()->CheckPackets(PCheck::ALL,ui->packet_list);
     ui->packet_search_input->clear();
}

//点击搜索用户信息
void BackStage::on_user_search_click_clicked()
{
    int id = ui->user_search_choose->currentIndex();
    void* input;
    bool ok;
    //检查判定搜索模式，转换输入
    if((UCheck)id == UCheck::USER_ID){
        int temp = ui->user_search_input->text().toInt(&ok);
        if(ok){
            input = &temp;
        }else{
            QMessageBox::critical(this,"error","Invalid Input");
            return;
        }
    }else{
        std::string str = ui->user_search_input->text().toStdString();
        input = &str;
    }
    //根据字段搜索用户
    _ms->GetUserController()->CheckUsers((UCheck)id,ui->user_list,BACKSTAGE_MODE,input);
    ui->user_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->user_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列

}

//点击刷新按钮
void BackStage::on_user_search_refresh_clicked()
{
    //重新搜索用户信息
    _ms->GetUserController()->CheckUsers(UCheck::ALL,ui->user_list,BACKSTAGE_MODE,nullptr);
    ui->user_search_input->clear();
}

//点击退出登录
void BackStage::on_sign_out_click_clicked()
{
    _ms->Signout();
    //发出退出信号
    emit SignoutSignal();
}

