/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Thu Oct 8 12:31:38 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openFileButton;
    QPushButton *butBubbleProcessing;
    QLineEdit *lEditDBFilePath;
    QPushButton *butChooseDBFile;
    QLineEdit *lEditPlaceLabelsFilePath;
    QPushButton *butPlaceLabelsFile;
    QLineEdit *lEditImageWidth;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lEditImageHeight;
    QLabel *label_3;
    QLineEdit *lEditFocalLength;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(586, 372);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openFileButton = new QPushButton(centralWidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));
        openFileButton->setGeometry(QRect(20, 10, 75, 23));
        butBubbleProcessing = new QPushButton(centralWidget);
        butBubbleProcessing->setObjectName(QString::fromUtf8("butBubbleProcessing"));
        butBubbleProcessing->setGeometry(QRect(140, 10, 171, 27));
        lEditDBFilePath = new QLineEdit(centralWidget);
        lEditDBFilePath->setObjectName(QString::fromUtf8("lEditDBFilePath"));
        lEditDBFilePath->setGeometry(QRect(140, 51, 411, 27));
        butChooseDBFile = new QPushButton(centralWidget);
        butChooseDBFile->setObjectName(QString::fromUtf8("butChooseDBFile"));
        butChooseDBFile->setGeometry(QRect(10, 50, 121, 27));
        lEditPlaceLabelsFilePath = new QLineEdit(centralWidget);
        lEditPlaceLabelsFilePath->setObjectName(QString::fromUtf8("lEditPlaceLabelsFilePath"));
        lEditPlaceLabelsFilePath->setGeometry(QRect(140, 91, 411, 27));
        butPlaceLabelsFile = new QPushButton(centralWidget);
        butPlaceLabelsFile->setObjectName(QString::fromUtf8("butPlaceLabelsFile"));
        butPlaceLabelsFile->setGeometry(QRect(10, 90, 121, 27));
        lEditImageWidth = new QLineEdit(centralWidget);
        lEditImageWidth->setObjectName(QString::fromUtf8("lEditImageWidth"));
        lEditImageWidth->setGeometry(QRect(120, 136, 51, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 140, 91, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 184, 91, 17));
        lEditImageHeight = new QLineEdit(centralWidget);
        lEditImageHeight->setObjectName(QString::fromUtf8("lEditImageHeight"));
        lEditImageHeight->setGeometry(QRect(120, 180, 51, 27));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 224, 91, 17));
        lEditFocalLength = new QLineEdit(centralWidget);
        lEditFocalLength->setObjectName(QString::fromUtf8("lEditFocalLength"));
        lEditFocalLength->setGeometry(QRect(120, 220, 51, 27));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 224, 67, 17));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        openFileButton->setText(QApplication::translate("MainWindow", "OpenFile", 0, QApplication::UnicodeUTF8));
        butBubbleProcessing->setText(QApplication::translate("MainWindow", "Open Bubble Processing", 0, QApplication::UnicodeUTF8));
        butChooseDBFile->setText(QApplication::translate("MainWindow", "Database File", 0, QApplication::UnicodeUTF8));
        lEditPlaceLabelsFilePath->setText(QString());
        butPlaceLabelsFile->setText(QApplication::translate("MainWindow", "Place Labels File", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Image Width:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Image Height:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Focal Length:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "pixels", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
