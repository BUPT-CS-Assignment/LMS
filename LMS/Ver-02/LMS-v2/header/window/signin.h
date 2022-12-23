#ifndef SIGNIN_H
#define SIGNIN_H

#include "header/main.h"
#include "header/mainService.h"

namespace Ui {
    class Signin;
}

/* 登录界面UI */
class Signin : public QWidget
{
    Q_OBJECT

public:
    explicit Signin(QWidget *parent = nullptr,MainService* ms = nullptr);
    Ui::Signin * GetUI();               //获取UI指针
    ~Signin();

signals:
    void SigninSuccess();               //用户登录信号
    void SigninManage();
    void SigninBackStage();             //管理员登录信号

private slots:
    void on_signin_click_clicked();     //点击登录
    void on_signup_switch_clicked();    //点击转到注册界面
    void on_signup_click_clicked();     //点击确认注册
    void on_go_back_clicked();          //点击返回登录界面


private:
    Ui::Signin *ui;                     //ui指针
    MainService* _ms;                   //主服务指针
};

#endif // SIGNIN_H
