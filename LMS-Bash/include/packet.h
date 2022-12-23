#ifndef __PACKET_H__
#define __PACKET_H__
#include <main.h>
#include <console.h>

#define PACK_RECV 0
#define PACK_PEND 1

enum class PCheck:int{
    ALL,
    TIME,
    USER_ID,
    PACKET_ID,
};

class Packet{
private:
    int _id;
    int _status;
    int _fromUser;
    int _destUser;
    std::string _sendTime;
    std::string _recvTime;

public:
    Packet(int userid){
        Console sc;
        _status = PACK_PEND;
        _fromUser = userid;
        _destUser = 0;
        _sendTime = sc.GetTime();
        _recvTime = "null";
    };
    Packet(int id,int status,int from,int dest,std::string sendtime,std::string recvtime){
        _id = id;
        _status = status;
        _fromUser = from;
        _destUser = dest;
        _sendTime = sendtime;
        _recvTime = recvtime;
    }
    int getID(){
        return _id;
    }
    void setID(int id){
        _id = id;
    }
    void setStatus(int status){
        _status = status;
    }
    int getStatus(){
        return _status;
    }
    void setRecvTime(std::string t){
        _recvTime = t;
    }
    std::string getSendTime(){
        return _sendTime;
    }
    std::string getRecvTime(){
        return _recvTime;
    }
    void setDestUser(int toid){
        _destUser = toid;
    }
    int getFromUser(){
        return _fromUser;
    }
    int getDestUser(){
        return _destUser;
    }
};

class PacketControl{
private:
    std::vector<Packet> _packetList;
    User* _Co_Ltd;
    User* _curUser;
    int check_all(int);
    int check_by_id(int,int id);
    int check_by_userid(int,int id);
    int check_by_time(int,std::string);
public:
    PacketControl(User* admin);
    void setUser(User*);
    int SendPacket();
    int RecvPacket();
    int CheckPackets(int,PCheck mode);
    int CheckPending();
    std::vector<Packet>* GetPacketList(){
        return &_packetList;
    }

};

#endif