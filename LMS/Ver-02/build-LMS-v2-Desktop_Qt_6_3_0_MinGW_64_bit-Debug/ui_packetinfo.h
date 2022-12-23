/********************************************************************************
** Form generated from reading UI file 'packetinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKETINFO_H
#define UI_PACKETINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PacketInfo
{
public:
    QWidget *widget;
    QLabel *packet_id;
    QLabel *label;
    QLabel *dest_user;
    QLabel *from_user;
    QLabel *label_4;
    QPushButton *packet_recv_click;
    QLabel *recv_time;
    QLabel *packet_status;
    QLabel *label_2;
    QPushButton *view_detail;
    QWidget *detail;
    QLabel *send_time;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *packet_describe;
    QPushButton *expand_close_click;
    QLabel *label_6;
    QLabel *count_type;
    QLabel *packet_count;
    QLabel *packet_price;
    QLabel *label_9;
    QPushButton *packet_collect_click;
    QLabel *packet_type;
    QLabel *label_7;

    void setupUi(QWidget *PacketInfo)
    {
        if (PacketInfo->objectName().isEmpty())
            PacketInfo->setObjectName(QString::fromUtf8("PacketInfo"));
        PacketInfo->resize(390, 170);
        PacketInfo->setStyleSheet(QString::fromUtf8("background:none;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        widget = new QWidget(PacketInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 370, 150));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:14px;"));
        packet_id = new QLabel(widget);
        packet_id->setObjectName(QString::fromUtf8("packet_id"));
        packet_id->setGeometry(QRect(80, 10, 131, 20));
        packet_id->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 54, 21));
        label->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        dest_user = new QLabel(widget);
        dest_user->setObjectName(QString::fromUtf8("dest_user"));
        dest_user->setGeometry(QRect(230, 45, 101, 31));
        dest_user->setStyleSheet(QString::fromUtf8("font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"text-align:center;"));
        from_user = new QLabel(widget);
        from_user->setObjectName(QString::fromUtf8("from_user"));
        from_user->setGeometry(QRect(30, 45, 91, 31));
        from_user->setStyleSheet(QString::fromUtf8("font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"text-align:center;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 35, 101, 31));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_send_arrow.png);\n"
"background:none;\n"
"border:none;"));
        packet_recv_click = new QPushButton(widget);
        packet_recv_click->setObjectName(QString::fromUtf8("packet_recv_click"));
        packet_recv_click->setGeometry(QRect(260, 110, 81, 31));
        packet_recv_click->setStyleSheet(QString::fromUtf8("border:1.5px solid rgb(204,204,204);\n"
"border-radius:14px;\n"
"color: rgb(0, 0, 0);"));
        recv_time = new QLabel(widget);
        recv_time->setObjectName(QString::fromUtf8("recv_time"));
        recv_time->setGeometry(QRect(90, 120, 160, 16));
        recv_time->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        packet_status = new QLabel(widget);
        packet_status->setObjectName(QString::fromUtf8("packet_status"));
        packet_status->setGeometry(QRect(150, 65, 61, 21));
        packet_status->setStyleSheet(QString::fromUtf8("font: 700 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"text-align:center;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 120, 61, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        view_detail = new QPushButton(widget);
        view_detail->setObjectName(QString::fromUtf8("view_detail"));
        view_detail->setGeometry(QRect(310, 7, 51, 31));
        view_detail->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_packet_detail.png);"));
        detail = new QWidget(widget);
        detail->setObjectName(QString::fromUtf8("detail"));
        detail->setGeometry(QRect(10, 10, 351, 131));
        detail->setStyleSheet(QString::fromUtf8(""));
        send_time = new QLabel(detail);
        send_time->setObjectName(QString::fromUtf8("send_time"));
        send_time->setGeometry(QRect(90, 40, 171, 21));
        send_time->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        label_3 = new QLabel(detail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 61, 21));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(detail);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 100, 61, 21));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        packet_describe = new QLabel(detail);
        packet_describe->setObjectName(QString::fromUtf8("packet_describe"));
        packet_describe->setGeometry(QRect(90, 100, 241, 20));
        packet_describe->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        expand_close_click = new QPushButton(detail);
        expand_close_click->setObjectName(QString::fromUtf8("expand_close_click"));
        expand_close_click->setGeometry(QRect(0, 0, 41, 31));
        expand_close_click->setStyleSheet(QString::fromUtf8("image: url(:/res/icon/icon_go_back.png);"));
        label_6 = new QLabel(detail);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 7, 81, 21));
        label_6->setStyleSheet(QString::fromUtf8("background:none;;\n"
"border:none;\n"
"font: 700 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(58,58,58);"));
        count_type = new QLabel(detail);
        count_type->setObjectName(QString::fromUtf8("count_type"));
        count_type->setGeometry(QRect(10, 70, 71, 21));
        count_type->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        packet_count = new QLabel(detail);
        packet_count->setObjectName(QString::fromUtf8("packet_count"));
        packet_count->setGeometry(QRect(90, 70, 61, 20));
        packet_count->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        packet_price = new QLabel(detail);
        packet_price->setObjectName(QString::fromUtf8("packet_price"));
        packet_price->setGeometry(QRect(250, 70, 61, 20));
        packet_price->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        label_9 = new QLabel(detail);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 70, 51, 21));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border:none;\n"
"font: 700 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        packet_collect_click = new QPushButton(widget);
        packet_collect_click->setObjectName(QString::fromUtf8("packet_collect_click"));
        packet_collect_click->setGeometry(QRect(260, 110, 81, 31));
        packet_collect_click->setStyleSheet(QString::fromUtf8("border:1.5px solid rgb(204,204,204);\n"
"border-radius:14px;\n"
"color: rgb(0, 0, 0);"));
        packet_type = new QLabel(widget);
        packet_type->setObjectName(QString::fromUtf8("packet_type"));
        packet_type->setGeometry(QRect(90, 90, 81, 20));
        packet_type->setStyleSheet(QString::fromUtf8("font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 90, 61, 21));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);\n"
"border:none;\n"
"font: 700 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(88, 88, 88);"));
        packet_id->raise();
        label->raise();
        dest_user->raise();
        from_user->raise();
        label_4->raise();
        packet_recv_click->raise();
        recv_time->raise();
        packet_status->raise();
        label_2->raise();
        view_detail->raise();
        packet_collect_click->raise();
        packet_type->raise();
        label_7->raise();
        detail->raise();

        retranslateUi(PacketInfo);

        QMetaObject::connectSlotsByName(PacketInfo);
    } // setupUi

    void retranslateUi(QWidget *PacketInfo)
    {
        PacketInfo->setWindowTitle(QCoreApplication::translate("PacketInfo", "Form", nullptr));
        packet_id->setText(QCoreApplication::translate("PacketInfo", "test", nullptr));
        label->setText(QCoreApplication::translate("PacketInfo", "\350\277\220\345\215\225\345\217\267", nullptr));
        dest_user->setText(QCoreApplication::translate("PacketInfo", "<html><head/><body><p>destUser</p></body></html>", nullptr));
        from_user->setText(QCoreApplication::translate("PacketInfo", "<html><head/><body><p>fromUser</p></body></html>", nullptr));
        label_4->setText(QString());
        packet_recv_click->setText(QCoreApplication::translate("PacketInfo", "\347\255\276\346\224\266", nullptr));
        recv_time->setText(QCoreApplication::translate("PacketInfo", "Time", nullptr));
        packet_status->setText(QCoreApplication::translate("PacketInfo", "<html><head/><body><p align=\"center\">\350\277\220\350\276\223\344\270\255</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("PacketInfo", "\347\255\276\346\224\266\346\227\266\351\227\264", nullptr));
        view_detail->setText(QString());
        send_time->setText(QCoreApplication::translate("PacketInfo", "Time", nullptr));
        label_3->setText(QCoreApplication::translate("PacketInfo", "\345\257\204\344\273\266\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("PacketInfo", "\347\211\251\345\223\201\346\217\217\350\277\260", nullptr));
        packet_describe->setText(QCoreApplication::translate("PacketInfo", "describe", nullptr));
        expand_close_click->setText(QString());
        label_6->setText(QCoreApplication::translate("PacketInfo", "<html><head/><body><p align=\"center\">\350\257\246\346\203\205</p></body></html>", nullptr));
        count_type->setText(QCoreApplication::translate("PacketInfo", "\351\207\215\351\207\217/\346\225\260\351\207\217", nullptr));
        packet_count->setText(QCoreApplication::translate("PacketInfo", "count", nullptr));
        packet_price->setText(QCoreApplication::translate("PacketInfo", "price", nullptr));
        label_9->setText(QCoreApplication::translate("PacketInfo", "\346\200\273\344\273\267", nullptr));
        packet_collect_click->setText(QCoreApplication::translate("PacketInfo", "\346\217\275\346\224\266", nullptr));
        packet_type->setText(QCoreApplication::translate("PacketInfo", "type", nullptr));
        label_7->setText(QCoreApplication::translate("PacketInfo", "\347\211\251\345\223\201\347\261\273\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PacketInfo: public Ui_PacketInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKETINFO_H
