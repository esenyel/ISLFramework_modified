/********************************************************************************
** Form generated from reading UI file 'imageprocessdialog.ui'
**
** Created: Mon Oct 19 12:15:19 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROCESSDIALOG_H
#define UI_IMAGEPROCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageProcessDialog
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QSlider *horsliderValLower;
    QLabel *label_8;
    QLineEdit *lEditBubbleNameAdd_2;
    QLabel *label_12;
    QLabel *labelOrgImage;
    QLabel *label_13;
    QLabel *label_10;
    QLineEdit *lEditBubbleNameFilter_4;
    QSlider *horsliderSatLower;
    QPushButton *butAddtoFilterNames;
    QListView *listViewVisFilterNames;
    QLabel *label_4;
    QListView *listViewInputFileNames;
    QPushButton *butAddtoInputFileNames;
    QPushButton *butRemoveInputFileNames;
    QGroupBox *groupBox;
    QRadioButton *rButHue_4;
    QRadioButton *rButFilter_4;
    QCheckBox *cBoxBubbleStats_4;
    QCheckBox *cBoxInvariants_4;
    QLineEdit *lEditNoHarmonicsInvariant_4;
    QLabel *label_15;
    QCheckBox *cBoxBubble_4;
    QCheckBox *cBoxOmni_4;
    QLineEdit *lEditNoImagesOmni_4;
    QLineEdit *lEditAngleOffsetOmni_4;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *lEditSatLower;
    QGroupBox *gBoxLDSet;
    QLineEdit *lEditDSetPath_4;
    QPushButton *butSetDSetPath_4;
    QPushButton *but_LoadImage_4;
    QPushButton *butApplyAll;
    QPushButton *butRemoveFilterNames;
    QGroupBox *gboxFilterTools;
    QPushButton *butLoadFilter_4;
    QPushButton *butApplyFilter_4;
    QLineEdit *lEditValLower;
    QLabel *label_18;
    QLineEdit *lEditSatUpper;
    QLabel *label_19;
    QSlider *horsliderValUpper;
    QLabel *label_20;
    QLineEdit *lEditValUpper;
    QLabel *labelProcessedImage;
    QSlider *horsliderSatUpper;

    void setupUi(QDialog *ImageProcessDialog)
    {
        if (ImageProcessDialog->objectName().isEmpty())
            ImageProcessDialog->setObjectName(QString::fromUtf8("ImageProcessDialog"));
        ImageProcessDialog->resize(999, 557);
        scrollArea = new QScrollArea(ImageProcessDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 1001, 641));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 999, 639));
        horsliderValLower = new QSlider(scrollAreaWidgetContents_3);
        horsliderValLower->setObjectName(QString::fromUtf8("horsliderValLower"));
        horsliderValLower->setGeometry(QRect(300, 320, 251, 29));
        horsliderValLower->setMaximum(255);
        horsliderValLower->setSliderPosition(30);
        horsliderValLower->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(scrollAreaWidgetContents_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(590, 20, 101, 17));
        lEditBubbleNameAdd_2 = new QLineEdit(scrollAreaWidgetContents_3);
        lEditBubbleNameAdd_2->setObjectName(QString::fromUtf8("lEditBubbleNameAdd_2"));
        lEditBubbleNameAdd_2->setGeometry(QRect(630, 240, 91, 27));
        label_12 = new QLabel(scrollAreaWidgetContents_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 20, 101, 17));
        labelOrgImage = new QLabel(scrollAreaWidgetContents_3);
        labelOrgImage->setObjectName(QString::fromUtf8("labelOrgImage"));
        labelOrgImage->setGeometry(QRect(20, 50, 260, 180));
        labelOrgImage->setFrameShape(QFrame::Box);
        label_13 = new QLabel(scrollAreaWidgetContents_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(370, 20, 121, 17));
        label_10 = new QLabel(scrollAreaWidgetContents_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(320, 310, 67, 17));
        lEditBubbleNameFilter_4 = new QLineEdit(scrollAreaWidgetContents_3);
        lEditBubbleNameFilter_4->setObjectName(QString::fromUtf8("lEditBubbleNameFilter_4"));
        lEditBubbleNameFilter_4->setGeometry(QRect(830, 240, 91, 27));
        horsliderSatLower = new QSlider(scrollAreaWidgetContents_3);
        horsliderSatLower->setObjectName(QString::fromUtf8("horsliderSatLower"));
        horsliderSatLower->setGeometry(QRect(30, 320, 251, 29));
        horsliderSatLower->setMaximum(255);
        horsliderSatLower->setSliderPosition(30);
        horsliderSatLower->setOrientation(Qt::Horizontal);
        butAddtoFilterNames = new QPushButton(scrollAreaWidgetContents_3);
        butAddtoFilterNames->setObjectName(QString::fromUtf8("butAddtoFilterNames"));
        butAddtoFilterNames->setGeometry(QRect(930, 240, 31, 27));
        listViewVisFilterNames = new QListView(scrollAreaWidgetContents_3);
        listViewVisFilterNames->setObjectName(QString::fromUtf8("listViewVisFilterNames"));
        listViewVisFilterNames->setGeometry(QRect(790, 40, 171, 192));
        label_4 = new QLabel(scrollAreaWidgetContents_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 270, 67, 17));
        listViewInputFileNames = new QListView(scrollAreaWidgetContents_3);
        listViewInputFileNames->setObjectName(QString::fromUtf8("listViewInputFileNames"));
        listViewInputFileNames->setGeometry(QRect(590, 40, 171, 192));
        butAddtoInputFileNames = new QPushButton(scrollAreaWidgetContents_3);
        butAddtoInputFileNames->setObjectName(QString::fromUtf8("butAddtoInputFileNames"));
        butAddtoInputFileNames->setGeometry(QRect(730, 240, 31, 27));
        butRemoveInputFileNames = new QPushButton(scrollAreaWidgetContents_3);
        butRemoveInputFileNames->setObjectName(QString::fromUtf8("butRemoveInputFileNames"));
        butRemoveInputFileNames->setGeometry(QRect(590, 240, 31, 27));
        groupBox = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(590, 310, 371, 181));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{border: 1px solid #000;}\n"
"border-color: rgb(0, 0, 0);\n"
""));
        rButHue_4 = new QRadioButton(groupBox);
        rButHue_4->setObjectName(QString::fromUtf8("rButHue_4"));
        rButHue_4->setGeometry(QRect(270, 10, 116, 22));
        rButFilter_4 = new QRadioButton(groupBox);
        rButFilter_4->setObjectName(QString::fromUtf8("rButFilter_4"));
        rButFilter_4->setGeometry(QRect(270, 40, 116, 22));
        cBoxBubbleStats_4 = new QCheckBox(groupBox);
        cBoxBubbleStats_4->setObjectName(QString::fromUtf8("cBoxBubbleStats_4"));
        cBoxBubbleStats_4->setGeometry(QRect(120, 10, 111, 22));
        cBoxInvariants_4 = new QCheckBox(groupBox);
        cBoxInvariants_4->setObjectName(QString::fromUtf8("cBoxInvariants_4"));
        cBoxInvariants_4->setGeometry(QRect(120, 40, 97, 22));
        lEditNoHarmonicsInvariant_4 = new QLineEdit(groupBox);
        lEditNoHarmonicsInvariant_4->setObjectName(QString::fromUtf8("lEditNoHarmonicsInvariant_4"));
        lEditNoHarmonicsInvariant_4->setGeometry(QRect(220, 60, 41, 27));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(124, 65, 101, 17));
        cBoxBubble_4 = new QCheckBox(groupBox);
        cBoxBubble_4->setObjectName(QString::fromUtf8("cBoxBubble_4"));
        cBoxBubble_4->setGeometry(QRect(10, 30, 97, 22));
        cBoxOmni_4 = new QCheckBox(groupBox);
        cBoxOmni_4->setObjectName(QString::fromUtf8("cBoxOmni_4"));
        cBoxOmni_4->setGeometry(QRect(120, 90, 97, 22));
        lEditNoImagesOmni_4 = new QLineEdit(groupBox);
        lEditNoImagesOmni_4->setObjectName(QString::fromUtf8("lEditNoImagesOmni_4"));
        lEditNoImagesOmni_4->setGeometry(QRect(220, 110, 41, 27));
        lEditAngleOffsetOmni_4 = new QLineEdit(groupBox);
        lEditAngleOffsetOmni_4->setObjectName(QString::fromUtf8("lEditAngleOffsetOmni_4"));
        lEditAngleOffsetOmni_4->setGeometry(QRect(220, 140, 41, 27));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(125, 145, 91, 17));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(122, 116, 91, 17));
        lEditSatLower = new QLineEdit(scrollAreaWidgetContents_3);
        lEditSatLower->setObjectName(QString::fromUtf8("lEditSatLower"));
        lEditSatLower->setGeometry(QRect(120, 309, 51, 21));
        gBoxLDSet = new QGroupBox(scrollAreaWidgetContents_3);
        gBoxLDSet->setObjectName(QString::fromUtf8("gBoxLDSet"));
        gBoxLDSet->setGeometry(QRect(30, 390, 281, 121));
        gBoxLDSet->setStyleSheet(QString::fromUtf8("QGroupBox{border: 1px solid #000;}\n"
"border-color: rgb(0, 0, 0);\n"
""));
        lEditDSetPath_4 = new QLineEdit(gBoxLDSet);
        lEditDSetPath_4->setObjectName(QString::fromUtf8("lEditDSetPath_4"));
        lEditDSetPath_4->setGeometry(QRect(2, 30, 271, 27));
        lEditDSetPath_4->setReadOnly(true);
        butSetDSetPath_4 = new QPushButton(gBoxLDSet);
        butSetDSetPath_4->setObjectName(QString::fromUtf8("butSetDSetPath_4"));
        butSetDSetPath_4->setGeometry(QRect(10, 80, 100, 27));
        but_LoadImage_4 = new QPushButton(gBoxLDSet);
        but_LoadImage_4->setObjectName(QString::fromUtf8("but_LoadImage_4"));
        but_LoadImage_4->setGeometry(QRect(120, 80, 100, 27));
        butApplyAll = new QPushButton(scrollAreaWidgetContents_3);
        butApplyAll->setObjectName(QString::fromUtf8("butApplyAll"));
        butApplyAll->setGeometry(QRect(730, 510, 97, 27));
        butRemoveFilterNames = new QPushButton(scrollAreaWidgetContents_3);
        butRemoveFilterNames->setObjectName(QString::fromUtf8("butRemoveFilterNames"));
        butRemoveFilterNames->setGeometry(QRect(790, 240, 31, 27));
        gboxFilterTools = new QGroupBox(scrollAreaWidgetContents_3);
        gboxFilterTools->setObjectName(QString::fromUtf8("gboxFilterTools"));
        gboxFilterTools->setGeometry(QRect(330, 390, 231, 71));
        gboxFilterTools->setStyleSheet(QString::fromUtf8("QGroupBox{border: 1px solid #000;}\n"
"border-color: rgb(0, 0, 0);\n"
""));
        gboxFilterTools->setTitle(QString::fromUtf8("Filter Tools"));
        gboxFilterTools->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gboxFilterTools->setFlat(false);
        butLoadFilter_4 = new QPushButton(gboxFilterTools);
        butLoadFilter_4->setObjectName(QString::fromUtf8("butLoadFilter_4"));
        butLoadFilter_4->setGeometry(QRect(10, 30, 97, 27));
        butApplyFilter_4 = new QPushButton(gboxFilterTools);
        butApplyFilter_4->setObjectName(QString::fromUtf8("butApplyFilter_4"));
        butApplyFilter_4->setGeometry(QRect(120, 30, 97, 27));
        lEditValLower = new QLineEdit(scrollAreaWidgetContents_3);
        lEditValLower->setObjectName(QString::fromUtf8("lEditValLower"));
        lEditValLower->setGeometry(QRect(400, 309, 51, 21));
        label_18 = new QLabel(scrollAreaWidgetContents_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(790, 20, 111, 17));
        lEditSatUpper = new QLineEdit(scrollAreaWidgetContents_3);
        lEditSatUpper->setObjectName(QString::fromUtf8("lEditSatUpper"));
        lEditSatUpper->setGeometry(QRect(120, 268, 51, 21));
        label_19 = new QLabel(scrollAreaWidgetContents_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(320, 270, 67, 17));
        horsliderValUpper = new QSlider(scrollAreaWidgetContents_3);
        horsliderValUpper->setObjectName(QString::fromUtf8("horsliderValUpper"));
        horsliderValUpper->setGeometry(QRect(300, 280, 251, 29));
        horsliderValUpper->setMaximum(255);
        horsliderValUpper->setSliderPosition(230);
        horsliderValUpper->setOrientation(Qt::Horizontal);
        label_20 = new QLabel(scrollAreaWidgetContents_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(40, 310, 67, 17));
        lEditValUpper = new QLineEdit(scrollAreaWidgetContents_3);
        lEditValUpper->setObjectName(QString::fromUtf8("lEditValUpper"));
        lEditValUpper->setGeometry(QRect(400, 269, 51, 21));
        labelProcessedImage = new QLabel(scrollAreaWidgetContents_3);
        labelProcessedImage->setObjectName(QString::fromUtf8("labelProcessedImage"));
        labelProcessedImage->setGeometry(QRect(300, 50, 260, 180));
        labelProcessedImage->setFrameShape(QFrame::Box);
        horsliderSatUpper = new QSlider(scrollAreaWidgetContents_3);
        horsliderSatUpper->setObjectName(QString::fromUtf8("horsliderSatUpper"));
        horsliderSatUpper->setGeometry(QRect(30, 280, 251, 29));
        horsliderSatUpper->setMaximum(255);
        horsliderSatUpper->setSliderPosition(230);
        horsliderSatUpper->setOrientation(Qt::Horizontal);
        scrollArea->setWidget(scrollAreaWidgetContents_3);

        retranslateUi(ImageProcessDialog);

        QMetaObject::connectSlotsByName(ImageProcessDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageProcessDialog)
    {
        ImageProcessDialog->setWindowTitle(QString());
        label_8->setText(QApplication::translate("ImageProcessDialog", "File Names", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ImageProcessDialog", "Original Image", 0, QApplication::UnicodeUTF8));
        labelOrgImage->setText(QString());
        label_13->setText(QApplication::translate("ImageProcessDialog", "Processed Image", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ImageProcessDialog", "Val Lower", 0, QApplication::UnicodeUTF8));
        butAddtoFilterNames->setText(QApplication::translate("ImageProcessDialog", "+", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ImageProcessDialog", "Sat Upper", 0, QApplication::UnicodeUTF8));
        butAddtoInputFileNames->setText(QApplication::translate("ImageProcessDialog", "+", 0, QApplication::UnicodeUTF8));
        butRemoveInputFileNames->setText(QApplication::translate("ImageProcessDialog", "-", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ImageProcessDialog", "Toolbox", 0, QApplication::UnicodeUTF8));
        rButHue_4->setText(QApplication::translate("ImageProcessDialog", "Hue", 0, QApplication::UnicodeUTF8));
        rButFilter_4->setText(QApplication::translate("ImageProcessDialog", "Filter", 0, QApplication::UnicodeUTF8));
        cBoxBubbleStats_4->setText(QApplication::translate("ImageProcessDialog", "Bubble Stats", 0, QApplication::UnicodeUTF8));
        cBoxInvariants_4->setText(QApplication::translate("ImageProcessDialog", "Invariants", 0, QApplication::UnicodeUTF8));
        lEditNoHarmonicsInvariant_4->setText(QString());
        label_15->setText(QApplication::translate("ImageProcessDialog", "Harmonic No:", 0, QApplication::UnicodeUTF8));
        cBoxBubble_4->setText(QApplication::translate("ImageProcessDialog", "Bubble", 0, QApplication::UnicodeUTF8));
        cBoxOmni_4->setText(QApplication::translate("ImageProcessDialog", "Omni", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("ImageProcessDialog", "Angle Offset", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("ImageProcessDialog", "No of Images", 0, QApplication::UnicodeUTF8));
        gBoxLDSet->setTitle(QApplication::translate("ImageProcessDialog", "Load Dataset", 0, QApplication::UnicodeUTF8));
        butSetDSetPath_4->setText(QApplication::translate("ImageProcessDialog", "Set Path", 0, QApplication::UnicodeUTF8));
        but_LoadImage_4->setText(QApplication::translate("ImageProcessDialog", "Load Image", 0, QApplication::UnicodeUTF8));
        butApplyAll->setText(QApplication::translate("ImageProcessDialog", "Apply All", 0, QApplication::UnicodeUTF8));
        butRemoveFilterNames->setText(QApplication::translate("ImageProcessDialog", "-", 0, QApplication::UnicodeUTF8));
        butLoadFilter_4->setText(QApplication::translate("ImageProcessDialog", "Load Filter", 0, QApplication::UnicodeUTF8));
        butApplyFilter_4->setText(QApplication::translate("ImageProcessDialog", "Apply Filter", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("ImageProcessDialog", "Filter Names", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("ImageProcessDialog", "Val Upper", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("ImageProcessDialog", "Sat Lower", 0, QApplication::UnicodeUTF8));
        labelProcessedImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageProcessDialog: public Ui_ImageProcessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESSDIALOG_H
