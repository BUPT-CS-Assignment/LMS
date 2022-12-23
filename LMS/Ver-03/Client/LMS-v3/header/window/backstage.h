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
    Ui::BackStage* GetUI();         //获取UI指针
    void Init();                    //初始化
    void CollectingRefresh();       //待分配列表刷新
    void CourierChooseRefresh();    //快递员选择列表刷新
    void UserTableRefresh();        //用户表格刷新
    void PacketTableRefresh();      //包裹表格刷新
    void OptionRefresh();           //待操作用户列表刷新
    void AddToPacket(QTableWidget*, std::vector<QStringList>);  //添加到包裹表格
    void AddToUser(QTableWidget*, std::vector<QStringList>);    //添加到用户表格
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

    /* 用户操作响应 */
    void option_set(int row);                   //用户操作选择
    void on_user_delete_clicked();              //删除用户
    void on_user_add_clicked();                 //添加用户
    
    /* 分配快递响应 */
    void on_packet_alloc_clicked();                 //分配快递
    void on_auto_allocation_stateChanged(int arg1); //自动分配切换
    
    /* 数据保存 */
    void on_store_data_click_clicked();

private:
    Ui::BackStage *ui;  //ui界面指针
    MainService* _ms;   //主服务指针
};

#endif // BACKSTAGE_H
