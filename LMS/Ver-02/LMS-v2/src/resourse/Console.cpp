#include "header/Basic.h"
using namespace std;

/* 获取路径 */
std::string Console::GetFilePath() const{
    char buff[250];
    _getcwd(buff, 250); //获取当前路径
    std::string str(buff);
    std::string filePath = str.substr(0,str.find("\\LMS\\Ver-02\\")+11);    //路径裁切
    return filePath;
}

/* 获取当地时间 */
string Console::GetTime() const{
    time_t t = time(NULL);
    struct tm p=*localtime(&t); //获取当地时间
    char str[20];
    //格式化输出
    sprintf(str,"%4.4d/%2.2d/%2.2d-%2.2d:%2.2d",
        p.tm_year+1900, p.tm_mon+1,p.tm_mday,p.tm_hour,p.tm_min);
    return string(str);
}

/* 打印错误信息 */
void Console::LogErr(string err) const{
    cout << BOLDRED << "[ Error ] " << err <<  RESET << endl;
}

/* 打印提示信息 */
void Console::LogMsg(string msg) const{
    cout << BOLDGREEN << "[ Msg ] " << msg << RESET << endl;
}

