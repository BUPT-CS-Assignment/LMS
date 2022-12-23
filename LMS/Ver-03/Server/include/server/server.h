#ifndef __SERVER_H__
#define __SERVER_H__

#include "sys.h"
#include "console.h"
#include "../service/mainService.h"

/* 服务器基本配置 */
enum DEFAULT:size_t{
    BIND_PORT=8201,                     //绑定端口
    MAX_CONNECT=100,                    //最大连接数量
    BUF_SIZE=1024,                      //缓冲区大小
    SEND_TIME_OUT = 15 * 1000,          //发送超时
    RECV_TIME_OUT = 5 * 60 * 1000,      //接收超时
};

/* Socket连接封装 */
class Socket{
private:
    SOCKET _fd;             //SOCKET句柄
    SOCKADDR_IN _addr;      //地址结构体
public:
    void Listen(size_t bind_port);      //端口监听
    SOCKET Accept(SOCKET server);       //连接监听
    int RecvData(std::string&);         //数据接收
    void Close();                       //关闭连接
    void SetTimeOut(size_t send = SEND_TIME_OUT,size_t recv = RECV_TIME_OUT);   //设置超时
    SOCKET getFd();                     //获取句柄

};

/* 服务端 */
class Server{
private:
    Socket _server;         //服务端Socket
    Console sc;             //控制台工具
    BackEnd* _backend;      //数据管理器
    WSADATA _wsaData;       //WSASocket
    static DWORD WINAPI _recvData(LPVOID);  //新连接建立线程函数
public:
    Server(size_t bind_port = BIND_PORT);   
    //获取数据管理器指针
    BackEnd* getBackEnd(){
        return _backend;
    }
    void Start();           //启动服务端
    

};

#endif