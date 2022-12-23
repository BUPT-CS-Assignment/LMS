#include "basic.h"
using namespace std;

/* 包裹信息格式化 */
string PacketBase::Format(){
    Console sc;
    string res = "";
    //逗号分隔
    res = to_string(_id) + ","
        + to_string(_status) + ","
        + to_string(_type) + ","
        + sc.dtos(_count) + ","
        + sc.dtos(getPrice()) + ","
        + to_string(_courier)+ ","
        + to_string(_fromUser) + ","
        + to_string(_destUser) + ","
        + _sendTime + ","
        + _recvTime + ","
        + _describe;
    return res;
}

/* 添加包裹 */
int PacketControl::AddPacket(PacketBase* p){
    if(!sc.wait(&_lock))    return TIME_OUT;
    setLock(LOCK::RUN);
    _packetList.push_back(p);
    setLock();
    return SUCCESS;
}

/* 文件读入 */
void PacketControl::ReadIn(){
    int res;
    res = st.ReadPacketList(&_packetList);
    sc.log(true,BOLDBLUE"PACKET Number : %d\n",res);
    //快速排序
    sort(_packetList.begin(),_packetList.end(),
        [](PacketBase* p1,PacketBase* p2)-> bool{
            return p1->getID() < p2->getID();
        });
}

/* 文件写入 */
int PacketControl::WriteBack(){
    if(!sc.wait(&_lock,LOCK::FREE,10)) return TIME_OUT;
    setLock(LOCK::BLOCK);
    int res;
    res = st.StorePacketList(&_packetList);
    if(res != SUCCESS){
        sc.err(RetValText[res]);
    }
    setLock();
    return res;
}

/* 字段匹配 */
bool PacketControl::packet_matching(const PacketBase* p,PacketMatchField field,string input) const{
    //字段匹配
    switch(field){
        case PacketMatchField::ID:
            return p->getID() == stoull(input);
        case PacketMatchField::TYPE:
            return p->getType() == stoi(input);
        case PacketMatchField::COUNT:
            return p->getCount() == stoi(input);
        case PacketMatchField::STATUS:
            return p->getStatus() == stoi(input);
        case PacketMatchField::COURIER:
            return p->getCourier() == stoi(input);
        case PacketMatchField::FROM:
            return p->getFromUser() == stoi(input);
        case PacketMatchField::DEST:
            return p->getDestUser() == stoi(input);
        ///部分匹配支持
        case PacketMatchField::SENDTIME:
            return p->getSendTime().compare(0,input.length(),input) == 0;
        case PacketMatchField::RECVTIME:
            return p->getRecvTime().compare(0,input.length(),input) == 0;
        case PacketMatchField::DESCRIBE:
            return p->getDescription().compare(0,input.length(),input) == 0;
    }
    return false;
}

/* 包裹搜索 */
std::vector<PacketBase*> PacketControl::PacketSearch(PacketMatchField* farray,string* inputs,int num){
    if(num == 0) return _packetList;
    vector<PacketBase*> list;
    if(!sc.wait(&_lock)) return list;
    setLock(LOCK::RUN);
    //遍历匹配
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        bool flag = true;
        //遍历字段
        for(int i = 0; i < num && flag; i++){
            setLock(LOCK::RUN);
            flag = packet_matching((*itr),farray[i],inputs[i]);
        }
        if(flag){
            list.push_back((*itr));
        }
        itr++;
    }
    setLock();
    //快速排序
    sort(list.begin(),list.end(),
         [farray](PacketBase* p1,PacketBase* p2)-> bool{
            if(farray[0] == PacketMatchField::SENDTIME){
                return p1->getSendTime() < p2->getSendTime();
            }else if(farray[0] == PacketMatchField::RECVTIME){
                return p1->getRecvTime() < p2->getRecvTime();
            }
            return p1->getID() < p2->getID();
    });
    return list;
}

/* 单个快递定位 */
PacketBase* PacketControl::PacketLocate(string id){
    if(!sc.wait(&_lock)) return nullptr;
    setLock(LOCK::RUN);
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        //快递信息匹配
        if(packet_matching((*itr),PacketMatchField::ID,id)){
            setLock();
            return (*itr);
        }
        setLock(LOCK::RUN);
        itr ++;
    }
    setLock();
    return nullptr;
}


PacketControl::~PacketControl(){
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        delete (*itr);
        itr++;
    }
}


