#include <packet.h>
#include <user.h>
#include <console.h>
using namespace std;


PacketControl::PacketControl(User* admin):_packetList(){
    _Co_Ltd = admin;
    _curUser = nullptr;
}

void PacketControl::setUser(User* user){
    _curUser = user;
}

int PacketControl::SendPacket(){
    Console sc;
    sc.LogMsg("===== Send Packet =====");
    if(_curUser->getBalance() < 15){
        sc.LogErr("Insufficient Balance");
        return 0;
    }
    int destid = sc.GetNum("packet dest <userid>");
    if(destid < 0){
        sc.LogMsg("Cancelled"); return 0;
    }
    int id = _packetList.size();
    Packet newPak(_curUser->getID());
    newPak.setID(id);
    
    newPak.setDestUser(destid);
    _packetList.push_back(newPak);
    _curUser->setBalance(_curUser->getBalance() - 15);
    _Co_Ltd->setBalance(_Co_Ltd->getBalance() + 15);
    sc.LogMsg("Send Packet '"+to_string(id)+"' To '"+to_string(destid)+"' Success");
    return 1;
}

int PacketControl::RecvPacket(){
    Console sc;
    sc.LogMsg("===== Recv Packet =====");
    int all = CheckPending();
    if(all == 0){
        sc.LogMsg("No Packets To Receive");
        return 1;
    }
    int idx = sc.GetNum("packet id");
    if(idx < 0){
        sc.LogMsg("Cancelled"); return 0;
    }
    /* 输入检查 */
    if(idx > _packetList.size() 
        || _packetList.at(idx).getStatus() == PACK_RECV
        ||(_curUser != _Co_Ltd && _packetList.at(idx).getDestUser() != _curUser->getID())
        ){
        sc.LogErr("Packet Not Found");
        return 0;
    }

    /* 签收 */
    _packetList.at(idx).setStatus(PACK_RECV);
    _packetList.at(idx).setRecvTime(sc.GetTime());
    sc.LogMsg("Packet '"+to_string(idx)+"' Receive Success");
    return 1;
}

int PacketControl::CheckPackets(int send_recv,PCheck mode){
    Console sc;
    int all = 0;
    if(mode == PCheck::ALL){
        /* 查看所有物件 */
        all = check_all(send_recv);
    }
    else if(mode == PCheck::PACKET_ID){
        /* 物件ID索引 */
        int id = sc.GetNum("pack id");
        all = check_by_id(send_recv,id);
    }
    else if(mode == PCheck::USER_ID){
        /* 查看发送/接收物件 */
        int id = sc.GetNum("user id");
        all = check_by_userid(send_recv,id);
    }
    else if(mode == PCheck::TIME){
        /* 物件时间索引 */
        string str = sc.GetStr("time");
        all = check_by_time(send_recv,str);
    }

    /* 打印空信息 */
    if(all == 0) sc.PrintPacketEmpty();

    /* 打印结尾 */
    sc.PrinfPacketInfo(nullptr, false, true);

    return all;
}

int PacketControl::check_all(int mode){
    Console sc;
    sc.PrinfPacketInfo(nullptr, true);
    int all = 0;    // 总数计算
    /* 遍历搜索 */
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        if(_curUser->getAuth() >= USER_ADMIN
            ||(mode == OPTION_CHECK_SENDS && (*itr).getFromUser() == _curUser->getID())
            ||(mode == OPTION_CHECK_RECVS && (*itr).getDestUser() == _curUser->getID()))
        {
            sc.PrinfPacketInfo(&(*itr));
            all ++;
        }
        itr ++;
    }
    return all;
}

int PacketControl::check_by_id(int mode,int id){
    Console sc;
    sc.PrinfPacketInfo(nullptr, true);
    /* 遍历搜索 */
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        if((*itr).getID() == id)
        {
            if(_curUser->getAuth() >= USER_ADMIN
                ||(mode == OPTION_CHECK_SENDS && (*itr).getFromUser() == _curUser->getID())
                ||(mode == OPTION_CHECK_RECVS && (*itr).getDestUser() == _curUser->getID()))
            {
                sc.PrinfPacketInfo(&(*itr));
                return 1;
            }
        }
        itr ++;
    }
    return 0;
}

int PacketControl::check_by_userid(int mode,int id){
    Console sc;
    sc.PrinfPacketInfo(nullptr, true);
    int all = 0;
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        if(_curUser->getAuth() >= USER_ADMIN){
            if((mode == OPTION_CHECK_SENDS && (*itr).getFromUser() == id)
                ||(mode == OPTION_CHECK_RECVS && (*itr).getDestUser() == id)){
                    sc.PrinfPacketInfo(&(*itr));
                    all++;
            }
        }
        else if((mode == OPTION_CHECK_SENDS && (*itr).getFromUser()==_curUser->getID() && (*itr).getDestUser()==id)
                ||(mode == OPTION_CHECK_RECVS && (*itr).getDestUser()==_curUser->getID() && (*itr).getFromUser()==id))
        {
            sc.PrinfPacketInfo(&(*itr));
            all ++;
        }
        itr ++;
    }
    return all;
}

int PacketControl::check_by_time(int mode,string t){
    Console sc;
    sc.PrinfPacketInfo(nullptr, true);
    int all = 0;
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        if(_curUser->getAuth() >= USER_ADMIN
            || (mode == OPTION_CHECK_SENDS && (*itr).getFromUser() == _curUser->getID())
            || (mode == OPTION_CHECK_RECVS && (*itr).getDestUser() == _curUser->getID()))
        {
            if((mode == OPTION_CHECK_SENDS && (*itr).getSendTime().compare(0,t.length(),t)==0)
             ||(mode == OPTION_CHECK_RECVS && (*itr).getRecvTime().compare(0,t.length(),t)==0))
            {
                sc.PrinfPacketInfo(&(*itr));
                all++;
            }
        }
        itr ++;
    }
    return all;
}

int PacketControl::CheckPending(){
    Console sc;
    sc.PrinfPacketInfo(nullptr, true);
    int all = 0;
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        if((*itr).getStatus() == PACK_PEND && 
            (_curUser->getAuth() >= USER_COLTD || (*itr).getDestUser() == _curUser->getID()))
        {
            sc.PrinfPacketInfo(&(*itr));
            all++;
        }
        itr ++;
    }
    if(all == 0) sc.PrintPacketEmpty();
    sc.PrinfPacketInfo(nullptr, false, true);
    return all;
}
