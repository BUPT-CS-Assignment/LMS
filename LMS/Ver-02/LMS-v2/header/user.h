#ifndef __USER_H__
#define __USER_H__
#include "main.h"
#include "window/navigation.h"
#include "window/backstage.h"
#include "storage.h"
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
    double _balance;            //余额
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
        std::string passwd,double balance,std::string tel,std::string addr){
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
    void setBalance(double balance){       //设置余额
        _balance = balance;
    }
    double getBalance() const{                   //获取余额
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
    std::string getAddr() const{              //获取地址
        return _address;
    }

};

/* 用户管理器 */
class UserControl{
private:
    Storager st;
    std::vector<User*> _userList;                   //用户列表
    std::vector<User*> _courierList;                //快递员列表
    //字段匹配 
    bool user_matching(const User*,UserMatchField,void* input) const;
public:
    //用户登录
    User* Signin(int userid,std::string passwd,int auth = (int)UserAuth::USER) const;
    void AddUser(User*);    //添加用户
    int DelUser(int userid);    //删除用户
    //用户搜搜
    std::vector<User*> UserSearch(UserMatchField*,void**,int num) const;
    User* UserLocate(int id) const;
    //获取管理员指针
    User* GetRoot();
    //获取快递员列表
    std::vector<User*>* getCourierList(){
        return &_courierList;
    }
    void ReadIn();      //文件读入
    void WriteBack();   //文件写入
};

#endif
