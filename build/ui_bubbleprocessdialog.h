/********************************************************************************
** Form generated from reading UI file 'bubbleprocessdialog.ui'
**
** Created: Mon Oct 19 12:42:25 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUBBLEPROCESSDIALOG_H
#define UI_BUBBLEPROCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>
#include "glbubbleviewer.h"

QT_BEGIN_NAMESPACE

class Ui_BubbleProcessDialog
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *but_SaveGLWidget;
    GLBubbleViewer *Widget_BPbubbleViewer;
    QGroupBox *GBox_readBubbleFiles;
    QLabel *label_9;
    QLineEdit *Edit_bubbleFilesRootDir_3;
    QPushButton *But_bubbleFilesSetRootDir_3;
    QLabel *label_10;
    QLineEdit *Edit_bubbleFilesExtension_3;
    QPushButton *But_fetchBubbleFiles_3;
    QComboBox *ComboBox_fetchedBubbles_3;
    QPushButton *But_chooseFile_3;
    QPushButton *But_readPoseData_3;
    QPushButton *But_transformBubbles_3;
    QLineEdit *Edit_transformSource_3;
    QLabel *label_11;
    QLabel *label_16;
    QLineEdit *Edit_transformTarget_3;
    QLabel *label_17;
    QLineEdit *Edit_bubbleType_3;
    QLabel *label_18;
    QLineEdit *Edit_bubbleNumber_3;
    QPushButton *But_calcDiff;

    void setupUi(QDialog *BubbleProcessDialog)
    {
        if (BubbleProcessDialog->objectName().isEmpty())
            BubbleProcessDialog->setObjectName(QString::fromUtf8("BubbleProcessDialog"));
        BubbleProcessDialog->resize(801, 394);
        scrollArea = new QScrollArea(BubbleProcessDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(-10, 0, 821, 501));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 819, 499));
        but_SaveGLWidget = new QPushButton(scrollAreaWidgetContents);
        but_SaveGLWidget->setObjectName(QString::fromUtf8("but_SaveGLWidget"));
        but_SaveGLWidget->setGeometry(QRect(560, 340, 97, 27));
        Widget_BPbubbleViewer = new GLBubbleViewer(scrollAreaWidgetContents);
        Widget_BPbubbleViewer->setObjectName(QString::fromUtf8("Widget_BPbubbleViewer"));
        Widget_BPbubbleViewer->setGeometry(QRect(450, 10, 341, 321));
        GBox_readBubbleFiles = new QGroupBox(scrollAreaWidgetContents);
        GBox_readBubbleFiles->setObjectName(QString::fromUtf8("GBox_readBubbleFiles"));
        GBox_readBubbleFiles->setGeometry(QRect(20, 10, 421, 291));
        label_9 = new QLabel(GBox_readBubbleFiles);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 22, 101, 16));
        Edit_bubbleFilesRootDir_3 = new QLineEdit(GBox_readBubbleFiles);
        Edit_bubbleFilesRootDir_3->setObjectName(QString::fromUtf8("Edit_bubbleFilesRootDir_3"));
        Edit_bubbleFilesRootDir_3->setGeometry(QRect(140, 20, 113, 20));
        Edit_bubbleFilesRootDir_3->setReadOnly(true);
        But_bubbleFilesSetRootDir_3 = new QPushButton(GBox_readBubbleFiles);
        But_bubbleFilesSetRootDir_3->setObjectName(QString::fromUtf8("But_bubbleFilesSetRootDir_3"));
        But_bubbleFilesSetRootDir_3->setGeometry(QRect(270, 19, 51, 23));
        label_10 = new QLabel(GBox_readBubbleFiles);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 52, 151, 16));
        Edit_bubbleFilesExtension_3 = new QLineEdit(GBox_readBubbleFiles);
        Edit_bubbleFilesExtension_3->setObjectName(QString::fromUtf8("Edit_bubbleFilesExtension_3"));
        Edit_bubbleFilesExtension_3->setGeometry(QRect(172, 50, 81, 20));
        But_fetchBubbleFiles_3 = new QPushButton(GBox_readBubbleFiles);
        But_fetchBubbleFiles_3->setObjectName(QString::fromUtf8("But_fetchBubbleFiles_3"));
        But_fetchBubbleFiles_3->setGeometry(QRect(10, 160, 101, 23));
        ComboBox_fetchedBubbles_3 = new QComboBox(GBox_readBubbleFiles);
        ComboBox_fetchedBubbles_3->setObjectName(QString::fromUtf8("ComboBox_fetchedBubbles_3"));
        ComboBox_fetchedBubbles_3->setGeometry(QRect(140, 160, 69, 22));
        But_chooseFile_3 = new QPushButton(GBox_readBubbleFiles);
        But_chooseFile_3->setObjectName(QString::fromUtf8("But_chooseFile_3"));
        But_chooseFile_3->setGeometry(QRect(310, 80, 111, 27));
        But_readPoseData_3 = new QPushButton(GBox_readBubbleFiles);
        But_readPoseData_3->setObjectName(QString::fromUtf8("But_readPoseData_3"));
        But_readPoseData_3->setGeometry(QRect(10, 120, 121, 27));
        But_transformBubbles_3 = new QPushButton(GBox_readBubbleFiles);
        But_transformBubbles_3->setObjectName(QString::fromUtf8("But_transformBubbles_3"));
        But_transformBubbles_3->setGeometry(QRect(140, 120, 141, 27));
        Edit_transformSource_3 = new QLineEdit(GBox_readBubbleFiles);
        Edit_transformSource_3->setObjectName(QString::fromUtf8("Edit_transformSource_3"));
        Edit_transformSource_3->setGeometry(QRect(180, 210, 71, 27));
        Edit_transformSource_3->setInputMethodHints(Qt::ImhDigitsOnly);
        label_11 = new QLabel(GBox_readBubbleFiles);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(170, 190, 101, 17));
        label_16 = new QLabel(GBox_readBubbleFiles);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(280, 190, 101, 17));
        Edit_transformTarget_3 = new QLineEdit(GBox_readBubbleFiles);
        Edit_transformTarget_3->setObjectName(QString::fromUtf8("Edit_transformTarget_3"));
        Edit_transformTarget_3->setGeometry(QRect(290, 210, 71, 27));
        Edit_transformTarget_3->setInputMethodHints(Qt::ImhDigitsOnly);
        label_17 = new QLabel(GBox_readBubbleFiles);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 85, 91, 16));
        Edit_bubbleType_3 = new QLineEdit(GBox_readBubbleFiles);
        Edit_bubbleType_3->setObjectName(QString::fromUtf8("Edit_bubbleType_3"));
        Edit_bubbleType_3->setGeometry(QRect(106, 80, 61, 27));
        Edit_bubbleType_3->setInputMethodHints(Qt::ImhDigitsOnly);
        label_18 = new QLabel(GBox_readBubbleFiles);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(176, 86, 61, 16));
        Edit_bubbleNumber_3 = new QLineEdit(GBox_readBubbleFiles);
        Edit_bubbleNumber_3->setObjectName(QString::fromUtf8("Edit_bubbleNumber_3"));
        Edit_bubbleNumber_3->setGeometry(QRect(240, 80, 61, 27));
        Edit_bubbleNumber_3->setInputMethodHints(Qt::ImhDigitsOnly);
        But_calcDiff = new QPushButton(GBox_readBubbleFiles);
        But_calcDiff->setObjectName(QString::fromUtf8("But_calcDiff"));
        But_calcDiff->setGeometry(QRect(210, 250, 131, 27));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(BubbleProcessDialog);

        QMetaObject::connectSlotsByName(BubbleProcessDialog);
    } // setupUi

    void retranslateUi(QDialog *BubbleProcessDialog)
    {
        BubbleProcessDialog->setWindowTitle(QApplication::translate("BubbleProcessDialog", "Bubble Processing", 0, QApplication::UnicodeUTF8));
        but_SaveGLWidget->setText(QApplication::translate("BubbleProcessDialog", "Save", 0, QApplication::UnicodeUTF8));
        GBox_readBubbleFiles->setTitle(QApplication::translate("BubbleProcessDialog", "Read Bubble Files", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BubbleProcessDialog", "Root Directory", 0, QApplication::UnicodeUTF8));
        But_bubbleFilesSetRootDir_3->setText(QApplication::translate("BubbleProcessDialog", "...", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BubbleProcessDialog", "Bubble File Extension", 0, QApplication::UnicodeUTF8));
        But_fetchBubbleFiles_3->setText(QApplication::translate("BubbleProcessDialog", "Fetch Bubbles", 0, QApplication::UnicodeUTF8));
        But_chooseFile_3->setText(QApplication::translate("BubbleProcessDialog", "Choose Bubble", 0, QApplication::UnicodeUTF8));
        But_readPoseData_3->setText(QApplication::translate("BubbleProcessDialog", "Read Pose Data", 0, QApplication::UnicodeUTF8));
        But_transformBubbles_3->setText(QApplication::translate("BubbleProcessDialog", "Transform Bubbles", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BubbleProcessDialog", "Source Bubble", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("BubbleProcessDialog", "Target Bubble", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("BubbleProcessDialog", "Bubble Type:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("BubbleProcessDialog", "Number:", 0, QApplication::UnicodeUTF8));
        But_calcDiff->setText(QApplication::translate("BubbleProcessDialog", "Calculate Diff", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BubbleProcessDialog: public Ui_BubbleProcessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUBBLEPROCESSDIALOG_H
