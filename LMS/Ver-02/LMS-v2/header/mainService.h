#ifndef MAINSERVICE_H
#define MAINSERVICE_H

#include "window/navigation.h"
#include "main.h"
#include "window/backstage.h"
#include "user.h"
#include "packet.h"

/* 主服务类 */
class MainService{
private:
    Console sc;             //控制台
    UserControl _USERS;     //用户管理器
    PacketControl _PACKETS; //包裹管理器
    bool _AUTO_ALLOCATION;  //自动分配状态
    Navigation* _NAV;       //用户界面指针
    BackStage* _BS;         //后台界面指针
    User* _CURUSER;         //当前用户指针
    User* _ROOT;            //快递公司指针

public:
    MainService(){
        _USERS.ReadIn();
        _PACKETS.ReadIn();
        _ROOT = _USERS.GetRoot();
        _AUTO_ALLOCATION = false;
        _CURUSER = nullptr;
    }
    ~MainService(){
        std::cout << "Bye~" << std::endl;
    }
    void StoreData(){
        _USERS.WriteBack();
        _PACKETS.WriteBack();
    }
    int Signin(int id,std::string passwd,int auth = USER_COMMON);   //用户登录
    int Signup(int id,std::string passwd);                          //用户注册
    int SendPacket(int type,int dest,double count,std::string description); //寄快递
    int RecvPacket(unsigned long long packetid);    //签收快递
    int Recharge(int);      //充值
    int AddUser(User*);     //添加用户
    int DelUser(int);       //删除用户
    int AllocateCourier(unsigned long long packetid,int userid);    //分配快递员
    int RandomAlloc(unsigned long long packetid);                   //自动分配
    int CollectPacket(unsigned long long packetid);                 //揽收快递
    //用户搜索
    std::vector<User*> UserSearch(UserMatchField*, void** input,int num) const;
    User* UserSearch(int id) const;
    //包裹搜索
    std::vector<PacketBase*> PacketSearch(PacketMatchField*,void** input,int num) const;
    PacketBase* PacketSearch(unsigned long long id) const;
    void Signout();                                                 //用户登出
    //添加到表格
    void AddToList(QListWidget*, std::vector<PacketBase*>,Navigation*,Manage*);
    //获取当前用户指针
    User* CURUSER(){
        return _CURUSER;
    }
    //获取快递公司指针
    User* ROOT(){
        return _ROOT;
    }
    //获取快递员列表
    std::vector<User*>* COURIERS(){
        return _USERS.getCourierList();
    }
    //获取自动分配状态
    bool getAllocStatus() const{
        return _AUTO_ALLOCATION;
    }
    //设置自动分配状态
    void setAllocStatus(bool i){
        _AUTO_ALLOCATION = i;
    }
};

#endif // MAINSERVICE_H
