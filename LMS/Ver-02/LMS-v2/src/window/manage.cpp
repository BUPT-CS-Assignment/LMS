#include "header/Basic.h"
using namespace std;

Manage::Manage(QWidget *parent,MainService* ms) :
    QWidget(parent),
    ui(new Ui::Manage)
{
    _ms = ms;
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

/*揽收包裹 */
void Manage::CollectPacket(unsigned long long id){
    _ms->CollectPacket(id);
    AllListRefresh();
    CollectedListRefresh();
    CollectingListRefresh();
    ui->user_funds->setText(QString::number(_ms->CURUSER()->getBalance(),'f',2));
    ui->page_search->hide();
}

/* 初始化 */
void Manage::Init(){
    ui->userid->setText(QString::number( _ms->CURUSER()->getID() ));
    //界面刷新
    AllListRefresh();
    CollectedListRefresh();
    CollectingListRefresh();
    UserInfoRefresh();
}

/* 列表刷新 */
void Manage::AllListRefresh(){
    PacketMatchField f[]={PacketMatchField::COURIER};
    int id = _ms->CURUSER()->getID();
    void* input[]={&id};
    vector<PacketBase*> list = _ms->PacketSearch(f,input,1);
    _ms->AddToList(ui->all_list,list,nullptr,this);

}

void Manage::CollectingListRefresh(){
    PacketMatchField f[]={PacketMatchField::COURIER,PacketMatchField::STATUS};
    int dest = _ms->CURUSER()->getID(),status = (int)PacketStatus::COLLECTING;
    void* input[]={&dest,&status};
    vector<PacketBase*> list = _ms->PacketSearch(f,input,2);
    _ms->AddToList(ui->collecting_list,list,nullptr,this);
}

void Manage::CollectedListRefresh(){
    PacketMatchField f[]={PacketMatchField::COURIER,PacketMatchField::STATUS};
    int dest = _ms->CURUSER()->getID(),status = (int)PacketStatus::PENDING;
    void* input[]={&dest,&status};
    vector<PacketBase*> list = _ms->PacketSearch(f,input,2);
    _ms->AddToList(ui->collected_list,list,nullptr,this);
}

void Manage::UserInfoRefresh(){
    ui->user_name->setText(QString::fromStdString(_ms->CURUSER()->getName()));
    ui->user_tel->setText(QString::fromStdString(_ms->CURUSER()->getTel()));
    ui->user_funds->setText(QString::number(_ms->CURUSER()->getBalance(),'f',2));

}
/* 页面切换 */
void Manage::ToFirstPage(){
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
    void* input = nullptr;
    bool ok;
    //输入检测
    if(idx == PacketMatchField::RECVTIME || idx == PacketMatchField::SENDTIME){
        string str = ui->search_input->text().toStdString();
        input = &str;
    }else{
        int temp = ui->search_input->text().toInt(&ok);
        if(ok)  input = &temp;
        else{
            QMessageBox::critical(this,"error","Invalid Input");    return;
        }
    }
    //匹配参数字段构建
    PacketMatchField f[]={PacketMatchField::COURIER,idx};
    int id = _ms->CURUSER()->getID();
    void* inputs[]={&id,input};
    //包裹搜索
    vector<PacketBase*> list = _ms->PacketSearch(f,inputs,2);
    _ms->AddToList(ui->search_list,list,nullptr,this);
    std::string str = "\"" + SearchChooseText[(int)idx] + " : " + ui->search_input->text().toStdString() + "\"";
    ui->search_condition->setText(QString::fromStdString(str));
    ui->page_search->show();
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
    User* user = _ms->CURUSER();
    ui->change_name_input->setPlaceholderText(QString::fromStdString(user->getName()));
    ui->change_tel_input->setPlaceholderText(QString::fromStdString(user->getTel()));
    ui->dia_change_info->show();
}


void Manage::on_change_passwd_click_clicked()
{
    string passwd = ui->change_passwd_input->text().toStdString();
    string passwd_cfm = ui->change_passwd_cfm_input->text().toStdString();
    //输入检测
    if(passwd.find(" ") != passwd.npos || passwd_cfm.find(" ") != passwd_cfm.npos){
        QMessageBox::information(this,"error","Invalid Input");
        return;
    }
    if(passwd.length() < 3 || passwd.length() > 16){
        QMessageBox::information(this,"error","Invalid Passwd Length");
        return;
    }
    if(passwd != passwd_cfm){
        QMessageBox::information(this,"error","Passwd Not Match");
        return;
    }
    _ms->CURUSER()->setPasswd(passwd);
    on_change_paaswd_cancel_click_clicked();
}


void Manage::on_recharge_click_clicked()
{
    bool ok;
    int charge = ui->recharge_input->text().toInt(&ok);
    //输入检测
    if(!ok){
        QMessageBox::critical(this,"error","Invalid Input");
        return;
    }
    if(charge <=0 || _ms->Recharge(charge) != 0){
        QMessageBox::critical(this,"error","Invalid ChargeNum");
        return;
    }
    UserInfoRefresh();
    on_recharge_cancel_click_clicked();
}


void Manage::on_change_info_click_clicked()
{
    string name = ui->change_name_input->text().toStdString();
    string tel = ui->change_tel_input->text().toStdString();
    //输入检测
    if(name.find(" ") != name.npos || tel.find(" ") != tel.npos ){
        QMessageBox::information(this,"error","Invalid Input");
        return;
    }
    if(name != "" && name != "null")    _ms->CURUSER()->setName(name);
    if(tel != "" && tel != "null")      _ms->CURUSER()->setTel(tel);
    on_change_info_cancel_click_clicked();
    UserInfoRefresh();
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
    //输入检测
    if(num == 0) {
        QMessageBox::information(this,"Msg","No Packets to Collect");
        return;
    }
    for(int i = 0; i < num; i ++){
        PacketInfo* p = (PacketInfo*)ui->collecting_list->itemWidget(ui->collecting_list->item(i));
        if(p == nullptr) {
            QMessageBox::information(this,"Msg","No Packets to Collect");
            break;
        }
        //揽收包裹
        _ms->CollectPacket(p->GetUI()->packet_id->text().toULongLong());
    }
    //界面刷新
    ui->collecting_list->clear();
    AllListRefresh();
    CollectedListRefresh();
    ui->user_funds->setText(QString::number(_ms->CURUSER()->getBalance(),'f',2));
}

