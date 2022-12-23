#ifndef PACKETINFO_H
#define PACKETINFO_H

#include <QWidget>
#include "header/window/navigation.h"
#include "header/main.h"

namespace Ui {
class PacketInfo;
}

/* 包裹信息UI */
class PacketInfo : public QWidget
{
    Q_OBJECT

public:
    explicit PacketInfo(QWidget *parent = nullptr,Navigation* nav = nullptr);
    void SetInfo(int userid,const Packet);   //设置包裹UI信息
    ~PacketInfo();

private slots:
    void on_packet_recv_click_clicked();    //点击签收包裹
    /////查看详情
    void on_view_detail_clicked();          //点击查看包裹更多信息
    void on_expand_close_click_clicked();   //点击取消查看包裹更多信息

private:
    Ui::PacketInfo *ui; //ui界面指针
    Navigation* Nav;    //用户界面类指针
};

#endif // PACKETINFO_H
