#ifndef __CONSOLE_H__
#define __CONSOLE_H__
#include "main.h"

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

/* 控制台类 */
class Console{

public:
    //弹窗管理器
    bool StatusCheck(int ret,
                     QString not_found_msg = "NOT_FOUND SIGNAL RECV",
                     QString sys_err_msg = "SYSTEM_ERR SIGNAL RECV",
                     QString null_ptr_msg = "NULL_PTR SIGNAL RECV"
                     ) const;
    void LogErr(std::string err) const;   //控制台输出错误信息
    void LogMsg(std::string msg) const;   //控制台输出提示信息
    std::string GetTime() const;          //获取当前时间, 格式'yyyy/mm/dd-hh:mm'

};


#endif
