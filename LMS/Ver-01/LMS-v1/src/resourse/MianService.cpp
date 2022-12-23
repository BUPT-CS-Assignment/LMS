#include "header/Basic.h"
using namespace std;

//主服务：登录
int MainService::Signin(int id,string passwd,int auth){
    int err = usrctrl.Signin(id,passwd,auth);   //调用用户控制器
    if(err == USER_SIGNIN_SUCCESS){
        pakctrl.setUser(usrctrl.GetCurUser());  //登录成功，绑定当前用户
    }
    return err;
}

//主服务：注册
int MainService::Signup(int id,string passwd){
    int err = usrctrl.Signup(id,passwd);    //调用用户控制器
    return err;
}

//主服务：登出
void MainService::Signout(){
    usrctrl.Signout();
    pakctrl.setUser(nullptr);   //取消用户绑定
    st.StoreUserList(usrctrl.GetUserList());    //存储用户信息到文件
    st.StorePacketList(pakctrl.GetPacketList());    //存储包裹信息到文件
}

void MainService::LinkNavigation(Navigation* nav){
    pakctrl.LinkNavigation(nav);    //链接用户页面
}

void MainService::ResetLink(){
    pakctrl.LinkNavigation(nullptr);    //取消链接页面
}


/*
LMS
    File
        [D]UserList
            (num)
            (idx id passwd name balance tel address)

        [D]PacketList
            (num)
            (id status src dest sendtime recvtime info)

        [C]Storager
            [F]Read()
            [F]Write()

    Src
        [C]User
            (idx id passwd name balance tel address)

        [C]Packet
            (id status src dest sendtime recvtime info)
    Sys
        [C]Terminal
            [F]InputRead()
            [F]Parser()
            [F]Executor()

        [C]UserControl
            [F]ListLoad( [C]Storager )
            [F]Signin() <Ret> [C]User
            [F]Signup()
            [F]Signout()

        [C]PacketControl
            [F]ListLoad( [C]Storager )
            [F]PacketCheck()


*/
