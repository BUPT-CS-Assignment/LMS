/********************************************************************************
** Form generated from reading UI file 'manage.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_H
#define UI_MANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manage
{
public:
    QWidget *widget;
    QPushButton *mng_check;
    QPushButton *mng_user;
    QStackedWidget *stackedWidget;
    QWidget *page_check;
    QTabWidget *tabWidget;
    QWidget *all;
    QListWidget *all_list;
    QWidget *collected;
    QListWidget *collected_list;
    QWidget *collecting;
    QListWidget *collecting_list;
    QLabel *label;
    QPushButton *refresh;
    QWidget *widget_2;
    QLineEdit *search_input;
    QPushButton *search;
    QComboBox *search_choose;
    QPushButton *collect_all;
    QWidget *page_user;
    QLabel *userid;
    QLabel *label_9;
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
    QLabel *user_funds;
    QPushButton *recharge;
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
    QWidget *dia_change_info;
    QPushButton *change_info_click;
    QPushButton *change_info_cancel_click;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *change_name_input;
    QLineEdit *change_tel_input;
    QWidget *page_search;
    QLabel *search_condition;
    QPushButton *search_goback;
    QListWidget *search_list;
    QLabel *label_10;

    void setupUi(QWidget *Manage)
    {
        if (Manage->objectName().isEmpty())
            Manage->setObjectName(QString::fromUtf8("Manage"));
        Manage->resize(405, 720);
        Manage->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"color: rgb(0, 0, 0);"));
        widget = new QWidget(Manage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 629, 405, 91));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-top:1px solid;\n"
"border-top-color: rgb(58, 58, 58);"));
        mng_check = new QPushButton(widget);
        mng_check->setObjectName(QString::fromUtf8("mng_check"));
        mng_check->setGeometry(QRect(70, 10, 101, 61));
        mng_check->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-style:none"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/navigation/icon_check_packet.png"), QSize(), QIcon::Normal, QIcon::Off);
        mng_check->setIcon(icon);
        mng_check->setIconSize(QSize(60, 60));
        mng_user = new QPushButton(widget);
        mng_user->setObjectName(QString::fromUtf8("mng_user"));
        mng_user->setEnabled(true);
        mng_user->setGeometry(QRect(230, 10, 101, 61));
        mng_user->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-style:none"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/navigation/icon_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        mng_user->setIcon(icon1);
        mng_user->setIconSize(QSize(60, 60));
        mng_user->setCheckable(false);
        mng_user->setAutoDefault(false);
        mng_user->setFlat(false);
        stackedWidget = new QStackedWidget(Manage);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 405, 630));
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
        all = new QWidget();
        all->setObjectName(QString::fromUtf8("all"));
        all_list = new QListWidget(all);
        all_list->setObjectName(QString::fromUtf8("all_list"));
        all_list->setGeometry(QRect(0, 0, 405, 512));
        all_list->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"background-color: rgb(236,236,236);\n"
"padding:0;"));
        all_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        all_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        all_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tabWidget->addTab(all, QString());
        collected = new QWidget();
        collected->setObjectName(QString::fromUtf8("collected"));
        collected_list = new QListWidget(collected);
        collected_list->setObjectName(QString::fromUtf8("collected_list"));
        collected_list->setGeometry(QRect(0, 0, 405, 512));
        collected_list->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"background-color: rgb(236,236,236);\n"
"padding:0;"));
        collected_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        collected_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        collected_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tabWidget->addTab(collected, QString());
        collecting = new QWidget();
        collecting->setObjectName(QString::fromUtf8("collecting"));
        collecting_list = new QListWidget(collecting);
        collecting_list->setObjectName(QString::fromUtf8("collecting_list"));
        collecting_list->setGeometry(QRect(0, 0, 405, 511));
        collecting_list->setStyleSheet(QString::fromUtf8("border-style:none;\n"
"background-color: rgb(236,236,236);\n"
"padding:0;"));
        collecting_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        collecting_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        collecting_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tabWidget->addTab(collecting, QString());
        label = new QLabel(page_check);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 405, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/icon/button_search.png"), QSize(), QIcon::Normal, QIcon::Off);
        search->setIcon(icon2);
        search->setIconSize(QSize(20, 20));
        search_choose = new QComboBox(page_check);
        search_choose->addItem(QString());
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
        collect_all = new QPushButton(page_check);
        collect_all->setObjectName(QString::fromUtf8("collect_all"));
        collect_all->setGeometry(QRect(270, 83, 71, 41));
        collect_all->setStyleSheet(QString::fromUtf8("border:0px ;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(127, 127, 127);"));
        stackedWidget->addWidget(page_check);
        label->raise();
        tabWidget->raise();
        refresh->raise();
        widget_2->raise();
        search_choose->raise();
        collect_all->raise();
        page_user = new QWidget();
        page_user->setObjectName(QString::fromUtf8("page_user"));
        page_user->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0.284, stop:0 rgba(207, 228, 253, 255), stop:1 rgba(236, 236, 236, 255));\n"
"}"));
        userid = new QLabel(page_user);
        userid->setObjectName(QString::fromUtf8("userid"));
        userid->setGeometry(QRect(110, 100, 131, 31));
        userid->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label_9 = new QLabel(page_user);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 100, 61, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);\n"
"background:none;"));
        dia_change_passwd = new QWidget(page_user);
        dia_change_passwd->setObjectName(QString::fromUtf8("dia_change_passwd"));
        dia_change_passwd->setGeometry(QRect(40, 260, 321, 161));
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
        user_funds = new QLabel(widget_6);
        user_funds->setObjectName(QString::fromUtf8("user_funds"));
        user_funds->setGeometry(QRect(90, 120, 151, 21));
        user_funds->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        recharge = new QPushButton(widget_6);
        recharge->setObjectName(QString::fromUtf8("recharge"));
        recharge->setGeometry(QRect(260, 115, 81, 31));
        recharge->setStyleSheet(QString::fromUtf8("background-color:rgb(255,65,65);\n"
"border-radius:14px;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(255,255,255);"));
        dia_recharge = new QWidget(page_user);
        dia_recharge->setObjectName(QString::fromUtf8("dia_recharge"));
        dia_recharge->setGeometry(QRect(80, 280, 241, 121));
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
        dia_change_info = new QWidget(page_user);
        dia_change_info->setObjectName(QString::fromUtf8("dia_change_info"));
        dia_change_info->setGeometry(QRect(40, 230, 321, 191));
        dia_change_info->setStyleSheet(QString::fromUtf8("border-radius:14px;\n"
"border:2px solid rgb(88, 88, 88);\n"
"background-color: rgb(255,255,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        change_info_click = new QPushButton(dia_change_info);
        change_info_click->setObjectName(QString::fromUtf8("change_info_click"));
        change_info_click->setGeometry(QRect(120, 140, 91, 31));
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
        stackedWidget->addWidget(page_user);
        userid->raise();
        label_9->raise();
        label_16->raise();
        userid_2->raise();
        widget_6->raise();
        widget_7->raise();
        dia_change_info->raise();
        dia_change_passwd->raise();
        dia_recharge->raise();
        page_search = new QWidget(Manage);
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

        retranslateUi(Manage);

        mng_user->setDefault(false);
        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Manage);
    } // setupUi

    void retranslateUi(QWidget *Manage)
    {
        Manage->setWindowTitle(QCoreApplication::translate("Manage", "Form", nullptr));
        mng_check->setText(QString());
        mng_user->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(all), QCoreApplication::translate("Manage", "\346\211\200\346\234\211", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(collected), QCoreApplication::translate("Manage", "\345\267\262\346\212\225\351\200\222", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(collecting), QCoreApplication::translate("Manage", "\345\276\205\346\217\275\346\224\266", nullptr));
        label->setText(QCoreApplication::translate("Manage", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\346\237\245\345\277\253\351\200\222</span></p></body></html>", nullptr));
        refresh->setText(QCoreApplication::translate("Manage", "\345\210\267\346\226\260", nullptr));
        search_input->setPlaceholderText(QCoreApplication::translate("Manage", "\346\220\234\347\264\242", nullptr));
        search->setText(QString());
        search_choose->setItemText(0, QCoreApplication::translate("Manage", "\350\277\220\345\215\225\345\217\267", nullptr));
        search_choose->setItemText(1, QCoreApplication::translate("Manage", "\346\224\266\344\273\266\344\272\272", nullptr));
        search_choose->setItemText(2, QCoreApplication::translate("Manage", "\346\224\266\344\273\266\346\227\266\351\227\264", nullptr));
        search_choose->setItemText(3, QCoreApplication::translate("Manage", "\345\257\204\344\273\266\346\227\266\351\227\264", nullptr));
        search_choose->setItemText(4, QCoreApplication::translate("Manage", "\345\217\221\344\273\266\344\272\272", nullptr));

        collect_all->setText(QCoreApplication::translate("Manage", "\345\205\250\351\203\250\346\217\275\346\224\266", nullptr));
        userid->setText(QCoreApplication::translate("Manage", "Userid", nullptr));
        label_9->setText(QCoreApplication::translate("Manage", "\345\277\253\351\200\222\345\221\230", nullptr));
        change_passwd_click->setText(QCoreApplication::translate("Manage", "\347\241\256\345\256\232", nullptr));
        change_paaswd_cancel_click->setText(QCoreApplication::translate("Manage", "X", nullptr));
        label_19->setText(QCoreApplication::translate("Manage", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_21->setText(QCoreApplication::translate("Manage", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_22->setText(QCoreApplication::translate("Manage", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_16->setText(QCoreApplication::translate("Manage", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\346\210\221\347\232\204</span></p></body></html>", nullptr));
        userid_2->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        user_name->setText(QCoreApplication::translate("Manage", "Username", nullptr));
        user_tel->setText(QCoreApplication::translate("Manage", "Tel", nullptr));
        user_funds->setText(QCoreApplication::translate("Manage", "Balance", nullptr));
        recharge->setText(QCoreApplication::translate("Manage", "\345\205\205\345\200\274", nullptr));
        recharge_click->setText(QCoreApplication::translate("Manage", "\347\241\256\345\256\232", nullptr));
        recharge_cancel_click->setText(QCoreApplication::translate("Manage", "X", nullptr));
        label_20->setText(QCoreApplication::translate("Manage", "\345\205\205\345\200\274", nullptr));
        recharge_input->setInputMask(QString());
        recharge_input->setPlaceholderText(QCoreApplication::translate("Manage", "\350\276\223\345\205\245\351\207\221\351\242\235", nullptr));
        change_passwd->setText(QCoreApplication::translate("Manage", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        change_info->setText(QCoreApplication::translate("Manage", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("Manage", "\345\237\272\347\241\200\346\234\215\345\212\241", nullptr));
        sign_out->setText(QCoreApplication::translate("Manage", "\351\200\200\345\207\272", nullptr));
        change_info_click->setText(QCoreApplication::translate("Manage", "\347\241\256\345\256\232", nullptr));
        change_info_cancel_click->setText(QCoreApplication::translate("Manage", "X", nullptr));
        label_11->setText(QCoreApplication::translate("Manage", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        label_12->setText(QCoreApplication::translate("Manage", "\345\247\223\345\220\215", nullptr));
        label_13->setText(QCoreApplication::translate("Manage", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        search_condition->setText(QCoreApplication::translate("Manage", "condition", nullptr));
        search_goback->setText(QString());
        label_10->setText(QCoreApplication::translate("Manage", "\346\220\234\347\264\242\347\273\223\346\236\234 :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manage: public Ui_Manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H
