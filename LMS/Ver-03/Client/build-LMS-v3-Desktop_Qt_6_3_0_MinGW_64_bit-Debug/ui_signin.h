/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signin
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QPushButton *signin_click;
    QLineEdit *signin_pwd_input;
    QLineEdit *signin_id_input;
    QLabel *label;
    QPushButton *signup_switch;
    QLabel *label_3;
    QComboBox *auth_choose;
    QWidget *page_2;
    QPushButton *go_back;
    QPushButton *signup_click;
    QLineEdit *signup_pwd_input;
    QLabel *label_4;
    QLineEdit *signup_id_input;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *signup_pwd_cfm_input;

    void setupUi(QWidget *Signin)
    {
        if (Signin->objectName().isEmpty())
            Signin->setObjectName(QString::fromUtf8("Signin"));
        Signin->resize(400, 300);
        Signin->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(80, 80, 80);\n"
"font: 700 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        stackedWidget = new QStackedWidget(Signin);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 400, 300));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(98, 120, 61, 21));
        signin_click = new QPushButton(page);
        signin_click->setObjectName(QString::fromUtf8("signin_click"));
        signin_click->setGeometry(QRect(160, 180, 81, 31));
        signin_click->setStyleSheet(QString::fromUtf8("border:2px solid rgb(112, 112, 112);\n"
"border-radius:14px;"));
        signin_pwd_input = new QLineEdit(page);
        signin_pwd_input->setObjectName(QString::fromUtf8("signin_pwd_input"));
        signin_pwd_input->setGeometry(QRect(170, 120, 131, 23));
        signin_pwd_input->setStyleSheet(QString::fromUtf8("color: rgb(186, 186, 186);\n"
"border: 1px solid;\n"
"border-radius:1px"));
        signin_pwd_input->setMaxLength(16);
        signin_pwd_input->setFrame(true);
        signin_pwd_input->setEchoMode(QLineEdit::Password);
        signin_pwd_input->setCursorPosition(0);
        signin_pwd_input->setDragEnabled(false);
        signin_pwd_input->setClearButtonEnabled(true);
        signin_id_input = new QLineEdit(page);
        signin_id_input->setObjectName(QString::fromUtf8("signin_id_input"));
        signin_id_input->setGeometry(QRect(170, 80, 131, 23));
        signin_id_input->setStyleSheet(QString::fromUtf8("color: rgb(186, 186, 186);\n"
"border: 1px solid;\n"
"border-radius:1px"));
        signin_id_input->setMaxLength(10);
        signin_id_input->setClearButtonEnabled(true);
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(98, 80, 61, 21));
        signup_switch = new QPushButton(page);
        signup_switch->setObjectName(QString::fromUtf8("signup_switch"));
        signup_switch->setGeometry(QRect(250, 250, 71, 31));
        signup_switch->setStyleSheet(QString::fromUtf8("border:none;\n"
"color: rgb(85, 170, 127);\n"
"border-radius:14px;"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 250, 161, 31));
        auth_choose = new QComboBox(page);
        auth_choose->addItem(QString());
        auth_choose->addItem(QString());
        auth_choose->addItem(QString());
        auth_choose->setObjectName(QString::fromUtf8("auth_choose"));
        auth_choose->setGeometry(QRect(320, 10, 71, 24));
        auth_choose->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius:0px;\n"
"	padding-left:6px;\n"
"	color: rgb(88, 88, 88);\n"
"	border-bottom:1px solid;\n"
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
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        go_back = new QPushButton(page_2);
        go_back->setObjectName(QString::fromUtf8("go_back"));
        go_back->setGeometry(QRect(20, 20, 80, 24));
        go_back->setStyleSheet(QString::fromUtf8("border: none"));
        signup_click = new QPushButton(page_2);
        signup_click->setObjectName(QString::fromUtf8("signup_click"));
        signup_click->setGeometry(QRect(160, 220, 80, 31));
        signup_click->setStyleSheet(QString::fromUtf8("border:2px solid rgb(112, 112, 112);\n"
"border-radius:14px;"));
        signup_pwd_input = new QLineEdit(page_2);
        signup_pwd_input->setObjectName(QString::fromUtf8("signup_pwd_input"));
        signup_pwd_input->setGeometry(QRect(180, 120, 113, 23));
        signup_pwd_input->setStyleSheet(QString::fromUtf8("color: rgb(186, 186, 186);\n"
"border: 1px solid;\n"
"border-radius:1px"));
        signup_pwd_input->setMaxLength(16);
        signup_pwd_input->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 120, 71, 21));
        signup_id_input = new QLineEdit(page_2);
        signup_id_input->setObjectName(QString::fromUtf8("signup_id_input"));
        signup_id_input->setGeometry(QRect(180, 80, 113, 23));
        signup_id_input->setStyleSheet(QString::fromUtf8("color: rgb(186, 186, 186);\n"
"border: 1px solid;\n"
"border-radius:1px"));
        signup_id_input->setMaxLength(10);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 80, 54, 21));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 160, 71, 21));
        signup_pwd_cfm_input = new QLineEdit(page_2);
        signup_pwd_cfm_input->setObjectName(QString::fromUtf8("signup_pwd_cfm_input"));
        signup_pwd_cfm_input->setGeometry(QRect(180, 160, 113, 23));
        signup_pwd_cfm_input->setStyleSheet(QString::fromUtf8("color: rgb(186, 186, 186);\n"
"border: 1px solid;\n"
"border-radius:1px"));
        signup_pwd_cfm_input->setMaxLength(16);
        signup_pwd_cfm_input->setEchoMode(QLineEdit::Password);
        stackedWidget->addWidget(page_2);

        retranslateUi(Signin);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Signin);
    } // setupUi

    void retranslateUi(QWidget *Signin)
    {
        Signin->setWindowTitle(QCoreApplication::translate("Signin", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Signin", "Passwd", nullptr));
        signin_click->setText(QCoreApplication::translate("Signin", "Sign in", nullptr));
        signin_pwd_input->setInputMask(QString());
        signin_pwd_input->setText(QString());
        signin_pwd_input->setPlaceholderText(QCoreApplication::translate("Signin", "\345\257\206\347\240\201", nullptr));
        signin_id_input->setInputMask(QString());
        signin_id_input->setPlaceholderText(QCoreApplication::translate("Signin", "\347\224\250\346\210\267ID", nullptr));
        label->setText(QCoreApplication::translate("Signin", "Userid", nullptr));
        signup_switch->setText(QCoreApplication::translate("Signin", "Sign up", nullptr));
        label_3->setText(QCoreApplication::translate("Signin", "Do not have an account ?", nullptr));
        auth_choose->setItemText(0, QCoreApplication::translate("Signin", "\347\224\250\346\210\267", nullptr));
        auth_choose->setItemText(1, QCoreApplication::translate("Signin", "\345\277\253\351\200\222\345\221\230", nullptr));
        auth_choose->setItemText(2, QCoreApplication::translate("Signin", "\347\256\241\347\220\206\345\221\230", nullptr));

        go_back->setText(QCoreApplication::translate("Signin", "Go Back", nullptr));
        signup_click->setText(QCoreApplication::translate("Signin", "Sign up", nullptr));
        signup_pwd_input->setInputMask(QString());
        signup_pwd_input->setPlaceholderText(QCoreApplication::translate("Signin", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("Signin", "Password", nullptr));
        signup_id_input->setInputMask(QString());
        signup_id_input->setPlaceholderText(QCoreApplication::translate("Signin", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("Signin", "Userid", nullptr));
        label_6->setText(QCoreApplication::translate("Signin", "Confirm", nullptr));
        signup_pwd_cfm_input->setInputMask(QString());
        signup_pwd_cfm_input->setPlaceholderText(QCoreApplication::translate("Signin", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signin: public Ui_Signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
