#include <storage.h>
#include <console.h>
using namespace std;

Storager::Storager(std::string filePath){
    _filePath = filePath;
}

int Storager::ReadUserList(vector<User>* userList){
    if(userList == nullptr) return 0;
    Console sc;
    ifstream ifs(PROJECT_DIR + "/data/users.txt", ios::in);
    if(!ifs.is_open()){
        sc.LogErr("User File Not Found");
        return 0;
    }
    while(!ifs.eof()){
        int id, auth, balance;
        string name, passwd, tel, address="";
        ifs >> id >> auth >> name >> passwd >> balance >> tel >> address;
        if(address == ""){
            return 1;
        }
        User user(id, auth, name, passwd, balance, tel, address);
        userList->push_back(user);
    }
    ifs.close();
    return 1;
}

int Storager::ReadPacketList(vector<Packet>* packetList){
    if(packetList == nullptr) return 0;
    Console sc;
    ifstream ifs(PROJECT_DIR + "/data/packets.txt", ios::in);
    if(!ifs.is_open()){
        sc.LogErr("Packet File Not Found");
        return 0;
    }
    while(!ifs.eof()){
        int id, status, from, dest;
        string sendtime, recvtime="";
        ifs >> id >> status >> from >> dest >> sendtime >> recvtime;
        if(recvtime == ""){
            return 1;
        }
        Packet packet(id, status, from, dest, sendtime, recvtime);
        packetList->push_back(packet);
    }
    ifs.close();
    return 1;
}

int Storager::StoreUserList(vector<User>* userList){
    if(userList == nullptr) return 0;
    Console sc;
    ofstream ofs(PROJECT_DIR + "/data/users.txt", ios::out | ios::trunc);
    auto itr = userList->begin();
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

int Storager::StorePacketList(vector<Packet>* packetList){
    if(packetList == nullptr) return 0;
    Console sc;
    ofstream ofs(PROJECT_DIR + "/data/packets.txt", ios::out | ios::trunc);
    auto itr = packetList->begin();
    while(itr != packetList->end()){
        ofs << (*itr).getID()<<" "
            <<(*itr).getStatus()<<" "
            <<(*itr).getFromUser()<<" "
            <<(*itr).getDestUser()<<" "
            <<(*itr).getSendTime()<<" "
            <<(*itr).getRecvTime()<<"\n";
        itr++;
    }
    ofs.close();
    return 1;
}