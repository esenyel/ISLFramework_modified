#include "MainWindow.h"
#include "ui_MainWindow.h"


#include <QtCore/QFile>
#include <QtGui/QFileDialog>
#include <QtCore/QDebug>
#include <QtGui/QMessageBox>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <ros/time.h>

// This is the required message type for velocity command
geometry_msgs::Twist twist;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rosLoop =  new RosThread;
    rosLoopThread = new QThread(this);


    rosLoop->moveToThread(rosLoopThread);

    connect(rosLoopThread,SIGNAL(finished()),rosLoop,SLOT(deleteLater()));
    connect(rosLoopThread,SIGNAL(started()),rosLoop,SLOT(loop()));

    initView();
    rosLoopThread->start();

}

MainWindow::~MainWindow()
{
    this->rosLoop->shutdownROS();
    rosLoopThread->quit();
    while(rosLoopThread->isRunning());
    DatabaseManager::closeDB();
    delete ui;
}

void MainWindow::initView(){

    connect(rosLoop,SIGNAL(rosStartFailed(void)),this,SLOT(handleROSStartFailure(void)));

    connect(rosLoop,SIGNAL(rosStarted(void)),this,SLOT(handleRosThreadStart(void)));

    pclDialog = 0;
    irobotDialog = 0;
    impDialog = 0;
    robot = 0;

    //initializing the image with and focal length in pixels
    //these values are applicable for Kinect images, for different cameras they should be different
    ui->lEditImageWidth->setText("640");
    ui->lEditImageHeight->setText("480");
    ui->lEditFocalLength->setText("525");

}



void MainWindow::sensorCB(const irobot_create_2_1::SensorPacket::ConstPtr& packet){

    qDebug()<<packet->batteryCharge;

}

void MainWindow::on_openFileButton_clicked()
{
    // when openFile button is clicked, two windows open PcProcessing and ImageProcessing
    if (!pclDialog){
        pclDialog = new PclDialog(this,&pcProcess);

        pcProcess.setViewer(pclDialog->viwer);
        pcProcess.initializeViewer(true);

        pclDialog->show();
        pclDialog->raise();
        pclDialog->activateWindow();

        connect(pclDialog,SIGNAL(kinectSave()),this,SLOT(handleRobotDataSaveRequest()));
    }
    else{
        pclDialog->show();
        pclDialog->raise();
        pclDialog->activateWindow();
    }

    if(!impDialog){

        int imageWidth = ui->lEditImageWidth->text().toInt();

        int imageHeight = ui->lEditImageHeight->text().toInt();

        int focalLength = ui->lEditFocalLength->text().toInt();


        impDialog = new ImageProcessDialog(this,imageWidth,imageHeight,focalLength);

        impDialog->show();
        impDialog->raise();
        impDialog->activateWindow();

    }
    else
    {
        impDialog->show();
        impDialog->raise();
        impDialog->activateWindow();
    }
}

void MainWindow::handleROSStartFailure(){

    QMessageBox::critical(this,"Attention","ROS has failed to start!!!");

}

void MainWindow::handleRosThreadStart(){

    robot = new Irobot(this);

    robot->rosThread = this->rosLoop;

    if(!irobotDialog){

        irobotDialog = new IRobotDialog(this,robot);
    }

    irobotDialog->show();

    qDebug()<<"Ros thread has started";

}

void MainWindow::on_butBubbleProcessing_clicked()
{
    BubbleProcessDialog* dlg = new BubbleProcessDialog(this);

    dlg->show();

}

void MainWindow::handleRobotDataSaveRequest()
{
    if(!robot->isConnected()) return;

    if(saveDataFileName == NULL){

        QDateTime noww = QDateTime::currentDateTime();

        saveDataFileName = "robotData_";

        saveDataFileName.append(noww.toString());

        saveDataFileName.append(".txt");

        QFile file(saveDataFileName);


        if(file.open(QFile::Append)){

            this->robot->saveData(&file);

            file.close();

        }
    }
    else{

        QFile file(saveDataFileName);


        if(file.open(QFile::Append)){

            this->robot->saveData(&file);

            file.close();

        }
    }
}

void MainWindow::on_butChooseDBFile_clicked()
{
    // Get the root directory to open a db file to write the bubbles
    QString path =   QFileDialog::getOpenFileName(this,"Open DB File","/home/hakan/Development/ISL/Datasets",tr("*.db"));

    if(path != NULL)
    {
        ui->lEditDBFilePath->setText(path);

        if(DatabaseManager::openDB(path))
        {
            qDebug()<<"Database opened Successfully!!";
        }
    }
}

void MainWindow::on_butPlaceLabelsFile_clicked()
{
    // Get the root directory
    QString path =   QFileDialog::getOpenFileName(this,"Open Place Labels File","/home/hakan/Development/ISL/Datasets",tr("*.txt"));

    if(path != NULL)
    {
        ui->lEditPlaceLabelsFilePath->setText(path);

        DatabaseManager::determinePlaceLabels(path);

    }

}
