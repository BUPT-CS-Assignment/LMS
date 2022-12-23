#include "basic.h"
using namespace std;

/* 打印日志 */
void Console::log(bool time_on,string content,...){
    //时间戳开关
    if(time_on){
        cout << RESET << TIME_CST() << " ";
    }
    printf(WHITE);
    //(printf) var_arg 宏
    va_list args;
    va_start(args, content);
    vprintf(content.c_str(), args);
    va_end(args);
    printf(RESET);
}

/* 输出提醒消息 */
void Console::msg(string content,bool time_on){
    //时间戳开关
    if(time_on){
        cout << GREEN << TIME_CST() << " ";
    }
    cout << BOLDGREEN << "<Message> " << content << RESET << endl;
}

/* 输出错误消息 */
void Console::err(string content,bool time_on){
    //时间戳开关
    if(time_on){
        cout << RED << TIME_CST() << " ";
    }
    cout << BOLDRED << "<Error> " << content << RESET << endl;
}

/* 获取CST时间 */
string Console::TIME_CST(){
    time_t timer;
    time(&timer);                   //获取当前时间
    char* str = ctime(&timer);      //CST转换
    str[strlen(str) - 1] = '\0';
    string curTime(str);        
    return "["+curTime+" CST]";     //格式化
}

/* 获取项目路径 */
string Console::getDir(){
    char buff[250];
    _getcwd(buff, 250);         //获取目录
    std::string str(buff);
    std::string res = str.substr(0,str.find("\\Server")+7);     //路径裁切
    return res;
}

/* 字符串分割 */
vector<string> Console::Split(const string& str, const string& c){
    string::size_type pos1, pos2;
    vector<string> res;
    pos2 = str.find(c);     //首个匹配位置
    pos1 = 0;
    while(pos2 != string::npos){
        res.push_back(str.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = str.find(c, pos1);   //循环检测下一匹配位置
    }
    if(pos1 != str.length()){
        res.push_back(str.substr(pos1)); 
    }
    return res;
}

/* 锁状态检测 */
bool Console::wait(LOCK* dest,LOCK status,int polling_time,int wait_timer){
    //循环次数
    while(polling_time){
        //检测锁状态
        if(*dest <= status)  return true;
        Sleep(wait_timer);  //等待特定时间
        --polling_time;
    }
    return false;
}

/* 浮点数转字符串 */
string Console::dtos(double d){
    char temp[20];
    sprintf(temp, "%.2lf", d);  //格式化输出 保留两位小数
    std::string str(temp);
    if(str.find(".00") != string::npos){
        str = str.substr(0,str.length()-3);     //整数化
    }
    return str;
}

/* 获取格式化CST时间 */
string Console::getTime(){
    time_t t = time(NULL);
    struct tm p=*localtime(&t); //获取当地时间
    char str[20];
    //格式化输出
    sprintf(str,"%4.4d/%2.2d/%2.2d-%2.2d:%2.2d",
        p.tm_year+1900, p.tm_mon+1,p.tm_mday,p.tm_hour,p.tm_min);
    return string(str);
}