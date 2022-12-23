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
    int id = ui->signin_id_input->text().toInt();
    string passwd = ui->signin_pwd_input->text().toStdString();
    int auth = ui->auth_choose->currentIndex();
    //登录
    int err = _ms->Signin(id,passwd,auth);
    //发送跳转信号
    if(err == USER_SIGNIN_SUCCESS){
        if(id == 0){
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
    else if(err == USER_AUTH_FAILED){
        QMessageBox::critical(this,"Error","Access Denied");
    }
    else{
        QMessageBox::critical(this,"Error","Wrong userid or passwd");
    }
}

void Signin::on_signup_switch_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Signin::on_signup_click_clicked()
{
    bool ok;
    int id = ui->signup_id_input->text().toInt(&ok);
    //输入检测
    if(ok){
        string passwd = ui->signup_pwd_input->text().toStdString();
        string passwd_cfm = ui->signup_pwd_cfm_input->text().toStdString();
        if(passwd == passwd_cfm){
            //输入匹配检测
            if(_ms->Signup(id,passwd) == USER_SIGNUP_SUCCESS){
                QMessageBox::information(this,"Message","Signup Success");
                on_go_back_clicked();
            }else{
                QMessageBox::information(this,"error","ID Existed");
            }
        }else{
            QMessageBox::critical(this,"error","Passwd Not Match");
        }
    }else{
        QMessageBox::information(this,"error","Invalid Input");
    }

}


void Signin::on_go_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->signup_id_input->clear();
    ui->signup_pwd_input->clear();
    ui->signup_pwd_cfm_input->clear();
}




