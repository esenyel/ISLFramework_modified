#ifndef KINECTUTILITY_H
#define KINECTUTILITY_H

#include "pcprocessing.h"
#include <vector>
#include <QFile>
#include <QTextStream>

using std::vector;

// Point structure to hold the xyrgb values
struct pointKin{

    int r;
    int g;
    int b;

    float x;
    float y;
    float z;

    int imgX;
    int imgY;

};


class KinectUtility
{
public:
    KinectUtility();

    static vector<pointKin> transformXYZtoImagePlane(cv::Mat xyzImage, cv::Mat rgbImage);

    static vector<pointKin> transformXYZtoImagePlane(pcl::PointCloud<pcl::PointXYZ> xyzCloud, cv::Mat rgbImage);

    static void convertDepthImage2Cloud(cv::Mat depthImage, sensor_msgs::PointCloud2::Ptr cloud);

    static void convertDepthText2Cloud(char* fileName, sensor_msgs::PointCloud2::Ptr cloud);


};

#endif // KINECTUTILITY_H
