#include "header/Basic.h"
using namespace std;

Navigation::Navigation(QWidget *parent, MainService* ms) :
    QWidget(parent),
    ui(new Ui::Navigation)
{   
    _ms = ms;   //连接主服务
    //UI设置
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
    //UI界面初始化
    ui->send_from->setText(_ms->USER()->getID());
    ui->send_from_addr->setText(_ms->USER()->getAddr());
    ui->userid->setText(_ms->USER()->getID());
    ui->send_dest->clear();
    ui->packet_describe->clear();
    //列表刷新
    SendListRefresh();
    PendListRefresh();
    RecvListRefresh();
    UserInfoRefresh();
}

void Navigation::SendListRefresh(){
    PacketMatchField f[]={PacketMatchField::FROM};
    QString input[]={_ms->USER()->getID()};
    vector<QStringList> list;
    if(_ms->PacketSearch(f,input,1,list) == SUCCESS){
        _ms->AddToList(ui->send_list,list,this,nullptr);
    }
}

void Navigation::PendListRefresh(){
    PacketMatchField f[]={PacketMatchField::DEST,PacketMatchField::STATUS};
    QString input[]={_ms->USER()->getID(),"1"}; //PacketStatus::PENDING;
    vector<QStringList> list;
    if(_ms->PacketSearch(f,input,2,list) == SUCCESS){
        _ms->AddToList(ui->pend_list,list,this,nullptr);
    }
}
void Navigation::RecvListRefresh(){
    PacketMatchField f[]={PacketMatchField::DEST,PacketMatchField::STATUS};
    QString input[]{_ms->USER()->getID(),"2"}; //PacketStatus::RECVED
    vector<QStringList> list;
    if(_ms->PacketSearch(f,input,2,list) == SUCCESS){
        _ms->AddToList(ui->recv_list,list,this,nullptr);
    }
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::on_nav_send_clicked()
{
     ToFirstPage();
}


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
    QString dest_id = ui->send_dest->text();
    //输入检测
    dest_id.toInt(&ok);
    if(!ok){
        QMessageBox::information(this,"Error","收件人指定不正确"); return;
    }
    QString info = ui->packet_describe->text();
    if(info == "") info = "null";
    if(info.indexOf(" ") != -1){
        QMessageBox::critical(this,"Error","非法的输入值");    return;
    }
    int count = 1;double count_d = 1;
    int type = ui->packet_type->currentIndex();
    if((PacketType)type == PacketType::BOOK){
        count = ui->packet_count->value();
    }else{
        count_d = ui->packet_count_double->value();
    }
    if(count == 0 || count_d == 0){
        QMessageBox::information(this,"ERROR","数量/重量不正确"); return;
    }
    
    //寄快递
    if(_ms->SendPacket(type,dest_id,(type == 2?((double)count):count_d),info) == SUCCESS){
        QMessageBox::information(this,"TIPS","寄出快递成功");
        //列表刷新
        SendListRefresh();
        PendListRefresh();
        UserInfoRefresh();
        ui->packet_count_double->setValue(0);
        ui->packet_count->setValue(0);
        ui->send_price->setText("---");
    }
    ui->send_dest->clear();
    ui->packet_describe->clear();
}

void Navigation::on_change_info_clicked()
{
    ui->change_name_input->setPlaceholderText(_ms->USER()->getName());
    ui->change_tel_input->setPlaceholderText(_ms->USER()->getTel());
    ui->change_addr_input->setPlaceholderText(_ms->USER()->getAddr());
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
    //输入检测
    QString input[]= {ui->search_input->text()};
    if(idx != PacketMatchField::RECVTIME && idx != PacketMatchField::SENDTIME){
        bool ok;
        input[0].toInt(&ok);
        if(!ok){
            QMessageBox::critical(this,"ERROR","非法的输入值");
            return;
        }
    }
    PacketMatchField f[]={idx};
    vector<QStringList> list;
    //包裹搜索
    if(_ms->PacketSearch(f,input,1,list) == SUCCESS){
        _ms->AddToList(ui->search_list,list,this,nullptr);
        QString str = "\"" + SearchChooseText[(int)idx] + " : " + ui->search_input->text() + "\"";
        ui->search_condition->setText(str);
        ui->page_search->show();
    }

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

void Navigation::RecvPacket(QString id){
    QString time;
    if(_ms->RecvPacket(id,time) == SUCCESS){
        //列表刷新
        SendListRefresh();
        PendListRefresh();
        RecvListRefresh();
        ui->page_search->hide();
    }
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
    QString name = ui->change_name_input->text();
    QString tel = ui->change_tel_input->text();
    QString addr = ui->change_addr_input->text();
    //输入检测
    if(name.indexOf(" ") != -1 || tel.indexOf(" ") != -1 || addr.indexOf(" ") != -1){
        QMessageBox::information(this,"ERROR","非法的输入值");
        return;
    }
    if(name == "") name = "null";
    if(tel == "") tel = "null";
    if(addr == "") addr = "null";
    UserMatchField f[]={UserMatchField::NAME,UserMatchField::TEL,UserMatchField::ADDRESS};
    QString input[]={name,tel,addr};
    //设置用户信息
    if(_ms->SetInfo(f,input,3) == SUCCESS){
        _ms->USER()->setName(name);
        _ms->USER()->setTel(tel);
        _ms->USER()->setAddr(addr);
        on_change_info_cancel_click_clicked();
        UserInfoRefresh();
    }
}

void Navigation::UserInfoRefresh(){
    //用户信息刷新
    ui->user_name->setText(_ms->USER()->getName());
    ui->user_tel->setText(_ms->USER()->getTel());
    ui->user_addr->setText(_ms->USER()->getAddr());
    ui->user_funds->setText(_ms->USER()->getBalance());
}


void Navigation::on_change_passwd_click_clicked()
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


void Navigation::on_recharge_click_clicked()
{
    bool ok;
    QString charge = ui->recharge_input->text();
    //输入检测
    int num = charge.toInt(&ok);
    if(!ok || num <= 0){
        QMessageBox::critical(this,"ERROR","非法的输入值");
        return;
    }
    QString cur_fund;
    if(_ms->Recharge(charge) == SUCCESS){
        UserInfoRefresh();
        on_recharge_cancel_click_clicked();
    }
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
    //价格提示更新
    if(arg1 == 0){
        ui->send_price->setText("---");
    }else{
        //价格计算
        ui->send_price->setText(QString::number(2 * arg1));
    }
}

void Navigation::on_packet_count_double_valueChanged(double arg1)
{
    //价格提示更新
    if(arg1 == 0){
        ui->send_price->setText("---");
    }else{
        //价格计算
        if((PacketType)ui->packet_type->currentIndex() == PacketType::BREAKABLE){
            ui->send_price->setText(QString::number(8 * arg1));
        }else{
            ui->send_price->setText(QString::number(5 * arg1));
        }
    }
}


void Navigation::on_packet_type_currentIndexChanged(int index)
{
    //物品类型更新
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




