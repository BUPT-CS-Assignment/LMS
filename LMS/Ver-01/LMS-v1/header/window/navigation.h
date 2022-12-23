#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QWidget>
#include "header/main.h"

namespace Ui {
    class Navigation;
}

/* 用户界面UI */
class Navigation : public QWidget
{
    Q_OBJECT

public:
    explicit Navigation(QWidget *parent = nullptr,MainService* ms = nullptr);
    Ui::Navigation * GetUI();   //获取UI界面指针
    void RecvPacket(int id);    //响应包裹签收
    void Init();                //界面初始化
    void ToFirstPage() const;    //返回主页
    ~Navigation();

signals:
    void SignoutSignal();       //登出信号

private slots:
    /* 导航栏响应 */
    void on_nav_send_clicked();                     //点击查看发快递界面
    void on_nav_check_clicked();                    //点击查看查快递界面
    void on_nav_user_clicked();                     //点击查看用户界面

    /* 寄快递响应 */
    void on_send_packet_clicked();                  //点击寄出快递

    /* 查快递响应 */
    void on_refresh_clicked();                      //点击刷新搜索界面
    void on_search_clicked();                       //点击搜索包裹
    void on_search_goback_clicked();                //点击后退到上一个界面

    /* 用户信息界面响应 */
    void on_sign_out_clicked();                     //点击退出
    /////修改用户信息
    void on_change_info_clicked();                  //点击修改用户信息
    void on_change_info_cancel_click_clicked();     //点击取消用户信息更改
    void on_change_info_click_clicked();            //点击确认修改信息
    /////充值
    void on_recharge_clicked();                     //点击充值
    void on_recharge_click_clicked();               //点击确认充值
    void on_recharge_cancel_click_clicked();        //点击取消充值
    /////修改密码
    void on_change_passwd_clicked();                //点击修改密码
    void on_change_passwd_click_clicked();          //点击确认修改密码
    void on_change_paaswd_cancel_click_clicked();   //点击取消密码修改


private:
    Ui::Navigation *ui;                             //UI界面指针
    MainService* _ms;                               //主服务指针
};

#endif // NAVIGATION_H
