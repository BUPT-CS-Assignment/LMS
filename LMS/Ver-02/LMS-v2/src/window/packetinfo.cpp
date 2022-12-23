#include "header/Basic.h"
using namespace std;
PacketInfo::PacketInfo(QWidget *parent,Navigation* nav,Manage* mng) :
    QWidget(parent),
    ui(new Ui::PacketInfo)
{
    ui->setupUi(this);
    ui->detail->hide();
    Nav = nav;
    Mng = mng;
}

PacketInfo::~PacketInfo()
{
    delete ui;
}

/* 初始化 */
void PacketInfo::Init(int userid,PacketBase* p,UserAuth auth) const{
    unsigned long long packetid = p->getID();
    int from = p->getFromUser(), dest = p->getDestUser(), status = p->getStatus();
    double count = p->getCount();
    string sendtime = p->getSendTime(), recvtime = p->getRecvTime(), describe = p->getDescription();
    ui->packet_status->setText(QString::fromStdString(PacketStatusText[status]));
    /* 权限/用户检测 */
    if(Mng != nullptr && auth == UserAuth::COURIER){
        ui->packet_recv_click->hide();
        if((PacketStatus)status != PacketStatus::COLLECTING){
            ui->packet_collect_click->hide();
        }
    }else if(Nav != nullptr && auth == UserAuth::USER && dest == userid){
        ui->packet_collect_click->hide();
        if((PacketStatus)status != PacketStatus::PENDING){
            ui->packet_recv_click->hide();
        }
    }else{
        ui->packet_collect_click->hide();
        ui->packet_recv_click->hide();
    }
    //信息填充
    ui->packet_id->setText(QString::number(packetid));
    ui->from_user->setText(QString::number(from));
    ui->dest_user->setText(QString::number(dest));
    ui->from_user->setAlignment(Qt::AlignHCenter);
    ui->dest_user->setAlignment(Qt::AlignHCenter);
    ui->packet_status->setAlignment(Qt::AlignHCenter);
    ui->packet_type->setText(QString::fromStdString(PacketTypeText[p->getType()]));
    ui->count_type->setText(p->getType()==2?QString("数量"):QString("重量"));
    ui->packet_count->setText(QString::number(p->getType()==2?((int)count):count));
    ui->send_time->setText(QString::fromStdString(sendtime));
    ui->recv_time->setText(QString::fromStdString(recvtime=="null"?"":recvtime));
    ui->packet_describe->setText(QString::fromStdString(describe));
    ui->packet_price->setText(QString::number(p->getPrice()));

}


void PacketInfo::on_packet_recv_click_clicked()
{
    Nav->RecvPacket(ui->packet_id->text().toULongLong());
}

void PacketInfo::on_packet_collect_click_clicked()
{
    Mng->CollectPacket(ui->packet_id->text().toULongLong());
}


void PacketInfo::on_expand_close_click_clicked()
{
    ui->detail->hide();
}


void PacketInfo::on_view_detail_clicked()
{
    ui->detail->show();
}



