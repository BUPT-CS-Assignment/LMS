#ifndef MAINSERVICE_H
#define MAINSERVICE_H

#include "../sys.h"
#include "packet.h"
#include "user.h"
#include "storage.h"
#include "../server/console.h"

/* 主服务类 */
class Service{
private:
    User* _CURUSER;                     //当前用户 
    BackEnd* _BACKEND;                  //数据管理器
    FUNCTION _func;                     //请求类型
    std::vector<std::string> _param;    //请求参数
    std::vector<std::string> _value;    //请求数据
    std::string _ans;                   //响应数据
    int exec_sign_in();         //登录
    int exec_sign_up();         //注册
    int exec_sign_out();        //登出
    int exec_add_user();        //添加用户
    int exec_del_user();        //删除用户
    int exec_set_user();        //设置用户信息
    int exec_recharge();        //充值
    int exec_check_user();      //用户搜所
    int exec_send_packet();     //发送包裹
    int exec_recv_packet();     //签收包裹
    int exec_collect_packet();  //揽收包裹
    int exec_alloc_courier();   //分配快递员
    int exec_check_packet();    //包裹搜索
    int exec_alloc_switch();    //自动分配开关
    int exec_auto_alloc();      //自动分配
    int exec_store_data();      //数据存储
public:
    Console sc;
    Service(Server* s);
    ~Service();
    //绑定当前用户
    void setUser(User* u){      
        _CURUSER = u;
    }
    //获取当前用户
    User* getUser(){
        return _CURUSER;
    }
    //获取请求类型
    FUNCTION getFunction(){
        return _func;
    }
    void SignOut();             //登出
    int Parse(std::string);     //请求解析
    int Exec();                 //请求执行
    void Clear();               //清除解析结果
    std::string Format(int res = SUCCESS);  //响应信息格式化
};

class BackEnd{
private:
    Console sc;                 //控制台工具
    UserControl _USERS;         //用户管理器
    PacketControl _PACKETS;     //包裹管理器
    bool _AUTO_ALLOCATION;      //自动分配状态
    User* _ROOT;                //管理员指针

public:
    BackEnd();
    ~BackEnd();
    //账户服务
    User*   Signin(int id,std::string passwd,int auth = USER_COMMON);   //用户登录
    int     Signup(int id,std::string passwd);                          //用户注册
    int     AddUser(User*);                                             //添加用户
    int     DelUser(int);                                               //删除用户
    //投递服务
    int     SendPacket(User* user,int type,int dest,double count,std::string description);
    //分配服务
    int     AllocateCourier(std::string packetid,int userid);
    int     RandomAlloc(std::string packetid);  //随机分配
    //揽收服务
    int     CollectPacket(User* user,std::string packetid);
    //签收服务
    int     RecvPacket(PacketBase* p);
    //信息修改服务
    int     Recharge(User* user,int num);   //充值
    int     SetInfo(User* user,UserMatchField*,std::string*,int num = 1);
    //用户搜索服务
    std::vector<User*>          UserSearch(UserMatchField*, std::string* input,int num);
    User*                       UserSearch(int id); //单个定位
    //包裹搜索服务
    std::vector<PacketBase*>    PacketSearch(PacketMatchField*,std::string* input,int num);
    PacketBase*                 PacketSearch(std::string id);   //单个定位
    //存储服务
    int StoreData(){
        int res;
        //文件写入
        res = _USERS.WriteBack();          
        if(res != SUCCESS)  return res;
        res = _PACKETS.WriteBack();
        return res;
    }
    //获取管理员指针
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
    void setAllocStatus(bool status){
        _AUTO_ALLOCATION = status;
    }
};

#endif // MAINSERVICE_H
