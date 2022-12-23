#include "basic.h"
using std::cout;
using std::cerr;
using std::endl;
using std::string;

string PROJECT_DIR;

/* --------------------- Socket --------------------- */

SOCKET Socket::getFd(){
    return _fd;
}

/* 端口监听 */
void Socket::Listen(size_t bind_port){
    _fd = WSASocket(AF_INET,SOCK_STREAM,0,NULL,0,WSA_FLAG_OVERLAPPED);
    //设置socket基础配置
    _addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);     //任意地址
    _addr.sin_family = AF_INET;                         //IPv4
    _addr.sin_port = htons(bind_port);                  //端口
    Console sc;
    //端口绑定
    if(bind(_fd,(SOCKADDR*)&_addr,sizeof(_addr)) != 0){
        sc.err("Bind Port "+std::to_string(bind_port)+" Failed");
        exit(-1);
    }
    sc.msg("Bind Port "+std::to_string(bind_port)+" Success");
    if(listen(_fd,MAX_CONNECT) != 0){
        sc.err("Listening Failed");
        exit(-1);
    }
    sc.msg("Listening...");
}


/* 连接监听 */
SOCKET Socket::Accept(SOCKET server){
    int length = sizeof(_addr);
    _fd = accept(server,(SOCKADDR*)&_addr,&length); //新连接建立检测
    return _fd;
}

/* 数据接收 */
int Socket::RecvData(std::string &ans){    
    char buf[BUF_SIZE];
    memset(buf,0,sizeof(buf));
    int res = recv(_fd,buf,sizeof(buf),0);
    if(res > 0){
        ans = string(buf);
        return 0;
    }
    if(res == 0)    return -1;
    return WSAGetLastError();

}

/* 关闭连接 */
void Socket::Close(){
    closesocket(_fd);
}

/* 设置超时 */
void Socket::SetTimeOut(size_t send,size_t recv){
    //发送超时
    setsockopt(_fd, SOL_SOCKET,SO_SNDTIMEO,(char *)&send, sizeof(int));
    //接收超时
    setsockopt(_fd, SOL_SOCKET,SO_RCVTIMEO,(char *)&recv, sizeof(int));
}


/* --------------------- Server --------------------- */

Server::Server(size_t bind_port){
    _backend = nullptr;
    size_t version = MAKEWORD(2,2);             //WSA版本
    if(WSAStartup(version,&_wsaData) != 0){
        exit(-1);
    }
    _server.Listen(bind_port);                  //开启端口监听
}

/* 启动服务 */
void Server::Start(){
    sc.msg("Server Start");
    PROJECT_DIR = sc.getDir();
    sc.log(true,BOLDWHITE"Current Dir: %s\n",PROJECT_DIR.c_str());
    _backend = new BackEnd();
    /* 自动保存线程 */
    std::thread([this](){
        sc.msg("Auto-Store Service Start");
        int ret;
        do{ 
            Sleep(3 * 60 * 1000);       //间隔3min
            ret = this->getBackEnd()->StoreData();  //存储数据
            if(ret == TIME_OUT){        //锁超时重试
                Sleep(100);
                ret = this->getBackEnd()->StoreData();
            }
            if(ret == SUCCESS){
                sc.msg("Data Store Success");
            }else{
                sc.log(true,BOLDWHITE"Data Store Time Out\n");
            }
        }while(ret==SUCCESS || ret == TIME_OUT);
        sc.err("Storage Error : "+RetValText[ret]+". Exiting...");
        exit(-1);
    }).detach();
    Socket connect;
    sc.msg("Waiting For Connection...");
    /* 循环连接监听 */
    while(true){
        connect.Accept(_server.getFd());
        if(connect.getFd() != INVALID_SOCKET){
            HANDLE thread;          //新线程
            void* temp[2]={(void*)&connect,(void*)this};    //构造参数指针数组
            //新建线程
            thread = CreateThread(nullptr,0,_recvData,&temp,0,nullptr); 
            CloseHandle(thread);   //关闭线程句柄
        }
    }
    _server.Close();    //关闭socket
    WSACleanup();       //清空WSA
}

/* 新连接线程 */
DWORD Server::_recvData(LPVOID param){
    /* 参数处理 */
    Server* server = (Server*)((void**)param)[1];
    Socket connect = *(Socket*)((void**)param)[0];
    connect.SetTimeOut();   //超时设置
    string fd = std::to_string(connect.getFd());
    server->sc.msg("Connection "+fd+" Establish");
    string res;
    ///连接到主服务
    Service svc(server); 
    while(connect.RecvData(res) == 0){
        svc.sc.log(true,BOLDWHITE "%s" RESET" -> Request %s\n",fd.c_str(),res.c_str());
        //请求解析
        int err = svc.Parse(res);
        if(err == SUCCESS){
            //请求执行
            err = svc.Exec();
            svc.sc.log(true,BOLDWHITE "%s" RESET" -> Exec return %s\n", fd.c_str(),RetValText[err].c_str());
        }else{
            svc.sc.err(fd+" -> Request Unknown return "+RetValText[err]);
        }
        //响应格式化
        string ans = svc.Format(err);
        int times = 5;  //5次重发
        int send_len;
        while(times){
            //长数据分段
            string ans_copy = ans;
            do{
                string buf;
                if(ans_copy.length() > 1024){
                    buf = ans_copy.substr(0,1024);
                    ans_copy = ans_copy.substr(1024);
                }else{
                    buf = ans_copy;
                    ans_copy = "";
                }
                //发回响应信息
                send_len = send(connect.getFd(),buf.c_str(),buf.length() + 1,0);
            }while(ans_copy.length() > 0);
            if(send_len > 0){
                break;
            }
            times--;
        }
        if(times == 0){
            svc.sc.err("Connection Time Out");
            break;
        }
    }
    //关闭连接
    server->sc.msg(std::to_string(connect.getFd())+" Disconnect");
    connect.Close();
    return 0;
}