#include "header/Basic.h"
using namespace std;
PacketInfo::PacketInfo(QWidget *parent,Navigation* nav,Manage* mng) :
    QWidget(parent),
    ui(new Ui::PacketInfo)
{
    ui->setupUi(this);
    ui->detail->hide();
    //连接用户界面+快递员界面
    Nav = nav;
    Mng = mng;
}

PacketInfo::~PacketInfo()
{
    delete ui;
}

bool PacketInfo::Init(QString userid,QStringList& info ,UserAuth auth) const{
    if(info.size() != 11) return false;
    ui->packet_status->setText(PacketStatusText[info[(int)PACK_RECV::STATUS][0].toLatin1()-'0']);
    //快递员界面/用户界面/权限判断
    if(Mng != nullptr && auth == UserAuth::COURIER){
        ui->packet_recv_click->hide();
        if(info[(int)PACK_RECV::STATUS][0] != '0'){
            ui->packet_collect_click->hide();
        }
    }else if(Nav != nullptr && auth == UserAuth::USER
             && info[(int)PACK_RECV::DEST] == userid){
        ui->packet_collect_click->hide();
        if(info[(int)PACK_RECV::STATUS][0] != '1'){
            ui->packet_recv_click->hide();
        }
    }else{
        ui->packet_collect_click->hide();
        ui->packet_recv_click->hide();
    }
    //填充组件文字
    ui->packet_id->setText(info[(int)PACK_RECV::ID]);
    ui->from_user->setText(info[(int)PACK_RECV::FROM]);
    ui->dest_user->setText(info[(int)PACK_RECV::DEST]);
    ui->from_user->setAlignment(Qt::AlignHCenter);
    ui->dest_user->setAlignment(Qt::AlignHCenter);
    ui->packet_status->setAlignment(Qt::AlignHCenter);
    ui->packet_type->setText(PacketTypeText[info[(int)PACK_RECV::TYPE][0].toLatin1()-'0']);
    ui->count_type->setText(info[(int)PACK_RECV::TYPE]=="2"?QString("数量"):QString("重量"));
    ui->packet_count->setText(info[(int)PACK_RECV::COUNT]);
    ui->send_time->setText(info[(int)PACK_RECV::SEND_TIME]);
    ui->recv_time->setText(info[(int)PACK_RECV::RECV_TIME]);
    ui->packet_describe->setText(info[(int)PACK_RECV::DESCRIBE]);
    ui->packet_price->setText(info[(int)PACK_RECV::PRICE]);
    return true;
}


void PacketInfo::on_packet_recv_click_clicked()
{
    Nav->RecvPacket(ui->packet_id->text()); //签收包裹
}

void PacketInfo::on_packet_collect_click_clicked()
{
    Mng->CollectPacket(ui->packet_id->text());  //揽收包裹
}


void PacketInfo::on_expand_close_click_clicked()
{
    ui->detail->hide(); //隐藏详细信息
}


void PacketInfo::on_view_detail_clicked()
{
    ui->detail->show(); //显示详细信息
}



