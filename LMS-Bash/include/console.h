#ifndef __CONSOLE_H__
#define __CONSOLE_H__
#include <main.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

enum __Option__{
    MAIN_PANEL,
    USER_PANEL,
    CHECK_PANEL,
    USER_SET_PANEL,
    USER_INFO,
    PACKET_INFO,
    USER_PANEL_HELP,
    SIGN_OUT,
    CHECK_ACCOUNT,

};


class Console{
private:
    /* Guidance */
    void print_header(__Option__);
    void print_sign();
    void print_user_panel();
    void print_check_panel();
    void print_user_set_panel();

    /* Read In */
    int read_in(int below,int above);
public:
    /* Input Check */
    int GetNum(std::string msg="Option");
    std::string GetStr(std::string msg="Option");

    /* Get Option */
    int GetOption(__Option__,bool show=true);

    /* Log Error Msg*/
    void LogErr(std::string err);
    void LogMsg(std::string msg);
    void PrintUserInfo(User* user,bool header = false,bool bottom = false);
    void PrinfPacketInfo(Packet* packet,bool header = false, bool bottom = false);
    void PrintPacketEmpty();
    std::string GetTime();
};


#endif