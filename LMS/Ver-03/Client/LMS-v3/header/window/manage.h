#ifndef MANAGE_H
#define MANAGE_H

#include "header/main.h"
#include "header/console.h"

namespace Ui {
class Manage;
}

class Manage : public QWidget
{
    Q_OBJECT //QT 宏

public:
    explicit Manage(QWidget *parent = nullptr,MainService* ms = nullptr);
    ~Manage();
    //获取主服务指针
    MainService* MS() const{
        return _ms;
    }
    Ui::Manage* GetUI();                //获取UI指针
    void CollectPacket(QString id);     //揽收包裹
    void Init();                        //界面初始化
    void AllListRefresh();              //所有列表刷新
    void CollectingListRefresh();       //待揽收列表刷新
    void CollectedListRefresh();        //已投递列表刷新
    void UserInfoRefresh();             //用户信息刷新
    void ToFirstPage();                 //转到首页

signals:
    void SignoutSignal();       //登出信号

private slots:
    /* 导航栏响应 */
    void on_mng_user_clicked();                     //点击查看用户界面
    void on_mng_check_clicked();                    //点击查看快递管理界面

    /* 快递搜索响应 */
    void on_search_clicked();                       //点击搜索快递
    void on_refresh_clicked();                      //点击刷新搜索界面
    void on_search_goback_clicked();                //点击关闭搜索页面

    /* 用户信息界面响应 */
    void on_sign_out_clicked();                     //退出
    /////修改用户信息
    void on_change_info_clicked();                  //点击修改用户信息
    void on_change_info_click_clicked();            //点击确认修改信息
    void on_change_info_cancel_click_clicked();     //点击取消修改信息
    /////修改密码
    void on_change_passwd_clicked();                //点击修改密码
    void on_change_passwd_click_clicked();          //点击确认修改密码
    void on_change_paaswd_cancel_click_clicked();   //点击取消修改密码
    /////充值
    void on_recharge_clicked();                     //点击充值
    void on_recharge_click_clicked();               //点击确认充值
    void on_recharge_cancel_click_clicked();        //点击取消充值

    void on_collect_all_clicked();                  //点击揽收所有快递

private:
    Ui::Manage *ui;     //UI指针
    MainService* _ms;   //主服务指针
};

#endif // MANAGE_H
