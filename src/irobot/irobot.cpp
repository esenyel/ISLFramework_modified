#include "irobot.h"
#include "rosThread.h"
#include <QDebug>
#include <QIODevice>
Irobot::Irobot(QObject *parent) :
    QObject(parent)
{

    saveInProgress = false;

    totalTraveledDistanceX = 0;

    totalTraveledDistanceY = 0;


    totalAngularHeading = 0;

    frameCount = 0;

    prevDist = 0;

    currentOrientation.z = 1111;

    // Holds the first orientation that is measured at the beginning position of the robot
    firstOrientation = 0;

    connected = false;

}
bool Irobot::isConnected()
{
    return connected;
}
void Irobot::handleSetFirstOrientation(){

    firstOrientation = currentOrientation.z;

}

void Irobot::sensorCB(const turtlebot_node::TurtlebotSensorStateConstPtr& packet){

    connected = true;

    if(!saveInProgress)
    {
        currentSensorPacket = packet;

        updateOdometry();
    }

}
void Irobot::kinectCB(const sensor_msgs::PointCloud2::ConstPtr &packet)
{

    if(!saveInProgress){

        pcl::fromROSMsg(*packet,currentCloud);

    }

}
void Irobot::os5000CB(const sensor_msgs::Imu::ConstPtr &packet){


    if(!saveInProgress)
        currentOrientation = packet->orientation;

}

void Irobot::updateOdometry()
{

    // IF we don't receive compass updates
    if(currentOrientation.z == 1111)
    {
        totalAngularHeading += currentSensorPacket->angle;

        totalTraveledDistanceX += ((double)currentSensorPacket->distance*100)*cos(currentSensorPacket->angle*M_PI/180);

        totalTraveledDistanceY+= ((double)currentSensorPacket->distance*100)*sin(currentSensorPacket->angle*M_PI/180);

    }
    else
    {

        totalTraveledDistanceX += ((double)currentSensorPacket->distance*100)*cos(((double)currentOrientation.z - firstOrientation)*M_PI/180);

        totalTraveledDistanceY += (((double)currentSensorPacket->distance*100)*sin(((double)currentOrientation.z - firstOrientation)*M_PI/180));

    }

}

void Irobot::saveData(QFile* file)
{
    saveInProgress = true;

    QTextStream stream(file);

    // IF we don't receive compass updates
    if(currentOrientation.z == 1111)
    {

        totalTraveledDistanceX += ((double)currentSensorPacket->distance*100)*cos(currentSensorPacket->angle*M_PI/180);

        totalTraveledDistanceY+= ((double)currentSensorPacket->distance*100)*sin(currentSensorPacket->angle*M_PI/180);

        stream<<frameCount<<" "<<totalTraveledDistanceX<<" "<<totalTraveledDistanceY<<" "<<currentSensorPacket->angle<<" "<<currentOrientation.z<<"\n";
    }
    else
    {

        double x = totalTraveledDistanceX  + ((double)currentSensorPacket->distance*100)*cos((double)currentOrientation.z*M_PI/180);

        totalTraveledDistanceX = x;

        double y = totalTraveledDistanceY + (((double)currentSensorPacket->distance*100)*sin((double)currentOrientation.z*M_PI/180));

        totalTraveledDistanceY = y;

        stream<<frameCount<<" "<<x<<" "<<y<<" "<<currentSensorPacket->angle<<" "<<currentOrientation.z<<"\n";

    }

    frameCount++;

    saveInProgress = false;

}

void Irobot::initIrobotConnection(QString robotPortName)
{

    os5000Subscriber = n.subscribe("os5000_data",10,&Irobot::os5000CB,this);

    createSubscriber = n.subscribe("turtlebot_node/sensor_state",10,&Irobot::sensorCB,this);

    createPublisher =  n.advertise<geometry_msgs::Twist>("cmd_vel",1);

}
Irobot::~Irobot(){

    n.shutdown();

}

void Irobot::setMotion(double forward, double angular){

    if(this->rosThread)
    {
        this->rosThread->velocityCommand.linear.x = forward;
        this->rosThread->velocityCommand.angular.z = angular;

        qDebug()<<"Motion Command sent";
    }


}

void Irobot::handleRobotRunError(QProcess::ProcessError error){

    qDebug()<<error;
}

double Irobot::getFirstOrientation()
{

    return firstOrientation;

}
