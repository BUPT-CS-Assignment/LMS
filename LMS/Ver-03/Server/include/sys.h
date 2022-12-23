#ifndef __SYS_H__
#define __SYS_H__

#include <WinSock2.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <direct.h>
#include <time.h>
#include <thread>
#include <windows.h>

#pragma comment(lib,"Ws2_32.lib")       //链接winsocket库

extern std::string PROJECT_DIR;         //项目路径

#define POLLING_TIMES           5       //锁状态循环检测次数
#define WAIT_TIMER              50      //锁状态等待时间

/* 返回值 */
enum ReturnValue{
    SUCCESS,
    TIME_OUT,
    NOT_FOUND,
    NULL_PTR,
    SYSTEM_ERR,
};

/* 返回代码字符串 */
static std::string BACK_MSG[]{
    "0",    //SUCCESS      
    "1",    //TIME_OUT    
    "2",    //NOT_FOUND    
    "3",    //NULL_PTR     
    "4",    //SYSTEM_ERR  
};

/* 返回信息字符串 */
static std::string RetValText[]{
    "SUCCESS",
    "TIME_OUT",
    "NOT_FOUND",
    "NULL_PTR",
    "SYSTEM_ERR",
};

/* 请求类型 */
enum class FUNCTION:char{
    /* Sign Function */
    SIGN_IN         = 'A',  //+ | userid,passwd,auth
    SIGN_UP         = 'B',  //+ | userid,passwd
    SIGN_OUT        = 'C',  //

    /* User Function */
    ADD_USER        = 'D',  //+ | userid,passwd,Auth,
    DEL_USER        = 'E',  //+ | userid
    SET_USER        = 'F',  //+ | field1,f2... | value1,v2...
    RECHARGE        = 'G',  //+ | num
    CHECK_USER      = 'H',  //+ | field1,f2... | value1,v2...

    /* Packet Function */   
    SEND_PACKET     = 'I',  //+ | type,dest,count,description  
    RECV_PACKET     = 'J',  //+ | packid
    COLLECT_PACKET  = 'K',  //+ | userid,packetid
    ALLOC_COURIER   = 'L',  //+ | packid,id
    CHECK_PACKET    = 'M',  //+ | field1,f2... | value1,v2...

    /* Other Function */
    ALLOC_SWITCH    = 'N',  //+ | get/check | val
    AUTO_ALLOC      = 'O',  //+ | packid
    STORE_DATA      = 'P',  //
};

/* 用户设置字段类型 */
enum class USER_SET_FIELD:char{
    PASSWD = 'A',
    TEL    = 'B',
    ADDR   = 'C',
};

/* 锁状态类型 */
enum class LOCK:int{
    FREE,
    RUN,
    BLOCK,
};

/* 包裹搜索匹配字段 */
enum class PacketMatchField:int{
    ID,
    DEST,
    RECVTIME,
    SENDTIME,
    FROM,
    TYPE,
    COUNT,
    STATUS,
    COURIER,
    DESCRIBE,
    ALL,
};

/* 用户搜索匹配字段 */
enum class UserMatchField:int{
    ID,
    AUTH,
    NAME,
    PASSWD,
    BALANCE,
    TEL,
    ADDRESS,
    ALL,
    COURIER,
};

/* 快递状态 */
enum class PacketStatus:int{
    COLLECTING, //待揽收
    PENDING,    //待签收
    RECVED,     //已签收
};

/* 用户权限 */
enum class UserAuth:int{
    USER,       //用户
    COURIER,    //快递员
    ADMIN,      //管理员
    ROOT,       //公司
};

/* 包裹类型 */
enum class PacketType:int{
    PACKAGE,        //普通包裹
    BREAKABLE,      //易碎品
    BOOK,           //图书
};

class User;
class PacketBase;
class UserControl;
class PacketControl;
class Console;
class BackEnd;
class Service;
class Server;
class Storager;

#endif