#include "header/Basic.h"
using namespace std;

MainService::MainService(){
    //Set Service Info
    _NAV = nullptr;
    _BS = nullptr;
    _USER = nullptr;
    _auto_alloc = false;
}

/* 启动服务 */
void MainService::Start(){
    //WSA初始化
    WSADATA wsadata;
    WSAStartup(0x202, &wsadata);
    //socket初始化
    _fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);  //TCP
    _addr.sin_family = AF_INET;      //IPv4
    _addr.sin_addr.S_un.S_addr = inet_addr(SERVER_ADDRESS); //服务器地址
    _addr.sin_port = htons(SERVER_PORT);    //服务器端口
    //设置超时
    size_t time_out = SEND_TIME_OUT;
    setsockopt(_fd,SOL_SOCKET,SO_SNDTIMEO,(char*)&time_out,sizeof(int));
    time_out = RECV_TIME_OUT;
    setsockopt(_fd,SOL_SOCKET,SO_RCVTIMEO,(char*)&time_out,sizeof(int));
}

/* 关闭服务 */
void MainService::Close(){
    closesocket(_fd);   //关闭socket
    WSACleanup();       //清除WSA信息
}

/* 连接服务器 */
bool MainService::Connect(int time){
    Close();
    Start();    //初始化连接参数
    //循环次数尝试
    while(time){
        //建立连接
        if(connect(_fd,(SOCKADDR*)&_addr,sizeof(SOCKADDR)) == -1){
            sc.LogErr("Connection Failed -> TIME_OUT. Retrying...");
            Sleep(3 * 1000);
            time--;
        }else{
            return true;
        }
    }
    closesocket(_fd);
    return false;
}

/* 发送请求 */
int MainService::Request(QString req,QString& ans,int polling_times){
    string request = req.toStdString();
    sc.LogMsg("[SEND] "+request);
    while(polling_times){
        if(send(_fd,request.c_str(),request.length() + 1,0) != SOCKET_ERROR){
            break;
        }
        polling_times--;
    }
    //超时重连
    while(polling_times == 0){
        QMessageBox::StandardButton result =
                QMessageBox::critical(nullptr,"ERROR","连接服务器超时",
                                      QMessageBox::Retry|QMessageBox::Cancel,
                                      QMessageBox::Retry
                                      );
        if(result == QMessageBox::Retry){
            //连接重试
            if(Connect(2)){
                if(_USER != nullptr){
                    //重新登录
                    if(Signin(_USER->getID(),_USER->getPasswd(),_USER->getAuth()) != SUCCESS){
                        return SYSTEM_ERR;
                    }
                }
                QMessageBox::information(nullptr,"TIPS","重连成功");
                return SUCCESS;
            }
        }else{
            break;
        }
    }
    if(polling_times == 0) return CONNECTION_LOST;

    int err;
    char buf[1024];
    QString res = "";
    //循环数据接收
    do{
        memset(buf,0,sizeof(buf));
        //接收数据
        err = recv(_fd,buf,sizeof(buf),0);
        res += QString::fromStdString(string(buf));
    }while(err >= 1024);
    if(err == SOCKET_ERROR){
        return CONNECTION_LOST;
    }
    sc.LogMsg("[RECV] "+res.toStdString());
    //响应数据解析
    QStringList list = res.split("|");
    int ret = list[0][0].toLatin1() - '0';
    if((ReturnValue)ret != ReturnValue::SUCCESS){
        return ret;
    }
    ans = list[1];
    return SUCCESS;
}

/* 获取当前用户 */
User* MainService::USER(){
    return _USER;
}

/* 登录 */
int MainService::Signin(QString id,QString passwd,int auth){
    QString req = FUNC_TEXT[SIGN_IN] + "||"
                    +id+","+passwd+","+QString::number(auth);
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret,"用户名/密码错误 或 权限不足","用户已经登录")){
        _USER = new User(ans.split(","));
        _USER->setPasswd(passwd);
    }else{
        _USER = nullptr;
    }
    return ret;
}

/* 注册 */
int MainService::Signup(QString id,QString passwd){
    QString req = FUNC_TEXT[SIGN_UP] + "||"
                    +id+","+passwd;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    sc.StatusCheck(ret,"用户名已存在");
    return ret;
}

/* 登出 */
int MainService::Signout(){
    QString req = FUNC_TEXT[SIGN_OUT] + "||";
    QString ans;
    //清除当前用户信息
    delete _USER;
    _USER = nullptr;
    int ret = Request(req,ans);
    Close();
    return ret;
}

/* 添加用户 */
int MainService::AddUser(QString id,QString passwd,int auth,int balance){
    QString req = FUNC_TEXT[ADD_USER]+"||"
                    +id+","+passwd+","+QString::number(auth)+","+QString::number(balance);
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    sc.StatusCheck(ret,"用户名已存在");
    return ret;
}

/* 删除用户 */
int MainService::DelUser(QString id){
    QString req = FUNC_TEXT[DEL_USER]+"||"
                    +id;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    sc.StatusCheck(ret,"未找到该用户","该用户正在登陆中");
    return ret;
}

/* 发送快递 */
int MainService::SendPacket(int type,QString dest,double count,QString description){
    QString req = FUNC_TEXT[SEND_PACKET]+"||"
                    +QString::number(type)+","+dest+","+QString::number(count)+","+description;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret,"NOT_FOUND SIGNAL RECV","余额不足")){
        _USER->setBalance(ans); //设置余额
    }
    return ret;
}

/* 分配快递员 */
int MainService::AllocateCourier(QString packetid,QString userid){
    QString req = FUNC_TEXT[ALLOC_COURIER]+"||"
                    +packetid+","+userid;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    sc.StatusCheck(ret);
    return ret;
}

/* 揽收快递 */
int MainService::CollectPacket(QString packetid){
    QString req = FUNC_TEXT[COLLECT_PACKET]+"||"
                    +packetid;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret)){
        _USER->setBalance(ans);
    }
    return ret;
}

/* 签收快递 */
int MainService::RecvPacket(QString packetid,QString& recv_time){
    QString req = FUNC_TEXT[RECV_PACKET]+"||"
                    +packetid;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret)){
        recv_time = ans;
    }
    return ret;
}

/* 充值 */
int MainService::Recharge(QString num){
    QString req = FUNC_TEXT[RECHARGE]+"||"
                    +num;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret,"NOT_FOUND SIGNAL RECV","金额错误")){
        _USER->setBalance(ans); //修改余额
    }
    return ret;
}

/* 设置信息 */
int MainService::SetInfo(UserMatchField* f,QString* s,int num){
    QString req = FUNC_TEXT[SET_USER]+"|";
    for(int i = 0;i < num; i++){
        req += QString::number((int)f[i]);
        if(i != num -1) req += ",";
    }
    //多字段分隔
    req += "|";
    for(int i = 0;i < num; i++){
        req += s[i];
        if(i != num -1) req += ",";
    }
    QString ans;
    int ret = Request(req,ans);
    sc.StatusCheck(ret);
    return ret;
}

/* 用户搜索 */
int MainService::UserSearch(UserMatchField* f, QString* s,int num,std::vector<QStringList>& res){
    QString req = FUNC_TEXT[CHECK_USER] +"|";
    for(int i = 0;i < num; i++){
        req += QString::number((int)f[i]);
        if(i != num -1) req += ",";
    }
    if(num == 0) req += QString::number((int)UserMatchField::ALL);
    //多字段分隔
    req += "|";
    for(int i = 0;i < num; i++){
        req += s[i];
        if(i != num -1) req += ",";
    }
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret)){
        res.clear();
        //响应信息解析
        QStringList users = ans.split(";");
        for(int i = 0; i < users.size(); i++){
            res.push_back(users[i].split(","));
        }
    }
    return ret;
}

/* 搜索快递员 */
int MainService::CourierSearch(std::vector<QStringList>& res){
    QString req = FUNC_TEXT[CHECK_USER] +"|";
    req += QString::number((int)UserMatchField::COURIER);
    req += "|";
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret)){
        res.clear();
        //响应信息解析
        QStringList users = ans.split(";");
        for(int i = 0; i < users.size(); i++){
            res.push_back(users[i].split(","));
        }
    }
    return ret;
}

/* 搜索包裹 */
int MainService::PacketSearch(PacketMatchField* f,QString* s,int num,std::vector<QStringList>& res){
    QString req = FUNC_TEXT[CHECK_PACKET]+"|";
    for(int i = 0;i < num; i++){
        req += QString::number((int)f[i]);
        if(i != num -1) req += ",";
    }
    if(num == 0) req += QString::number((int)PacketMatchField::ALL);
    //多字段分隔
    req += "|";
    for(int i = 0;i < num; i++){
        req += s[i];
        if(i != num -1) req += ",";
    }
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret)){
        res.clear();
        //响应信息解析
        QStringList packets = ans.split(";");
        for(int i = 0; i < packets.size(); i++){
            res.push_back(packets[i].split(","));
        }
    }
    return ret;
}

/* 添加到列表 */
void MainService::AddToList(QListWidget* List,vector<QStringList>& packets,Navigation* n,Manage* m){
    List->clear();
    if(packets.size() == 0){
        //填充快递信息对象
        QListWidgetItem *pItem = new QListWidgetItem(List);
        pItem->setText(QString("No Packets"));
        List->addItem(pItem);
        return;
    }
    auto itr = packets.begin();
    while(itr != packets.end()){
        PacketInfo* pInfo = new PacketInfo(nullptr,n,m);
        if(!pInfo->Init(_USER->getID(),(*itr), m == nullptr?UserAuth::USER : UserAuth::COURIER)){
            itr++;
            continue;
        }
        //添加到列表
        QListWidgetItem *pItem = new QListWidgetItem(List);
        pItem->setSizeHint(QSize(390,170));
        List->addItem(pItem);
        List->setItemWidget(pItem,pInfo);
        itr ++;
    }
}

/* 获取自动分配状态 */
int MainService::GetAutoAlloc(){
    QString req = FUNC_TEXT[ALLOC_SWITCH]+"|";
    req += "0|";
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret)){
        //响应解析
        _auto_alloc = ans[0]=='T'?true:false;
    }
    return ret;
}

/* 设置自动分配状态 */
int MainService::SetAutoAlloc(bool status){
    QString req = FUNC_TEXT[ALLOC_SWITCH]+"|";
    req += "1|";
    req += status?"T":"F";
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    if(sc.StatusCheck(ret)){
        //响应解析
        _auto_alloc = status;
    }
    return ret;
}

/* 自动分配 */
int MainService::AutoAlloc(QString list){
    QString req = FUNC_TEXT[AUTO_ALLOC]+"||";
    req += list;
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    sc.StatusCheck(ret);
    return ret;
}

/* 数据存储 */
int MainService::StoreData(){
    QString req = FUNC_TEXT[STORE_DATA]+"||";
    QString ans;
    //发送请求
    int ret = Request(req,ans);
    sc.StatusCheck(ret);
    return ret;
}

