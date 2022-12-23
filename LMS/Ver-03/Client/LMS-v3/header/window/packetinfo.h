#ifndef PACKETINFO_H
#define PACKETINFO_H

#include <QWidget>
#include "navigation.h"
#include "manage.h"
#include "header/main.h"

namespace Ui {
class PacketInfo;
}

/* 包裹信息UI */
class PacketInfo : public QWidget
{
    Q_OBJECT    //QT 宏

public:
    explicit PacketInfo(QWidget *parent = nullptr,Navigation* nav = nullptr,Manage* mng = nullptr);
    //初始化
    bool Init(QString userid,QStringList& info,UserAuth auth = UserAuth::USER) const;
    ~PacketInfo();
    Ui::PacketInfo* GetUI(){
        return ui;
    }

private slots:
    void on_packet_recv_click_clicked();    //点击签收包裹
    /////查看详情
    void on_view_detail_clicked();          //点击查看包裹更多信息
    void on_expand_close_click_clicked();   //点击取消查看包裹更多信息
    void on_packet_collect_click_clicked(); //点击揽收包裹

private:
    Ui::PacketInfo *ui; //ui界面指针
    Navigation* Nav;    //用户界面类指针
    Manage* Mng;        //快递员界面指针
};

#endif // PACKETINFO_H
