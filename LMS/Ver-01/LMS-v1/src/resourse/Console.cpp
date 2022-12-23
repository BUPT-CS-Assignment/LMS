#include "header/Basic.h"
using namespace std;

//获取当前目录
std::string Console::GetFilePath() const{
    char buff[250];
    //获得当前完整目录
    _getcwd(buff, 250);
    std::string str(buff);
    //数据文件目录裁切
    std::string filePath = str.substr(0,str.find_first_of("LMS")+3);
    return filePath;
}

//获取系统时间
string Console::GetTime() const{
    //获得当前时间
    time_t t = time(NULL);
    //转换为当地时间
    struct tm p=*localtime(&t);
    char str[20];
    //格式化
    sprintf(str,"%4.4d/%2.2d/%2.2d-%2.2d:%2.2d",
        p.tm_year+1900, p.tm_mon+1,p.tm_mday,p.tm_hour,p.tm_min);
    return string(str);
}

//控制台输出错误信息（调试用）
void Console::LogErr(string err) const{
    cout << BOLDRED << "[ Error ] " << err <<  RESET << endl;
}

//控制台输出提示信息（调试用）
void Console::LogMsg(string msg) const{
    cout << BOLDGREEN << "[ Msg ] " << msg << RESET << endl;
}

