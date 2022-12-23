#include "header/Basic.h"
using namespace std;

/* 用户登录 */
int MainService::Signin(int id,string passwd,int auth){
    //用户定位
    User* user = _USERS.UserLocate(id);
    //权限 & 密码检测
    if(user == nullptr ||user->getAuth() < auth || user->getPasswd() != passwd){
        return USER_SIGNIN_FAILED;
    }
    _CURUSER = user;
    return USER_SIGNIN_SUCCESS;
}

/* 用户注册 */
int MainService::Signup(int id,string passwd){
    User* user = _USERS.UserLocate(id);
    if(user != nullptr){
        return USER_SIGNUP_FAILED;
    }
    //新建对象
    User* u = new User(id,passwd,(int)UserAuth::USER);
    _USERS.AddUser(u);
    return USER_SIGNUP_SUCCESS;
}

/* 用户登出 */
void MainService::Signout(){
    _CURUSER = nullptr;
    StoreData();
}

/* 寄快递 */
int MainService::SendPacket(int type,int dest,double count,string description){
    static time_t pre_time = 0;
    time_t t = time(NULL);
    //操作过快检测
    if(t == pre_time){
        QMessageBox::critical(nullptr,"Error","Operattion Too Fast");
        return -1;
    }else{
        pre_time = t;
    }
    //新建包裹对象
    PacketBase* pb;
    switch((PacketType)type){
        case PacketType::PACKAGE:
            pb = new Package(); break;
        case PacketType::BREAKABLE:
            pb = new Breakable();   break;
        case PacketType::BOOK:
            pb = new Book();    break;
    }
    //计算价格
    pb->setCount(count);
    double price = pb->getPrice();
    //余额检测
    if(_CURUSER->getBalance() < price) return 1;
    _CURUSER->setBalance(_CURUSER->getBalance() - price);
    _ROOT->setBalance(_ROOT->getBalance() + price);
    srand(time(nullptr));

    //填充信息
    unsigned long long id = t + _CURUSER->getID();
    pb->setID(id);
    pb->setFromUser(_CURUSER->getID());
    pb->setDestUser(dest);
    pb->setSendTime(sc.GetTime());
    pb->setDescription(description);
    //添加包裹
    _PACKETS.AddPacket(pb);
    //判定自动分配
    if(_AUTO_ALLOCATION){
        RandomAlloc(id);
    }
    return 0;
}

/* 包裹搜索 */
vector<PacketBase*> MainService::PacketSearch(PacketMatchField* f,void** input,int num) const{
    return _PACKETS.PacketSearch(f,input,num);
}

/* 单个包裹定位 */
PacketBase* MainService::PacketSearch(unsigned long long id) const{
    return _PACKETS.PacketLocate(id);
}

/* 包裹签收 */
int MainService::RecvPacket(unsigned long long packetid){
    Console sc;
    //包裹定位
    PacketBase* p = _PACKETS.PacketLocate(packetid);
    p->setStatus((int)PacketStatus::RECVED);    //设置状态
    p->setRecvTime(sc.GetTime());               //设置签收时间
    return 0;
}

/* 用户搜索 */
std::vector<User*> MainService::UserSearch(UserMatchField* f, void** input,int num) const{
    return _USERS.UserSearch(f,input,num);
}

/* 单个用户定位 */
User* MainService::UserSearch(int id) const{
    return _USERS.UserLocate(id);
}

/* 添加用户 */
int MainService::AddUser(User* user){
    _USERS.AddUser(user);
    return 0;
}

/* 删除用户 */
int MainService::DelUser(int id){
    return _USERS.DelUser(id);
}

/* 分配快递员 */
int MainService::AllocateCourier(unsigned long long packetid,int userid){
    //包裹定位
    PacketBase* p = _PACKETS.PacketLocate(packetid);
    if(p == nullptr) return 0;
    p->setCourier(userid);  //设置分配快递员信息
    return 1;
}

/* 随机分配 */
int MainService::RandomAlloc(unsigned long long packetid){
    static unsigned long long t = 0;
    //获取快递员列表
    vector<User*>* list = _USERS.getCourierList();
    if(list->size() == 0)    return 0;
    //随机数生成
    srand(time(nullptr) + (t++));
    int id = rand()%(list->size());
    //分配快递员
    return AllocateCourier(packetid,list->at(id)->getID());
}

/* 揽收快递 */
int MainService::CollectPacket(unsigned long long packetid){
    //快递定位
    PacketBase* p = _PACKETS.PacketLocate(packetid);
    if(p == nullptr)    return -1;
    //设置包裹状态
    p->setStatus((int)PacketStatus::PENDING);
    //设置金额流转
    double half = p->getPrice()/2;
    _CURUSER->setBalance(_CURUSER->getBalance() + half);
    _ROOT->setBalance(_ROOT->getBalance() - half);
    return 0;
}

/* 充值 */
int MainService::Recharge(int balance){
    if(balance + _CURUSER->getBalance() < 0)    return -1;
    //重置余额
    _CURUSER->setBalance((double)balance + _CURUSER->getBalance());
    return 0;
}

/* 添加到列表 */
void MainService::AddToList(QListWidget* List,vector<PacketBase*> packets,Navigation* n,Manage* m){
    List->clear();  //清空列表
    //空里列表处理
    if(packets.size() == 0){
        //初始化组件
        QListWidgetItem *pItem = new QListWidgetItem(List);
        pItem->setText(QString("No Packets"));
        
        List->addItem(pItem);
        return;
    }
    auto itr = packets.begin();
    while(itr != packets.end()){
        //初始化组件
        PacketInfo* pInfo = new PacketInfo(nullptr,n,m);
        //内容填充
        pInfo->Init(_CURUSER->getID(),(*itr), m == nullptr?UserAuth::USER : UserAuth::COURIER);
        QListWidgetItem *pItem = new QListWidgetItem(List);
        pItem->setSizeHint(QSize(390,170)); //设置组件大小
        List->addItem(pItem);   //添加入列表
        List->setItemWidget(pItem,pInfo);
        itr ++;
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
