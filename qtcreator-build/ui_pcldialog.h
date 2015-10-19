/********************************************************************************
** Form generated from reading UI file 'pcldialog.ui'
**
** Created: Mon Oct 19 12:15:19 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLDIALOG_H
#define UI_PCLDIALOG_H

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
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PclDialog
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVTKWidget *qvtkwidget;
    QGroupBox *gBoxLDSet;
    QLineEdit *lEditDSetPath;
    QPushButton *butSetDSetPath;
    QLineEdit *lEditItemNumber;
    QPushButton *butLoadItem;
    QPushButton *butNextItem;
    QPushButton *butPrevItem;
    QLineEdit *lEditInputCloudFileName;
    QPushButton *butSavePointCloud;
    QLineEdit *lEditDatasetStart;
    QLineEdit *lEditDatasetEnd;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lEditOutputCloudFileName;
    QLabel *label_12;
    QLabel *label_13;
    QTabWidget *pclFuncTabs;
    QWidget *tab;
    QPushButton *butVoxelGridFilter;
    QCheckBox *cBoxVoxelGridApplied;
    QPushButton *butCalNormals;
    QPushButton *butSaveNormalAngleHist;
    QPushButton *butCalculateAllNormalAngleHistogram;
    QWidget *tab_2;
    QPushButton *butRotateCloud;
    QLineEdit *lEditRotationXDeg;
    QLineEdit *lEditRotationYDeg;
    QLineEdit *lEditRotationZDeg;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lEditScalePointCloud;
    QPushButton *butScalePointCloud;
    QPushButton *butApplyTransformationtoAll;
    QLineEdit *lEditCloudMaxRange;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *butGeneratePointCloudBubbles;
    QLabel *label_10;
    QLineEdit *lEditOutputBubbleName;
    QLabel *label_11;
    QLineEdit *lEditNoInvariantHarmonics;
    QWidget *tab_3;
    QPushButton *butKinectStart;
    QPushButton *butKinectSave;
    QLabel *labelImageThumbnail;
    QCheckBox *cBoxCloudVisualization;

    void setupUi(QDialog *PclDialog)
    {
        if (PclDialog->objectName().isEmpty())
            PclDialog->setObjectName(QString::fromUtf8("PclDialog"));
        PclDialog->resize(981, 521);
        scrollArea = new QScrollArea(PclDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 1031, 521));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1029, 519));
        qvtkwidget = new QVTKWidget(scrollAreaWidgetContents);
        qvtkwidget->setObjectName(QString::fromUtf8("qvtkwidget"));
        qvtkwidget->setGeometry(QRect(20, 20, 451, 451));
        qvtkwidget->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        gBoxLDSet = new QGroupBox(scrollAreaWidgetContents);
        gBoxLDSet->setObjectName(QString::fromUtf8("gBoxLDSet"));
        gBoxLDSet->setGeometry(QRect(490, 280, 411, 211));
        lEditDSetPath = new QLineEdit(gBoxLDSet);
        lEditDSetPath->setObjectName(QString::fromUtf8("lEditDSetPath"));
        lEditDSetPath->setGeometry(QRect(2, 20, 271, 27));
        lEditDSetPath->setReadOnly(true);
        butSetDSetPath = new QPushButton(gBoxLDSet);
        butSetDSetPath->setObjectName(QString::fromUtf8("butSetDSetPath"));
        butSetDSetPath->setGeometry(QRect(300, 20, 97, 27));
        lEditItemNumber = new QLineEdit(gBoxLDSet);
        lEditItemNumber->setObjectName(QString::fromUtf8("lEditItemNumber"));
        lEditItemNumber->setGeometry(QRect(190, 130, 81, 27));
        butLoadItem = new QPushButton(gBoxLDSet);
        butLoadItem->setObjectName(QString::fromUtf8("butLoadItem"));
        butLoadItem->setGeometry(QRect(300, 130, 97, 27));
        butNextItem = new QPushButton(gBoxLDSet);
        butNextItem->setObjectName(QString::fromUtf8("butNextItem"));
        butNextItem->setGeometry(QRect(344, 170, 51, 27));
        butPrevItem = new QPushButton(gBoxLDSet);
        butPrevItem->setObjectName(QString::fromUtf8("butPrevItem"));
        butPrevItem->setGeometry(QRect(270, 170, 61, 27));
        lEditInputCloudFileName = new QLineEdit(gBoxLDSet);
        lEditInputCloudFileName->setObjectName(QString::fromUtf8("lEditInputCloudFileName"));
        lEditInputCloudFileName->setGeometry(QRect(160, 54, 113, 27));
        butSavePointCloud = new QPushButton(gBoxLDSet);
        butSavePointCloud->setObjectName(QString::fromUtf8("butSavePointCloud"));
        butSavePointCloud->setGeometry(QRect(205, 170, 51, 27));
        lEditDatasetStart = new QLineEdit(gBoxLDSet);
        lEditDatasetStart->setObjectName(QString::fromUtf8("lEditDatasetStart"));
        lEditDatasetStart->setGeometry(QRect(10, 170, 51, 27));
        lEditDatasetEnd = new QLineEdit(gBoxLDSet);
        lEditDatasetEnd->setObjectName(QString::fromUtf8("lEditDatasetEnd"));
        lEditDatasetEnd->setGeometry(QRect(80, 170, 51, 27));
        label_4 = new QLabel(gBoxLDSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(19, 150, 41, 17));
        label_5 = new QLabel(gBoxLDSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(92, 150, 31, 17));
        lEditOutputCloudFileName = new QLineEdit(gBoxLDSet);
        lEditOutputCloudFileName->setObjectName(QString::fromUtf8("lEditOutputCloudFileName"));
        lEditOutputCloudFileName->setGeometry(QRect(160, 90, 113, 27));
        label_12 = new QLabel(gBoxLDSet);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(21, 58, 131, 20));
        label_13 = new QLabel(gBoxLDSet);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 93, 141, 20));
        pclFuncTabs = new QTabWidget(scrollAreaWidgetContents);
        pclFuncTabs->setObjectName(QString::fromUtf8("pclFuncTabs"));
        pclFuncTabs->setGeometry(QRect(480, 30, 471, 251));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        butVoxelGridFilter = new QPushButton(tab);
        butVoxelGridFilter->setObjectName(QString::fromUtf8("butVoxelGridFilter"));
        butVoxelGridFilter->setGeometry(QRect(10, 20, 131, 27));
        cBoxVoxelGridApplied = new QCheckBox(tab);
        cBoxVoxelGridApplied->setObjectName(QString::fromUtf8("cBoxVoxelGridApplied"));
        cBoxVoxelGridApplied->setGeometry(QRect(170, 23, 97, 20));
        cBoxVoxelGridApplied->setCheckable(false);
        butCalNormals = new QPushButton(tab);
        butCalNormals->setObjectName(QString::fromUtf8("butCalNormals"));
        butCalNormals->setGeometry(QRect(10, 70, 131, 27));
        butSaveNormalAngleHist = new QPushButton(tab);
        butSaveNormalAngleHist->setObjectName(QString::fromUtf8("butSaveNormalAngleHist"));
        butSaveNormalAngleHist->setGeometry(QRect(10, 120, 211, 27));
        butCalculateAllNormalAngleHistogram = new QPushButton(tab);
        butCalculateAllNormalAngleHistogram->setObjectName(QString::fromUtf8("butCalculateAllNormalAngleHistogram"));
        butCalculateAllNormalAngleHistogram->setGeometry(QRect(230, 120, 111, 27));
        pclFuncTabs->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        butRotateCloud = new QPushButton(tab_2);
        butRotateCloud->setObjectName(QString::fromUtf8("butRotateCloud"));
        butRotateCloud->setGeometry(QRect(40, 60, 97, 27));
        lEditRotationXDeg = new QLineEdit(tab_2);
        lEditRotationXDeg->setObjectName(QString::fromUtf8("lEditRotationXDeg"));
        lEditRotationXDeg->setGeometry(QRect(20, 30, 41, 27));
        lEditRotationYDeg = new QLineEdit(tab_2);
        lEditRotationYDeg->setObjectName(QString::fromUtf8("lEditRotationYDeg"));
        lEditRotationYDeg->setGeometry(QRect(70, 30, 41, 27));
        lEditRotationZDeg = new QLineEdit(tab_2);
        lEditRotationZDeg->setObjectName(QString::fromUtf8("lEditRotationZDeg"));
        lEditRotationZDeg->setGeometry(QRect(120, 30, 41, 27));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(35, 12, 20, 17));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(86, 11, 20, 17));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(135, 12, 16, 17));
        lEditScalePointCloud = new QLineEdit(tab_2);
        lEditScalePointCloud->setObjectName(QString::fromUtf8("lEditScalePointCloud"));
        lEditScalePointCloud->setGeometry(QRect(60, 100, 51, 27));
        butScalePointCloud = new QPushButton(tab_2);
        butScalePointCloud->setObjectName(QString::fromUtf8("butScalePointCloud"));
        butScalePointCloud->setGeometry(QRect(40, 130, 97, 27));
        butApplyTransformationtoAll = new QPushButton(tab_2);
        butApplyTransformationtoAll->setObjectName(QString::fromUtf8("butApplyTransformationtoAll"));
        butApplyTransformationtoAll->setGeometry(QRect(40, 170, 91, 27));
        lEditCloudMaxRange = new QLineEdit(tab_2);
        lEditCloudMaxRange->setObjectName(QString::fromUtf8("lEditCloudMaxRange"));
        lEditCloudMaxRange->setGeometry(QRect(322, 20, 41, 27));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(238, 23, 81, 20));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(370, 24, 61, 17));
        butGeneratePointCloudBubbles = new QPushButton(tab_2);
        butGeneratePointCloudBubbles->setObjectName(QString::fromUtf8("butGeneratePointCloudBubbles"));
        butGeneratePointCloudBubbles->setGeometry(QRect(220, 140, 231, 27));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(169, 63, 161, 20));
        lEditOutputBubbleName = new QLineEdit(tab_2);
        lEditOutputBubbleName->setObjectName(QString::fromUtf8("lEditOutputBubbleName"));
        lEditOutputBubbleName->setGeometry(QRect(322, 60, 113, 27));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(190, 100, 121, 20));
        lEditNoInvariantHarmonics = new QLineEdit(tab_2);
        lEditNoInvariantHarmonics->setObjectName(QString::fromUtf8("lEditNoInvariantHarmonics"));
        lEditNoInvariantHarmonics->setGeometry(QRect(320, 100, 61, 27));
        pclFuncTabs->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        butKinectStart = new QPushButton(tab_3);
        butKinectStart->setObjectName(QString::fromUtf8("butKinectStart"));
        butKinectStart->setGeometry(QRect(220, 10, 97, 27));
        butKinectSave = new QPushButton(tab_3);
        butKinectSave->setObjectName(QString::fromUtf8("butKinectSave"));
        butKinectSave->setGeometry(QRect(220, 50, 97, 27));
        labelImageThumbnail = new QLabel(tab_3);
        labelImageThumbnail->setObjectName(QString::fromUtf8("labelImageThumbnail"));
        labelImageThumbnail->setGeometry(QRect(10, 10, 191, 161));
        labelImageThumbnail->setStyleSheet(QString::fromUtf8("border: 2px solid black"));
        cBoxCloudVisualization = new QCheckBox(tab_3);
        cBoxCloudVisualization->setObjectName(QString::fromUtf8("cBoxCloudVisualization"));
        cBoxCloudVisualization->setGeometry(QRect(220, 90, 161, 22));
        pclFuncTabs->addTab(tab_3, QString());
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(PclDialog);

        pclFuncTabs->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PclDialog);
    } // setupUi

    void retranslateUi(QDialog *PclDialog)
    {
        PclDialog->setWindowTitle(QApplication::translate("PclDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        gBoxLDSet->setTitle(QApplication::translate("PclDialog", "Load Dataset", 0, QApplication::UnicodeUTF8));
        butSetDSetPath->setText(QApplication::translate("PclDialog", "Set Path", 0, QApplication::UnicodeUTF8));
        butLoadItem->setText(QApplication::translate("PclDialog", "Load", 0, QApplication::UnicodeUTF8));
        butNextItem->setText(QApplication::translate("PclDialog", "Next", 0, QApplication::UnicodeUTF8));
        butPrevItem->setText(QApplication::translate("PclDialog", "Prev", 0, QApplication::UnicodeUTF8));
        butSavePointCloud->setText(QApplication::translate("PclDialog", "Save", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PclDialog", "Start", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PclDialog", "End", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("PclDialog", "Input Cloud Name:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("PclDialog", "Output Cloud Name:", 0, QApplication::UnicodeUTF8));
        butVoxelGridFilter->setText(QApplication::translate("PclDialog", "Voxel Grid Filter", 0, QApplication::UnicodeUTF8));
        cBoxVoxelGridApplied->setText(QApplication::translate("PclDialog", "Applied", 0, QApplication::UnicodeUTF8));
        butCalNormals->setText(QApplication::translate("PclDialog", "Calculate Normals", 0, QApplication::UnicodeUTF8));
        butSaveNormalAngleHist->setText(QApplication::translate("PclDialog", "Save Normal Angle Histogram", 0, QApplication::UnicodeUTF8));
        butCalculateAllNormalAngleHistogram->setText(QApplication::translate("PclDialog", "Apply All", 0, QApplication::UnicodeUTF8));
        pclFuncTabs->setTabText(pclFuncTabs->indexOf(tab), QApplication::translate("PclDialog", "Voxel", 0, QApplication::UnicodeUTF8));
        butRotateCloud->setText(QApplication::translate("PclDialog", "Rotate", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PclDialog", "x", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PclDialog", "y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PclDialog", "z", 0, QApplication::UnicodeUTF8));
        butScalePointCloud->setText(QApplication::translate("PclDialog", "Scale", 0, QApplication::UnicodeUTF8));
        butApplyTransformationtoAll->setText(QApplication::translate("PclDialog", "Apply All", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PclDialog", "Max range: ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PclDialog", "(meters)", 0, QApplication::UnicodeUTF8));
        butGeneratePointCloudBubbles->setText(QApplication::translate("PclDialog", "Generate Bubbles and Invariants", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("PclDialog", "Output Bubble Name:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("PclDialog", "No of Harmonics:", 0, QApplication::UnicodeUTF8));
        pclFuncTabs->setTabText(pclFuncTabs->indexOf(tab_2), QApplication::translate("PclDialog", "Bubble", 0, QApplication::UnicodeUTF8));
        butKinectStart->setText(QApplication::translate("PclDialog", "Start", 0, QApplication::UnicodeUTF8));
        butKinectSave->setText(QApplication::translate("PclDialog", "Save", 0, QApplication::UnicodeUTF8));
        labelImageThumbnail->setText(QString());
        cBoxCloudVisualization->setText(QApplication::translate("PclDialog", "Cloud Visualization", 0, QApplication::UnicodeUTF8));
        pclFuncTabs->setTabText(pclFuncTabs->indexOf(tab_3), QApplication::translate("PclDialog", "Microsoft Kinect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PclDialog: public Ui_PclDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLDIALOG_H
