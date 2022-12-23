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

//点击确认登录
void Signin::on_signin_click_clicked()
{
    int id = ui->signin_id_input->text().toInt();
    string passwd = ui->signin_pwd_input->text().toStdString();
    //确定登录权限
    int auth = (ui->is_admin->isChecked() ? 1 : 0);
    int err = _ms->Signin(id,passwd,auth);
    //判定登录结果
    if(err == USER_SIGNIN_SUCCESS){
        if(auth == USER_COMMON) emit SigninSuccess();
        else emit SigninBackStage();
    }
    else if(err == USER_AUTH_FAILED){
        QMessageBox::critical(this,"Error","Access Denied");
    }
    else{
        QMessageBox::critical(this,"Error","Wrong userid or passwd");
    }
}

//点击跳转到注册页面
void Signin::on_signup_switch_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//点击确认注册
void Signin::on_signup_click_clicked()
{
    bool ok;
    int id = ui->signup_id_input->text().toInt(&ok);
    //检查输入合法性
    if(ok){
        string passwd = ui->signup_pwd_input->text().toStdString();
        string passwd_cfm = ui->signup_pwd_cfm_input->text().toStdString();
        //检查输入结果匹配
        if(passwd == passwd_cfm){
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

//点击返回登录页面
void Signin::on_go_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->signup_id_input->clear();
    ui->signup_pwd_input->clear();
    ui->signup_pwd_cfm_input->clear();
}




