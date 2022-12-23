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
    QString _id;                    //用户名(ID,唯一)
    QString _name;          //姓名
    int _auth;
    QString _passwd;
    QString _balance;            //余额
    QString _tel;           //联系方式
    QString _address;       //地址

    public:
    //构造函数
    User(int id,int auth = (int)UserAuth::USER){
        _id = QString::number(id);
        _auth = auth;
        _name = "null";
        _balance = 0;
        _tel = "null";
        _address = "null";
    }
    //完整构造
    User(QStringList list){
        _id =  list[0];
        _auth = list[1].toInt();
        _name = list[2];
        _balance = list[3];
        _tel = list[4];
        _address = list[5];
    }
    int getAuth() const{
        return _auth;
    }
    QString getID() const{                        //获取用户名
        return _id;
    }
    QString getPasswd() const{
        return _passwd;
    }
    void setPasswd(QString p){
        _passwd = p;
    }
    QString getName() const{            //获取姓名
        return _name;
    }
    void setName(QString name){         //设置姓名
        _name = name;
    }
    void setBalance(QString balance){   //设置余额
        _balance = balance;
    }
    QString getBalance() const{         //获取余额
        return _balance;
    }
    void setTel(QString tel){           //设置联系方式
        _tel = tel;
    }
    QString getTel() const{             //获取联系方式
        return _tel;
    }
    void setAddr(QString addr){         //设置地址
        _address = addr;
    }
    QString getAddr() const{            //获取地址
        return _address;
    }

};

enum class USER_RECV:int{
    ID,
    AUTH,
    NAME,
    BALANCE,
    TEL,
    ADDRESS,
};

#endif
