#include "header/Basic.h"
using namespace std;

UserControl::UserControl():_userList(){
    _curUser = nullptr;
}

//用户登录
int UserControl::Signin(int userid,string passwd,int auth){
    auto itr = _userList.begin();
    //遍历搜索
    while(itr != _userList.end()){
        if((*itr).getID() == userid){
            //权限检测
            if((*itr).getAuth() < auth){
                return USER_AUTH_FAILED;
            }
            //密码比对
            if((*itr).getPasswd() == passwd){
                _curUser = &(*itr);
                return USER_SIGNIN_SUCCESS;
            }
            else{
                return USER_SIGNIN_FAILED;
            }
        }
        itr ++;
    }
    return USER_SIGNIN_FAILED;
}

//注册
int UserControl::Signup(int userid,string passwd){
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        //查找重复ID
        if((*itr).getID() == userid)    return USER_SIGNUP_FAILED;
        itr ++;
    }
    User user(userid,passwd,USER_COMMON);
    _userList.push_back(user);
    return USER_SIGNUP_SUCCESS;
}

//用户登出
void UserControl::Signout(){
    //取消当前用户指针挂载
    _curUser = nullptr;
}

//设置用户信息
void UserControl::SetInfo(std::string name,std::string tel,std::string addr){
    //判空填充
    if(name != "" && name != "null")  _curUser->setName(name);
    if(tel != "" && tel != "null")   _curUser->setTel(tel);
    if(addr != "" && addr != "null")  _curUser->setAddr(addr);
}

//设置密码
void UserControl::SetPasswd(std::string passwd){
    _curUser->setPasswd(passwd);
}

//充值
int UserControl::Recharge(int price){
    int balance = _curUser->getBalance();
    //合法输入检测
    if(price <=0 || balance + price <= 0)   return 0;
    _curUser->setBalance(balance + price);
    return 1;
}

//用户搜索
void UserControl::CheckUsers(UCheck mode,void* dest,int auth,void* input){
    if(auth == USER_MODE){
        //用户模式下，更新用户信息
        ((Navigation*)dest)->GetUI()->userid->setText(QString::number(_curUser->getID()));
        ((Navigation*)dest)->GetUI()->user_name->setText(QString::fromStdString(_curUser->getName()));
        ((Navigation*)dest)->GetUI()->user_tel->setText(QString::fromStdString(_curUser->getTel()));
        ((Navigation*)dest)->GetUI()->user_addr->setText(QString::fromStdString(_curUser->getAddr()));
        ((Navigation*)dest)->GetUI()->user_funds->setText(QString::number(_curUser->getBalance()));
    }else if(auth == BACKSTAGE_MODE){
        //后台模式下，遍历搜索用户信息
        switch(mode){
            case UCheck::ALL:
                check_traverse((QTableWidget*)dest,nullptr,nullptr);    break;
            case UCheck::USER_ID:
                check_traverse((QTableWidget*)dest,&UserControl::check_by_userid,input);  break;
            case UCheck::USER_NAME:
                check_traverse((QTableWidget*)dest,&UserControl::check_by_name,input);  break;
            case UCheck::USER_TEL:
                check_traverse((QTableWidget*)dest,&UserControl::check_by_tel,input);  break;
            case UCheck::USER_ADDR:
                check_traverse((QTableWidget*)dest,&UserControl::check_by_addr,input);  break;
        }
    }
}

//添加用户信息到表格
void UserControl::AddToTable(QTableWidget* table,User& u){
    int row = table->rowCount();
    table->setRowCount(row + 1);
    table->setItem(row,0,new QTableWidgetItem(QString::number(u.getID())));
    table->setItem(row,1,new QTableWidgetItem(QString::number(u.getAuth())));
    table->setItem(row,2,new QTableWidgetItem(QString::number(u.getBalance())));
    table->setItem(row,3,new QTableWidgetItem(QString::fromStdString(u.getName())));
    table->setItem(row,4,new QTableWidgetItem(QString::fromStdString(u.getTel())));
    table->setItem(row,5,new QTableWidgetItem(QString::fromStdString(u.getAddr())));
}

//遍历搜索
void UserControl::check_traverse(QTableWidget* dest,compare c,void* input){
    dest->clearContents();
    dest->setRowCount(0);
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        //比对
        if(input == nullptr || (this->*c)((*itr),input)){
            UserControl::AddToTable(dest,(*itr));
        }
        itr++;
    }
}

//按ID搜索
bool UserControl::check_by_userid(User& u,void* input){
    int id = *(int*)input;
    return (u.getID() == id);
}
//按用户名搜索
bool UserControl::check_by_name(User& u,void* input){
    string name = *(string*)input;
    return (u.getName().find(name) != name.npos);
}
//按电话搜索
bool UserControl::check_by_tel(User& u,void* input){
    string tel = *(string*)input;
    return (u.getTel().find(tel) != tel.npos);
}
//按地址搜索
bool UserControl::check_by_addr(User& u,void* input){
    string addr = *(string*)input;
    return (u.getAddr().find(addr) != addr.npos);
}
