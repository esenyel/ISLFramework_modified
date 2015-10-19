#include "rosThread.h"
#include <QDebug>
RosThread::RosThread()
{
    shutdown = false;

    velocityCommand.linear.x = 0;
    velocityCommand.angular.z = 0;

}

void RosThread::loop()
{
    ros::NodeHandle n;

   velocityCommandPublisher =  n.advertise<geometry_msgs::Twist>("cmd_vel",1);

    if(!ros::ok()){

        emit rosStartFailed();

        return;
    }

    emit rosStarted();

    ros::Rate loop(10);

    while(ros::ok())
    {

        velocityCommandPublisher.publish(velocityCommand);

        ros::spinOnce();

        loop.sleep();

    }

}

void RosThread::shutdownROS()
{
    ros::shutdown();

}
