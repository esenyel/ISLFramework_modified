/********************************************************************************
** Form generated from reading UI file 'irobotdialog.ui'
**
** Created: Thu Oct 8 12:31:34 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IROBOTDIALOG_H
#define UI_IROBOTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_IRobotDialog
{
public:
    QPushButton *butRobotForward;
    QPushButton *butRobotLeft;
    QPushButton *butRobotBack;
    QPushButton *butRobotRight;
    QPushButton *butRobotStop;
    QGroupBox *gBoxRobotComm;
    QLineEdit *lEditRobotPort;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lEditKinectPort;
    QLabel *label_3;
    QLineEdit *lEditCompassPort;
    QLineEdit *lEditHorSpeed;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lEditAngularSpeed;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *butIRobotConnect;
    QPushButton *butIRobotSetFirstOrientation;
    QLineEdit *lEditFirstOrientation;

    void setupUi(QDialog *IRobotDialog)
    {
        if (IRobotDialog->objectName().isEmpty())
            IRobotDialog->setObjectName(QString::fromUtf8("IRobotDialog"));
        IRobotDialog->resize(698, 300);
        butRobotForward = new QPushButton(IRobotDialog);
        butRobotForward->setObjectName(QString::fromUtf8("butRobotForward"));
        butRobotForward->setGeometry(QRect(150, 20, 97, 27));
        butRobotLeft = new QPushButton(IRobotDialog);
        butRobotLeft->setObjectName(QString::fromUtf8("butRobotLeft"));
        butRobotLeft->setGeometry(QRect(30, 60, 97, 27));
        butRobotBack = new QPushButton(IRobotDialog);
        butRobotBack->setObjectName(QString::fromUtf8("butRobotBack"));
        butRobotBack->setGeometry(QRect(150, 100, 97, 27));
        butRobotRight = new QPushButton(IRobotDialog);
        butRobotRight->setObjectName(QString::fromUtf8("butRobotRight"));
        butRobotRight->setGeometry(QRect(260, 60, 97, 27));
        butRobotStop = new QPushButton(IRobotDialog);
        butRobotStop->setObjectName(QString::fromUtf8("butRobotStop"));
        butRobotStop->setGeometry(QRect(150, 60, 97, 27));
        gBoxRobotComm = new QGroupBox(IRobotDialog);
        gBoxRobotComm->setObjectName(QString::fromUtf8("gBoxRobotComm"));
        gBoxRobotComm->setGeometry(QRect(440, 12, 201, 131));
        lEditRobotPort = new QLineEdit(gBoxRobotComm);
        lEditRobotPort->setObjectName(QString::fromUtf8("lEditRobotPort"));
        lEditRobotPort->setGeometry(QRect(120, 20, 61, 27));
        label = new QLabel(gBoxRobotComm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 23, 81, 17));
        label_2 = new QLabel(gBoxRobotComm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 62, 81, 17));
        lEditKinectPort = new QLineEdit(gBoxRobotComm);
        lEditKinectPort->setObjectName(QString::fromUtf8("lEditKinectPort"));
        lEditKinectPort->setGeometry(QRect(120, 59, 61, 27));
        label_3 = new QLabel(gBoxRobotComm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 103, 101, 17));
        lEditCompassPort = new QLineEdit(gBoxRobotComm);
        lEditCompassPort->setObjectName(QString::fromUtf8("lEditCompassPort"));
        lEditCompassPort->setGeometry(QRect(120, 100, 61, 27));
        lEditHorSpeed = new QLineEdit(IRobotDialog);
        lEditHorSpeed->setObjectName(QString::fromUtf8("lEditHorSpeed"));
        lEditHorSpeed->setGeometry(QRect(150, 150, 51, 27));
        label_4 = new QLabel(IRobotDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 154, 121, 17));
        label_5 = new QLabel(IRobotDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(202, 154, 41, 17));
        lEditAngularSpeed = new QLineEdit(IRobotDialog);
        lEditAngularSpeed->setObjectName(QString::fromUtf8("lEditAngularSpeed"));
        lEditAngularSpeed->setGeometry(QRect(150, 186, 51, 27));
        label_6 = new QLabel(IRobotDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(202, 190, 41, 17));
        label_7 = new QLabel(IRobotDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 190, 121, 17));
        butIRobotConnect = new QPushButton(IRobotDialog);
        butIRobotConnect->setObjectName(QString::fromUtf8("butIRobotConnect"));
        butIRobotConnect->setGeometry(QRect(490, 146, 97, 27));
        butIRobotSetFirstOrientation = new QPushButton(IRobotDialog);
        butIRobotSetFirstOrientation->setObjectName(QString::fromUtf8("butIRobotSetFirstOrientation"));
        butIRobotSetFirstOrientation->setGeometry(QRect(400, 190, 151, 27));
        lEditFirstOrientation = new QLineEdit(IRobotDialog);
        lEditFirstOrientation->setObjectName(QString::fromUtf8("lEditFirstOrientation"));
        lEditFirstOrientation->setGeometry(QRect(560, 190, 61, 27));

        retranslateUi(IRobotDialog);

        QMetaObject::connectSlotsByName(IRobotDialog);
    } // setupUi

    void retranslateUi(QDialog *IRobotDialog)
    {
        IRobotDialog->setWindowTitle(QApplication::translate("IRobotDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        butRobotForward->setText(QApplication::translate("IRobotDialog", "Forward", 0, QApplication::UnicodeUTF8));
        butRobotLeft->setText(QApplication::translate("IRobotDialog", "Left", 0, QApplication::UnicodeUTF8));
        butRobotBack->setText(QApplication::translate("IRobotDialog", "Backward", 0, QApplication::UnicodeUTF8));
        butRobotRight->setText(QApplication::translate("IRobotDialog", "Right", 0, QApplication::UnicodeUTF8));
        butRobotStop->setText(QApplication::translate("IRobotDialog", "Stop", 0, QApplication::UnicodeUTF8));
        gBoxRobotComm->setTitle(QApplication::translate("IRobotDialog", "Comm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IRobotDialog", "Robot Port", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IRobotDialog", "Kinect Port", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("IRobotDialog", "Compass Port", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("IRobotDialog", "Horizontal Speed", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("IRobotDialog", "cm/s", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("IRobotDialog", "rad/s", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("IRobotDialog", "Angular Speed", 0, QApplication::UnicodeUTF8));
        butIRobotConnect->setText(QApplication::translate("IRobotDialog", "Connect", 0, QApplication::UnicodeUTF8));
        butIRobotSetFirstOrientation->setText(QApplication::translate("IRobotDialog", "Set First Orientation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IRobotDialog: public Ui_IRobotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IROBOTDIALOG_H
