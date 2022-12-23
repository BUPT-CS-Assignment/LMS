#ifndef MAINSERVICE_H
#define MAINSERVICE_H

#include "window/navigation.h"
#include "main.h"
#include "window/backstage.h"
#include "user.h"
#include "packet.h"

#define SEND_TIME_OUT 20 * 1000
#define RECV_TIME_OUT 20 * 1000
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8201

/* 主服务类 */
class MainService{
private:
    Console sc;             //控制台
    Navigation* _NAV;       //用户界面指针
    BackStage* _BS;         //后台界面指针
    User* _USER;            //当前用户指针
    SOCKET _fd;             //socket句柄
    SOCKADDR_IN _addr;      //socket地址信息
    bool _auto_alloc;       //自动分配状态

public:
    MainService();
    void    Start();        //启动服务
    int     Request(QString req,QString& ans,int polling_times = 3);    //发送请求
    bool    Connect(int time = 1);  //连接服务器
    void    AddToList(QListWidget*, std::vector<QStringList>&,Navigation*,Manage*); //添加到包裹列表
    void    Close();        //关闭连接
    //
    User*   USER();         //获取用户指针
    int     Signin(QString id,QString passwd,int auth = USER_COMMON);   //用户登录
    int     Signup(QString id,QString passwd);                          //用户注册
    int     Signout();      //登出
    int     AddUser(QString id,QString passwd,int auth,int balance);    //添加用户 
    int     DelUser(QString id);        //删除用户
    //投递服务
    int     SendPacket(int type,QString dest,double count,QString description);
    //分配服务
    int     AllocateCourier(QString packetid,QString userid);
    int     RandomAlloc(QString packetid);  //随机分配
    //揽收服务
    int     CollectPacket(QString packetid);
    //签收服务
    int     RecvPacket(QString packetid,QString& recv_time);
    //信息修改服务  
    int     Recharge(QString num);  //充值
    int     SetInfo(UserMatchField*,QString*,int num = 1);
    //用户搜索服务
    int     UserSearch(UserMatchField*, QString* input,int num,std::vector<QStringList>&);
    int     UserSearch(int id,User*);   //单个用户定位
    int     CourierSearch(std::vector<QStringList>&);   //搜索快递员
    //包裹搜索服务
    int     PacketSearch(PacketMatchField*,QString* input,int num,std::vector<QStringList>&);
    int     PacketSearch(QString id,PacketBase*);   //单个快递定位
    //分配快递服务
    int     GetAutoAlloc(); //获取自动分配状态
    int     SetAutoAlloc(bool status = true);   //设置自动分配状态
    int     AutoAlloc(QString list);            //自动分配
    //存储服务
    int     StoreData();

};

#endif // MAINSERVICE_H
