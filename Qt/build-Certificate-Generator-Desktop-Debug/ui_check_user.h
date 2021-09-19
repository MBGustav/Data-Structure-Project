/********************************************************************************
** Form generated from reading UI file 'check_user.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECK_USER_H
#define UI_CHECK_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Check_User
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *txt_user;
    QLineEdit *txt_pass;
    QPushButton *pushButton;

    void setupUi(QDialog *Check_User)
    {
        if (Check_User->objectName().isEmpty())
            Check_User->setObjectName(QString::fromUtf8("Check_User"));
        Check_User->resize(345, 158);
        widget = new QWidget(Check_User);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 321, 121));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txt_user = new QLineEdit(widget);
        txt_user->setObjectName(QString::fromUtf8("txt_user"));

        verticalLayout->addWidget(txt_user);

        txt_pass = new QLineEdit(widget);
        txt_pass->setObjectName(QString::fromUtf8("txt_pass"));
        txt_pass->setMaxLength(15);
        txt_pass->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(txt_pass);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        retranslateUi(Check_User);

        QMetaObject::connectSlotsByName(Check_User);
    } // setupUi

    void retranslateUi(QDialog *Check_User)
    {
        Check_User->setWindowTitle(QCoreApplication::translate("Check_User", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Check_User", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Check_User", "Password", nullptr));
#if QT_CONFIG(whatsthis)
        txt_pass->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        txt_pass->setText(QCoreApplication::translate("Check_User", "0000000000000", nullptr));
        pushButton->setText(QCoreApplication::translate("Check_User", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Check_User: public Ui_Check_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECK_USER_H
