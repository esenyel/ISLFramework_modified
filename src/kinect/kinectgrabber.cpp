#include "kinectgrabber.h"
#include <rosbag/recorder.h>
#include <rosbag/bag.h>

#include <boost/thread.hpp>
static KinectGrabber* thisGrabber;

KinectGrabber::KinectGrabber(QObject *parent) :
    QObject(parent)
{

    shouldSave = false;

    shouldQuit = false;

    frameCounterImage = 0;

    frameCounterCloud = 0;

    saveCloud = false;

    saveImage = false;

    thisGrabber = this;

    emitCloudFrame = false;

}

sensor_msgs::PointCloud2ConstPtr cloud;


void KinectGrabber::cb(const sensor_msgs::PointCloud2ConstPtr& input){

    if(this->emitCloudFrame)
        emit frame(input);

    if(saveCloud)
    {

        pcl::PointCloud<pcl::PointXYZRGB> cld;

        pcl::fromROSMsg(*input,cld);

        QString fileName = "cloud_";

        fileName.append(QString::number(frameCounterCloud));

        fileName.append(".pcd");

        pcl::io::savePCDFileBinary(fileName.toStdString(),cld);

        frameCounterCloud++;

        saveCloud = false;
    }

}
void KinectGrabber::imagecb(const sensor_msgs::ImageConstPtr &input){

    cv_bridge::CvImagePtr img = cv_bridge::toCvCopy(input);

    emit imageFrame(img->image);

    if(saveImage)
    {

        QString fileName = "rgbImage_";

        fileName.append(QString::number(frameCounterImage));

        fileName.append(".jpg");

        cv::imwrite(fileName.toStdString(),img->image);

        frameCounterImage++;

        saveImage = false;

    }
}

void KinectGrabber::grabFromKinect()
{

    QProcess* rosLaunch = new QProcess();

    rosLaunch->setWorkingDirectory(QDir::temp().absolutePath());

    ros::NodeHandle n;

    // If fails, it returns an empty subscriber
    sub = n.subscribe<sensor_msgs::PointCloud2> ("/camera/depth_registered/points", 1,&KinectGrabber::cb,this);

    imageSub = n.subscribe<sensor_msgs::Image>("/camera/rgb/image_color",1,&KinectGrabber::imagecb,this);

    if(!sub) emit error();
    else
        emit started();

}

void KinectGrabber::stopKinect(){

    sub.shutdown();

}

void KinectGrabber::handleSaveRequest(){

    saveCloud = true;
    saveImage = true;

}

void KinectGrabber::setEmitCloudFrame(bool status){

    emitCloudFrame = status;

}
