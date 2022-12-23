#ifndef __STORAGE_H__
#define __STORAGE_H__
#include "main.h"
#include "user.h"
#include "packet.h"

/* 存储器类 */
class Storager{
private:
public:
    int ReadUserList(std::vector<User>*) const;       //从文件读入用户列表
    int ReadPacketList(std::vector<Packet>*) const;   //从文件读入包裹列表
    int StoreUserList(std::vector<User>*) const;      //存储用户列表到文件
    int StorePacketList(std::vector<Packet>*) const;  //存储包裹列表到文件

};

#endif
