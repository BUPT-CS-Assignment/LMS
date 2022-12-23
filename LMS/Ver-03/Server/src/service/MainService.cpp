#include "basic.h"
using namespace std;

Service::Service(Server* server):_param(), _value(){
    //空指针检测
    _CURUSER = nullptr;
    if(server == nullptr){
        sc.err("No Server Connect");
        exit(-1);
    }
    _BACKEND = server->getBackEnd();    //连接数据管理器
    _ans = "";                          //初始化返回数据
}

Service::~Service(){
    SignOut();
}

/* 清空请求数据 */
void Service::Clear(){
    _param.clear();
    _value.clear();
    _ans = "";
}

/* 登出 */
void Service::SignOut(){
    if(_CURUSER != nullptr) _CURUSER->setStatus(false); //登录状态设置
    _CURUSER = nullptr;                                 //重置当前用户指针
}

/* 请求解析 */
int Service::Parse(std::string request){
    if(request.length() == 0) return NULL_PTR;
    char function = request[0]; //请求类型
    _func = (FUNCTION)function;
    if(function < (char)FUNCTION::SIGN_IN || function > (char)FUNCTION::STORE_DATA){
        return NOT_FOUND;
    }
    //三段分割
    int pos1 = request.find('|');
    int pos2 = request.find('|', pos1 + 1);
    if(pos1 == string::npos || pos2 == string::npos){
        return SYSTEM_ERR;
    }
    Clear();
    string param = request.substr(pos1 + 1, pos2 - pos1 - 1);
    string value = request.substr(pos2 + 1);
    //内容分割
    _param = sc.Split(param, ",");
    _value = sc.Split(value, ",");
    return SUCCESS;
}

//请求执行
int Service::Exec(){
    switch(_func){
        case FUNCTION::SIGN_IN:         return exec_sign_in();          //登录
        case FUNCTION::SIGN_UP:         return exec_sign_up();          //注册
        case FUNCTION::SIGN_OUT:        return exec_sign_out();         //登出
            //
        case FUNCTION::ADD_USER:        return exec_add_user();         //添加用户
        case FUNCTION::DEL_USER:        return exec_del_user();         //删除用户
        case FUNCTION::SET_USER:        return exec_set_user();         //设置用户信息
        case FUNCTION::RECHARGE:        return exec_recharge();         //充值 
        case FUNCTION::CHECK_USER:      return exec_check_user();       //用户搜索
            //
        case FUNCTION::SEND_PACKET:     return exec_send_packet();      //发送包裹
        case FUNCTION::RECV_PACKET:     return exec_recv_packet();      //签收包裹
        case FUNCTION::COLLECT_PACKET:  return exec_collect_packet();   //揽收包裹
        case FUNCTION::ALLOC_COURIER:   return exec_alloc_courier();    //分配快递员
        case FUNCTION::CHECK_PACKET:    return exec_check_packet();     //包裹搜索
            //
        case FUNCTION::ALLOC_SWITCH:    return exec_alloc_switch();     //切换自动分配
        case FUNCTION::AUTO_ALLOC:      return exec_auto_alloc();       //自动分配
        case FUNCTION::STORE_DATA:      return exec_store_data();       //数据存储
        default:                        return NOT_FOUND;
    }
}

/* 返回信息格式化 */
string Service::Format(int res){
    //返回值代码+返回数据
    string ret = BACK_MSG[res] + "|";
    ret += _ans;
    Clear();    //清空请求信息
    return ret;
}

/* 登录 */
int Service::exec_sign_in(){
    //请求内容解析判断
    if(_CURUSER != nullptr && _CURUSER->getStatus())   return SYSTEM_ERR;
    if(_value.size() < 3){
        return SYSTEM_ERR;
    }
    int id = stoi(_value[0]);
    int auth = stoi(_value[2]);
    _CURUSER = _BACKEND->Signin(id, _value[1], auth);

    if(_CURUSER == nullptr) return NOT_FOUND;
    _ans = _CURUSER->Format();

    return SUCCESS;
}

/* 注册 */
int Service::exec_sign_up(){
    int id = stoi(_value[0]);
    return _BACKEND->Signup(id, _value[1]);
}

/* 登出 */
int Service::exec_sign_out(){
    SignOut();
    return SUCCESS;
}

/* 添加用户 */
int Service::exec_add_user(){
    //请求参数解析判断
    if(_value.size() < 4){
        return SYSTEM_ERR;
    }
    int id = stoi(_value[0]);
    int auth = stoi(_value[2]);
    double balance = stod(_value[3]);
    User* u = new User(id, _value[1], auth);
    u->setBalance(balance);
    return _BACKEND->AddUser(u);
}

/* 删除用户 */
int Service::exec_del_user(){
    int id = stoi(_value[0]);
    return _BACKEND->DelUser(id);
}

/* 设置用户信息 */
int Service::exec_set_user(){
    int length = _param.size();
    UserMatchField f[length];
    string str[length];
    for(int i = 0; i < length; i++){
        f[i] = (UserMatchField)stoi(_param[i]);
        str[i] = _value[i];
    }
    return _BACKEND->SetInfo(_CURUSER, f, str, length);
}

/* 充值 */
int Service::exec_recharge(){
    int num = stoi(_value[0]);
    int ret = _BACKEND->Recharge(_CURUSER, num);
    _ans = sc.dtos(_CURUSER->getBalance());
    return ret;
}

/* 用户搜索 */
int Service::exec_check_user(){
    int length = _param.size();
    vector<User*> list;
    if((UserMatchField)stoi(_param[0]) == UserMatchField::ALL){
        length = 0;
        list = _BACKEND->UserSearch(nullptr, nullptr, 0);
    }
    else if((UserMatchField)(stoi(_param[0])) == UserMatchField::COURIER){
        list = *_BACKEND->COURIERS();
    }
    else{
        UserMatchField f[length];
        string str[length];
        for(int i = 0; i < length; i++){
            f[i] = (UserMatchField)stoi(_param[i]);
            str[i] = _value[i];
        }
        list = _BACKEND->UserSearch(f, str, length);
    }
    _ans = "";
    for(int i = 0; i < list.size(); i++){
        _ans += list[i]->Format() + ";";
    }
    return SUCCESS;
}

/* 发送包裹 */
int Service::exec_send_packet(){
    //请求参数解析判断
    if(_value.size() < 4){
        return SYSTEM_ERR;
    }
    int type = stoi(_value[0]);
    int dest = stoi(_value[1]);
    double count = stod(_value[2]);
    int ret = _BACKEND->SendPacket(_CURUSER, type, dest, count, _value[3]);
    if(ret == SUCCESS){
        _ans = sc.dtos(_CURUSER->getBalance());
    }
    return ret;
}

/* 签收包裹 */
int Service::exec_recv_packet(){
    PacketBase* p = _BACKEND->PacketSearch(_value[0]);
    int ret = _BACKEND->RecvPacket(p);
    if(ret == SUCCESS)  _ans = p->getRecvTime();
    return ret;
}

/* 揽收包裹 */
int Service::exec_collect_packet(){
    int ret = _BACKEND->CollectPacket(_CURUSER, _value[0]);
    if(ret == SUCCESS)  _ans = sc.dtos(_CURUSER->getBalance());
    return ret;
}

/* 分配快递员 */
int Service::exec_alloc_courier(){
    int userid = stoi(_value[1]);
    return _BACKEND->AllocateCourier(_value[0], userid);
}

/* 包裹搜索 */
int Service::exec_check_packet(){
    int length = _param.size();
    //请求参数解析
    vector<PacketBase*> list;
    PacketMatchField f[length];
    string str[length];
    if((PacketMatchField)stoi(_param[0]) == PacketMatchField::ALL){
        length = 0;
    }
    for(int i = 0; i < length; i++){
        f[i] = (PacketMatchField)stoi(_param[i]);
        str[i] = _value[i];
    }
    list = _BACKEND->PacketSearch(f, str, length);
    _ans = "";
    for(int i = 0; i < list.size(); i++){
        _ans += list[i]->Format() + ";";
    }
    return SUCCESS;
}

/* 自动分配 */
int Service::exec_auto_alloc(){
    int ret;
    for(int i = 0; i < _value.size();  i++){
        ret = _BACKEND->RandomAlloc(_value[i]);
        if(ret != SUCCESS){
            return ret;
        }
    }
    return SUCCESS;
}

/* 设置自动分配状态 */
int Service::exec_alloc_switch(){
    if(_param[0] == "0"){
        bool res = _BACKEND->getAllocStatus();
        if(res) _ans = "T";
        else    _ans = "F";
        return SUCCESS;
    }
    else if(_param[0] == "1"){
        if(_value[0] == "T"){
            _BACKEND->setAllocStatus(true);
        }
        else if(_value[0] == "F"){
            _BACKEND->setAllocStatus(false);
        }
        else{
            return NOT_FOUND;
        }
        return SUCCESS;
    }
    return NOT_FOUND;
}

/* 数据存储 */
int Service::exec_store_data(){
    return _BACKEND->StoreData();
}