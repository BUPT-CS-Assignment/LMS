#include "header/Basic.h"
using namespace std;

/* 用户登录 */
User* UserControl::Signin(int userid,string passwd,int auth) const{
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        if((*itr)->getID() == userid){
            //字段匹配
            if((*itr)->getAuth() >= auth && (*itr)->getPasswd() == passwd){
                return (*itr);
            }
        }
        itr ++;
    }
    return nullptr;
}

/* 添加用户 */
void UserControl::AddUser(User* u){
    if(u == nullptr)    return;
    _userList.push_back(u);
    //快递员检测
    if(u->getAuth() == (int)UserAuth::COURIER){
        _courierList.push_back(u);
        //快速排序
        sort(_courierList.begin(),_courierList.end(),[](User* u1,User* u2)-> bool{return u1->getID() < u2->getID();});
    }
    //快速排序
    sort(_userList.begin(),_userList.end(),[](User* u1,User* u2)-> bool{return u1->getID() < u2->getID();});

}

/* 删除用户 */
int UserControl::DelUser(int userid){
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        if((*itr)->getID() == userid){
            //快递员检测
            if((*itr)->getAuth() == (int)UserAuth::COURIER){
                auto itrr = _courierList.begin();
                while(itrr != _courierList.end()){
                    if((*itrr)->getID() == userid){
                        //删除快递员
                        _courierList.erase(itrr);
                    }
                    itrr++;
                }
            }
            delete (*itr);
            _userList.erase(itr);   //删除用户
            return 0;
        }
        itr ++;
    }
    return -1;
}

User* UserControl::GetRoot(){
    return _userList.at(0);
}

/* 文件读入 */
void UserControl::ReadIn(){
    st.ReadUserList(&_userList,&_courierList);
    sort(_userList.begin(),_userList.end(),[](User* u1,User* u2)-> bool{return u1->getID() < u2->getID();});
}

/* 文件写入 */
void UserControl::WriteBack(){
    st.StoreUserList(&_userList);
}

/* 字段匹配 */
bool UserControl::user_matching(const User* u,UserMatchField field,void* input) const{
    if(u == nullptr) return false;
    switch(field){
        case UserMatchField::ID:
            return u->getID() == VOID_TO_INT input;
        case UserMatchField::AUTH:
            return u->getAuth() == VOID_TO_INT input;
        case UserMatchField::BALANCE:
            return u->getBalance() == VOID_TO_INT input;
        case UserMatchField::PASSWD:
            return u->getPasswd() == VOID_TO_STR input;
        case UserMatchField::NAME:
            return u->getName().compare(0,((string*)input)->length(),VOID_TO_STR input) == 0;
        case UserMatchField::TEL:
            return u->getTel().compare(0,((string*)input)->length(),VOID_TO_STR input) == 0;
        case UserMatchField::ADDRESS:
            return u->getAddr().compare(0,((string*)input)->length(),VOID_TO_STR input) == 0;
    }
    return false;
}

/* 用户搜索 */
vector<User*> UserControl::UserSearch(UserMatchField* farray,void** inputs,int num) const{
    if(num == 0) return _userList;
    vector<User*> list;
    //遍历搜索
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        bool flag = true;
        //遍历字段
        for(int i = 0; i < num && flag; i++){
            flag = user_matching((*itr),farray[i],inputs[i]);
        }
        if(flag){
            list.push_back((*itr));
        }
        itr++;
    }
    //快速排序
    sort(list.begin(),list.end(),[](User* u1,User* u2)-> bool{return u1->getID() < u2->getID();});
    return list;
}

//单个用户定位
User* UserControl::UserLocate(int id) const{
    auto itr = _userList.begin();
    //遍历搜索
    while(itr != _userList.end()){
        //字段匹配
        if(user_matching((*itr),UserMatchField::ID,&id)){
            return *itr;
        }
        itr++;
    }
    return nullptr;
}

