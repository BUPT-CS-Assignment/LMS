/********************************************************************************
** Form generated from reading UI file 'backstage.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKSTAGE_H
#define UI_BACKSTAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackStage
{
public:
    QWidget *nav_bar;
    QPushButton *packet_page_select;
    QPushButton *sign_out_click;
    QPushButton *user_page_select;
    QLabel *label_4;
    QStackedWidget *stackedWidget;
    QWidget *page_packet;
    QPushButton *packet_search_refresh;
    QComboBox *packet_search_choose;
    QLineEdit *packet_search_input;
    QTableWidget *packet_list;
    QPushButton *packet_search_click;
    QLabel *label_2;
    QTableWidget *collecting_list;
    QWidget *widget;
    QComboBox *packet_alloc_choose;
    QPushButton *packet_alloc;
    QLabel *option_packet_id;
    QLabel *label;
    QWidget *widget_2;
    QLabel *label_12;
    QCheckBox *auto_allocation;
    QComboBox *search_courier_choose;
    QWidget *page_user;
    QTableWidget *user_list;
    QComboBox *user_search_choose;
    QLineEdit *user_search_input;
    QPushButton *user_search_click;
    QPushButton *user_search_refresh;
    QLabel *label_3;
    QWidget *widget_3;
    QComboBox *user_option_choose;
    QPushButton *user_delete;
    QLabel *label_13;
    QWidget *widget_4;
    QLabel *label_14;
    QWidget *widget_5;
    QLabel *label_7;
    QLabel *label_5;
    QComboBox *add_user_auth;
    QLabel *label_9;
    QLineEdit *add_user_id;
    QSpinBox *add_user_balance;
    QPushButton *user_add;
    QWidget *widget_6;
    QLabel *label_15;

    void setupUi(QWidget *BackStage)
    {
        if (BackStage->objectName().isEmpty())
            BackStage->setObjectName(QString::fromUtf8("BackStage"));
        BackStage->resize(1024, 576);
        BackStage->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        nav_bar = new QWidget(BackStage);
        nav_bar->setObjectName(QString::fromUtf8("nav_bar"));
        nav_bar->setGeometry(QRect(0, 0, 150, 581));
        nav_bar->setStyleSheet(QString::fromUtf8("background-color:rgb(40,44,53);\n"
"color:rgb(204,204,204);\n"
"border:none;\n"
"font: 600 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        packet_page_select = new QPushButton(nav_bar);
        packet_page_select->setObjectName(QString::fromUtf8("packet_page_select"));
        packet_page_select->setGeometry(QRect(0, 90, 150, 41));
        packet_page_select->setStyleSheet(QString::fromUtf8("background-color:rgb(66,181,130);\n"
"color:rgb(255,255,255);"));
        sign_out_click = new QPushButton(nav_bar);
        sign_out_click->setObjectName(QString::fromUtf8("sign_out_click"));
        sign_out_click->setGeometry(QRect(20, 530, 101, 31));
        sign_out_click->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(204,204,204);"));
        user_page_select = new QPushButton(nav_bar);
        user_page_select->setObjectName(QString::fromUtf8("user_page_select"));
        user_page_select->setGeometry(QRect(0, 130, 150, 41));
        user_page_select->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(nav_bar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 30, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 28pt \"\344\274\230\350\256\276\346\240\207\351\242\230\351\273\221\";\n"
"color:rgb(204,204,204);"));
        stackedWidget = new QStackedWidget(BackStage);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 0, 881, 581));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 236, 236);"));
        page_packet = new QWidget();
        page_packet->setObjectName(QString::fromUtf8("page_packet"));
        packet_search_refresh = new QPushButton(page_packet);
        packet_search_refresh->setObjectName(QString::fromUtf8("packet_search_refresh"));
        packet_search_refresh->setGeometry(QRect(790, 50, 71, 31));
        packet_search_refresh->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgb(227,192,104);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        packet_search_choose = new QComboBox(page_packet);
        packet_search_choose->addItem(QString());
        packet_search_choose->addItem(QString());
        packet_search_choose->addItem(QString());
        packet_search_choose->addItem(QString());
        packet_search_choose->addItem(QString());
        packet_search_choose->addItem(QString());
        packet_search_choose->setObjectName(QString::fromUtf8("packet_search_choose"));
        packet_search_choose->setGeometry(QRect(110, 50, 81, 31));
        packet_search_choose->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color:rgb(255,255,255);\n"
"	border:2px solid rgb(67,180,136);\n"
"	font: 600 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:rgb(67,180,136);\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        packet_search_input = new QLineEdit(page_packet);
        packet_search_input->setObjectName(QString::fromUtf8("packet_search_input"));
        packet_search_input->setGeometry(QRect(200, 50, 521, 31));
        packet_search_input->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border:1px solid rgb(204,204,204);\n"
"padding-left:8px;\n"
"font: 600 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(127, 127, 127);"));
        packet_list = new QTableWidget(page_packet);
        packet_list->setObjectName(QString::fromUtf8("packet_list"));
        packet_list->setGeometry(QRect(170, 90, 691, 477));
        packet_list->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color:rgb(255,255,255);"));
        packet_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        packet_list->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        packet_search_click = new QPushButton(page_packet);
        packet_search_click->setObjectName(QString::fromUtf8("packet_search_click"));
        packet_search_click->setGeometry(QRect(720, 50, 71, 31));
        packet_search_click->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgb(67,180,136);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_2 = new QLabel(page_packet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 881, 41));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-bottom:1px solid rgb(204, 204, 204);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(103, 103, 103);"));
        collecting_list = new QTableWidget(page_packet);
        collecting_list->setObjectName(QString::fromUtf8("collecting_list"));
        collecting_list->setGeometry(QRect(10, 120, 151, 281));
        collecting_list->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color:rgb(255,255,255);"));
        collecting_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widget = new QWidget(page_packet);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 410, 151, 107));
        widget->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color:rgb(255,255,255);"));
        packet_alloc_choose = new QComboBox(widget);
        packet_alloc_choose->setObjectName(QString::fromUtf8("packet_alloc_choose"));
        packet_alloc_choose->setGeometry(QRect(10, 60, 81, 31));
        packet_alloc_choose->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding-left:6px;\n"
"	color: rgb(88, 88, 88);\n"
"}\n"
"\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	margin-right:10px;\n"
"	width:14px;\n"
"	height:7px;\n"
"	border-image: url(:/res/icon/icon_arrow_down.png);\n"
"}"));
        packet_alloc = new QPushButton(widget);
        packet_alloc->setObjectName(QString::fromUtf8("packet_alloc"));
        packet_alloc->setGeometry(QRect(100, 60, 41, 31));
        packet_alloc->setStyleSheet(QString::fromUtf8("color: rgb(88, 88, 88);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        option_packet_id = new QLabel(widget);
        option_packet_id->setObjectName(QString::fromUtf8("option_packet_id"));
        option_packet_id->setGeometry(QRect(10, 30, 131, 28));
        option_packet_id->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 21));
        label->setStyleSheet(QString::fromUtf8("border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        widget_2 = new QWidget(page_packet);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 90, 151, 31));
        widget_2->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color: rgb(61, 65, 73);"));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 5, 51, 21));
        label_12->setStyleSheet(QString::fromUtf8("border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        auto_allocation = new QCheckBox(page_packet);
        auto_allocation->setObjectName(QString::fromUtf8("auto_allocation"));
        auto_allocation->setGeometry(QRect(10, 526, 151, 41));
        auto_allocation->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"	border:1px solid rgb(204,204,204);\n"
"	background-color:rgb(255,255,255);\n"
"	padding-left:8px;\n"
"	font: 500 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(88, 88, 88);\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"	background-color:rgba(0,0,0,0);\n"
"\n"
"	width:36px;\n"
"	height:36px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked{\n"
"	image: url(:/res/icon/icon_switch_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"	image: url(:/res/icon/icon_switch_on.png);\n"
"}\n"
"\n"
""));
        search_courier_choose = new QComboBox(page_packet);
        search_courier_choose->setObjectName(QString::fromUtf8("search_courier_choose"));
        search_courier_choose->setGeometry(QRect(10, 50, 91, 31));
        search_courier_choose->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color:rgb(255,255,255);\n"
"	border:2px solid rgb(139,163,183);\n"
"	padding-left:6px;\n"
"	color: rgb(88, 88, 88);\n"
"	font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	margin-right:10px;\n"
"	width:14px;\n"
"	height:7px;\n"
"	border-image: url(:/res/icon/icon_arrow_down.png);\n"
"}"));
        stackedWidget->addWidget(page_packet);
        packet_search_refresh->raise();
        packet_search_input->raise();
        packet_list->raise();
        label_2->raise();
        packet_search_choose->raise();
        packet_search_click->raise();
        widget->raise();
        widget_2->raise();
        collecting_list->raise();
        auto_allocation->raise();
        search_courier_choose->raise();
        page_user = new QWidget();
        page_user->setObjectName(QString::fromUtf8("page_user"));
        user_list = new QTableWidget(page_user);
        user_list->setObjectName(QString::fromUtf8("user_list"));
        user_list->setGeometry(QRect(180, 90, 681, 477));
        user_list->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color:rgb(255,255,255);"));
        user_list->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        user_list->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        user_search_choose = new QComboBox(page_user);
        user_search_choose->addItem(QString());
        user_search_choose->addItem(QString());
        user_search_choose->addItem(QString());
        user_search_choose->addItem(QString());
        user_search_choose->setObjectName(QString::fromUtf8("user_search_choose"));
        user_search_choose->setGeometry(QRect(10, 50, 71, 31));
        user_search_choose->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color:rgb(255,255,255);\n"
"	border:2px solid rgb(67,180,136);\n"
"	border-radius:1px;\n"
"	font: 600 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:rgb(67,180,136);\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"	font: 600 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:rgb(67,180,136);\n"
"}\n"
"\n"
""));
        user_search_input = new QLineEdit(page_user);
        user_search_input->setObjectName(QString::fromUtf8("user_search_input"));
        user_search_input->setGeometry(QRect(90, 50, 631, 31));
        user_search_input->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border:1px solid rgb(204,204,204);\n"
"padding-left:8px;\n"
"font: 600 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(127, 127, 127);"));
        user_search_click = new QPushButton(page_user);
        user_search_click->setObjectName(QString::fromUtf8("user_search_click"));
        user_search_click->setGeometry(QRect(720, 50, 71, 31));
        user_search_click->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgb(67,180,136);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        user_search_refresh = new QPushButton(page_user);
        user_search_refresh->setObjectName(QString::fromUtf8("user_search_refresh"));
        user_search_refresh->setGeometry(QRect(790, 50, 71, 31));
        user_search_refresh->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:rgb(227,192,104);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3 = new QLabel(page_user);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 881, 41));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-bottom:1px solid rgb(204, 204, 204);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(103, 103, 103);"));
        widget_3 = new QWidget(page_user);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 120, 161, 221));
        widget_3->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color:rgb(255,255,255);"));
        user_option_choose = new QComboBox(widget_3);
        user_option_choose->setObjectName(QString::fromUtf8("user_option_choose"));
        user_option_choose->setGeometry(QRect(10, 40, 141, 31));
        user_option_choose->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding-left:6px;\n"
"	color: rgb(88, 88, 88);\n"
"}\n"
"\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	margin-right:10px;\n"
"	width:14px;\n"
"	height:7px;\n"
"	border-image: url(:/res/icon/icon_arrow_down.png);\n"
"}"));
        user_delete = new QPushButton(widget_3);
        user_delete->setObjectName(QString::fromUtf8("user_delete"));
        user_delete->setGeometry(QRect(10, 80, 141, 31));
        user_delete->setStyleSheet(QString::fromUtf8("color: rgb(88, 88, 88);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_13 = new QLabel(widget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 10, 61, 21));
        label_13->setStyleSheet(QString::fromUtf8("border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        widget_4 = new QWidget(page_user);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(10, 90, 161, 31));
        widget_4->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color: rgb(61, 65, 73);"));
        label_14 = new QLabel(widget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 5, 71, 21));
        label_14->setStyleSheet(QString::fromUtf8("border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        widget_5 = new QWidget(page_user);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(10, 375, 161, 191));
        widget_5->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color:rgb(255,255,255);"));
        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 41, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(45, 45, 45);\n"
"border:none;"));
        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 51, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(45, 45, 45);\n"
"border:none;"));
        add_user_auth = new QComboBox(widget_5);
        add_user_auth->addItem(QString());
        add_user_auth->addItem(QString());
        add_user_auth->addItem(QString());
        add_user_auth->setObjectName(QString::fromUtf8("add_user_auth"));
        add_user_auth->setGeometry(QRect(60, 60, 91, 31));
        add_user_auth->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding-left:6px;\n"
"	color: rgb(88, 88, 88);\n"
"	border:1px solid rgb(204, 204, 204);\n"
"	border-radius:2px;\n"
"}\n"
"\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	margin-right:12px;\n"
"	width:16px;\n"
"	height:8px;\n"
"	border-image: url(:/res/icon/icon_arrow_down.png);\n"
"}"));
        label_9 = new QLabel(widget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 100, 41, 31));
        add_user_id = new QLineEdit(widget_5);
        add_user_id->setObjectName(QString::fromUtf8("add_user_id"));
        add_user_id->setGeometry(QRect(60, 20, 91, 31));
        add_user_id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"padding-left:4px;\n"
"color: rgb(88, 88, 88);\n"
"border:1px solid rgb(204, 204, 204);\n"
"border-radius:2px;"));
        add_user_id->setMaxLength(10);
        add_user_balance = new QSpinBox(widget_5);
        add_user_balance->setObjectName(QString::fromUtf8("add_user_balance"));
        add_user_balance->setGeometry(QRect(60, 100, 91, 31));
        add_user_balance->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"   	border:none;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border:1px solid rgb(204, 204, 204);\n"
"	border-radius:2px;\n"
"	padding-left:6px;\n"
"	color: rgb(88, 88, 88);\n"
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
        add_user_balance->setMaximum(32767);
        user_add = new QPushButton(widget_5);
        user_add->setObjectName(QString::fromUtf8("user_add"));
        user_add->setGeometry(QRect(10, 140, 141, 31));
        user_add->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"border-radius:3px;\n"
"color: rgb(88, 88, 88);\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        widget_6 = new QWidget(page_user);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(10, 350, 161, 31));
        widget_6->setStyleSheet(QString::fromUtf8("border:1px solid rgb(204,204,204);\n"
"background-color: rgb(61, 65, 73);"));
        label_15 = new QLabel(widget_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 5, 71, 21));
        label_15->setStyleSheet(QString::fromUtf8("border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(page_user);
        user_list->raise();
        user_search_choose->raise();
        user_search_input->raise();
        user_search_refresh->raise();
        label_3->raise();
        user_search_click->raise();
        widget_3->raise();
        widget_4->raise();
        widget_5->raise();
        widget_6->raise();

        retranslateUi(BackStage);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BackStage);
    } // setupUi

    void retranslateUi(QWidget *BackStage)
    {
        BackStage->setWindowTitle(QCoreApplication::translate("BackStage", "Form", nullptr));
        packet_page_select->setText(QCoreApplication::translate("BackStage", "\345\277\253\351\200\222\344\277\241\346\201\257", nullptr));
        sign_out_click->setText(QCoreApplication::translate("BackStage", "\351\200\200\345\207\272", nullptr));
        user_page_select->setText(QCoreApplication::translate("BackStage", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("BackStage", "LMS", nullptr));
        packet_search_refresh->setText(QCoreApplication::translate("BackStage", "Refresh", nullptr));
        packet_search_choose->setItemText(0, QCoreApplication::translate("BackStage", "\350\277\220\345\215\225\345\217\267", nullptr));
        packet_search_choose->setItemText(1, QCoreApplication::translate("BackStage", "\346\224\266\344\273\266\344\272\272", nullptr));
        packet_search_choose->setItemText(2, QCoreApplication::translate("BackStage", "\346\224\266\344\273\266\346\227\266\351\227\264", nullptr));
        packet_search_choose->setItemText(3, QCoreApplication::translate("BackStage", "\345\257\204\344\273\266\346\227\266\351\227\264", nullptr));
        packet_search_choose->setItemText(4, QCoreApplication::translate("BackStage", "\345\257\204\344\273\266\344\272\272", nullptr));
        packet_search_choose->setItemText(5, QCoreApplication::translate("BackStage", "ALL", nullptr));

        packet_search_input->setPlaceholderText(QCoreApplication::translate("BackStage", "\346\220\234\347\264\242", nullptr));
        packet_search_click->setText(QCoreApplication::translate("BackStage", "Search", nullptr));
        label_2->setText(QCoreApplication::translate("BackStage", "    PACKET-BACKSTAGE", nullptr));
        packet_alloc->setText(QCoreApplication::translate("BackStage", "Alloc", nullptr));
        option_packet_id->setText(QString());
        label->setText(QCoreApplication::translate("BackStage", "Packet", nullptr));
        label_12->setText(QCoreApplication::translate("BackStage", "New", nullptr));
        auto_allocation->setText(QCoreApplication::translate("BackStage", "Auto Allocate", nullptr));
        user_search_choose->setItemText(0, QCoreApplication::translate("BackStage", "\347\224\250\346\210\267\345\220\215", nullptr));
        user_search_choose->setItemText(1, QCoreApplication::translate("BackStage", "\345\247\223\345\220\215", nullptr));
        user_search_choose->setItemText(2, QCoreApplication::translate("BackStage", "\347\224\265\350\257\235", nullptr));
        user_search_choose->setItemText(3, QCoreApplication::translate("BackStage", "\345\234\260\345\235\200", nullptr));

        user_search_input->setPlaceholderText(QCoreApplication::translate("BackStage", "\346\220\234\347\264\242", nullptr));
        user_search_click->setText(QCoreApplication::translate("BackStage", "Search", nullptr));
        user_search_refresh->setText(QCoreApplication::translate("BackStage", "Refresh", nullptr));
        label_3->setText(QCoreApplication::translate("BackStage", "    USER-BACKSTAGE", nullptr));
        user_delete->setText(QCoreApplication::translate("BackStage", "Delete", nullptr));
        label_13->setText(QCoreApplication::translate("BackStage", "USER", nullptr));
        label_14->setText(QCoreApplication::translate("BackStage", "OPTION", nullptr));
        label_7->setText(QCoreApplication::translate("BackStage", "\346\235\203\351\231\220", nullptr));
        label_5->setText(QCoreApplication::translate("BackStage", "\347\224\250\346\210\267\345\220\215", nullptr));
        add_user_auth->setItemText(0, QCoreApplication::translate("BackStage", "\347\224\250\346\210\267", nullptr));
        add_user_auth->setItemText(1, QCoreApplication::translate("BackStage", "\345\277\253\351\200\222\345\221\230", nullptr));
        add_user_auth->setItemText(2, QCoreApplication::translate("BackStage", "\347\256\241\347\220\206\345\221\230", nullptr));

        label_9->setStyleSheet(QCoreApplication::translate("BackStage", "font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(45, 45, 45);\n"
"border:none;", nullptr));
        label_9->setText(QCoreApplication::translate("BackStage", "\344\275\231\351\242\235", nullptr));
        add_user_id->setPlaceholderText(QString());
        user_add->setText(QCoreApplication::translate("BackStage", "Add", nullptr));
        label_15->setText(QCoreApplication::translate("BackStage", "NEW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackStage: public Ui_BackStage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKSTAGE_H
