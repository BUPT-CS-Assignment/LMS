#include<user.h>
#include <console.h>
using namespace std;

UserControl::UserControl():_userList(){
    _curUser = nullptr;
}

int UserControl::Sign(){
    Console sc;
    int num = sc.GetOption(MAIN_PANEL);     // 获取操作码
    while(true){
        switch(num){
            /* 登录 */
            case PROGRAM_SIGN_IN:
                if(!sign_in()){
                    sc.LogErr("Wrong ID or Passwd");    break;
                }
                else{
                    sc.LogMsg("Signin Success");    return 1;
                }

            /* 注册 */
            case PROGRAM_SIGN_UP:
                if(!sign_up()){
                    sc.LogErr("Signup Failed");    break;
                }
                else{
                    sc.LogMsg("Signup Success");    return 1;
                }
            /* 保存数据 */
            case PROGRAM_SAVE_DATA: return 2;
            /* 退出程序 */
            case PROGRAM_EXIT: return 3;
            default:break;
        }
        num = sc.GetOption(MAIN_PANEL, false);
    }

}

int UserControl::sign_in(){
    Console sc;
    /* 获取用户ID与密码 */
    sc.LogMsg("===== Signin =====");
    int id = sc.GetNum("userid");
    string passwd = sc.GetStr("passwd");

    /* 遍历查询 */
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        if((*itr).getID() == id){
            if((*itr).getPasswd() == passwd){
                _curUser = &(*itr);
                return 1;
            }
            else{
                return 0;
            }
        }
        itr ++;
    }
    return 0;
}

int UserControl::sign_up(){
    Console sc;
    sc.LogMsg("===== Signup =====");
    int id = sc.GetNum("userid");
    if(id < 1000){
        sc.LogErr("ID Invalid");
        return 0;
    }

    /* 检测ID重复 */
    auto itr = _userList.begin();
    while(itr != _userList.end()){
        if((*itr).getID() == id){
            sc.LogErr("ID Existed");
            return 0;
        }
        itr ++;
    }
    /* 密码确认 */
    string passwd="", passwd_cfm;
    do{ 
        if(passwd != "")    sc.LogErr("Passwd Mismatch");
        passwd = sc.GetStr("passwd");
        passwd_cfm = sc.GetStr("passwd confirm");
    } while(passwd != passwd_cfm);

    /* 其他信息 */
    string name = sc.GetStr("name");
    string tel = sc.GetStr("contact");
    string addr = sc.GetStr("address");

    /* 添加用户 */
    User user(id,USER_COMMON,name,passwd,0,tel,addr);
    _userList.push_back(user);
    return 1;
}

void UserControl::sign_out(){
    _curUser = nullptr;
}

void UserControl::UserOption(USet mode){
    Console sc;
    if(mode == USet::CHECK_ALL){
        return check_users();
    }else if(mode == USet::CHECK_BALANCE){
        sc.LogMsg("Current Balance : "+to_string(_curUser->getBalance()));
    }else if(mode == USet::RECHARGE){
        sc.LogMsg("===== Recharge =====");
        int charge = sc.GetNum("charge");
        int old = _curUser->getBalance();
        if(charge <= 0 || old+charge <= 0){
            sc.LogErr("Charge Num Invalid");
        }else{
            _curUser->setBalance(old + charge);
            sc.LogMsg("Charge Success");
            sc.LogMsg("Current Balance : "+to_string(_curUser->getBalance()));
        }
    }else if(mode == USet::CHANGE_PASSWD){
        return change_passwd();
    }else if(mode == USet::CHANGE_NAME){
        _curUser->setName(sc.GetStr("new name"));
        sc.LogMsg("Change Name Success");
    }else if(mode == USet::CHANGE_CONTACT){
        _curUser->setTel(sc.GetStr("new contact"));
        sc.LogMsg("Change Contact Success");
    }else if(mode == USet::CHANGE_ADDRESS){
        _curUser->setAddr(sc.GetStr("new address"));
        sc.LogMsg("Change Address Success");
    }
}

void UserControl::change_passwd(){
    Console sc;
    string passwd="", passwd_cfm;
    do{ 
        if(passwd != "")    sc.LogErr("Passwd Mismatch");
        passwd = sc.GetStr("new passwd");
        passwd_cfm = sc.GetStr("new passwd confirm");
    } while(passwd != passwd_cfm);
    sc.LogMsg("Change Passwd Success");
}

void UserControl::check_users(){
    Console sc;
    
    /* 非管理员查看个人信息 */
    if(_curUser->getAuth() < USER_ADMIN){
        return sc.PrintUserInfo(_curUser,true,true);
    }

    /* 管理员查看所有用户 */
    auto itr = _userList.begin();
    sc.PrintUserInfo(nullptr,true);
    while(itr != _userList.end()){
        sc.PrintUserInfo(&(*itr));
        itr++;
    }
    sc.PrintUserInfo(nullptr,false,true);
}
