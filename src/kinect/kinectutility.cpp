#include "kinectutility.h"
#include "kinecttransformer.h"
#include <QDebug>

float RawDepthToMeters(int depthValue)
{
    if (depthValue < 2047)
    {
        return float(1.0 / (double(depthValue) * -0.0030711016 + 3.3309495161));
    }
    return 0.0f;
}

KinectTransformer kinectTransformer;

using std::vector;

/* Transform the xyz points on the image plane using opencv xyz image */
vector<pointKin> KinectUtility::transformXYZtoImagePlane(cv::Mat xyzImage, cv::Mat rgbImage)
{

    return kinectTransformer.transformXYZToImage(xyzImage,rgbImage);

}

/* Transform the xyz points on the image plane using pcl point cloud */
vector<pointKin> KinectUtility::transformXYZtoImagePlane(pcl::PointCloud<pcl::PointXYZ> xyzCloud, cv::Mat rgbImage){


    return kinectTransformer.transformXYZToImage(xyzCloud,rgbImage);

}

void KinectUtility::convertDepthImage2Cloud(cv::Mat depthImage, sensor_msgs::PointCloud2::Ptr cloud)
{
    static const double fx_d = 1.0 / 5.9421434211923247e+02;
    static const double fy_d = 1.0 / 5.9104053696870778e+02;
    static const double cx_d = 3.3930780975300314e+02;
    static const double cy_d = 2.4273913761751615e+02;

    pcl::PointCloud<pcl::PointXYZRGB> xyzCloud;

    xyzCloud.height = 1;

    for(int i = 0; i < depthImage.rows; i++){
        for(int j = 0; j < depthImage.cols; j++){

            float depth = depthImage.at<float>(i,j);

            pcl::PointXYZRGB pt;

            pt.x = float((j - cx_d) * depth * fx_d);
            pt.y = float((i - cy_d) * depth * fy_d);
            pt.z = float(depth);

            xyzCloud.points.push_back(pt);
        }

    }

    xyzCloud.width  = xyzCloud.points.size();

    pcl::toROSMsg(xyzCloud,*cloud);
}
void KinectUtility::convertDepthText2Cloud(char* fileName, sensor_msgs::PointCloud2::Ptr cloud)
{
    int width = 640;
    int height = 480;

    double r = 0;

    double focalLength = 120.0;
    double pixelSize = 0.10419999808073044;
    double P2R = pixelSize * ( 1280 / width ) / focalLength;

    char s[256];

    pcl::PointCloud<pcl::PointXYZRGB> xyzCloud;
    xyzCloud.height = 1;

    std::ifstream is(fileName);
    if(is.fail()) return;

        for(int j = 0; j < height; j++){

            for(int i = 0; i < width; i++){

            pcl::PointXYZRGB pt;

             is>>s;

            if(strcmp(s,"nan") == 0) r = 0;
            else r = atof(s);

            pt.x  = r * P2R * ( i - width/2 );
            pt.y =  r * P2R * ( j - height/2 );
            pt.z  = r;

            xyzCloud.points.push_back(pt);

        }

    }

    xyzCloud.width  = xyzCloud.points.size();

    pcl::toROSMsg(xyzCloud,*cloud);

}

