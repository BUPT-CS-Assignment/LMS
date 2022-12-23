#ifndef __PACKET_H__
#define __PACKET_H__
#include "main.h"
#include "console.h"
#include "window/navigation.h"
#include "window/packetinfo.h"
#include "window/backstage.h"
#include "storage.h"
#include "ui_navigation.h"
#include "ui_packetinfo.h"

/* 包裹类 */
class PacketBase{
private:
    unsigned long long _id; //运单号(包裹ID)
    int _status;            //包裹状态
    int _courier;           //揽收人
    int _fromUser;          //寄件人
    int _destUser;          //收件人
    std::string _sendTime;  //寄件时间
    std::string _recvTime;  //签收时间
    std::string _describe;  //包裹描述信息
    int _type;              //包裹类型
    double _count;          //包裹数量/重量
public:
    //构造函数
    PacketBase(){
        _id = 0;    _count = 0;
        _status = (int)PacketStatus::COLLECTING;
        _courier = _fromUser = _destUser = _type = 0;
        _sendTime = _recvTime = _describe = "null";
    }
    //完整信息构造
    void Fill(unsigned long long id,int status,int courier,int from,int dest,
              std::string sendtime,std::string recvtime,std::string info = "null"){
        _id = id;
        _status = status;
        _courier = courier;
        _fromUser = from;
        _destUser = dest;
        _sendTime = sendtime;
        _recvTime = recvtime;
        _describe = info;
    }
    unsigned long long getID() const{                  //获取运单号
        return _id;
    }
    void setID(unsigned long long id){                 //设置运单号
        _id = id;
    }
    void setStatus(int status){         //设置包裹状态
        _status = status;
    }
    int getCourier() const{             //获取揽收人
        return _courier;
    }
    void setCourier(int id){            //设置揽收人
        _courier = id;
    }
    int getStatus() const{              //获取包裹状态
        return _status;
    }
    void setSendTime(std::string t){    //设置寄件时间
        _sendTime = t;
    }
    void setRecvTime(std::string t){    //设置收件时间
        _recvTime = t;
    }
    std::string getSendTime() const{    //获取收件时间
        return _sendTime;
    }
    std::string getRecvTime() const{    //获取签收时间
        return _recvTime;
    }
    void setDestUser(int toid){         //设置签收时间
        _destUser = toid;
    }
    void setFromUser(int id){           //设置寄件人ID
        _fromUser = id;
    }
    int getFromUser() const{            //获取寄件人ID
        return _fromUser;
    }
    int getDestUser() const{            //获取收件人ID
        return _destUser;
    }
    void setDescription(std::string d){ //设置描述信息
        _describe = d;
    }
    std::string getDescription() const{ //获取描述信息
        return _describe;
    }
    int getType() const{                //获取包裹类型
        return _type;
    }
    void setType(int t){                //设置包裹类型
        _type = t;
    }
    double getCount() const{            //获取包裹重量/数量
        return _count;
    }
    void setCount(double c){            //设置包裹重量/数量
        _count = c;
    }
    virtual double getPrice(){return 0;}//计算价格
    virtual ~PacketBase(){}
};

/* 易碎品 */
class Breakable:public PacketBase{
public:
    Breakable():PacketBase(){
        setType((int)PacketType::BREAKABLE);
    }
    //计算价格
    virtual double getPrice(){
        return 8 * getCount();
    }
    virtual ~Breakable(){}
};

/* 图书 */
class Book:public PacketBase{
public:
    Book():PacketBase(){
        setType((int)PacketType::BOOK);
    }
    //计算价格
    virtual double getPrice(){
        return 2 * getCount();
    }
    virtual ~Book(){}
};

/* 普通快递 */
class Package:public PacketBase{
public:
    Package():PacketBase(){
        setType((int)PacketType::PACKAGE);
    }
    //计算价格
    virtual double getPrice(){
        return 5 * getCount();
    }
    virtual ~Package(){}
};


/* 包裹管理器 */
class PacketControl{
private:
    Storager st;
    std::vector<PacketBase*> _packetList;   //包裹列表
    //字段匹配
    bool packet_matching(const PacketBase*,PacketMatchField,void* input) const;
public:
    //包裹搜索
    std::vector<PacketBase*> PacketSearch(PacketMatchField*,void** input,int num) const;
    PacketBase* PacketLocate(unsigned long long id) const; 
    void SetPacketStatus(unsigned long long packetid,PacketStatus) const;   //设置包裹状态
    void AddPacket(PacketBase*);    //添加包裹
    int ReadIn();       //文件读入
    void WriteBack();   //文件写入
    ~PacketControl();

};

#endif
