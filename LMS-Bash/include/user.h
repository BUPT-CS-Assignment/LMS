#ifndef __USER_H__
#define __USER_H__
#include <main.h>
#define USER_COMMON 0
#define USER_ADMIN  1
#define USER_COLTD  2

enum class USet:int{
    CHECK_ALL,
    CHECK_BALANCE,
    RECHARGE,
    CHANGE_PASSWD,
    CHANGE_NAME,
    CHANGE_CONTACT,
    CHANGE_ADDRESS,
};

class User{
    private:
    int _id;
    int _auth;
    std::string _name;
    std::string _passwd;
    int _balance;
    std::string _tel;
    std::string _address;

    public:
    User(int id, std::string passwd, int auth){
        _id = id;
        _passwd = passwd;
        _name = "null";
        _auth = auth;
        _balance = 0;
        _tel = "null";
        _address = "null";
    }
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
    int getID(){
        return _id;
    }
    int getAuth(){
        return _auth;
    }
    std::string getName(){
        return _name;
    }
    void setName(std::string name){
        _name = name;
    }
    void setPasswd(std::string passwd){
        _passwd = passwd;
    }
    std::string getPasswd(){
        return _passwd;
    }
    void setBalance(int balance){
        _balance = balance;
    }
    int getBalance(){
        return _balance;
    }
    void setTel(std::string tel){
        _tel = tel;
    }
    std::string getTel(){
        return _tel;
    }
    void setAddr(std::string addr){
        _address = addr;
    }
    std::string getAddr(){
        return _address;
    }

};

class UserControl{
private:
    std::vector<User> _userList;
    User* _curUser;
    int sign_in();
    int sign_up();
    int remove_user();
    void check_users();
    void change_passwd();
    void recharge();
public:
    UserControl();
    int Sign();
    void sign_out();
    void CheckUsers();
    User* GetCurUser(){
        return _curUser;
    }
    User* GetAdmin(){
        return &_userList.at(0);
    }
    int AddUser(User&);
    std::vector<User>* GetUserList(){
        return &_userList;
    }
    void UserOption(USet mode);

};

#endif