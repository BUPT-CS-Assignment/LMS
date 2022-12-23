#include "header/Basic.h"
using namespace std;

Signin::Signin(QWidget *parent,MainService* ms) :
    QWidget(parent),
    ui(new Ui::Signin)
{
    _ms = ms;
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Signin::~Signin()
{
    delete ui;
}

Ui::Signin* Signin::GetUI(){
    return ui;
}

void Signin::on_signin_click_clicked()
{
    //连接服务器
    if(!_ms->Connect(1)){
        QMessageBox::critical(this,"ERROR","连接服务器失败，请重试");
        return;
    }
    QString id = ui->signin_id_input->text();
    QString passwd = ui->signin_pwd_input->text();
    int auth = ui->auth_choose->currentIndex();
    //登录请求
    if( _ms->Signin(id,passwd,auth)== SUCCESS){
        //跳转信号发送
        if(id == "0"){
            emit SigninBackStage();
            return;
        }
        switch((UserAuth)auth){
            case UserAuth::USER:
                emit SigninSuccess();   break;
            case UserAuth::COURIER:
                emit SigninManage();    break;
            case UserAuth::ADMIN: case UserAuth::ROOT:
                emit SigninBackStage(); break;
        }
    }
}

void Signin::on_signup_switch_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Signin::on_signup_click_clicked()
{
    bool ok;
    QString id = ui->signup_id_input->text();
    id.toInt(&ok);
    //输入检测
    if(ok){
        QString passwd = ui->signup_pwd_input->text();
        QString passwd_cfm = ui->signup_pwd_cfm_input->text();
        if(passwd == passwd_cfm){
            //连接服务器
            if(!_ms->Connect(1)){
                QMessageBox::critical(this,"ERROR","连接服务器失败，请重试");
                return;
            }
            //注册请求
            if(_ms->Signup(id,passwd) == SUCCESS){
                QMessageBox::information(this,"TIPS","注册成功");
                on_go_back_clicked();
            }
        }else{
            QMessageBox::critical(this,"ERROR","两次输入不匹配");
        }
    }else{
        QMessageBox::information(this,"ERROR","非法的输入值");
    }

}


void Signin::on_go_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->signup_id_input->clear();
    ui->signup_pwd_input->clear();
    ui->signup_pwd_cfm_input->clear();
}




