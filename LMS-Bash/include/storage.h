#ifndef __STORAGE_H__
#define __STORAGE_H__
#include <main.h>
#include <user.h>
#include <packet.h>

class Storager{
private:
    std::string  _filePath;
public:
    Storager(std::string filePath="/");
    int ReadUserList(std::vector<User>*);
    int ReadPacketList(std::vector<Packet>*);
    int StoreUserList(std::vector<User>*);
    int StorePacketList(std::vector<Packet>*);

};

#endif