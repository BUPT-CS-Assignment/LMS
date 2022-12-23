#ifndef __USER_H__
#define __USER_H__
#include "main.h"
#include "window/navigation.h"
#include "window/backstage.h"
#define USER_COMMON 0
#define USER_ADMIN  1
#define USER_COLTD  2

/* 用户类 */
class User{
    private:
    int _id;                    //用户名(ID,唯一)
    int _auth;                  //权限
    std::string _name;          //姓名
    std::string _passwd;        //密码
    int _balance;               //余额
    std::string _tel;           //联系方式
    std::string _address;       //地址

    public:
    //构造函数
    User(int id, std::string passwd, int auth){
        _id = id;
        _passwd = passwd;
        _name = "null";
        _auth = auth;
        _balance = 0;
        _tel = "null";
        _address = "null";
    }
    //完整构造
    User(int id,int auth,std::string name,
        std::string passwd,int balance,std::string tel,std::string addr){
        _id = id;
        _auth = auth;
        _name = name;
        _passwd = passwd;
        _balance = balance;
        _tel = tel;
        _address = addr;
    }
    int getID() const{                        //获取用户名
        return _id;
    }
    int getAuth() const{                      //获取权限
        return _auth;
    }
    std::string getName() const{              //获取姓名
        return _name;
    }
    void setName(std::string name){     //设置姓名
        _name = name;
    }
    void setPasswd(std::string passwd){ //设置密码
        _passwd = passwd;
    }
    std::string getPasswd() const{            //获取密码
        return _passwd;
    }
    void setBalance(int balance){       //设置余额
        _balance = balance;
    }
    int getBalance() const{                   //获取余额
        return _balance;
    }
    void setTel(std::string tel){       //设置联系方式
        _tel = tel;
    }
    std::string getTel() const{               //获取联系方式
        return _tel;
    }
    void setAddr(std::string addr){     //设置地址
        _address = addr;
    }
    std::string getAddr(){              //获取地址
        return _address;
    }

};

/* 用户管理器 */
class UserControl{
private:
    std::vector<User> _userList;                    //用户列表
    User* _curUser;                                 //当前用户
    //判别函数类型指针
    typedef bool (UserControl::*compare)(User&,void*);
    //遍历搜索(传入判别函数指针)
    void check_traverse(QTableWidget* dest,compare,void* input = nullptr);
    /* 判别函数 */
    bool check_by_userid(User&,void*);              //按用户名(ID)判别
    bool check_by_name(User&,void*);                //按姓名判别
    bool check_by_tel(User&,void*);                 //按联系方式判别
    bool check_by_addr(User&,void*);                //按地址判别
    void AddToTable(QTableWidget*,User&);           //添加到Widget表格(后台管理GUI)
public:
    UserControl();
    int Signin(int userid,std::string passwd,int auth = USER_COMMON);   //用户登录
    int Signup(int userid,std::string passwd);                          //用户注册
    void Signout();                                                     //用户登出
    int Recharge(int price);                                            //充值
    void SetPasswd(std::string passwd);                                 //设置密码
    void SetInfo(std::string name,std::string tel = "null",std::string addr = "null");  //设置用户信息
    void CheckUsers(UCheck,void* dest,int auth,void* input);                            //用户信息查询
    User* GetCurUser(){                     //获取当前用户
        return _curUser;
    }
    User* GetAdmin(){                       //获取物流公司
        return &_userList.at(0);
    }
    std::vector<User>* GetUserList(){       //获取用户列表
        return &_userList;
    }
};

#endif
