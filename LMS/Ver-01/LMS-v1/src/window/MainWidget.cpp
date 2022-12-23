#include "header/Basic.h"
using namespace std;

MainWidget::MainWidget(QWidget *parent,MainService* ms)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    this->_ms = ms;
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/icon/icon_window_title"));
    this->setWindowTitle("LMS SIGN");
    this->setFixedSize(400,300);
    // 设置页面大小
    Sign_in = new Signin(this,_ms); //400 * 300
    Nav = new Navigation(this,_ms); //405 * 720
    BS = new BackStage(this,_ms);   //1024 * 576
    // 显示登录界面
    Nav->hide();
    BS->hide();
    Sign_in->show();
    //链接信号槽
    connect(Sign_in,SIGNAL(SigninSuccess()),this,SLOT(ShowNavigation()));
    connect(Nav,SIGNAL(SignoutSignal()),this,SLOT(HideNavigation()));
    connect(Sign_in,SIGNAL(SigninBackStage()),this,SLOT(ShowBackStage()));
    connect(BS,SIGNAL(SignoutSignal()),this,SLOT(HideBackStage()));
}

MainWidget::~MainWidget()
{
    delete ui;
}

//显示用户界面
void MainWidget::ShowNavigation(){
    this->setWindowTitle("LMS USER");
    _ms->LinkNavigation(Nav);
    Nav->Init();
    Nav->ToFirstPage();
    Sign_in->hide();
    Sign_in->GetUI()->signin_id_input->clear();
    Sign_in->GetUI()->signin_pwd_input->clear();
    Nav->show();
    this->setFixedSize(405,720);

}

//隐藏用户界面
void MainWidget::HideNavigation(){
    this->setWindowTitle("LMS SIGN");
    Nav->hide();
    _ms->ResetLink();
    this->setFixedSize(400,300);
    Sign_in->show();
}

//显示后台界面
void MainWidget::ShowBackStage(){
    this->setWindowTitle("LMS BACKSTAGE");
    BS->Init();
    Sign_in->hide();
    Sign_in->GetUI()->signin_id_input->clear();
    Sign_in->GetUI()->signin_pwd_input->clear();
    BS->show();
    this->setFixedSize(1024,576);

}

//隐藏 后台界面
void MainWidget::HideBackStage(){
    this->setWindowTitle("LMS SIGN");
    BS->hide();
    _ms->ResetLink();
    this->setFixedSize(400,300);
    Sign_in->show();
}

//关闭应用时自动保存数据到文件
void MainWidget::closeEvent(QCloseEvent* event){
    _ms->StoreData();
}

