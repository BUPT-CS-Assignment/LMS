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
#include <unistd.h>
#include <fstream>
#include <iomanip>

class Console;
class User;
class Packet;
class PacketControl;
class UserControl;
class Storager;

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

#endif