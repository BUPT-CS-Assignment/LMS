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
#include<windows.h>


class Console;
class User;
class Packet;
class PacketControl;
class UserControl;
class Storager;
class MainService;

extern std::string PROJECT_DIR;

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

enum class USet:int{
    CHECK_ALL,
    CHECK_BALANCE,
    RECHARGE,
    CHANGE_PASSWD,
    CHANGE_NAME,
    CHANGE_CONTACT,
    CHANGE_ADDRESS,
};

#define USER_SIGNIN_SUCCESS 1
#define USER_SIGNIN_FAILED  0
#define USER_AUTH_FAILED    2
#define USER_SIGNUP_SUCCESS 1
#define USER_SIGNUP_FAILED  0

/* 包裹搜索类型 */
enum class PCheck:int{
    PACKET_ID,          //按包裹ID搜索
    RECV_USER_ID,       //按签收人ID搜索
    RECV_TIME,          //按签收时间搜索
    SEND_TIME,          //按发件时间搜索
    SEND_USER_ID,       //按发件人ID搜索
    PACKET_PEND,        //按运输状态搜索
    PACKET_RECV,        //按签收状态搜索
    //////
    ALL,                //搜索所有包裹
};

/* 用户搜索类型 */
enum class UCheck:int{
    USER_ID,            //按用户ID搜索
    USER_NAME,          //按用户名搜索
    USER_TEL,           //按用户联系方式搜索
    USER_ADDR,          //按用户地址搜索
    /////
    ALL,                //搜索所有用户
};

#define USER_MODE 0         //登录类型-用户
#define BACKSTAGE_MODE 1    //登录类型-管理后台

/* 搜索选择对应文字 */
static std::string SearchChooseText[]{
    "运单号",
    "收件人",
    "收件时间",
    "寄件时间",
    "寄件人",
    "运输中",
    "已签收"
};

#endif
