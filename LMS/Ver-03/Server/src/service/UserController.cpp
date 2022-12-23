#include "basic.h"
using namespace std;

/* 用户信息格式化 */
string User::Format() const{
    Console sc;
    string res = "";
    //逗号分隔
    res = to_string(_id) + ","
        + to_string(_auth) + ","
        + _name + ","
        + sc.dtos(_balance) + ","
        + _tel + ","
        + _address;
    return res;
}

/* 登录 */
User* UserControl::Signin(int userid,string passwd,int auth){
    if(!sc.wait(&_lock))    return nullptr;
    setLock(LOCK::RUN);
    //遍历搜索
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        if((*itr)->getID() == userid){
            //权限 & 密码匹配
            if((*itr)->getAuth() >= auth && (*itr)->getPasswd() == passwd){
                setLock();
                return (*itr);
            }
        }
        setLock(LOCK::RUN);
        itr ++;
    }
    setLock();
    return nullptr;
}

/* 添加用户 */
int UserControl::AddUser(User* u){
    if(!sc.wait(&_lock))    return TIME_OUT;
    if(u == nullptr)        return NULL_PTR;

    setLock(LOCK::RUN);
    _userList.push_back(u);
    //快递员判断
    if(u->getAuth() == (int)UserAuth::COURIER){
        _courierList.push_back(u);
        //快速排序
        sort(_courierList.begin(),_courierList.end(),[](User* u1,User* u2)-> bool{return u1->getID() < u2->getID();});
    }
    //快速排序
    sort(_userList.begin(),_userList.end(),[](User* u1,User* u2)-> bool{return u1->getID() < u2->getID();});
    setLock();
    return SUCCESS;
}

/* 删除用户 */
int UserControl::DelUser(int userid){
    if(!sc.wait(&_lock,LOCK::FREE)) return TIME_OUT;
    setLock(LOCK::BLOCK);
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        if((*itr)->getID() == userid){
            //登录状态检测
            if((*itr)->getStatus()){
                setLock();
                return SYSTEM_ERR;
            }
            (*itr)->setPasswd("0 0");
            //快递员检测
            if((*itr)->getAuth() == (int)UserAuth::COURIER){
                auto itrr = _courierList.begin();
                while(itrr != _courierList.end()){
                    if((*itrr)->getID() == userid){
                        _courierList.erase(itrr);   //清除快递员列表中信息
                        break;
                    }
                    itrr++;
                }
            }
            User* temp = (*itr);
            _userList.erase(itr);   //清楚用户列表中信息
            delete temp;
            setLock();
            return SUCCESS;
        }
        itr ++;
    }
    setLock();
    return NOT_FOUND;
}

/* 获取管理员指针 */
User* UserControl::GetRoot(){
    return _userList.at(0);
}

/* 用户信息文件读入 */
void UserControl::ReadIn(){
    int res;
    res = st.ReadUserList(&_userList,&_courierList);    //文件读取
    sc.log(true,BOLDBLUE"USER Number : %d\n",res);
    //快速排序
    sort(_userList.begin(),_userList.end(),
        [](User* u1,User* u2)-> bool{
            return u1->getID() < u2->getID();
    });
}

/* 用户信息写入 */
int UserControl::WriteBack(){
    if(!sc.wait(&_lock,LOCK::FREE,10))  return TIME_OUT;
    setLock(LOCK::BLOCK);
    int res;
    res = st.StoreUserList(&_userList); //文件写入
    if(res != SUCCESS){
        sc.err(RetValText[res]);
    }
    setLock();
    return res;
}

/* 字段匹配 */
bool UserControl::user_matching(const User* u,UserMatchField field,string input) const{
    if(u == nullptr) return false;  //空指针检测
    //字段匹配
    switch(field){
        case UserMatchField::ID:
            return u->getID() == stoi(input);
        case UserMatchField::AUTH:
            return u->getAuth() == stoi(input);
        case UserMatchField::BALANCE:
            return u->getBalance() == stod(input);
        case UserMatchField::PASSWD:
            return u->getPasswd() == input;
        ////部分匹配支持
        case UserMatchField::NAME:
            return u->getName().compare(0,input.length(),input) == 0;
        case UserMatchField::TEL:
            return u->getTel().compare(0,input.length(),input) == 0;
        case UserMatchField::ADDRESS:
            return u->getAddr().compare(0,input.length(),input) == 0;
    }
    return false;
}

/* 用户搜索 */
vector<User*> UserControl::UserSearch(UserMatchField* farray,string* inputs,int num){
    if(num == 0) return _userList;
    vector<User*> list;
    if(!sc.wait(&_lock)) return list;

    setLock(LOCK::RUN);
    //遍历搜索
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        bool flag = true;
        //遍历字段
        for(int i = 0; i < num && flag; i++){
            setLock(LOCK::RUN);
            flag = user_matching((*itr),farray[i],inputs[i]);
        }
        if(flag){
            list.push_back((*itr));
        }
        itr++;
    }
    setLock();
    //快速排序
    sort(list.begin(),list.end(),[](User* u1,User* u2)-> bool{return u1->getID() < u2->getID();});
    return list;
}

/* 单个用户定位 */
User* UserControl::UserLocate(int id){
    if(!sc.wait(&_lock)) return nullptr;
    setLock(LOCK::RUN);
    //遍历搜索
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        //用户名字段匹配
        if(user_matching((*itr),UserMatchField::ID,to_string(id))){
            setLock();
            return (*itr);
        }
        setLock(LOCK::RUN);
        itr++;
    }
    setLock();
    return nullptr;
}

