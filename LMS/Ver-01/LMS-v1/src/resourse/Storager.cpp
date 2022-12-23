#include "header/Basic.h"
using namespace std;

//读取用户列表
int Storager::ReadUserList(vector<User>* userList) const{
    if(userList == nullptr) return 0;
    Console sc;
    //打开文件
    ifstream ifs(PROJECT_DIR + "\\data\\users.txt", ios::in);
    if(!ifs.is_open()){
        MessageBox(GetForegroundWindow(),L"'*\\LMS\\data\\users.text' Not Found",L"LMS ERROR",1);
        exit(1);
    }
    while(!ifs.eof()){
        int id, auth, balance;
        string name, passwd, tel, address="";
        //读取用户信息
        ifs >> id >> auth >> name >> passwd >> balance >> tel >> address;
        if(address == ""){
            return 1;
        }
        //构造添加新用户
        User user(id, auth, name, passwd, balance, tel, address);
        userList->push_back(user);
    }
    ifs.close();
    if(userList->size() == 0){
        MessageBox(GetForegroundWindow(),L"'*\\LMS\\data\\users.text' Damaged",L"LMS ERROR",1);
        exit(1);
    }
    return 1;
}

//读取包裹列表
int Storager::ReadPacketList(vector<Packet>* packetList) const{
    if(packetList == nullptr) return 0;
    Console sc;
    //打开文件
    ifstream ifs(PROJECT_DIR + "\\data\\packets.txt", ios::in);
    if(!ifs.is_open()){
        return 0;
    }
    while(!ifs.eof()){
        int id, status, from, dest;
        string sendtime, recvtime, describe="";
        //读取包裹信息
        ifs >> id >> status >> from >> dest >> sendtime >> recvtime >> describe;
        if(describe == ""){
            return 1;
        }
        //构造添加新包裹
        Packet packet(id, status, from, dest, sendtime, recvtime, describe);
        packetList->push_back(packet);
    }
    ifs.close();
    return 1;
}

//存储用户信息
int Storager::StoreUserList(vector<User>* userList) const{
    if(userList == nullptr) return 0;
    //打开文件，重写
    ofstream ofs(PROJECT_DIR + "\\data\\users.txt", ios::out | ios::trunc);
    auto itr = userList->begin();
    //按顺序写入用户信息
    while(itr != userList->end()){
        ofs << (*itr).getID()<<" "
            <<(*itr).getAuth()<<" "
            <<(*itr).getName()<<" "
            <<(*itr).getPasswd()<<" "
            <<(*itr).getBalance()<<" "
            <<(*itr).getTel()<<" "
            <<(*itr).getAddr()<<"\n";
        itr++;
    }
    ofs.close();
    return 1;
}

//存储包裹信息
int Storager::StorePacketList(vector<Packet>* packetList) const{
    if(packetList == nullptr) return 0;
    //打开文件，重写
    ofstream ofs(PROJECT_DIR + "\\data\\packets.txt", ios::out | ios::trunc);
    auto itr = packetList->begin();
    //按顺序写入包裹信息
    while(itr != packetList->end()){
        ofs << (*itr).getID()<<" "
            <<(*itr).getStatus()<<" "
            <<(*itr).getFromUser()<<" "
            <<(*itr).getDestUser()<<" "
            <<(*itr).getSendTime()<<" "
            <<(*itr).getRecvTime()<<" "
            <<(*itr).getDescription()<<"\n";
        itr++;
    }
    ofs.close();
    return 1;
}
