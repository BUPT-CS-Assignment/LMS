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
    on_nav_send_clicked();
}

Ui::Navigation *Navigation::GetUI(){
    return ui;
}

//用户界面刷新
void Navigation::Init(){
    int id = _ms->GetUserController()->GetCurUser()->getID();
    string addr = _ms->GetUserController()->GetCurUser()->getAddr();
    ui->send_from->setText(QString::number(id));
    ui->send_from_addr->setText(QString::fromStdString(addr));
    _ms->GetPacketController()->CheckPackets(PCheck::SEND_USER_ID,ui->send_list,&id);
    _ms->GetPacketController()->CheckPackets(PCheck::PACKET_RECV,ui->recv_list,nullptr);
    _ms->GetPacketController()->CheckPackets(PCheck::PACKET_PEND,ui->pend_list,nullptr);
    _ms->GetUserController()->CheckUsers(UCheck::ALL,this,USER_MODE,nullptr);
}

Navigation::~Navigation()
{
    delete ui;
}

//转到第一页
void Navigation::on_nav_send_clicked()
{
     ToFirstPage();
}

//转到查包裹页面
void Navigation::on_nav_check_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_check);
    ui->tabWidget->setCurrentIndex(0);
    //更换图标状态
    ui->nav_user->setIcon(QIcon(":/res/navigation/icon_user.png"));
    ui->nav_check->setIcon(QIcon(":/res/navigation/icon_check_packet_choose.png"));
    ui->nav_send->setIcon(QIcon(":/res/navigation/icon_send_packet.png"));
}

//转到用户信息页面
void Navigation::on_nav_user_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_user);
    //更换图标状态
    ui->nav_user->setIcon(QIcon(":/res/navigation/icon_user_choose.png"));
    ui->nav_check->setIcon(QIcon(":/res/navigation/icon_check_packet.png"));
    ui->nav_send->setIcon(QIcon(":/res/navigation/icon_send_packet.png"));
}

//转到寄包裹页面
void Navigation::ToFirstPage() const{
    ui->stackedWidget->setCurrentWidget(ui->page_send);
    //更换图标状态
    ui->nav_user->setIcon(QIcon(":/res/navigation/icon_user.png"));
    ui->nav_check->setIcon(QIcon(":/res/navigation/icon_check_packet.png"));
    ui->nav_send->setIcon(QIcon(":/res/navigation/icon_send_packet_choose.png"));
}

//点击寄快递
void Navigation::on_send_packet_clicked()
{
    bool ok = false;
    int dest_id = ui->send_dest->text().toInt(&ok);
    std::string describe = ui->packet_describe->text().toStdString();
    /* 输入检查 */
    if(describe == "") describe = "null";
    if(describe.find(" ") != describe.npos){
        QMessageBox::critical(this,"error","Invalid Input");
        return;
    }
    if(ok){
        if(_ms->GetPacketController()->SendPacket(dest_id,describe) == 1){
            QMessageBox::information(this,"Message","Send Packet Success");
            //清楚输入框
            ui->send_dest->clear();
            ui->packet_describe->clear();
            int id = _ms->GetUserController()->GetCurUser()->getID();
            int status = PACKET_STATUS_PEND;
            //更新当前用户相关包裹列表
            _ms->GetPacketController()->CheckPackets(PCheck::SEND_USER_ID,ui->send_list,&id);
            _ms->GetPacketController()->CheckPackets(PCheck::PACKET_PEND,ui->pend_list,&status);
            ui->user_funds->setText(QString::number(_ms->GetUserController()->GetCurUser()->getBalance()));
        }
    }else{
        QMessageBox::information(this,"Error","Invalid Input");
    }

}

//点击更改用户信息
void Navigation::on_change_info_clicked()
{
    User* user = _ms->GetUserController()->GetCurUser();
    ui->change_name_input->setPlaceholderText(QString::fromStdString(user->getName()));
    ui->change_tel_input->setPlaceholderText(QString::fromStdString(user->getTel()));
    ui->change_addr_input->setPlaceholderText(QString::fromStdString(user->getAddr()));
    ui->dia_change_info->show();
}


//点击登出s
void Navigation::on_sign_out_clicked()
{
    _ms->Signout();
    //发出登出信号
    emit SignoutSignal();
}

//点击搜素包裹
void Navigation::on_search_clicked()
{
    int id = ui->search_choose->currentIndex();
    void* input = nullptr;
    bool ok;
    //输入字段类型检查
    if((PCheck)id == PCheck::RECV_TIME || (PCheck)id == PCheck::SEND_TIME){
        string str = ui->search_input->text().toStdString();
        input = &str;
    }else{
        int temp = ui->search_input->text().toInt(&ok);
        if(ok){
            input = &temp;
        }else{
            QMessageBox::critical(this,"error","Invalid Input");
            return;
        }
    }
    //按字段搜素
    _ms->GetPacketController()->CheckPackets((PCheck)id,ui->search_list,input);
    std::string str = "\"" + SearchChooseText[id] + " : " + ui->search_input->text().toStdString() + "\"";
    ui->search_condition->setText(QString::fromStdString(str));
    ui->page_search->show();
}

//点击打开充值对话框
void Navigation::on_recharge_clicked()
{
    ui->dia_recharge->show();
}

//点击关闭搜索框
void Navigation::on_search_goback_clicked()
{
    ui->search_list->clear();
    ui->search_condition->setText("");
    ui->page_search->hide();
}

//点击刷新
void Navigation::on_refresh_clicked()
{
    Init();
}

//签收包裹
void Navigation::RecvPacket(int id){
    //调用包裹管理器
    _ms->GetPacketController()->RecvPacket(id);
    Init();
    ui->page_search->hide();
}

//点击取消修改信息
void Navigation::on_change_info_cancel_click_clicked()
{
    ui->dia_change_info->hide();
    ui->change_name_input->clear();
    ui->change_tel_input->clear();
    ui->change_addr_input->clear();
}

//点击取消修改密码
void Navigation::on_change_paaswd_cancel_click_clicked()
{
    ui->dia_change_passwd->hide();
    ui->change_passwd_input->clear();
    ui->change_passwd_cfm_input->clear();
}

//点击确认修改信息
void Navigation::on_change_info_click_clicked()
{
    string name = ui->change_name_input->text().toStdString();
    string tel = ui->change_tel_input->text().toStdString();
    string addr = ui->change_addr_input->text().toStdString();
    //合法输入检查
    if(name.find(" ") != name.npos || tel.find(" ") != tel.npos || addr.find(" ") != addr.npos){
        QMessageBox::information(this,"error","Invalid Input");
        return;
    }
    _ms->GetUserController()->SetInfo(name,tel,addr);
    on_change_info_cancel_click_clicked();
    _ms->GetUserController()->CheckUsers(UCheck::ALL,this,USER_MODE,nullptr);
}

//点击确定修改密码
void Navigation::on_change_passwd_click_clicked()
{
    string passwd = ui->change_passwd_input->text().toStdString();
    string passwd_cfm = ui->change_passwd_cfm_input->text().toStdString();
    //合法输入检查
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
    _ms->GetUserController()->SetPasswd(passwd);
    on_change_paaswd_cancel_click_clicked();
}

//点击确认充值
void Navigation::on_recharge_click_clicked()
{
    bool ok;
    int charge = ui->recharge_input->text().toInt(&ok);
    //输入合法检查
    if(!ok){
        QMessageBox::critical(this,"error","Invalid Input");
        return;
    }
    if(_ms->GetUserController()->Recharge(charge) != 1){
        QMessageBox::critical(this,"error","Invalid ChargeNum");
        return;
    }
    _ms->GetUserController()->CheckUsers(UCheck::ALL,this,USER_MODE,nullptr);
    on_recharge_cancel_click_clicked();
}

//点击取消充值
void Navigation::on_recharge_cancel_click_clicked()
{
    ui->dia_recharge->hide();
    ui->recharge_input->clear();
}

//点击打开修改密码对话框
void Navigation::on_change_passwd_clicked()
{
    ui->dia_change_passwd->show();
}

