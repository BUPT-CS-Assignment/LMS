#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "sys.h"

#define TIME_ON 1       //开启时间戳
#define TIME_OFF 0      //关闭时间戳

/* 控制台工具 */
class Console{
public:
    void log(bool time_on,std::string content, ...);    //带时间戳日志打印
    void msg(std::string,bool time_on = true);          //输出提醒信息
    void err(std::string,bool time_on = true);          //输出错误信息
    std::string TIME_CST();                             //获取CST时间
    std::string getTime();                              //获取格式化CST时间
    std::string getDir();                               //获取当前目录
    //判断锁状态
    bool wait(LOCK* dest,LOCK status = LOCK::RUN, int polling_time = POLLING_TIMES, int wait_timer = WAIT_TIMER);
    //字符串分割
    std::vector<std::string> Split(const std::string&, const std::string&);
    //浮点数转字符串
    std::string dtos(double d);
};

#define RESET       "\033[0m"       /* Reset */
#define BLACK       "\033[30m"      /* Black */
#define RED         "\033[31m"      /* Red */
#define GREEN       "\033[32m"      /* Green */
#define YELLOW      "\033[33m"      /* Yellow */
#define BLUE        "\033[34m"      /* Blue */
#define MAGENTA     "\033[35m"      /* Magenta */
#define CYAN        "\033[36m"      /* Cyan */
#define WHITE       "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#endif