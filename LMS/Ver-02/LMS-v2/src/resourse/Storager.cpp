#include "header/Basic.h"
using namespace std;

/* 用户信息文件读入 */
int Storager::ReadUserList(vector<User*>* userList,std::vector<User*>* courierList) const{
    if(userList == nullptr) return 0;
    //打开文件
    ifstream ifs(PROJECT_DIR + "\\LMS-v2\\data\\users.txt", ios::in);
    if(!ifs.is_open()){
        MessageBox(GetForegroundWindow(),L"'*\\LMS-v2\\data\\users.text' Not Found",L"LMS ERROR",1);
        exit(1);
    }
    while(!ifs.eof()){
        int id, auth;
        double balance;
        string name, passwd, tel, address="";
        //按字段读取
        ifs >> id >> auth >> name >> passwd >> balance >> tel >> address;
        if(address == ""){
            return 1;
        }
        //新建用户对象
        User* user = new User(id, auth, name, passwd, balance, tel, address);
        userList->push_back(user);
        if(courierList != nullptr && auth == (int)UserAuth::COURIER){
            courierList->push_back(user);
        }
    }
    ifs.close();    //关闭文件流
    if(userList->size() == 0){
        MessageBox(GetForegroundWindow(),L"'*\\LMS-v2\\data\\users.text' Damaged",L"LMS ERROR",1);
        exit(1);
    }
    return 1;
}

/* 包裹信息文件读取 */
int Storager::ReadPacketList(vector<PacketBase*>* packetList) const{
    if(packetList == nullptr) return 0;
    //打开文件
    ifstream ifs(PROJECT_DIR + "\\LMS-v2\\data\\packets.txt", ios::in);
    if(!ifs.is_open()){
        return 0;
    }
    while(!ifs.eof()){
        int id,type; double count;
        //按字段读取
        ifs >> id >> type >> count;
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
        //设置信息
        pb->setCount(count);
        int status,courier,from,dest;
        string sendtime, recvtime, describe="";
        ifs >> status >> courier >>  from >> dest >> sendtime >> recvtime >> describe;
        if(describe == ""){
            return 1;
        }
        //填充信息
        pb->Fill(id,status,courier,from,dest,sendtime,recvtime,describe);
        //添加到列表
        packetList->push_back(pb);
    }
    ifs.close();    //关闭文件流
    return 1;
}

/* 用户列表存储 */
int Storager::StoreUserList(vector<User*>* userList) const{
    if(userList == nullptr) return 0;
    //打开文件覆盖重写
    ofstream ofs(PROJECT_DIR + "\\LMS-v2\\data\\users.txt", ios::out | ios::trunc);
    ofs.setf(ios::fixed,ios::floatfield);
    ofs.precision(2);
    auto itr = userList->begin();
    //遍历按行写入
    while(itr != userList->end()){
        ofs << (*itr)->getID()<<" "
            <<(*itr)->getAuth()<<" "
            <<(*itr)->getName()<<" "
            <<(*itr)->getPasswd()<<" "
            <<(*itr)->getBalance()<<" "
            <<(*itr)->getTel()<<" "
            <<(*itr)->getAddr()<<"\n";
        itr++;
    }
    ofs.close();    //关闭文件流
    return 1;
}

/* 包裹信息存储 */
int Storager::StorePacketList(vector<PacketBase*>* packetList) const{
    if(packetList == nullptr) return 0;
    //打开文件覆盖重写
    ofstream ofs(PROJECT_DIR + "\\LMS-v2\\data\\packets.txt", ios::out | ios::trunc);
    ofs.setf(ios::fixed,ios::floatfield);
    ofs.precision(2);
    auto itr = packetList->begin();
    //遍历按行写入
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
    ofs.close();
    return 1;
}
