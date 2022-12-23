#include "header/Basic.h"

#include <QApplication>

std::string PROJECT_DIR = "/";

int main(int argc, char *argv[])
{
    Console sc;
    PROJECT_DIR = sc.GetFilePath();
    std::cout <<  PROJECT_DIR << std::endl; //程序运行目录
    MainService ms;             //启动主服务
    QApplication a(argc, argv);
    MainWidget w(nullptr,&ms);  //构建主窗口,接连主服务
    w.show();
    return a.exec();
}
