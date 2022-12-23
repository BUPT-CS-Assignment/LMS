/********************************************************************************
** Form generated from reading UI file 'navigation.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATION_H
#define UI_NAVIGATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Navigation
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_send;
    QLabel *label_3;
    QWidget *widget_3;
    QPushButton *send_packet;
    QLabel *label_5;
    QLabel *send_price;
    QLabel *label_17;
    QWidget *widget_4;
    QLabel *send_from;
    QLineEdit *send_dest;
    QLabel *send_from_addr;
    QWidget *widget_5;
    QLabel *label_15;
    QLineEdit *packet_describe;
    QWidget *widget_8;
    QLabel *label_4;
    QLabel *label_18;
    QSpinBox *packet_count;
    QComboBox *packet_type;
    QLabel *label_23;
    QLabel *packet_type_text;
    QDoubleSpinBox *packet_count_double;
    QWidget *page_check;
    QTabWidget *tabWidget;
    QWidget *send;
    QListWidget *send_list;
    QWidget *recv;
    QListWidget *recv_list;
    QWidget *recv_ed;
    QListWidget *pend_list;
    QLabel *label;
    QPushButton *refresh;
    QWidget *widget_2;
    QLineEdit *search_input;
    QPushButton *search;
    QComboBox *search_choose;
    QWidget *page_user;
    QLabel *userid;
    QLabel *label_9;
    QLabel *user_funds;
    QPushButton *recharge;
    QWidget *dia_change_info;
    QPushButton *change_info_click;
    QPushButton *change_info_cancel_click;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *change_name_input;
    QLineEdit *change_tel_input;
    QLineEdit *change_addr_input;
    QWidget *dia_change_passwd;
    QPushButton *change_passwd_click;
    QPushButton *change_paaswd_cancel_click;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *change_passwd_input;
    QLineEdit *change_passwd_cfm_input;
    QLabel *label_16;
    QLabel *userid_2;
    QWidget *widget_6;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *user_name;
    QLabel *user_tel;
    QLabel *user_addr;
    QWidget *dia_recharge;
    QPushButton *recharge_click;
    QPushButton *recharge_cancel_click;
    QLabel *label_20;
    QLineEdit *recharge_input;
    QWidget *widget_7;
    QPushButton *change_passwd;
    QPushButton *change_info;
    QLabel *label_2;
    QPushButton *sign_out;
    QWidget *page_search;
    QLabel *search_condition;
    QPushButton *search_goback;
    QListWidget *search_list;
    QLabel *label_10;
    QWidget *widget;
    QPushButton *nav_send;
    QPushButton *nav_check;
    QPushButton *nav_user;

    void setupUi(QWidget *Navigation)
    {
        if (Navigation->objectName().isEmpty())
            Navigation->setObjectName(QString::fromUtf8("Navigation"));
        Navigation->resize(405, 720);
        Navigation->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color: rgb(0, 0, 0);"));
        stackedWidget = new QStackedWidget(Navigation);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 405, 630));
        page_send = new QWidget();
        page_send->setObjectName(QString::fromUtf8("page_send"));
        page_send->setStyleSheet(QString::fromUtf8("background-color: rgb(236,236,236);"));
        label_3 = new QLabel(page_send);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 405, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_3 = new QWidget(page_send);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 570, 405, 61));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        send_packet = new QPushButton(widget_3);
        send_packet->setObjectName(QString::fromUtf8("send_packet"));
        send_packet->setGeometry(QRect(290, 10, 101, 41));
        send_packet->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgb(255, 65, 65);\n"
"border-radius:20px;\n"
"color: rgb(255, 255, 255);\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 10, 61, 41));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        send_price = new QLabel(widget_3);
        send_price->setObjectName(QString::fromUtf8("send_price"));
        send_price->setGeometry(QRect(100, 20, 171, 21));
        send_price->setStyleSheet(QString::fromUtf8("color: rgb(255, 65, 65);\n"
"font: 700 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(80, 10, 21, 41));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(255, 65, 65);\n"
"font: 700 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        widget_4 = new QWidget(page_send);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 70, 401, 181));
        widget_4->setStyleSheet(QString::fromUtf8("border-image: url(:/res/background/send_window.png);\n"
""));
        send_from = new QLabel(widget_4);
        send_from->setObjectName(QString::fromUtf8("send_from"));
        send_from->setGeometry(QRect(60, 30, 241, 31));
        send_from->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"background:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        send_dest = new QLineEdit(widget_4);
        send_dest->setObjectName(QString::fromUtf8("send_dest"));
        send_dest->setGeometry(QRect(60, 100, 301, 31));
        send_dest->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"border:1px solid #A0A0A0;\n"
"border-radius:8px;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-left:8px;\n"
"color: rgb(127,127,127);\n"
"background-color:rgb(236,236,236);"));
        send_dest->setMaxLength(10);
        send_from_addr = new QLabel(widget_4);
        send_from_addr->setObjectName(QString::fromUtf8("send_from_addr"));
        send_from_addr->setGeometry(QRect(60, 60, 241, 21));
        send_from_addr->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"background:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        widget_5 = new QWidget(page_send);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 400, 401, 121));
        widget_5->setStyleSheet(QString::fromUtf8("border-image: url(:/res/background/send_detail.png);\n"
""));
        label_15 = new QLabel(widget_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(60, 20, 61, 31));
        label_15->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"background:none;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        packet_describe = new QLineEdit(widget_5);
        packet_describe->setObjectName(QString::fromUtf8("packet_describe"));
        packet_describe->setGeometry(QRect(30, 60, 341, 31));
        packet_describe->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"border:1px solid #A0A0A0;\n"
"border-radius:8px;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"padding-left:8px;\n"
"color: rgb(127,127,127);\n"
"background-color:rgb(236,236,236);\n"
""));
        widget_8 = new QWidget(page_send);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(10, 250, 381, 141));
        widget_8->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border:none;\n"
"border-radius:17px;"));
        label_4 = new QLabel(widget_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 31, 31));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_send_type.png);"));
        label_18 = new QLabel(widget_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(50, 10, 61, 31));
        label_18->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"background:none;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        packet_count = new QSpinBox(widget_8);
        packet_count->setObjectName(QString::fromUtf8("packet_count"));
        packet_count->setGeometry(QRect(250, 80, 111, 31));
        packet_count->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"   	border:1px solid rgb(140, 140, 140);\n"
"	border-radius:8px;\n"
"	padding-left:8px;\n"
"	color: rgb(88, 88, 88);\n"
"	font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QSpinBox::up-button { \n"
"	border: none;\n"
"	width: 11px;\n"
"	margin-top: 2px;\n"
"	margin-right: 8px;\n"
"	margin-bottom: 0px;\n"
"}\n"
"\n"
"QSpinBox::down-button { \n"
"	border: none;\n"
"	width: 12px;\n"
"	margin-top: 0px;\n"
"	margin-right: 8px;\n"
"	margin-bottom: 2px;\n"
"}\n"
"\n"
"QSpinBox::up-arrow { \n"
"	width:15px;\n"
"	height:7px;\n"
"	border-image: url(:/res/icon/icon_arrow_up.png);\n"
"}\n"
"\n"
"QSpinBox::down-arrow { \n"
"	width:15px;\n"
"	height:7px;\n"
"	border-image: url(:/res/icon/icon_arrow_down.png);\n"
"}\n"
""));
        packet_count->setMaximum(32767);
        packet_type = new QComboBox(widget_8);
        packet_type->addItem(QString());
        packet_type->addItem(QString());
        packet_type->addItem(QString());
        packet_type->setObjectName(QString::fromUtf8("packet_type"));
        packet_type->setGeometry(QRect(250, 40, 111, 31));
        packet_type->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border:1px solid rgb(140, 140, 140);\n"
"	border-radius:8px;\n"
"	padding-left:8px;\n"
"	color: rgb(88, 88, 88);\n"
"	font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"}\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"	width:30px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	image: url(:/res/icon/icon_list.png);\n"
"	width:30px;\n"
"	height:30px;\n"
"	\n"
"}"));
        label_23 = new QLabel(widget_8);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(30, 45, 61, 31));
        label_23->setStyleSheet(QString::fromUtf8("	color: rgb(88, 88, 88);\n"
"	font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        packet_type_text = new QLabel(widget_8);
        packet_type_text->setObjectName(QString::fromUtf8("packet_type_text"));
        packet_type_text->setGeometry(QRect(30, 80, 111, 31));
        packet_type_text->setStyleSheet(QString::fromUtf8("	color: rgb(88, 88, 88);\n"
"	font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        packet_count_double = new QDoubleSpinBox(widget_8);
        packet_count_double->setObjectName(QString::fromUtf8("packet_count_double"));
        packet_count_double->setGeometry(QRect(250, 80, 111, 31));
        packet_count_double->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"   	border:1px solid rgb(140, 140, 140);\n"
"	border-radius:8px;\n"
"	padding-left:8px;\n"
"	color: rgb(88, 88, 88);\n"
"	font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button { \n"
"	border: none;\n"
"	width: 11px;\n"
"	margin-top: 2px;\n"
"	margin-right: 8px;\n"
"	margin-bottom: 0px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button { \n"
"	border: none;\n"
"	width: 12px;\n"
"	margin-top: 0px;\n"
"	margin-right: 8px;\n"
"	margin-bottom: 2px;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-arrow { \n"
"	width:15px;\n"
"	height:7px;\n"
"	border-image: url(:/res/icon/icon_arrow_up.png);\n"
"}\n"
"\n"
"QDoubleSpinBox::down-arrow { \n"
"	width:15px;\n"
"	height:7px;\n"
"	border-image: url(:/res/icon/icon_arrow_down.png);\n"
"}\n"
""));
        packet_count_double->setSingleStep(0.100000000000000);
        stackedWidget->addWidget(page_send);
        page_check = new QWidget();
        page_check->setObjectName(QString::fromUtf8("page_check"));
        tabWidget = new QTabWidget(page_check);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 90, 405, 542));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{\n"
"	border-style:none;\n"
"	background-color: rgb(236,236,236);\n"
"}\n"
"QTabWidget::tab-bar{\n"
"	background:none;\n"
"}\n"
"QTabBar::tab{\n"
"	height:30px;\n"
"	width:80px;\n"
"	\n"
"	font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QTabBar::tab:selected{\n"
"	border-bottom:4px solid rgb(255,65,65);\n"
"	background:none;\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"QTabBar::tab:!selected{\n"
"	border-bottom:4px solid rgb(255,255,255);\n"
"	background:none;\n"
"	color: rgb(127, 127, 127);\n"
"}"));
        send = new QWidget();
        send->setObjectName(QString::fromUtf8("send"));
        send_list = new QListWidget(send);
        send_list->setObjectName(QString::fromUtf8("send_list"));
        send_list->setGeometry(QRect(0, 0, 405, 512));
        send_list->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"background-color: rgb(236,236,236);\n"
"padding:0;"));
        send_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        send_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        send_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tabWidget->addTab(send, QString());
        recv = new QWidget();
        recv->setObjectName(QString::fromUtf8("recv"));
        recv_list = new QListWidget(recv);
        recv_list->setObjectName(QString::fromUtf8("recv_list"));
        recv_list->setGeometry(QRect(0, 0, 405, 512));
        recv_list->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"background-color: rgb(236,236,236);\n"
"padding:0;"));
        recv_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        recv_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        recv_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tabWidget->addTab(recv, QString());
        recv_ed = new QWidget();
        recv_ed->setObjectName(QString::fromUtf8("recv_ed"));
        pend_list = new QListWidget(recv_ed);
        pend_list->setObjectName(QString::fromUtf8("pend_list"));
        pend_list->setGeometry(QRect(0, 0, 405, 511));
        pend_list->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"background-color: rgb(236,236,236);\n"
"padding:0;"));
        pend_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        pend_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pend_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tabWidget->addTab(recv_ed, QString());
        label = new QLabel(page_check);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 405, 61));
        label->setFont(font);
        refresh = new QPushButton(page_check);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(340, 83, 51, 41));
        refresh->setStyleSheet(QString::fromUtf8("border:0px ;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(127, 127, 127);"));
        widget_2 = new QWidget(page_check);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(110, 50, 281, 31));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(236,236,236);\n"
"border:0px;\n"
"border-radius:14px"));
        search_input = new QLineEdit(widget_2);
        search_input->setObjectName(QString::fromUtf8("search_input"));
        search_input->setGeometry(QRect(10, 0, 231, 31));
        search_input->setStyleSheet(QString::fromUtf8("padding-left:8px;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(127,127,127);"));
        search_input->setMaxLength(32);
        search = new QPushButton(widget_2);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(240, 0, 41, 31));
        search->setStyleSheet(QString::fromUtf8("border-style:none"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icon/button_search.png"), QSize(), QIcon::Normal, QIcon::Off);
        search->setIcon(icon);
        search->setIconSize(QSize(20, 20));
        search_choose = new QComboBox(page_check);
        search_choose->addItem(QString());
        search_choose->addItem(QString());
        search_choose->addItem(QString());
        search_choose->addItem(QString());
        search_choose->setObjectName(QString::fromUtf8("search_choose"));
        search_choose->setGeometry(QRect(10, 50, 81, 31));
        search_choose->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border:1px solid rgb(140, 140, 140);\n"
"	border-radius:8px;\n"
"	\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
"}\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"	width:30px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"	image: url(:/res/icon/icon_list.png);\n"
"	width:30px;\n"
"	height:30px;\n"
"	\n"
"}"));
        search_choose->setIconSize(QSize(20, 20));
        search_choose->setFrame(true);
        stackedWidget->addWidget(page_check);
        label->raise();
        tabWidget->raise();
        refresh->raise();
        widget_2->raise();
        search_choose->raise();
        page_user = new QWidget();
        page_user->setObjectName(QString::fromUtf8("page_user"));
        page_user->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.284, stop:0 rgba(207, 228, 253, 255), stop:1 rgba(236, 236, 236, 255));\n"
"}"));
        userid = new QLabel(page_user);
        userid->setObjectName(QString::fromUtf8("userid"));
        userid->setGeometry(QRect(110, 80, 161, 31));
        userid->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label_9 = new QLabel(page_user);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(110, 120, 31, 21));
        label_9->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);\n"
"background:none;"));
        user_funds = new QLabel(page_user);
        user_funds->setObjectName(QString::fromUtf8("user_funds"));
        user_funds->setGeometry(QRect(150, 120, 91, 21));
        user_funds->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);\n"
"background:none;"));
        recharge = new QPushButton(page_user);
        recharge->setObjectName(QString::fromUtf8("recharge"));
        recharge->setGeometry(QRect(300, 110, 81, 31));
        recharge->setStyleSheet(QString::fromUtf8("background-color:rgb(255,65,65);\n"
"border-radius:14px;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(255,255,255);"));
        dia_change_info = new QWidget(page_user);
        dia_change_info->setObjectName(QString::fromUtf8("dia_change_info"));
        dia_change_info->setGeometry(QRect(40, 230, 321, 211));
        dia_change_info->setStyleSheet(QString::fromUtf8("border-radius:14px;\n"
"border:2px solid rgb(88, 88, 88);\n"
"background-color: rgb(255,255,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        change_info_click = new QPushButton(dia_change_info);
        change_info_click->setObjectName(QString::fromUtf8("change_info_click"));
        change_info_click->setGeometry(QRect(110, 170, 91, 31));
        change_info_click->setStyleSheet(QString::fromUtf8("background-color:rgb(255,65,65);\n"
"border-radius:14px;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:none;\n"
"color:rgb(255,255,255);"));
        change_info_cancel_click = new QPushButton(dia_change_info);
        change_info_cancel_click->setObjectName(QString::fromUtf8("change_info_cancel_click"));
        change_info_cancel_click->setGeometry(QRect(283, 8, 31, 24));
        change_info_cancel_click->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;\n"
"color: rgb(88, 88, 88);"));
        label_11 = new QLabel(dia_change_info);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(130, 10, 71, 21));
        label_11->setStyleSheet(QString::fromUtf8("border:none;"));
        label_12 = new QLabel(dia_change_info);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 50, 54, 31));
        label_12->setStyleSheet(QString::fromUtf8("border:none;"));
        label_13 = new QLabel(dia_change_info);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 95, 71, 21));
        label_13->setStyleSheet(QString::fromUtf8("border:none;"));
        label_14 = new QLabel(dia_change_info);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 135, 54, 21));
        label_14->setStyleSheet(QString::fromUtf8("border:none;"));
        change_name_input = new QLineEdit(dia_change_info);
        change_name_input->setObjectName(QString::fromUtf8("change_name_input"));
        change_name_input->setGeometry(QRect(100, 50, 191, 31));
        change_name_input->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"color: rgb(88, 88, 88);\n"
"border-radius:3px;\n"
"padding-left:8px;"));
        change_name_input->setMaxLength(10);
        change_tel_input = new QLineEdit(dia_change_info);
        change_tel_input->setObjectName(QString::fromUtf8("change_tel_input"));
        change_tel_input->setGeometry(QRect(100, 90, 191, 31));
        change_tel_input->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"color: rgb(88, 88, 88);\n"
"border-radius:3px;\n"
"padding-left:8px;"));
        change_tel_input->setMaxLength(13);
        change_addr_input = new QLineEdit(dia_change_info);
        change_addr_input->setObjectName(QString::fromUtf8("change_addr_input"));
        change_addr_input->setGeometry(QRect(100, 130, 191, 31));
        change_addr_input->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"color: rgb(88, 88, 88);\n"
"border-radius:3px;\n"
"padding-left:8px;"));
        change_addr_input->setMaxLength(32);
        dia_change_passwd = new QWidget(page_user);
        dia_change_passwd->setObjectName(QString::fromUtf8("dia_change_passwd"));
        dia_change_passwd->setGeometry(QRect(40, 270, 321, 161));
        dia_change_passwd->setStyleSheet(QString::fromUtf8("border-radius:14px;\n"
"border:2px solid rgb(88, 88, 88);\n"
"background-color: rgb(255,255,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        change_passwd_click = new QPushButton(dia_change_passwd);
        change_passwd_click->setObjectName(QString::fromUtf8("change_passwd_click"));
        change_passwd_click->setGeometry(QRect(110, 120, 101, 31));
        change_passwd_click->setStyleSheet(QString::fromUtf8("background-color:rgb(255,65,65);\n"
"border-radius:14px;\n"
"border:none;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(255,255,255);"));
        change_paaswd_cancel_click = new QPushButton(dia_change_passwd);
        change_paaswd_cancel_click->setObjectName(QString::fromUtf8("change_paaswd_cancel_click"));
        change_paaswd_cancel_click->setGeometry(QRect(285, 10, 31, 21));
        change_paaswd_cancel_click->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;\n"
"color: rgb(88, 88, 88);"));
        label_19 = new QLabel(dia_change_passwd);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(130, 3, 61, 31));
        label_19->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
""));
        label_21 = new QLabel(dia_change_passwd);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 40, 54, 31));
        label_21->setStyleSheet(QString::fromUtf8("border:none;"));
        label_22 = new QLabel(dia_change_passwd);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 80, 71, 31));
        label_22->setStyleSheet(QString::fromUtf8("border:none;"));
        change_passwd_input = new QLineEdit(dia_change_passwd);
        change_passwd_input->setObjectName(QString::fromUtf8("change_passwd_input"));
        change_passwd_input->setGeometry(QRect(100, 40, 191, 31));
        change_passwd_input->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);padding-left:8px;"));
        change_passwd_input->setMaxLength(16);
        change_passwd_input->setEchoMode(QLineEdit::Password);
        change_passwd_cfm_input = new QLineEdit(dia_change_passwd);
        change_passwd_cfm_input->setObjectName(QString::fromUtf8("change_passwd_cfm_input"));
        change_passwd_cfm_input->setGeometry(QRect(100, 80, 191, 31));
        change_passwd_cfm_input->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);padding-left:8px;"));
        change_passwd_cfm_input->setMaxLength(16);
        change_passwd_cfm_input->setEchoMode(QLineEdit::Password);
        label_16 = new QLabel(page_user);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 0, 405, 61));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        userid_2 = new QLabel(page_user);
        userid_2->setObjectName(QString::fromUtf8("userid_2"));
        userid_2->setGeometry(QRect(20, 70, 81, 79));
        userid_2->setStyleSheet(QString::fromUtf8("background:none;\n"
"border-image: url(:/res/icon/icon_user_image.png);"));
        widget_6 = new QWidget(page_user);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(20, 170, 361, 161));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border:0px;\n"
"border-radius:18px;"));
        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 10, 51, 41));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_userinfo.png);\n"
"background:none;"));
        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 60, 49, 39));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_tel.png);\n"
"background:none;"));
        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 110, 51, 41));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_address.png);\n"
"background:none;"));
        user_name = new QLabel(widget_6);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        user_name->setGeometry(QRect(90, 20, 251, 21));
        user_name->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        user_tel = new QLabel(widget_6);
        user_tel->setObjectName(QString::fromUtf8("user_tel"));
        user_tel->setGeometry(QRect(90, 70, 251, 21));
        user_tel->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        user_addr = new QLabel(widget_6);
        user_addr->setObjectName(QString::fromUtf8("user_addr"));
        user_addr->setGeometry(QRect(90, 120, 251, 21));
        user_addr->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        dia_recharge = new QWidget(page_user);
        dia_recharge->setObjectName(QString::fromUtf8("dia_recharge"));
        dia_recharge->setGeometry(QRect(80, 270, 241, 121));
        dia_recharge->setStyleSheet(QString::fromUtf8("border-radius:14px;\n"
"border:2px solid rgb(88, 88, 88);\n"
"background-color: rgb(255,255,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        recharge_click = new QPushButton(dia_recharge);
        recharge_click->setObjectName(QString::fromUtf8("recharge_click"));
        recharge_click->setGeometry(QRect(80, 80, 81, 31));
        recharge_click->setStyleSheet(QString::fromUtf8("background-color:rgb(255,65,65);\n"
"border-radius:14px;\n"
"border:none;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(255,255,255);"));
        recharge_cancel_click = new QPushButton(dia_recharge);
        recharge_cancel_click->setObjectName(QString::fromUtf8("recharge_cancel_click"));
        recharge_cancel_click->setGeometry(QRect(210, 8, 21, 24));
        recharge_cancel_click->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;\n"
"color: rgb(88, 88, 88);"));
        label_20 = new QLabel(dia_recharge);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(100, 10, 41, 21));
        label_20->setStyleSheet(QString::fromUtf8("border:none;"));
        recharge_input = new QLineEdit(dia_recharge);
        recharge_input->setObjectName(QString::fromUtf8("recharge_input"));
        recharge_input->setGeometry(QRect(20, 40, 201, 31));
        recharge_input->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"color: rgb(88, 88, 88);\n"
"padding-left:8px;"));
        recharge_input->setMaxLength(9);
        widget_7 = new QWidget(page_user);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(20, 350, 361, 111));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border:0px;\n"
"border-radius:14px;\n"
"border-radius:18px;"));
        change_passwd = new QPushButton(widget_7);
        change_passwd->setObjectName(QString::fromUtf8("change_passwd"));
        change_passwd->setGeometry(QRect(20, 60, 81, 31));
        change_passwd->setStyleSheet(QString::fromUtf8("background-color:rgb(204,204,204);\n"
"border-radius:14px;\n"
"border:none;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(0,0,0);"));
        change_info = new QPushButton(widget_7);
        change_info->setObjectName(QString::fromUtf8("change_info"));
        change_info->setGeometry(QRect(110, 60, 81, 31));
        change_info->setStyleSheet(QString::fromUtf8("background-color:rgb(204,204,204);\n"
"border-radius:14px;\n"
"border:none;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(0,0,0);"));
        label_2 = new QLabel(widget_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 71, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        sign_out = new QPushButton(widget_7);
        sign_out->setObjectName(QString::fromUtf8("sign_out"));
        sign_out->setGeometry(QRect(270, 60, 71, 31));
        sign_out->setStyleSheet(QString::fromUtf8("background-color:rgb(255,65,65);\n"
"border-radius:14px;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(255,255,255);"));
        stackedWidget->addWidget(page_user);
        userid->raise();
        label_9->raise();
        user_funds->raise();
        recharge->raise();
        label_16->raise();
        userid_2->raise();
        widget_6->raise();
        widget_7->raise();
        dia_change_passwd->raise();
        dia_change_info->raise();
        dia_recharge->raise();
        page_search = new QWidget(Navigation);
        page_search->setObjectName(QString::fromUtf8("page_search"));
        page_search->setEnabled(true);
        page_search->setGeometry(QRect(0, 50, 405, 671));
        page_search->setStyleSheet(QString::fromUtf8("background-color:rgb(236,236,236);"));
        search_condition = new QLabel(page_search);
        search_condition->setObjectName(QString::fromUtf8("search_condition"));
        search_condition->setGeometry(QRect(130, 10, 251, 31));
        search_condition->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        search_goback = new QPushButton(page_search);
        search_goback->setObjectName(QString::fromUtf8("search_goback"));
        search_goback->setGeometry(QRect(10, 10, 41, 31));
        search_goback->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_go_back.png);\n"
"background:none;\n"
"border:none;"));
        search_list = new QListWidget(page_search);
        search_list->setObjectName(QString::fromUtf8("search_list"));
        search_list->setGeometry(QRect(0, 50, 405, 571));
        search_list->setStyleSheet(QString::fromUtf8("border:none;padding:0;\n"
"background-color:rgb(236,236,236);"));
        search_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        search_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        search_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        label_10 = new QLabel(page_search);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 10, 71, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        search_goback->raise();
        label_10->raise();
        search_condition->raise();
        search_list->raise();
        widget = new QWidget(Navigation);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 629, 405, 91));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-top:1px solid;\n"
"border-top-color: rgb(58, 58, 58);"));
        nav_send = new QPushButton(widget);
        nav_send->setObjectName(QString::fromUtf8("nav_send"));
        nav_send->setGeometry(QRect(20, 10, 101, 61));
        nav_send->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-style:none"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/navigation/icon_send_packet.png"), QSize(), QIcon::Normal, QIcon::Off);
        nav_send->setIcon(icon1);
        nav_send->setIconSize(QSize(60, 60));
        nav_check = new QPushButton(widget);
        nav_check->setObjectName(QString::fromUtf8("nav_check"));
        nav_check->setGeometry(QRect(150, 10, 101, 61));
        nav_check->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-style:none"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/navigation/icon_check_packet.png"), QSize(), QIcon::Normal, QIcon::Off);
        nav_check->setIcon(icon2);
        nav_check->setIconSize(QSize(60, 60));
        nav_user = new QPushButton(widget);
        nav_user->setObjectName(QString::fromUtf8("nav_user"));
        nav_user->setEnabled(true);
        nav_user->setGeometry(QRect(280, 10, 101, 61));
        nav_user->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-style:none"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/navigation/icon_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        nav_user->setIcon(icon3);
        nav_user->setIconSize(QSize(60, 60));
        nav_user->setCheckable(false);
        nav_user->setAutoDefault(false);
        nav_user->setFlat(false);
        stackedWidget->raise();
        widget->raise();
        page_search->raise();

        retranslateUi(Navigation);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(2);
        nav_user->setDefault(false);


        QMetaObject::connectSlotsByName(Navigation);
    } // setupUi

    void retranslateUi(QWidget *Navigation)
    {
        Navigation->setWindowTitle(QCoreApplication::translate("Navigation", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("Navigation", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\345\257\204\345\277\253\351\200\222</span></p></body></html>", nullptr));
        send_packet->setText(QCoreApplication::translate("Navigation", "\344\270\213\345\215\225", nullptr));
        label_5->setText(QCoreApplication::translate("Navigation", "\351\242\204\344\274\260\346\200\273\344\273\267", nullptr));
        send_price->setText(QCoreApplication::translate("Navigation", "---", nullptr));
        label_17->setText(QCoreApplication::translate("Navigation", "\357\277\245", nullptr));
        send_from->setText(QCoreApplication::translate("Navigation", "From User", nullptr));
        send_dest->setPlaceholderText(QCoreApplication::translate("Navigation", "\346\224\266\344\273\266\344\272\272", nullptr));
        send_from_addr->setText(QCoreApplication::translate("Navigation", "Addr", nullptr));
        label_15->setText(QCoreApplication::translate("Navigation", "\347\211\251\345\223\201\346\217\217\350\277\260", nullptr));
        packet_describe->setText(QString());
        packet_describe->setPlaceholderText(QCoreApplication::translate("Navigation", "\350\276\223\345\205\245\347\211\251\345\223\201\346\217\217\350\277\260", nullptr));
        label_4->setText(QString());
        label_18->setText(QCoreApplication::translate("Navigation", "\347\211\251\345\223\201\350\257\246\346\203\205", nullptr));
        packet_type->setItemText(0, QCoreApplication::translate("Navigation", "\346\231\256\351\200\232\345\214\205\350\243\271", nullptr));
        packet_type->setItemText(1, QCoreApplication::translate("Navigation", "\346\230\223\347\242\216\345\223\201", nullptr));
        packet_type->setItemText(2, QCoreApplication::translate("Navigation", "\345\233\276\344\271\246", nullptr));

        label_23->setText(QCoreApplication::translate("Navigation", "\347\211\251\345\223\201\347\261\273\345\236\213", nullptr));
        packet_type_text->setText(QCoreApplication::translate("Navigation", "\347\211\251\345\223\201\351\207\215\351\207\217/\346\225\260\351\207\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(send), QCoreApplication::translate("Navigation", "\345\257\204\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(recv), QCoreApplication::translate("Navigation", "\345\267\262\347\255\276\346\224\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(recv_ed), QCoreApplication::translate("Navigation", "\345\276\205\347\255\276\346\224\266", nullptr));
        label->setText(QCoreApplication::translate("Navigation", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\346\237\245\345\277\253\351\200\222</span></p></body></html>", nullptr));
        refresh->setText(QCoreApplication::translate("Navigation", "\345\210\267\346\226\260", nullptr));
        search_input->setPlaceholderText(QCoreApplication::translate("Navigation", "\346\220\234\347\264\242", nullptr));
        search->setText(QString());
        search_choose->setItemText(0, QCoreApplication::translate("Navigation", "\350\277\220\345\215\225\345\217\267", nullptr));
        search_choose->setItemText(1, QCoreApplication::translate("Navigation", "\346\224\266\344\273\266\344\272\272", nullptr));
        search_choose->setItemText(2, QCoreApplication::translate("Navigation", "\346\224\266\344\273\266\346\227\266\351\227\264", nullptr));
        search_choose->setItemText(3, QCoreApplication::translate("Navigation", "\345\257\204\344\273\266\346\227\266\351\227\264", nullptr));

        userid->setText(QCoreApplication::translate("Navigation", "Userid", nullptr));
        label_9->setText(QCoreApplication::translate("Navigation", "\344\275\231\351\242\235", nullptr));
        user_funds->setText(QCoreApplication::translate("Navigation", "Balance", nullptr));
        recharge->setText(QCoreApplication::translate("Navigation", "\345\205\205\345\200\274", nullptr));
        change_info_click->setText(QCoreApplication::translate("Navigation", "\347\241\256\345\256\232", nullptr));
        change_info_cancel_click->setText(QCoreApplication::translate("Navigation", "X", nullptr));
        label_11->setText(QCoreApplication::translate("Navigation", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        label_12->setText(QCoreApplication::translate("Navigation", "\345\247\223\345\220\215", nullptr));
        label_13->setText(QCoreApplication::translate("Navigation", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        label_14->setText(QCoreApplication::translate("Navigation", "\345\234\260\345\235\200", nullptr));
        change_passwd_click->setText(QCoreApplication::translate("Navigation", "\347\241\256\345\256\232", nullptr));
        change_paaswd_cancel_click->setText(QCoreApplication::translate("Navigation", "X", nullptr));
        label_19->setText(QCoreApplication::translate("Navigation", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_21->setText(QCoreApplication::translate("Navigation", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_22->setText(QCoreApplication::translate("Navigation", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_16->setText(QCoreApplication::translate("Navigation", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\346\210\221\347\232\204</span></p></body></html>", nullptr));
        userid_2->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        user_name->setText(QCoreApplication::translate("Navigation", "Username", nullptr));
        user_tel->setText(QCoreApplication::translate("Navigation", "Tel", nullptr));
        user_addr->setText(QCoreApplication::translate("Navigation", "Address", nullptr));
        recharge_click->setText(QCoreApplication::translate("Navigation", "\347\241\256\345\256\232", nullptr));
        recharge_cancel_click->setText(QCoreApplication::translate("Navigation", "X", nullptr));
        label_20->setText(QCoreApplication::translate("Navigation", "\345\205\205\345\200\274", nullptr));
        recharge_input->setInputMask(QString());
        recharge_input->setPlaceholderText(QCoreApplication::translate("Navigation", "\350\276\223\345\205\245\351\207\221\351\242\235", nullptr));
        change_passwd->setText(QCoreApplication::translate("Navigation", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        change_info->setText(QCoreApplication::translate("Navigation", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("Navigation", "\345\237\272\347\241\200\346\234\215\345\212\241", nullptr));
        sign_out->setText(QCoreApplication::translate("Navigation", "\351\200\200\345\207\272", nullptr));
        search_condition->setText(QCoreApplication::translate("Navigation", "condition", nullptr));
        search_goback->setText(QString());
        label_10->setText(QCoreApplication::translate("Navigation", "\346\220\234\347\264\242\347\273\223\346\236\234 :", nullptr));
        nav_send->setText(QString());
        nav_check->setText(QString());
        nav_user->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Navigation: public Ui_Navigation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATION_H
