#include "basic.h"
using namespace std;

BackEnd::BackEnd(){
    _USERS.ReadIn();            //读取用户信息文件
    _PACKETS.ReadIn();          //读取包裹信息文件
    _ROOT = _USERS.GetRoot();   //获取管理员指针
    _AUTO_ALLOCATION = false;   //设置自动分配标志
}

BackEnd::~BackEnd(){
    sc.msg("Service Close");
}

/* 登录 */
User* BackEnd::Signin(int id,string passwd,int auth){
    User* user = UserSearch(id);
    //信息匹配
    if(user == nullptr ||user->getAuth() < auth || user->getPasswd() != passwd){
        return nullptr;
    }
    //状态设置
    user->setStatus(true);
    return user;
}

/* 注册 */
int BackEnd::Signup(int id,string passwd){
    User* user = UserSearch(id);
    //空指针检测
    if(user != nullptr){
        return NOT_FOUND;
    }
    //新建用户
    User* u = new User(id,passwd,(int)UserAuth::USER);
    return _USERS.AddUser(u);
}

/* 发送包裹 */
int BackEnd::SendPacket(User* CURUSER,int type,int dest,double count,string description){
    if(CURUSER == nullptr)  return NULL_PTR;
    static time_t pre_time = 0;
    time_t t = time(NULL);
    //操作间隔检测
    if(t == pre_time){
        return SYSTEM_ERR;
    }else{
        pre_time = t;
    }
    int ret;
    //包裹对象初始化
    PacketBase* pb;
    switch((PacketType)type){
        case PacketType::PACKAGE:
            pb = new Package(); break;
        case PacketType::BREAKABLE:
            pb = new Breakable();   break;
        case PacketType::BOOK:
            pb = new Book();    break;
    }
    pb->setCount(count);                //更新数量/重量
    double price = pb->getPrice();      //更新加个

    //余额检测
    if(CURUSER->getBalance() < price) return SYSTEM_ERR;
    CURUSER->setBalance(CURUSER->getBalance() - price);
    _ROOT->setBalance(_ROOT->getBalance() + price);
    srand(time(nullptr));

    //设置包裹信息
    size_t id = t + CURUSER->getID();
    pb->setID(id);
    pb->setFromUser(CURUSER->getID());
    pb->setDestUser(dest);
    pb->setSendTime(sc.getTime());
    pb->setDescription(description);
    ret = _PACKETS.AddPacket(pb);
    if(ret != SUCCESS) return ret;

    //自动分配检测
    if(_AUTO_ALLOCATION){
        ret = RandomAlloc(to_string(id));
    }
    return ret;
}

/* 包裹搜索 */
vector<PacketBase*> BackEnd::PacketSearch(PacketMatchField* f,string* input,int num){
    return _PACKETS.PacketSearch(f,input,num);
}

/* 包裹定位 */
PacketBase* BackEnd::PacketSearch(string id){
    return _PACKETS.PacketLocate(id);
}

/* 签收包裹 */
int BackEnd::RecvPacket(PacketBase* p){
    if(p == nullptr) return NULL_PTR;           //空指针检测
    p->setStatus((int)PacketStatus::RECVED);    //设置状态
    p->setRecvTime(sc.getTime());               //设置签收时间
    return SUCCESS;
}

/* 用户搜索 */
std::vector<User*> BackEnd::UserSearch(UserMatchField* f, string* input,int num){
    return _USERS.UserSearch(f,input,num);
}

/* 用户定位 */
User* BackEnd::UserSearch(int id){
    return _USERS.UserLocate(id);
}

/* 添加用户 */
int BackEnd::AddUser(User* user){
    User* u = UserSearch(user->getID());
    if(u != nullptr){
        return NOT_FOUND;
    }
    return _USERS.AddUser(user);
}

/* 删除用户 */
int BackEnd::DelUser(int id){
    User* user = _USERS.UserLocate(id);
    if(user == nullptr) return NOT_FOUND;
    //快递员检测 
    if(user->getAuth() == (int)UserAuth::COURIER){
        PacketMatchField f[]{PacketMatchField::COURIER,PacketMatchField::STATUS};
        string inputs[]{to_string(id),"0"};
        //搜索未揽收快递
        vector<PacketBase*> list = _PACKETS.PacketSearch(f,inputs,2);
        auto itr = list.begin();
        //重置未揽收快递信息
        while(itr != list.end()){
            (*itr)->setCourier(0);
            itr++;
        }
    }
    return _USERS.DelUser(id);
}

/* 分配快递员 */
int BackEnd::AllocateCourier(string packetid,int userid){
    PacketBase* p = _PACKETS.PacketLocate(packetid);
    if(p == nullptr) return NULL_PTR;
    p->setCourier(userid);          //设置揽收人
    return SUCCESS;
}

/* 随机分配 */
int BackEnd::RandomAlloc(string packetid){
    static size_t t = 0;
    vector<User*>* list = _USERS.getCourierList();
    if(list->size() == 0)    return NULL_PTR;   //空指针检测
    //随机数生成
    srand(time(nullptr) + (t++));
    int id = rand()%(list->size());
    return AllocateCourier(packetid,list->at(id)->getID());
}

/* 揽收快递 */
int BackEnd::CollectPacket(User* CURUSER,string packetid){
    if(CURUSER == nullptr)    return NULL_PTR;  //空指针检测
    PacketBase* p = _PACKETS.PacketLocate(packetid);
    if(p == nullptr)    return NULL_PTR;
    //设置快递状态
    p->setStatus((int)PacketStatus::PENDING);
    //设置金额流转
    double half = p->getPrice()/2;
    CURUSER->setBalance(CURUSER->getBalance() + half);
    _ROOT->setBalance(_ROOT->getBalance() - half);
    return SUCCESS;
}

/* 充值 */
int BackEnd::Recharge(User* CURUSER,int balance){
    if(CURUSER == nullptr) return NULL_PTR;
    if(balance + CURUSER->getBalance() < 0)    return SYSTEM_ERR;
    //设置余额
    CURUSER->setBalance((double)balance + CURUSER->getBalance());
    return SUCCESS;
}

/* 设置信息 */
int BackEnd::SetInfo(User* CURUSER,UserMatchField* f,std::string* val,int num){
    if(CURUSER == nullptr)  return NULL_PTR;
    //字段匹配
    for(int i = 0; i < num; i++){
        switch(f[i]){
            case UserMatchField::NAME:
                CURUSER->setName(val[i]); break;
            case UserMatchField::PASSWD:
                CURUSER->setPasswd(val[i]);break;
            case UserMatchField::TEL:
                CURUSER->setTel(val[i]);break;
            case UserMatchField::ADDRESS:
                CURUSER->setAddr(val[i]);break;
            default: return NOT_FOUND;
        }
    }
    return SUCCESS;
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
