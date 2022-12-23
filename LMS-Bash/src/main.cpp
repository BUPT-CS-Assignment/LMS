#include <iostream>
#include <main.h>
#include <user.h>
#include <packet.h>
#include <console.h>
#include <storage.h>
using namespace std;
std::string PROJECT_DIR = "/";

int main(){
    /* 目录读取 */
    string dir = get_current_dir_name();
    PROJECT_DIR = dir.substr(0, dir.find("/LMS") + 4);

    /* 类实例 */
    Console sc;             // 控制台
    Storager st;            // 存储器
    UserControl usrctrl;    // 用户操作

    /* 数据文件导入 */
    st.ReadUserList(usrctrl.GetUserList());          // 读取用户信息
    PacketControl pakctrl(usrctrl.GetAdmin());       // 物件操作
    st.ReadPacketList(pakctrl.GetPacketList());      // 读取物件信息

    /* 运行 */                                  // 提示表单次显示
    while(1){
        if(usrctrl.GetCurUser() == nullptr){            // 检测登录状态
            int option = usrctrl.Sign();
            if(option == PROGRAM_SAVE_DATA || option == PROGRAM_EXIT){
                st.StoreUserList(usrctrl.GetUserList());        // 存储用户表
                st.StorePacketList(pakctrl.GetPacketList());    //存储物件表
            }
            if(option == PROGRAM_EXIT){
                sc.LogMsg("Exiting...");
                cout << RESET;
                exit(1);
            }
        }
        else{
            pakctrl.setUser(usrctrl.GetCurUser());              // 连接登录用户
            int input = sc.GetOption(USER_PANEL);         // 获取主页操作码
            switch(input){
                /* 发送快递 */
                case OPTION_SEND_PACKET:
                    pakctrl.SendPacket();
                    break;

                /* 接收快递 */
                case OPTION_RECV_PACKET:
                    pakctrl.RecvPacket();
                    break;

                /* 查询快递 */
                case OPTION_CHECK_SENDS: case OPTION_CHECK_RECVS:
                    pakctrl.CheckPackets(input,(PCheck)sc.GetOption(CHECK_PANEL));
                    break;

                /* 用户信息查询修改 */
                case OPTION_USER_INFO:
                    usrctrl.UserOption((USet)sc.GetOption(USER_SET_PANEL));
                    break;

                /* 登出 */
                case OPTION_SIGN_OUT:
                    usrctrl.sign_out();
                    break;

                /* 帮助面板 */
                default:
                    sc.GetOption(USER_PANEL_HELP);
                    break;
            }
        }
    }
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
