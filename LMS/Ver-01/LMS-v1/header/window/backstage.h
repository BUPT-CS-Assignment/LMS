#ifndef BACKSTAGE_H
#define BACKSTAGE_H

#include <QWidget>
#include "header/main.h"

namespace Ui {
class BackStage;
}

/* 后台界面UI */
class BackStage : public QWidget
{
    Q_OBJECT    //QT 宏

public:
    explicit BackStage(QWidget *parent = nullptr, MainService* ms = nullptr);
    Ui::BackStage* GetUI();
    void Init();
    ~BackStage();

signals:
    void SignoutSignal();                       //登出信号

private slots:
    void on_sign_out_click_clicked();           //登出按钮点击
    /* 导航栏响应 */
    void on_packet_page_select_clicked();       //选择查看包裹信息界面
    void on_user_page_select_clicked();         //选择查看用户信息界面

    /* 包裹搜索响应 */
    void on_packet_search_click_clicked();      //包裹界面搜索按钮点击
    void on_packet_search_refresh_clicked();    //包裹界面刷新

    /* 用户搜索响应 */
    void on_user_search_click_clicked();        //用户信息界面搜索按钮点击
    void on_user_search_refresh_clicked();      //用户信息界面刷新

private:
    Ui::BackStage *ui;  //ui界面指针
    MainService* _ms;   //主服务指针
};

#endif // BACKSTAGE_H
