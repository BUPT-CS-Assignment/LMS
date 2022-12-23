#include "header/Basic.h"
using namespace std;

/* 添加包裹 */
void PacketControl::AddPacket(PacketBase* p){
    _packetList.push_back(p);
}

/* 文件读入 */
int PacketControl::ReadIn(){
    st.ReadPacketList(&_packetList);
    //快速排序
    sort(_packetList.begin(),_packetList.end(),[](PacketBase* p1,PacketBase* p2)-> bool{return p1->getID() < p2->getID();});
    return 0;
}

/* 文件写入 */
void PacketControl::WriteBack(){
    st.StorePacketList(&_packetList);
}

/* 字段匹配 */
bool PacketControl::packet_matching(const PacketBase* p,PacketMatchField field,void* input) const{
    switch(field){
        case PacketMatchField::ID:
            return p->getID() == *(unsigned long long*)input;
        case PacketMatchField::TYPE:
            return p->getType() == VOID_TO_INT input;
        case PacketMatchField::COUNT:
            return p->getCount() == VOID_TO_INT input;
        case PacketMatchField::STATUS:
            return p->getStatus() == VOID_TO_INT input;
        case PacketMatchField::COURIER:
            return p->getCourier() == VOID_TO_INT input;
        case PacketMatchField::FROM:
            return p->getFromUser() == VOID_TO_INT input;
        case PacketMatchField::DEST:
            return p->getDestUser() == VOID_TO_INT input;
        ///部分匹配支持
        case PacketMatchField::SENDTIME:
            return p->getSendTime().compare(0,((string*)input)->length(),VOID_TO_STR input) == 0;
        case PacketMatchField::RECVTIME:
            return p->getRecvTime().compare(0,((string*)input)->length(),VOID_TO_STR input) == 0;
        case PacketMatchField::DESCRIBE:
            return p->getDescription().compare(0,((string*)input)->length(),VOID_TO_STR input) == 0;
    }
    return false;
}

/* 包裹搜索 */
std::vector<PacketBase*> PacketControl::PacketSearch(PacketMatchField* farray,void** inputs,int num) const{
    if(num == 0) return _packetList;
    vector<PacketBase*> list;
    //遍历搜索
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        bool flag = true;
        //遍历字段
        for(int i = 0; i < num && flag; i++){
            flag = packet_matching((*itr),farray[i],inputs[i]);
        }
        if(flag){
            list.push_back((*itr));
        }
        itr++;
    }
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

/* 单个包裹定位 */
PacketBase* PacketControl::PacketLocate(unsigned long long id) const{
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        //字段匹配
        if(packet_matching((*itr),PacketMatchField::ID,&id)){
            return *itr;
        }
        itr ++;
    }
    return nullptr;
}

/* 设置包裹状态 */
void PacketControl::SetPacketStatus(unsigned long long packetid,PacketStatus s) const{
    auto itr = _packetList.begin();
    //遍历搜索
    while(itr != _packetList.end()){
        //字段匹配
        if(packet_matching((*itr),PacketMatchField::ID,&packetid)){
            (*itr)->setStatus((int)s);  //设置状态
            return;
        }
        itr ++;
    }
}

PacketControl::~PacketControl(){
    auto itr = _packetList.begin();
    while(itr != _packetList.end()){
        delete (*itr);
        itr++;
    }
}
