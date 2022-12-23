#include "header/Basic.h"
using namespace std;

/* 获取当地时间 */
string Console::GetTime() const{
    time_t t = time(NULL);
    struct tm p=*localtime(&t);
    char str[20];
    sprintf(str,"%4.4d/%2.2d/%2.2d-%2.2d:%2.2d",
        p.tm_year+1900, p.tm_mon+1,p.tm_mday,p.tm_hour,p.tm_min);
    return string(str);
}

/* 弹窗管理器 */
bool Console::StatusCheck(int ret,QString not_found_msg,QString sys_err_msg,QString null_ptr_msg) const{
    if(ret == SUCCESS) return true;
    if(ret == NOT_FOUND){
        QMessageBox::critical(nullptr,"ERROR",not_found_msg);
    }else if(ret == SYSTEM_ERR){
        QMessageBox::critical(nullptr,"ERROR",sys_err_msg);
    }else if(ret == NULL_PTR){
        QMessageBox::critical(nullptr,"ERROR",null_ptr_msg);
    }else if(ret == TIME_OUT){
        QMessageBox::information(nullptr,"TIPS","请求超时，服务器繁忙");
    }
    return false;
}

/* 打印错误信息 */
void Console::LogErr(string err) const{
    cout << BOLDRED << "[ Error ] " << err <<  RESET << endl;
}

/* 打印提醒信息 */
void Console::LogMsg(string msg) const{
    cout << BOLDWHITE << "[ Msg ] " << msg << RESET << endl;
}

