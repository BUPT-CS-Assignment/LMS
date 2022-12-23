#include "basic.h"
using namespace std;

/* 用户文件读取 */
int Storager::ReadUserList(vector<User*>* userList,std::vector<User*>* courierList) const{
    if(userList == nullptr) return 0;
    //打开文件
    ifstream ifs(PROJECT_DIR + "\\data\\users.txt", ios::in);
    Console sc;
    if(!ifs.is_open()){
        sc.err("'*\\Server\\data\\users.txt' Not Found");
        exit(1);
    }
    int all = 0;
    while(!ifs.eof()){
        int id, auth;
        double balance;
        //按字段读取
        string name, passwd, tel, address="";
        ifs >> id >> auth >> name >> passwd >> balance >> tel >> address;
        if(address == ""){
            //文件损坏判断
            if(all == 0){
                sc.err("'*\\Server\\data\\users.txt' Damaged");
                exit(1);
            }
            return all;
        }
        //用户列表构建
        User* user = new User(id, auth, name, passwd, balance, tel, address);
        userList->push_back(user);
        all++;
        if(courierList != nullptr && auth == (int)UserAuth::COURIER){
            courierList->push_back(user);
        }
    }
    ifs.close();
    if(userList->size() == 0){
        sc.err("'*\\Server\\data\\users.txt' Damaged");
        exit(1);
    }
    return all;
}

/* 包裹文件读取 */
int Storager::ReadPacketList(vector<PacketBase*>* packetList) const{
    if(packetList == nullptr) return 0;
    //打开文件
    ifstream ifs(PROJECT_DIR + "\\data\\packets.txt", ios::in);
    if(!ifs.is_open()){
        return 0;
    }
    int all = 0;
    while(!ifs.eof()){
        int id,type; double count;
        //按字段读取
        ifs >> id >> type >> count;
        //设置包裹对象信息
        PacketBase* pb;
        switch((PacketType)type){
            case PacketType::PACKAGE:
                pb = new Package(); break;
            case PacketType::BREAKABLE:
                pb = new Breakable();   break;
            case PacketType::BOOK:
                pb = new Book();    break;
        }
        pb->setCount(count);
        int status,courier,from,dest;
        string sendtime, recvtime, describe="";
        //剩余信息填充
        ifs >> status >> courier >>  from >> dest >> sendtime >> recvtime >> describe;
        if(describe == ""){
            return all;
        }
        //构建包裹列表
        pb->Fill(id,status,courier,from,dest,sendtime,recvtime,describe);
        packetList->push_back(pb);
        all++;
    }
    ifs.close();
    return all;
}

/* 用户信息写入 */
int Storager::StoreUserList(vector<User*>* userList) const{
    if(userList == nullptr) return NULL_PTR;
    //文件打开覆盖重写
    ofstream ofs(PROJECT_DIR + "\\data\\users.txt", ios::out | ios::trunc);
    ofs.setf(ios::fixed,ios::floatfield);
    ofs.precision(2);
    auto itr = userList->begin();
    //按行写入
    while(itr != userList->end()){
        ofs << (*itr)->getID()<<" "
            << (*itr)->getAuth()<<" "
            << (*itr)->getName()<<" "
            << (*itr)->getPasswd()<<" "
            << (*itr)->getBalance()<<" "
            << (*itr)->getTel()<<" "
            << (*itr)->getAddr()<<"\n";
        itr++;
    }
    ofs.close();        //关闭文件流
    return SUCCESS;
}

/* 包裹信息写入 */
int Storager::StorePacketList(vector<PacketBase*>* packetList) const{
    if(packetList == nullptr) return NULL_PTR;
    //文件打开覆盖重写
    ofstream ofs(PROJECT_DIR + "\\data\\packets.txt", ios::out | ios::trunc);
    ofs.setf(ios::fixed,ios::floatfield);
    ofs.precision(2);
    auto itr = packetList->begin();
    //按行写入
    while(itr != packetList->end()){
        ofs << (*itr)->getID() << " "
            << (*itr)->getType() << " "
            << (*itr)->getCount() << " "
            << (*itr)->getStatus() << " "
            << (*itr)->getCourier() << " "
            << (*itr)->getFromUser() << " "
            << (*itr)->getDestUser() << " "
            << (*itr)->getSendTime() << " "
            << (*itr)->getRecvTime() << " "
            << (*itr)->getDescription() << "\n";
        itr++;
    }
    ofs.close();    //关闭文件流
    return SUCCESS;
}
