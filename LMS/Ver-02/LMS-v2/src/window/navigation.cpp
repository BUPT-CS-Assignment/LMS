#include "header/Basic.h"
using namespace std;

Navigation::Navigation(QWidget *parent, MainService* ms) :
    QWidget(parent),
    ui(new Ui::Navigation)
{   
    _ms = ms;
    ui->setupUi(this);
    ui->page_search->hide();
    ui->dia_change_info->hide();
    ui->dia_change_passwd->hide();
    ui->dia_recharge->hide();
    on_packet_type_currentIndexChanged(0);
    on_nav_send_clicked();
}

Ui::Navigation *Navigation::GetUI(){
    return ui;
}


void Navigation::Init(){
    ui->send_from->setText(QString::number( _ms->CURUSER()->getID() ));
    ui->send_from_addr->setText(QString::fromStdString( _ms->CURUSER()->getAddr() ));
    ui->userid->setText(QString::number( _ms->CURUSER()->getID() ));
    //界面刷新
    SendListRefresh();
    PendListRefresh();
    RecvListRefresh();
    UserInfoRefresh();
}

void Navigation::SendListRefresh(){
    PacketMatchField f[]={PacketMatchField::FROM};
    int id = _ms->CURUSER()->getID();
    void* input[]={&id};
    vector<PacketBase*> list = _ms->PacketSearch(f,input,1);
    _ms->AddToList(ui->send_list,list,this,nullptr);
}
void Navigation::PendListRefresh(){
    PacketMatchField f[]={PacketMatchField::DEST,PacketMatchField::STATUS};
    int dest = _ms->CURUSER()->getID(),status = (int)PacketStatus::PENDING;
    void* input[]={&dest,&status};
    vector<PacketBase*> list = _ms->PacketSearch(f,input,2);
    _ms->AddToList(ui->pend_list,list,this,nullptr);
}
void Navigation::RecvListRefresh(){
    PacketMatchField f[]={PacketMatchField::DEST,PacketMatchField::STATUS};
    int dest = _ms->CURUSER()->getID(),status = (int)PacketStatus::RECVED;
    void* input[]={&dest,&status};
    vector<PacketBase*> list = _ms->PacketSearch(f,input,2);
    _ms->AddToList(ui->recv_list,list,this,nullptr);
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::on_nav_send_clicked()
{
     ToFirstPage();
}

/* 界面切换 */
void Navigation::on_nav_check_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_check);
    ui->tabWidget->setCurrentIndex(0);
    ui->nav_user->setIcon(QIcon(":/res/navigation/icon_user.png"));
    ui->nav_check->setIcon(QIcon(":/res/navigation/icon_check_packet_choose.png"));
    ui->nav_send->setIcon(QIcon(":/res/navigation/icon_send_packet.png"));
}


void Navigation::on_nav_user_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_user);
    ui->nav_user->setIcon(QIcon(":/res/navigation/icon_user_choose.png"));
    ui->nav_check->setIcon(QIcon(":/res/navigation/icon_check_packet.png"));
    ui->nav_send->setIcon(QIcon(":/res/navigation/icon_send_packet.png"));
}

void Navigation::ToFirstPage() const{
    ui->stackedWidget->setCurrentWidget(ui->page_send);
    ui->nav_user->setIcon(QIcon(":/res/navigation/icon_user.png"));
    ui->nav_check->setIcon(QIcon(":/res/navigation/icon_check_packet.png"));
    ui->nav_send->setIcon(QIcon(":/res/navigation/icon_send_packet_choose.png"));
}


void Navigation::on_send_packet_clicked()
{
    bool ok = false;
    int dest_id = ui->send_dest->text().toInt(&ok);
    //输入检测
    if(!ok){
        QMessageBox::information(this,"Error","Invalid Input"); return;
    }
    std::string info = ui->packet_describe->text().toStdString();
    if(info == "") info = "null";
    if(info.find(" ") != info.npos){
        QMessageBox::critical(this,"Error","Invalid Input");    return;
    }
    int count = 1;double count_d = 1;
    int type = ui->packet_type->currentIndex();
    if((PacketType)type == PacketType::BOOK){
        count = ui->packet_count->value();
    }else{
        count_d = ui->packet_count_double->value();
    }
    if(count == 0 || count_d == 0){
        QMessageBox::information(this,"Error","Invalid Number or Weight"); return;
    }
    //寄快递
    int err = _ms->SendPacket(type,dest_id,(type == 2?((double)count):count_d),info);
    if(err == 0){
        QMessageBox::information(this,"Message","Send Packet Success");
        //界面刷新
        SendListRefresh();
        PendListRefresh();
        UserInfoRefresh();
        ui->packet_count_double->setValue(0);
        ui->packet_count->setValue(0);
        ui->send_price->setText("---");
    }else{
        QMessageBox::critical(this,"Error","Insufficient Funds");
    }
}

void Navigation::on_change_info_clicked()
{
    User* user = _ms->CURUSER();
    ui->change_name_input->setPlaceholderText(QString::fromStdString(user->getName()));
    ui->change_tel_input->setPlaceholderText(QString::fromStdString(user->getTel()));
    ui->change_addr_input->setPlaceholderText(QString::fromStdString(user->getAddr()));
    ui->dia_change_info->show();
}


void Navigation::on_sign_out_clicked()
{
    _ms->Signout();
    emit SignoutSignal();
}


void Navigation::on_search_clicked()
{
    PacketMatchField idx = (PacketMatchField)ui->search_choose->currentIndex();
    void* input = nullptr;
    //输入检测
    bool ok;
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
    //搜索字段匹配构建
    PacketMatchField f[]={idx};
    void* inputs[]={input};
    //包裹搜搜
    vector<PacketBase*> list = _ms->PacketSearch(f,inputs,1);
    _ms->AddToList(ui->search_list,list,this,nullptr);
    std::string str = "\"" + SearchChooseText[(int)idx] + " : " + ui->search_input->text().toStdString() + "\"";
    ui->search_condition->setText(QString::fromStdString(str));
    ui->page_search->show();
}


void Navigation::on_recharge_clicked()
{
    ui->dia_recharge->show();
}


void Navigation::on_search_goback_clicked()
{
    ui->search_list->clear();
    ui->search_condition->setText("");
    ui->page_search->hide();
}


void Navigation::on_refresh_clicked()
{
    Init();
}

void Navigation::RecvPacket(unsigned long long id){
    _ms->RecvPacket(id);//签收包裹
    //界面刷新
    SendListRefresh();
    PendListRefresh();
    RecvListRefresh();
    ui->page_search->hide();
}


void Navigation::on_change_info_cancel_click_clicked()
{
    ui->dia_change_info->hide();
    ui->change_name_input->clear();
    ui->change_tel_input->clear();
    ui->change_addr_input->clear();
}


void Navigation::on_change_paaswd_cancel_click_clicked()
{
    ui->dia_change_passwd->hide();
    ui->change_passwd_input->clear();
    ui->change_passwd_cfm_input->clear();
}


void Navigation::on_change_info_click_clicked()
{
    string name = ui->change_name_input->text().toStdString();
    string tel = ui->change_tel_input->text().toStdString();
    string addr = ui->change_addr_input->text().toStdString();
    if(name.find(" ") != name.npos || tel.find(" ") != tel.npos || addr.find(" ") != addr.npos){
        QMessageBox::information(this,"error","Invalid Input");
        return;
    }
    if(name != "" && name != "null")    _ms->CURUSER()->setName(name);
    if(tel != "" && tel != "null")      _ms->CURUSER()->setTel(tel);
    if(addr != "" && addr != "null")    _ms->CURUSER()->setAddr(addr);
    on_change_info_cancel_click_clicked();
    UserInfoRefresh();
}

void Navigation::UserInfoRefresh(){
    ui->user_name->setText(QString::fromStdString(_ms->CURUSER()->getName()));
    ui->user_tel->setText(QString::fromStdString(_ms->CURUSER()->getTel()));
    ui->user_addr->setText(QString::fromStdString(_ms->CURUSER()->getAddr()));
    ui->user_funds->setText(QString::number(_ms->CURUSER()->getBalance(),'f',2));
}


void Navigation::on_change_passwd_click_clicked()
{
    string passwd = ui->change_passwd_input->text().toStdString();
    string passwd_cfm = ui->change_passwd_cfm_input->text().toStdString();
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


void Navigation::on_recharge_click_clicked()
{
    bool ok;
    int charge = ui->recharge_input->text().toInt(&ok);
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


void Navigation::on_recharge_cancel_click_clicked()
{
    ui->dia_recharge->hide();
    ui->recharge_input->clear();
}


void Navigation::on_change_passwd_clicked()
{
    ui->dia_change_passwd->show();
}


void Navigation::on_packet_count_valueChanged(int arg1)
{
    if(arg1 == 0){
        ui->send_price->setText("---");
    }else{
        ui->send_price->setText(QString::number(2 * arg1));
    }
}

void Navigation::on_packet_count_double_valueChanged(double arg1)
{
    if(arg1 == 0){
        ui->send_price->setText("---");
    }else{
        if((PacketType)ui->packet_type->currentIndex() == PacketType::BREAKABLE){
            ui->send_price->setText(QString::number(8 * arg1));
        }else{
            ui->send_price->setText(QString::number(5 * arg1));
        }
    }
}


void Navigation::on_packet_type_currentIndexChanged(int index)
{
    switch((PacketType)index){
        case PacketType::PACKAGE:case PacketType::BREAKABLE:
            ui->packet_type_text->setText("物品重量");
            ui->packet_count->hide();
            ui->packet_count_double->show();
            ui->packet_count_double->setValue(0);
            break;
        case PacketType::BOOK:
            ui->packet_type_text->setText("物品数量");
            ui->packet_count_double->hide();
            ui->packet_count->show();
            ui->packet_count->setValue(0);
            break;
    }
    ui->send_price->setText("---");
}




