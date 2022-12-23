
#ifndef MAINSERVICE_H
#define MAINSERVICE_H

#include "main.h"
#include "user.h"
#include "packet.h"
#include "storage.h"
#include "console.h"

/* 主服务类 */
class MainService{
private:
    Console sc;             // 控制台
    Storager st;            // 存储器
    UserControl usrctrl;    // 用户管理器
    PacketControl pakctrl;  // 包裹管理器

public:
    MainService(){
        st.ReadUserList(usrctrl.GetUserList());                     //从文件读入用户列表
        pakctrl.setAdmin(usrctrl.GetAdmin());                       //连接物流公司
        st.ReadPacketList(pakctrl.GetPacketList());                 //从文件读入包裹列表
    }
    ~MainService(){
        std::cout << "Bye~" << std::endl;
    }
    void StoreData(){
        st.StoreUserList(usrctrl.GetUserList());                    // 存储用户表
        st.StorePacketList(pakctrl.GetPacketList());                //存储物件表
    }
    int Signin(int id,std::string passwd,int auth = USER_COMMON);   //用户登录
    int Signup(int id,std::string passwd);                          //用户注册
    void Signout();                                                 //用户登出
    void LinkNavigation(Navigation*);                               //连接用户界面类
    void ResetLink();                                               //取消连接
    UserControl* GetUserController(){                               //获取用户管理器
        return &usrctrl;
    }
    PacketControl* GetPacketController(){                           //获取包裹管理器
        return &pakctrl;
    }

};

#endif // MAINSERVICE_H
