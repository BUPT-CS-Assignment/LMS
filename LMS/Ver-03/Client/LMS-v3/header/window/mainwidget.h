#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "header/window/signin.h"
#include "header/window/navigation.h"
#include "header/window/backstage.h"
#include "header/main.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

/* 主界面UI */
class MainWidget : public QWidget
{
    Q_OBJECT    //QT 宏

public:
    MainWidget(QWidget *parent = nullptr,MainService* ms = nullptr);
    ~MainWidget();

private slots:
    void ShowNavigation();              //显示用户界面
    void HideNavigation();              //隐藏用户界面
    void ShowBackStage();               //显示后台界面
    void HideBackStage();               //隐藏后台界面
    void ShowManage();                  //显示快递员界面
    void HideManage();                  //隐藏快递员界面

private:
    void closeEvent(QCloseEvent* event);//应用退出操作
    MainService* _ms;                   //主服务指针
    Ui::MainWidget *ui;                 //主界面ui指针
    Signin *Sign_in;                    //登录界面GUI模块指针
    Navigation *Nav;                    //用户界面GUI模块指针
    BackStage* BS;                      //后台管理界面GUI模块指针
    Manage* Mng;                        //快递员界面GUI模块指针


};
#endif // MAINWIDGET_H
