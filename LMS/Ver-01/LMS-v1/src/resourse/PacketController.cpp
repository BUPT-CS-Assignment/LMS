#include "header/Basic.h"
using namespace std;


PacketControl::PacketControl(User* admin):_packetList(){
    _Co_Ltd = admin;
    _curUser = nullptr;
    _output_dest = BACKSTAGE_MODE;
    _nav_link = nullptr;
}

//设置当前用户指针
void PacketControl::setUser(User* user){
    _curUser = user;
}

//设置管理员用户指针
void PacketControl::setAdmin(User* admin){
    _Co_Ltd = admin;
}

//链接用户页面UI
void PacketControl::LinkNavigation(Navigation* nav){
    _nav_link = nav;
    if(nav == nullptr)  _output_dest = BACKSTAGE_MODE;
    else _output_dest = USER_MODE;
}

//发送包裹
int PacketControl::SendPacket(int dest_id,std::string describe){
    Console sc;
    /* 余额检查 */
    if(_curUser->getBalance() < 15){
        QMessageBox::critical(nullptr,"error","Insufficient Balance");
        sc.LogErr("Insufficient Balance");
        return 0;
    }
    /* 用户检查 */
    if(dest_id < 0){
        sc.LogMsg("Cancelled"); return -1;
    }
    /* 新建包裹 */
    int id = _packetList.size();
    Packet newPak(_curUser->getID());
    newPak.setID(id);                   //设置ID
    newPak.setDescription(describe);    //设置描述
    newPak.setDestUser(dest_id);        //设置收件人

    _packetList.push_back(newPak);      //添加新包裹
    /* 余额状态更新 */
    _curUser->setBalance(_curUser->getBalance() - 15);
    _Co_Ltd->setBalance(_Co_Ltd->getBalance() + 15);
    sc.LogMsg("Send Packet '"+to_string(id)+"' To '"+to_string(dest_id)+"' Success");
    return 1;
}

//签收包裹
void PacketControl::RecvPacket(int idx){
    Console sc;
    sc.LogMsg("===== Recv Packet =====");
    _packetList.at(idx).setStatus(PACKET_STATUS_RECV);  //设置签收状态
    _packetList.at(idx).setRecvTime(sc.GetTime());      //设置签收时间
    sc.LogMsg("Packet '"+to_string(idx)+"' Receive Success");
}

//搜索包裹
void PacketControl::CheckPackets(PCheck mode,void* list,void* input) const {
    int auth = USER_COMMON, temp = 0;

    /* 清空UI表格 */
    if(_output_dest == BACKSTAGE_MODE){
        auth = USER_ADMIN;
        ((QTableWidget*)list)->clearContents();
        ((QTableWidget*)list)->setRowCount(0);
    }else{
        ((QListWidget*)list)->clear();
    }

    /* 检查判别类型 */
    switch(mode){
        case PCheck::ALL:
            check_traverse(list,&PacketControl::check_all,auth,input);  break;
        case PCheck::PACKET_PEND:
            temp = PACKET_STATUS_PEND;
            check_traverse(list,&PacketControl::check_by_status,auth,&temp);  break;
        case PCheck::PACKET_RECV:
            temp = PACKET_STATUS_RECV;
            check_traverse(list,&PacketControl::check_by_status,auth,&temp);  break;
        case PCheck::PACKET_ID:
            check_traverse(list,&PacketControl::check_by_packet_id,auth,input); break;
        case PCheck::RECV_USER_ID:
            check_traverse(list,&PacketControl::check_by_recv_user,auth,input); break;
        case PCheck::SEND_TIME:
            check_traverse(list,&PacketControl::check_by_send_time,auth,input); break;
        case PCheck::RECV_TIME:
            check_traverse(list,&PacketControl::check_by_recv_time,auth,input); break;
        case PCheck::SEND_USER_ID:
            check_traverse(list,&PacketControl::check_by_send_user,auth,input); break;
    }
}

/* 添加包裹到列表 */
void PacketControl::AddToList(QListWidget* List,const Packet p,int Userid) const{
    PacketInfo *pInfo = new PacketInfo(nullptr, _nav_link);
    pInfo->SetInfo(Userid,p);
    QListWidgetItem *pItem = new QListWidgetItem(List);
    pItem->setSizeHint(QSize(390,170));
    List->addItem(pItem);
    List->setItemWidget(pItem,pInfo);
}

/* 添加包裹到表格 */
void PacketControl::AddToTable(QTableWidget* table,const Packet p) const{
    int row = table->rowCount();
    table->setRowCount(row + 1);
    table->setItem(row,0,new QTableWidgetItem(QString::number(p.getID())));
    table->setItem(row,1,new QTableWidgetItem(QString::number(p.getStatus())));
    table->setItem(row,2,new QTableWidgetItem(QString::number(p.getFromUser())));
    table->setItem(row,3,new QTableWidgetItem(QString::number(p.getDestUser())));
    table->setItem(row,4,new QTableWidgetItem(QString::fromStdString(p.getSendTime())));
    table->setItem(row,5,new QTableWidgetItem(QString::fromStdString(p.getRecvTime())));
    table->setItem(row,6,new QTableWidgetItem(QString::fromStdString(p.getDescription())));
}

//遍历搜索函数
void PacketControl::check_traverse(void* list,compare c,int auth,void* input) const{
    int all = 0;    // 总数计算
    int userid = _curUser->getID();
    /* 遍历搜索 */
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        if((this->*c)((*itr),auth,userid,input)){
            if(_output_dest == USER_MODE){
                AddToList((QListWidget*)list,(*itr),userid);
            }else if(_output_dest == BACKSTAGE_MODE){
                AddToTable((QTableWidget*)list,(*itr));
            }
            all++;
        }
        itr ++;
    }
    if(all == 0 && _output_dest == USER_MODE){
        QListWidgetItem* p = new QListWidgetItem();
        p->setText("No Packets");
        ((QListWidget*)list)->addItem(p);
    }
}

//比对寄件时间
bool PacketControl::check_by_send_time(const Packet p,int auth,int userid,void* input) const{
    string t = *(string*)input;
    if(auth == USER_COMMON && p.getFromUser() != userid)    return false;
    if(p.getSendTime().compare(0,t.length(),t)==0) return true;
    return false;
}

//比对收件时间
bool PacketControl::check_by_recv_time(const Packet p,int auth,int userid,void* input) const{
    string t = *(string*)input;
    if(auth == USER_COMMON && p.getFromUser() != userid)    return false;
    if(p.getRecvTime().compare(0,t.length(),t)==0) return true;
    return false;
}

//比对寄件人
bool PacketControl::check_by_send_user(const Packet p,int auth,int userid,void* input) const{
    int user = *(int*)input;
    if(auth == USER_COMMON && p.getFromUser() != userid)    return false;
    if(p.getFromUser() == user) return true;
    return false;
}

//比对收件人
bool PacketControl::check_by_recv_user(const Packet p,int auth,int userid,void* input) const{
    int user = *(int*)input;
    if(auth == USER_COMMON && p.getFromUser() != userid)    return false;
    if(p.getDestUser() == user) return true;
    return false;
}

//比对运单号
bool PacketControl::check_by_packet_id(const Packet p,int auth,int userid,void* input) const{
    int id = *(int*)input;
    if(auth == USER_COMMON && p.getFromUser() != userid)    return false;
    if(p.getID() == id) return true;
    return false;
}

//比对运单状态
bool PacketControl::check_by_status(const Packet p,int auth,int userid,void* input) const{
    int status = *(int*)input;
    if(auth == USER_COMMON && p.getDestUser() != userid)    return false;
    if(p.getStatus() == status) return true;
    return false;
}

//搜索所有
bool PacketControl::check_all(const Packet p,int auth,int userid,void* input) const{
    if(auth == USER_COMMON && p.getFromUser() != userid)    return false;
    return true;
}
