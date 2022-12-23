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
    //设置窗口大小
    Sign_in = new Signin(this,_ms); //400 * 300
    Nav = new Navigation(this,_ms); //405 * 720
    Mng = new Manage(this,_ms);     //405 * 720
    BS = new BackStage(this,_ms);   //1024 * 576
    //显示登录界面
    Nav->hide();
    BS->hide();
    Mng->hide();
    Sign_in->show();
    //槽信号连接
    connect(Sign_in,SIGNAL(SigninSuccess()),this,SLOT(ShowNavigation()));
    connect(Nav,SIGNAL(SignoutSignal()),this,SLOT(HideNavigation()));
    connect(Sign_in,SIGNAL(SigninBackStage()),this,SLOT(ShowBackStage()));
    connect(BS,SIGNAL(SignoutSignal()),this,SLOT(HideBackStage()));
    connect(Sign_in,SIGNAL(SigninManage()),this,SLOT(ShowManage()));
    connect(Mng,SIGNAL(SignoutSignal()),this,SLOT(HideManage()));
}

MainWidget::~MainWidget()
{
    delete ui;
}

//显示用户界面
void MainWidget::ShowNavigation(){
    this->setWindowTitle("LMS USER");
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

//隐藏后台界面
void MainWidget::HideBackStage(){
    this->setWindowTitle("LMS SIGN");
    BS->hide();
    this->setFixedSize(400,300);
    Sign_in->show();
}

//显示快递员界面
void MainWidget::ShowManage(){
    this->setWindowTitle("LMS COURIER");
    Mng->Init();
    Mng->ToFirstPage();
    Sign_in->hide();
    Sign_in->GetUI()->signin_id_input->clear();
    Sign_in->GetUI()->signin_pwd_input->clear();
    Mng->show();
    this->setFixedSize(405,720);
}

//隐藏快递员界面
void MainWidget::HideManage(){
    this->setWindowTitle("LMS SIGN");
    Mng->hide();
    this->setFixedSize(400,300);
    Sign_in->show();
}

//关闭信号
void MainWidget::closeEvent(QCloseEvent* event){
    _ms->Close();
}

