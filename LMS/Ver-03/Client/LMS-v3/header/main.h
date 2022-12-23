#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <direct.h>
#include <time.h>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTableWidget>
#include <QListWidget>
#include <WinSock2.h>
#include <windows.h>

class Console;
class User;
class PacketBase;
class PacketControl;
class UserControl;
class MainService;

extern std::string PROJECT_DIR;

#define VOID_TO_INT             *(int*)
#define VOID_TO_STR             *(std::string*)

#define PROGRAM_SIGN_IN         0
#define PROGRAM_SIGN_UP         1
#define PROGRAM_SAVE_DATA       2
#define PROGRAM_EXIT            3

//操作代码
#define OPTION_SEND_PACKET      0
#define OPTION_RECV_PACKET      1
#define OPTION_USER_INFO        2
#define OPTION_CHECK_SENDS      3
#define OPTION_CHECK_RECVS      4
#define OPTION_SIGN_OUT         5

//快递状态
#define PACKET_STATUS_PEND      0
#define PACKET_STATUS_RECV      1
#define PACKET_STATUS_SEND      2

//用户登录状态
#define USER_SIGNIN_SUCCESS     1
#define USER_SIGNIN_FAILED      0
#define USER_AUTH_FAILED        2
#define USER_SIGNUP_SUCCESS     1
#define USER_SIGNUP_FAILED      0

#define USER_MODE               0   //登录类型-用户
#define COURIER_MODE            1   //登录类型-快递员
#define ROOT_MODE               2   //登录类型-管理后台

//返回信息字符串
static QString RetValText[]{
    "SUCCESS",
    "TIME_OUT",
    "NOT_FOUND",
    "NULL_PTR",
    "SYSTEM_ERR",
    "CONNECTION_LOST",
};

//请求类型
enum FUNCTION:int{
    /* Sign Function */
    SIGN_IN,        //+ | userid,passwd,auth
    SIGN_UP,        //+ | userid,passwd
    SIGN_OUT,       //

    /* User Function */
    ADD_USER,       //+ | userid,passwd,Auth,
    DEL_USER,       //+ | userid
    SET_USER,       //+ | field1,f2... | value1,v2...
    RECHARGE,       //+ | num
    CHECK_USER,     //+ | field1,f2... | value1,v2...

    /* Packet Function */
    SEND_PACKET,    //+ | type,dest,count,description
    RECV_PACKET,    //+ | packid
    COLLECT_PACKET, //+ | userid,packetid
    ALLOC_COURIER,  //+ | packid,id
    CHECK_PACKET,   //+ | field1,f2... | value1,v2...

    /* Other Function */
    ALLOC_SWITCH,   //+ | get/check | val
    AUTO_ALLOC,     //+ | packid1,id2...
    STORE_DATA,
};

//请求代码字符串
static QString FUNC_TEXT[]{
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
};

//用户信息修改字段
enum class USER_SET_FIELD:char{
    PASSWD = 'A',
    TEL    = 'B',
    ADDR   = 'C',
};

//用户搜索匹配字段
enum class USER_CHECK_FIELD:char{
    ALL     = 'A',
    MAIN    = 'B',
    ///
    ID      = 'C',
    AUTH    = 'D',
    NAME    = 'E',
    PASSWD  = 'F',
    BALANCE = 'G',
    TEL     = 'H',
    ADDRESS = 'I',
};

//包裹搜索匹配字段
enum class PACKET_CHECK_FIELD:char{
    ALL         ='A',
    ///
    ID          = 'B',
    DEST        = 'C',
    RECVTIME    = 'D',
    SENDTIME    = 'E',
    FROM        = 'F',
    TYPE        = 'G',
    COUNT       = 'H',
    STATUS      = 'I',
    COURIER     = 'J',
    DESCRIBE    = 'K',
};

//锁信号
enum class LOCK:int{
    FREE,
    RUN,
    BLOCK,
};

//返回值
enum ReturnValue{
    SUCCESS,
    TIME_OUT,
    NOT_FOUND,
    NULL_PTR,
    SYSTEM_ERR,
    CONNECTION_LOST,
};

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

// 快递状态
enum class PacketStatus:int{
    COLLECTING, //待揽收
    PENDING,    //待签收
    RECVED,     //已签收
};

//包裹状态 文字
static QString PacketStatusText[]{
    "待揽收",
    "待签收",
    "已签收",
};

//用户类型
enum class UserAuth:int{
    USER,       //用户
    COURIER,    //快递员
    ADMIN,      //管理员
    ROOT,       //公司
};

//用户类型文字
static QString UserAuthText[]{
    "用户",
    "快递员",
    "管理员",
    "公司"
};

//包裹类型
enum class PacketType:int{
    PACKAGE,
    BREAKABLE,
    BOOK,
};

//包裹类型文字
static QString PacketTypeText[]{
    "普通包裹",
    "易碎品",
    "图书",
};

// 搜索选择对应文字
static QString SearchChooseText[]{
    "运单号",
    "收件人",
    "收件时间",
    "寄件时间",
    "寄件人",
};

#endif
