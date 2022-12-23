#include "header/Basic.h"
using namespace std;

Manage::Manage(QWidget *parent,MainService* ms) :
    QWidget(parent),
    ui(new Ui::Manage)
{
    _ms = ms;
    //UI设置
    ui->setupUi(this);
    ui->page_search->hide();
    ui->dia_change_info->hide();
    ui->dia_change_passwd->hide();
    ui->dia_recharge->hide();
    on_mng_check_clicked();
}

Manage::~Manage()
{
    delete ui;
}

Ui::Manage* Manage::GetUI(){
    return ui;
}

void Manage::CollectPacket(QString id){
    QString fund;
    //揽收快递
    int ret = _ms->CollectPacket(id);
    if(ret != SUCCESS)  return;
    //列表刷新
    AllListRefresh();
    CollectedListRefresh();
    CollectingListRefresh();
    ui->user_funds->setText(_ms->USER()->getBalance());
    ui->page_search->hide();
}

void Manage::Init(){
    //页面刷新
    ui->userid->setText(_ms->USER()->getID());
    AllListRefresh();
    CollectedListRefresh();
    CollectingListRefresh();
    UserInfoRefresh();
}

void Manage::AllListRefresh(){
    PacketMatchField f[]={PacketMatchField::COURIER};
    QString input[]={ _ms->USER()->getID()};
    vector<QStringList> list;
    //快递搜索
    if(_ms->PacketSearch(f,input,1,list) == SUCCESS){
        _ms->AddToList(ui->all_list,list,nullptr,this); //添加到列表
    }
}

void Manage::CollectingListRefresh(){
    PacketMatchField f[]={PacketMatchField::COURIER,PacketMatchField::STATUS};
    QString input[]={_ms->USER()->getID(),"0"}; //PacketStatus::COLLECTING
    vector<QStringList> list;
    if(_ms->PacketSearch(f,input,2,list) == SUCCESS){
        _ms->AddToList(ui->collecting_list,list,nullptr,this);
    }
}

void Manage::CollectedListRefresh(){
    PacketMatchField f[]={PacketMatchField::COURIER,PacketMatchField::STATUS};
    QString input[]={_ms->USER()->getID(),"1"}; //PacketStatus::PENDING
    vector<QStringList> list;
    if(_ms->PacketSearch(f,input,2,list) == SUCCESS){
        _ms->AddToList(ui->collected_list,list,nullptr,this);
    }

}

void Manage::UserInfoRefresh(){
    //刷新用户信息
    ui->user_name->setText(_ms->USER()->getName());
    ui->user_tel->setText(_ms->USER()->getTel());
    ui->user_funds->setText(_ms->USER()->getBalance());

}

void Manage::ToFirstPage(){
    //跳转到首页
    ui->stackedWidget->setCurrentWidget(ui->page_check);
    ui->mng_user->setIcon(QIcon(":/res/navigation/icon_user.png"));
    ui->mng_check->setIcon(QIcon(":/res/navigation/icon_check_packet_choose.png"));
}


void Manage::on_mng_user_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_user);
    ui->mng_user->setIcon(QIcon(":/res/navigation/icon_user_choose.png"));
    ui->mng_check->setIcon(QIcon(":/res/navigation/icon_check_packet.png"));
}


void Manage::on_mng_check_clicked()
{
    ToFirstPage();
}


void Manage::on_search_clicked()
{

    PacketMatchField idx = (PacketMatchField)ui->search_choose->currentIndex();
    QString input[]= {_ms->USER()->getID(),ui->search_input->text()};
    //输入检测
    if(idx != PacketMatchField::RECVTIME && idx != PacketMatchField::SENDTIME){
        bool ok;
        input[0].toInt(&ok);
        if(!ok){
            QMessageBox::critical(this,"ERROR","非法的输入值");
            return;
        }
    }
    PacketMatchField f[]={PacketMatchField::COURIER,idx};
    vector<QStringList> list;
    //包裹搜索
    if(_ms->PacketSearch(f,input,2,list) == SUCCESS){
        //添加到列表
        _ms->AddToList(ui->search_list,list,nullptr,this);
        QString str = "\"" + SearchChooseText[(int)idx] + " : " + ui->search_input->text() + "\"";
        ui->search_condition->setText(str);
        ui->page_search->show();
    }
}


void Manage::on_refresh_clicked()
{
    Init();
}


void Manage::on_change_passwd_clicked()
{
    ui->dia_change_passwd->show();
}


void Manage::on_change_info_clicked()
{
    ui->change_name_input->setPlaceholderText(_ms->USER()->getName());
    ui->change_tel_input->setPlaceholderText(_ms->USER()->getTel());
    ui->dia_change_info->show();
}


void Manage::on_change_passwd_click_clicked()
{
    QString passwd = ui->change_passwd_input->text();
    QString passwd_cfm = ui->change_passwd_cfm_input->text();
    //输入检测
    if(passwd.indexOf(" ") != -1 || passwd_cfm.indexOf(" ") != -1){
        QMessageBox::information(this,"ERROR","非法的输入值");
        return;
    }
    if(passwd.length() < 3 || passwd.length() > 16){
        QMessageBox::information(this,"ERROR","密码长度不正确");
        return;
    }
    if(passwd != passwd_cfm){
        QMessageBox::information(this,"ERROR","输入不匹配");
        return;
    }
    UserMatchField f[]={UserMatchField::PASSWD};
    QString input[]={passwd};
    if(_ms->SetInfo(f,input,1) == SUCCESS){
        _ms->USER()->setPasswd(passwd);
        on_change_paaswd_cancel_click_clicked();
    }
}


void Manage::on_recharge_click_clicked()
{
    bool ok;
    QString charge = ui->recharge_input->text();
    //输入检测
    int num = charge.toInt(&ok);
    if(!ok || num <= 0){
        QMessageBox::critical(this,"ERROR","非法的输入值");
        return;
    }
    //充值
    if(_ms->Recharge(charge) == SUCCESS){
        UserInfoRefresh();
        on_recharge_cancel_click_clicked();
    }
}


void Manage::on_change_info_click_clicked()
{
    QString name = ui->change_name_input->text();
    QString tel = ui->change_tel_input->text();
    if(name.indexOf(" ") != -1 || tel.indexOf(" ") != -1 ){
        QMessageBox::information(this,"ERROR","非法的输入值");
        return;
    }
    if(name == "") name = "null";
    if(tel == "") tel = "null";
    UserMatchField f[]={UserMatchField::NAME,UserMatchField::TEL};
    QString input[]={name,tel};
    //设置用户信息
    if(_ms->SetInfo(f,input,2) == SUCCESS){
        _ms->USER()->setName(name);
        _ms->USER()->setTel(tel);
        on_change_info_cancel_click_clicked();
        UserInfoRefresh();
    }
}


void Manage::on_change_info_cancel_click_clicked()
{
    ui->dia_change_info->hide();
    ui->change_name_input->clear();
    ui->change_tel_input->clear();
}


void Manage::on_change_paaswd_cancel_click_clicked()
{
    ui->dia_change_passwd->hide();
    ui->change_passwd_input->clear();
    ui->change_passwd_cfm_input->clear();
}


void Manage::on_recharge_cancel_click_clicked()
{
    ui->dia_recharge->hide();
    ui->recharge_input->clear();
}


void Manage::on_sign_out_clicked()
{
    _ms->Signout();
    emit SignoutSignal();
}


void Manage::on_search_goback_clicked()
{
    ui->search_list->clear();
    ui->search_condition->setText("");
    ui->page_search->hide();
}


void Manage::on_recharge_clicked()
{
    ui->dia_recharge->show();
}


void Manage::on_collect_all_clicked()
{
    int num = ui->collecting_list->count();
    if(num == 0) {
        QMessageBox::information(this,"TIPS","没有待揽收的包裹");
        return;
    }
    //遍历未揽收列表
    for(int i = 0; i < num; i ++){
        PacketInfo* p = (PacketInfo*)ui->collecting_list->itemWidget(ui->collecting_list->item(i));
        if(p == nullptr) {
            QMessageBox::information(this,"TIPS","没有待揽收的包裹");
            break;
        }
        //揽收快递
        int ret = _ms->CollectPacket(p->GetUI()->packet_id->text());
        if(ret != SUCCESS){
            return;
        }
    }
    //页面刷新
    ui->collecting_list->clear();
    AllListRefresh();
    CollectedListRefresh();
    UserInfoRefresh();
}

