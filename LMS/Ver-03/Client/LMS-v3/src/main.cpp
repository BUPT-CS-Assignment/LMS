#include "header/Basic.h"

#include <QApplication>

std::string PROJECT_DIR = "/";

int main(int argc, char *argv[])
{
    MainService ms;             //启动主服务
    QApplication a(argc, argv);
    MainWidget w(nullptr,&ms);  //构建主窗口,接连主服务
    w.show();
    return a.exec();
}
