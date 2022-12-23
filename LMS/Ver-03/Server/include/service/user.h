#ifndef __USER_H__
#define __USER_H__
#include "../sys.h"
#include "../server/console.h"
#include "storage.h"
#define USER_COMMON 0
#define USER_ADMIN  1
#define USER_COLTD  2

/* 用户类 */
class User{
    private:
    bool _signin;               //登录状态
    int _id;                    //用户名(ID,唯一)
    int _auth;                  //权限
    std::string _name;          //姓名
    std::string _passwd;        //密码
    double _balance;            //余额
    std::string _tel;           //联系方式
    std::string _address;       //地址

    public:
    //构造函数
    User(int id, std::string passwd, int auth){
        _signin = false;
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
        std::string passwd,double balance,std::string tel,std::string addr){
        _signin = false;
        _id = id;
        _auth = auth;
        _name = name;
        _passwd = passwd;
        _balance = balance;
        _tel = tel;
        _address = addr;
    }
    int getID() const{                  //获取用户名
        return _id;
    }
    int getAuth() const{                //获取权限
        return _auth;
    }
    std::string getName() const{        //获取姓名
        return _name;
    }
    void setName(std::string name){     //设置姓名
        _name = name;
    }
    void setPasswd(std::string passwd){ //设置密码
        _passwd = passwd;
    }
    std::string getPasswd() const{      //获取密码
        return _passwd;
    }
    void setBalance(double balance){    //设置余额
        _balance = balance;
    }
    double getBalance() const{          //获取余额
        return _balance;
    }
    void setTel(std::string tel){       //设置联系方式
        _tel = tel;
    }
    std::string getTel() const{         //获取联系方式
        return _tel;
    }
    void setAddr(std::string addr){     //设置地址
        _address = addr;
    }
    std::string getAddr() const{        //获取地址
        return _address;
    }
    bool getStatus() const{             //获取登录状态 
        return _signin;
    } 
    void setStatus(bool t){             //设置登录状态
        _signin = t;
    }
    std::string Format() const;         //用户信息格式化

};

/* 用户管理器 */
class UserControl{
private:
    LOCK _lock;                         //数据锁
    Storager st;                        //存储器
    Console sc;                         //控制台工具
    std::vector<User*> _userList;       //用户列表
    std::vector<User*> _courierList;    //快递员列表
    //字段匹配
    bool user_matching(const User*,UserMatchField,std::string input) const;
public:
    UserControl():_userList(),_courierList(){
        _lock = LOCK::FREE;
    }
    LOCK* getLock(){                        //获取锁状态
        return &_lock;
    }
    void setLock(LOCK lv = LOCK::FREE){     //设置锁状态
        _lock = lv;
    }
    User* Signin(int userid,std::string passwd,int auth = (int)UserAuth::USER); //登录
    int AddUser(User*);         //添加用户
    int DelUser(int userid);    //删除用户
    std::vector<User*> UserSearch(UserMatchField*,std::string*,int num);    //用户搜索
    User* UserLocate(int id);   //单个用户定位
    User* GetRoot();            //获取管理员指针
    std::vector<User*>* getCourierList(){   //获取快递员列表指针
        return &_courierList;
    }
    void ReadIn();              //文件读入
    int  WriteBack();           //文件写入
};

#endif
