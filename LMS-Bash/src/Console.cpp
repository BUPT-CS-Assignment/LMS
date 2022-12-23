#include <console.h>
#include <user.h>
#include <packet.h>
using namespace std;

int Console::GetOption(__Option__ MODE,bool showhead){
    if(showhead) print_header(MODE);
    switch(MODE){
        case MAIN_PANEL:
            if(showhead) print_sign();
            return read_in(0, 3);
        case USER_PANEL:
            if(showhead) print_user_panel();
            return read_in(0,5);
        case USER_PANEL_HELP:
            print_user_panel();
            return 0;
        case USER_SET_PANEL:
            if(showhead) print_user_set_panel();
            return read_in(0,6);
        case CHECK_PANEL:
            if(showhead) print_check_panel();
            return read_in(0,3);
    }
    return 0;
}

void Console::print_header(__Option__ MODE){
    switch(MODE){
        case MAIN_PANEL:
            cout << BOLDBLUE << "+-------------------------------------------+" << endl;
            cout << BOLDBLUE << "|                  START                    |" << endl;
            cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl;
            break;
        case USER_PANEL: case USER_PANEL_HELP: 
            cout << BOLDBLUE << "+-------------------------------------------+" << endl;
            cout << BOLDBLUE << "|                   OPTION                  |" << endl;
            cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl;
            break;
        case USER_SET_PANEL:
            cout << BOLDBLUE << "+-------------------------------------------+" << endl;
            cout << BOLDBLUE << "|                USER OPTION                |" << endl;
            cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl;
            break;
        case CHECK_PANEL:
            cout << BOLDBLUE << "+-------------------------------------------+" << endl;
            cout << BOLDBLUE << "|                CHECK OPTION               |" << endl;
            cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl;
            break;
        case USER_INFO :
            cout << BOLDYELLOW <<"+===========+=============+============+==============+=====================+" <<endl;
            cout << BOLDYELLOW <<"| ID        | Name        | Balance    | Contact      | Address             |" <<endl;
            cout << BOLDYELLOW <<"+===========+=============+============+==============+=====================+" <<endl;
            break;
        case PACKET_INFO :
            cout << BOLDYELLOW <<"+=========+========+===========+===========+===================+===================+" <<endl;
            cout << BOLDYELLOW <<"| ID      | Status | From      | Dest      | Send Time         | Recv Time         |" <<endl;
            cout << BOLDYELLOW <<"+=========+========+===========+===========+===================+===================+" <<endl;
    }
}

void Console::print_sign(){
    cout << BOLDBLUE << "| 0 |     Sign In     | 2 |    Store Data   |" << endl;
    cout << BOLDBLUE << "| 1 |     Sign Up     | 3 |      Exit       |" << endl;
    cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl << endl;
}

void Console::print_user_panel(){
    cout << BOLDBLUE << "| 0 |   Send Packet   | 3 |   Check Sends   |" << endl;
    cout << BOLDBLUE << "| 1 |   Recv Packet   | 4 |   Check Recvs   |" << endl;
    cout << BOLDBLUE << "| 2 |    User Info    | 5 |    Sign Out     |" << endl; 
    cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl;
}

void Console::print_check_panel(){
    cout << BOLDBLUE << "| 0 |       All       | 2 |    User ID      |" << endl;
    cout << BOLDBLUE << "| 1 |      Time       | 3 |    Packet ID    |" << endl;
    cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl;
}

void Console::print_user_set_panel(){
    cout << BOLDBLUE << "| 0 |    Check All    | 4 |  Change Name    |" << endl;
    cout << BOLDBLUE << "| 1 |  Check Balance  | 5 |  Change Contact |" << endl;
    cout << BOLDBLUE << "| 2 |    Recharge     | 6 |  Change Address |" << endl; 
    cout << BOLDBLUE << "| 3 |  Change Passwd  |   |                 |" << endl; 
    cout << BOLDBLUE << "+---+-----------------+---+-----------------+" << endl;
}

int Console::read_in(int below, int above){
    int num = GetNum();
    if(num < below || num > above){
        cout << BOLDRED << "[ Error ] Option '" << num << "' Undefined" << endl;
        return read_in(below, above);
    }
    return num;
}

int Console::GetNum(string msg){
    int num;
    cout << BOLDWHITE << "( " << msg << " )" << " >>> " << CYAN;
    cin >> num;
    if(!cin || cin.get() != '\n'){
        LogErr("Type 'Number' Mismatch");
        cin.clear();
        //cin.sync();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        return GetNum(msg);
    }
    return num;
}

string Console::GetStr(string msg){
    string str;
    cout << BOLDWHITE << "( " << msg << " )" << " >>> " << CYAN;
    cin >> str;
    cin.clear();
    return str;
}

void Console::LogErr(string err){
    cout << BOLDRED << "[ Error ] " << err << endl;
}

void Console::LogMsg(string msg){
    cout << BOLDGREEN << "[ Msg ] " << msg << endl;
}

string Console::GetTime(){
    time_t t;
    time(&t);
    struct tm p=*localtime(&t);
    localtime_r(&t,&p);
    char str[20];
    sprintf(str,"%4.4d/%2.2d/%2.2d-%2.2d:%2.2d",
        p.tm_year+1900, p.tm_mon+1,p.tm_mday,p.tm_hour,p.tm_min);
    return string(str);
}

void Console::PrintUserInfo(User* user,bool header,bool bottom){
    if(header) print_header(USER_INFO);
    if(user != nullptr){
        cout << BOLDYELLOW <<"| "        
            << std::left << setw(10) << user->getID()<<"| "
            << std::left << setw(12) << user->getName()<<"| "
            << std::left << setw(11) << user->getBalance()<<"| "
            << std::left << setw(13) <<user->getTel() << "| "
            << std::left << setw(20) <<user->getAddr() << "| "
            << endl;
    }
    if(bottom){
        cout << BOLDYELLOW <<"+===========+=============+============+==============+=====================+" <<endl;
    }
}

void Console::PrinfPacketInfo(Packet* packet,bool header,bool bottom){
    if(header) print_header(PACKET_INFO);
    if(packet != nullptr){
        cout << BOLDYELLOW <<"| "
            << std::left << setw(8) << packet->getID()<<"| "
            << std::left << setw(7) << (packet->getStatus() == 0?"Recv.":"Pend.")<<"| " 
            << std::left << setw(10) << packet->getFromUser()<<"| "
            << std::left << setw(10) << packet->getDestUser()<<"| "
            << std::left << setw(18) << packet->getSendTime()<<"| "
            << std::left << setw(18) << packet->getRecvTime()<<"| "
            << endl;
    }
    if(bottom){
        cout << BOLDYELLOW <<"+=========+========+===========+===========+===================+===================+" <<endl;
    }
}

void Console::PrintPacketEmpty(){
    cout << BOLDYELLOW <<"|"
        << std::right << setw(48) << "No Packet Found"
        << setw(35) <<"|"
        << endl;
}
