#ifndef __PACKET_H__
#define __PACKET_H__
#include "main.h"
#include "console.h"
#include "window/navigation.h"
#include "window/packetinfo.h"
#include "window/backstage.h"
#include "ui_navigation.h"
#include "ui_packetinfo.h"

/* 包裹类 */
class Packet{
private:
    int _id;                //运单号(包裹ID)
    int _status;            //包裹状态
    int _fromUser;          //寄件人
    int _destUser;          //收件人
    std::string _sendTime;  //寄件时间
    std::string _recvTime;  //签收时间
    std::string _describe;  //包裹描述信息

public:
    //构造函数
    Packet(int userid){
        Console sc;
        _status = PACKET_STATUS_PEND;
        _fromUser = userid;
        _destUser = 0;
        _sendTime = sc.GetTime();   //控制台类获取当前时间
        _recvTime = "null";
        _describe = "null";
    };
    //完整信息构造
    Packet(int id,int status,int from,int dest,std::string sendtime,std::string recvtime,std::string info = "null"){
        _id = id;
        _status = status;
        _fromUser = from;
        _destUser = dest;
        _sendTime = sendtime;
        _recvTime = recvtime;
        _describe = info;
    }
    int getID() const{                        //获取运单号
        return _id;
    }
    void setID(int id){                 //设置运单号
        _id = id;
    }
    void setStatus(int status){         //设置包裹状态
        _status = status;
    }
    int getStatus() const{                    //获取包裹状态
        return _status;
    }
    void setRecvTime(std::string t){    //设置收件时间
        _recvTime = t;
    }
    std::string getSendTime() const{          //获取收件时间
        return _sendTime;
    }
    std::string getRecvTime() const{          //获取签收时间
        return _recvTime;
    }
    void setDestUser(int toid){         //设置签收时间
        _destUser = toid;
    }
    int getFromUser() const{                  //获取寄件人ID
        return _fromUser;
    }
    int getDestUser() const{                  //获取收件人ID
        return _destUser;
    }
    void setDescription(std::string d){ //设置描述信息
        _describe = d;
    }
    std::string getDescription() const{       //获取描述信息
        return _describe;
    }
};

/* 包裹管理器 */
class PacketControl{
private:
    std::vector<Packet> _packetList;    //包裹列表
    User* _Co_Ltd;                      //物理公司指针
    User* _curUser;                     //当前用户指针
    int _output_dest;                   //信息输出模式(用户界面/后台界面)
    Navigation* _nav_link;              //用户界面指针
    //判别函数类型指针
    typedef bool (PacketControl::*compare)(const Packet,int,int,void*)  const;
    //遍历搜索(传入判别函数指针)
    void check_traverse(void* dest,compare,int auth,void* input = nullptr) const;
    /* 判别函数 */
    bool check_all(const Packet,int auth,int userid,void* input = nullptr) const;   //查看所有
    bool check_by_status(const Packet,int auth,int userid,void* input) const;       //按包裹状态判断
    bool check_by_send_time(const Packet,int auth,int userid,void* input) const;    //按发件时间判断
    bool check_by_recv_time(const Packet,int auth,int userid,void* input) const;    //按签收时间判断
    bool check_by_send_user(const Packet,int auth,int userid,void* input) const;    //按发件人判断
    bool check_by_recv_user(const Packet,int auth,int userid,void* input) const;    //按签收人判断
    bool check_by_packet_id(const Packet,int auth,int userid,void* input) const;    //按包裹ID判断
    void AddToList(QListWidget*,const Packet,int Userid) const;                     //添加到Widget列表(用户GUI)
    void AddToTable(QTableWidget*,const Packet) const;                              //添加到Widget表格(后台管理GUI)

public:
    PacketControl(User* admin = nullptr);
    void setUser(User*);                                                //连接当前用户
    void setAdmin(User*);                                               //连接物流公司
    void LinkNavigation(Navigation* nav);                               //连接用户界面GUI
    int  SendPacket(int dest_id,std::string descirbe);                  //寄出包裹
    void RecvPacket(int idx);                                           //签收包裹
    void CheckPackets(PCheck,void* list,void* input = nullptr)const;    //搜索包裹
    std::vector<Packet>* GetPacketList() {                              //获取包裹列表
        return &_packetList;
    }

};

#endif
