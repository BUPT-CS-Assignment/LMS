#include "header/Basic.h"

PacketInfo::PacketInfo(QWidget *parent,Navigation* nav) :
    QWidget(parent),
    ui(new Ui::PacketInfo)
{
    ui->setupUi(this);
    ui->detail->hide();
    Nav = nav;
}

PacketInfo::~PacketInfo()
{
    delete ui;
}

//填充包裹信息到页面组件
void PacketInfo::SetInfo(int userid,const Packet p){

    int packetid = p.getID();
    int fromuser = p.getFromUser();
    int destuser = p.getDestUser();
    int status = p.getStatus();
    std::string sendtime = p.getSendTime();
    std::string recvtime = p.getRecvTime();
    std::string describe = p.getDescription();
    ui->packet_id->setText(QString::number(packetid));
    ui->from_user->setText(QString::number(fromuser));
    ui->dest_user->setText(QString::number(destuser));
    ui->from_user->setAlignment(Qt::AlignHCenter);
    ui->dest_user->setAlignment(Qt::AlignHCenter);
    //设置状态文字
    if(status == PACKET_STATUS_PEND){
        ui->packet_status->setText("运输中");
        if(userid != p.getDestUser()){
            ui->packet_recv_click->hide();
        }
    }else{
        ui->packet_status->setText("已签收");
        ui->packet_recv_click->hide();
    }
    ui->packet_status->setAlignment(Qt::AlignHCenter);
    ui->send_time->setText(QString::fromStdString(sendtime));
    ui->recv_time->setText(QString::fromStdString(recvtime=="null"?"":recvtime));
    ui->packet_describe->setText(QString::fromStdString(describe));
}

//点击签收包裹
void PacketInfo::on_packet_recv_click_clicked()
{
    Nav->RecvPacket(ui->packet_id->text().toInt());
}

//点击关闭包裹详情
void PacketInfo::on_expand_close_click_clicked()
{
    ui->detail->hide();
}

//点击展开包裹详情
void PacketInfo::on_view_detail_clicked()
{
    ui->detail->show();
}

