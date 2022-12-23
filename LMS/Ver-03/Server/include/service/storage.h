#ifndef __STORAGE_H__
#define __STORAGE_H__
#include "../sys.h"

/* 存储器类 */
class Storager{
public:
    int ReadUserList(std::vector<User*>*,std::vector<User*>* courier = nullptr) const;  //从文件读入用户列表
    int ReadPacketList(std::vector<PacketBase*>*) const;   //从文件读入包裹列表
    int StoreUserList(std::vector<User*>*) const;      //存储用户列表到文件
    int StorePacketList(std::vector<PacketBase*>*) const;  //存储包裹列表到文件

};

#endif
