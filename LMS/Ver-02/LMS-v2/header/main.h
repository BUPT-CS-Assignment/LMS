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
#include <windows.h>


class Console;
class User;
class PacketBase;
class PacketControl;
class UserControl;
class Storager;
class MainService;

extern std::string PROJECT_DIR;

#define VOID_TO_INT             *(int*)
#define VOID_TO_STR             *(std::string*)

#define PROGRAM_SIGN_IN         0
#define PROGRAM_SIGN_UP         1
#define PROGRAM_SAVE_DATA       2
#define PROGRAM_EXIT            3

#define OPTION_SEND_PACKET      0
#define OPTION_RECV_PACKET      1
#define OPTION_USER_INFO        2
#define OPTION_CHECK_SENDS      3
#define OPTION_CHECK_RECVS      4
#define OPTION_SIGN_OUT         5

#define PACKET_STATUS_PEND      0
#define PACKET_STATUS_RECV      1
#define PACKET_STATUS_SEND      2


#define USER_SIGNIN_SUCCESS     1
#define USER_SIGNIN_FAILED      0
#define USER_AUTH_FAILED        2
#define USER_SIGNUP_SUCCESS     1
#define USER_SIGNUP_FAILED      0


#define USER_MODE               0   //登录类型-用户
#define COURIER_MODE            1   //登录类型-快递员
#define ROOT_MODE               2   //登录类型-管理后台


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
};


enum class UserMatchField:int{
    ID,
    AUTH,
    NAME,
    PASSWD,
    BALANCE,
    TEL,
    ADDRESS,
};

/* 快递状态 */
enum class PacketStatus:int{
    COLLECTING, //待揽收
    PENDING,    //待签收
    RECVED,     //已签收
};

static std::string PacketStatusText[]{
    "待揽收",
    "待签收",
    "已签收",
};

enum class UserAuth:int{
    USER,       //用户
    COURIER,    //快递员
    ADMIN,      //管理员
    ROOT,       //公司
};

static std::string UserAuthText[]{
    "用户",
    "快递员",
    "管理员",
    "公司"
};

enum class PacketType:int{
    PACKAGE,
    BREAKABLE,
    BOOK,
};

static std::string PacketTypeText[]{
    "普通包裹",
    "易碎品",
    "图书",
};

/* 搜索选择对应文字 */
static std::string SearchChooseText[]{
    "运单号",
    "收件人",
    "收件时间",
    "寄件时间",
    "寄件人",
};

#endif
