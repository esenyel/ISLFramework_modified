#include "bubbleprocess.h"
#include <QStringList>
#include <QTextStream>
#include <math.h>
#include <QDebug>
double bubbleProcess::round(double r) {
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

using std::vector;

QString bubblesRootDirectory;
QString threeDFilesRootDirectory;
QString writeBubblesRootDirectory;


QStringList bubblesFolderList;
QStringList bubblesfileList;
QStringList threeDfileList;

vector< vector<bubblePoint> > staticBubbles;

vector <positionData> robotPoses;

static vector<vector<int> > imagePanAngles;

static vector<vector<int> > imageTiltAngles;


bubbleProcess::bubbleProcess()
{
}
void bubbleProcess::setBubblesRootDirectory(QString rootDirectory){

	bubblesRootDirectory =  rootDirectory;
}
QString bubbleProcess::getBubblesRootDirectory(){
	
	return bubblesRootDirectory;

}
bubbleStatistics bubbleProcess::calculateBubbleStatistics(vector<bubblePoint> bubble, float maxDist)
{
    bubbleStatistics result;

    std::vector<float> values(bubble.size());
    for(int i = 0; i < bubble.size(); i++)
    {
        values[i] = bubble.at(i).val;
    }

    cv::Scalar summ = cv::sum(values);

    result.mean = summ[0]/(60*60);

    if(result.mean > 1.0) result.mean = 1.0;

    cv::Scalar     mean;
    cv::Scalar     stddev;

    cv::meanStdDev(values,mean,stddev);

    result.maxDist = maxDist;

    result.variance = stddev.val[0]*stddev.val[0];

    return result;

}

// it is needed to calculate pan and tilt angles of every pixel in the image
vector<vector<int> > bubbleProcess::calculateImagePanAngles(int focalLengthPixels, int imageWidth, int imageHeight)
{
    vector<vector<int> > result(imageHeight, std::vector<int>(imageWidth));


    for(int i = 0; i < imageHeight; i++){

        for(int j = 0; j < imageWidth; j++ )
        {

            int deltax = imageWidth/2 - j;


            float pan = atan2((double)deltax,(double)focalLengthPixels);


            int panInt = (pan*180)/M_PI;

            //setting the pan angle between 0-360
            if(panInt < 0)panInt += 360;
            else if(panInt > 359) panInt -=360;

            result[i][j] = panInt;

        }

    }

    if(imagePanAngles.size() > 0){

        for(int i = 0; i < imagePanAngles.size(); i++){
            imagePanAngles[i].clear();
        }

        imagePanAngles.clear();
    }

    imagePanAngles.resize(imageHeight,std::vector<int> (imageWidth));

    imagePanAngles = result;

    return result;

}

//calculating tilt angles for every pixel in the image
vector<vector<int> > bubbleProcess::calculateImageTiltAngles(int focalLengthPixels, int imageWidth, int imageHeight)
{
    vector<vector<int> > result(imageHeight, std::vector<int>(imageWidth));


    for(int i = 0; i < imageHeight; i++){

        for(int j = 0; j < imageWidth; j++ )
        {

            int deltay = imageHeight/2 - i;

            float tilt = atan2((double)deltay,(double)focalLengthPixels);


            int tiltInt = (tilt*180)/M_PI;

            // setting the tilt angle between 0-360
            if(tiltInt < 0)tiltInt += 360;
            else if(tiltInt > 359) tiltInt -=360;

            result[i][j] = tiltInt;

        }

    }

    if(imageTiltAngles.size() > 0){

        for(int i = 0; i < imageTiltAngles.size(); i++){
            imageTiltAngles[i].clear();
        }

        imageTiltAngles.clear();

    }

    imageTiltAngles.resize(imageHeight,std::vector<int>(imageWidth));

    imageTiltAngles = result;



    return result;

}

// a function to convert the gray images to bubbles
vector<bubblePoint> bubbleProcess::convertGrayImage2Bub(cv::Mat grayImage, int focalLengthPixels, int maxval, float angleOffset)
{

    vector<bubblePoint> result;

    // a bubble space consists of bubble points which have 3 elements: pan, tilt angles and the value
    // specifying the pan, tilt angles and the value of each bubble point
    for(int i = 0; i < grayImage.rows; i++)
    {
        for(int j = 0; j < grayImage.cols; j++)
        {
            float val = (float)grayImage.at<uchar>(i,j)/(float)maxval;

            if(val > 0){

                bubblePoint pt;

                pt.panAng = imagePanAngles[i][j] + angleOffset;

                pt.tiltAng = imageTiltAngles[i][j];

                if(pt.panAng < 0)pt.panAng += 360;
                else if(pt.panAng > 359) pt.panAng -=360;

                if(pt.tiltAng < 0)pt.tiltAng += 360;
                else if(pt.tiltAng > 359) pt.tiltAng -=360;

                pt.val = val;

                // combining all bubble points in the bubble space
                result.push_back(pt);
            }
        }
    }

    return result;

}

// a function to convert the gray images to bubbles
vector<bubblePoint> bubbleProcess::convertGrayImage2Bub(cv::Mat grayImage, int focalLengthPixels, int maxval)
{

    vector<bubblePoint> result;

    int centerx = grayImage.cols/2;

    int centery = grayImage.rows/2;

    for(int i = 0; i < grayImage.rows; i++)
    {
        for(int j = 0; j < grayImage.cols; j++)
        {
            float val = (float)grayImage.at<uchar>(i,j)/(float)maxval;

            if(val > 0){

                bubblePoint pt;

                pt.panAng = imagePanAngles[i][j];

                pt.tiltAng = imageTiltAngles[i][j];

                pt.val = val;

                result.push_back(pt);
            }
        }
    }
    return result;
}

vector<positionData> bubbleProcess::readPositionData(QFile* file){

    vector <positionData> result;

    QTextStream stream(file);

    if(!file->isOpen()) return result;

    QString line =stream.readLine();

    while(line != NULL)
    {
        positionData pt;

        QStringList lt = line.split(" ",QString::SkipEmptyParts);

        if(lt.size() == 4){

            pt.x = lt[0].toDouble();
            pt.y= lt[1].toDouble();
            pt.z = lt[2].toDouble();
            pt.headingD = lt[3].toDouble();

            result.push_back(pt);

        }

        line = stream.readLine();
    }

    return result;

}

void bubbleProcess::set3DFilesRootDirectory(QString rootDirectory){
	
	threeDFilesRootDirectory = rootDirectory;


}

QString bubbleProcess::get3DFilesRootDirectory(){

	return threeDFilesRootDirectory;

}

void bubbleProcess::setWriteBubblesRootDirectory(QString rootDirectory){

	writeBubblesRootDirectory = rootDirectory;
}

QString bubbleProcess::getWriteBubblesRootDirectory(){

	return writeBubblesRootDirectory;


}
void bubbleProcess::setBubblesFolderList(QStringList folderList){

    bubblesFolderList = folderList;

}
QStringList bubbleProcess::getBubblesFolderList(){


    return bubblesFolderList;
}

void bubbleProcess::setBubblesFileList(QStringList fileList){

	bubblesfileList = fileList;
}
QStringList bubbleProcess::getBubblesFileList(){

	return bubblesfileList;
}

void bubbleProcess::set3DFileList(QStringList fileList){

	threeDfileList = fileList;
}
QStringList bubbleProcess::get3DFileList(){

	return threeDfileList;
}

void bubbleProcess::setBubblesXYZ(std::vector< std::vector<bubblePointXYZ> > bubblesXYZ){

	this->bubblesXYZ = bubblesXYZ;

}

vector< vector<bubblePointXYZ> > bubbleProcess::getBubblesXYZ(){

	return this->bubblesXYZ;

}

void bubbleProcess::setBubbles(std::vector< std::vector<bubblePoint> > bubbles){

    staticBubbles = bubbles;

}

vector< vector<bubblePoint> > bubbleProcess::getBubbles(){

    return staticBubbles;

}

void bubbleProcess::addToBubbles(std::vector< bubblePoint > aBubble)
{

    staticBubbles.push_back(aBubble);

}

// a function to read the bubble from a qfile
vector<bubblePoint> bubbleProcess::readBubble(QFile *file){

	QTextStream stream(file);

	vector<bubblePoint> result;

    if(!file->isOpen()) return result;


    QString line = stream.readLine();


    while(line != NULL)
	{
		bubblePoint pt;

		QStringList lt = line.split(" ");

		if(lt.size() == 3){
			
			pt.panAng = lt[0].toInt();
			pt.tiltAng= lt[1].toInt();
			pt.val = lt[2].toDouble();

			// if val is in normal ranges save it
            if(pt.val < 1 && pt.val > 0){
                result.push_back(pt);
            }
        }
		
        line = stream.readLine();
	}

	return result;

}

// a function which converts a XYZ bubble space to a spherical bubble space
vector<bubblePoint> bubbleProcess::convertBubXYZ2BubSpherical(std::vector<bubblePointXYZ> bubbleXYZ, double maxRange){

    // create the result vector
    vector<bubblePoint> result;

    // for all the points in XYZ bubble
    for(int i = 0; i < bubbleXYZ.size(); i++){

        bubblePoint bp;

        // Calculate panAngle
        bp.panAng = (int)round(((atan2(bubbleXYZ[i].y, bubbleXYZ[i].x))*(double)180/3.14159));

        if(bp.panAng < 0)bp.panAng += 360;
        else if(bp.panAng > 359) bp.panAng -=360;
        // Calculate the magnitude of XY projection of the laser ray
        double rXY = sqrt(bubbleXYZ[i].y*bubbleXYZ[i].y + bubbleXYZ[i].x*bubbleXYZ[i].x);

        // Calculate the tilt angle
        bp.tiltAng = (int)round(((atan2(bubbleXYZ[i].z, rXY))*(double)180/3.14159));

        if(bp.tiltAng < 0)bp.tiltAng += 360;
        else if(bp.tiltAng > 359) bp.tiltAng -=360;

        // Calculate the r value and normalize it
        bp.val = (float)sqrt(bubbleXYZ[i].y*bubbleXYZ[i].y + bubbleXYZ[i].x*bubbleXYZ[i].x + bubbleXYZ[i].z*bubbleXYZ[i].z)/maxRange;

        result.push_back(bp);

    }

    // return resulting bubble
    return result;

}


// Converts a bubble in XYZ space to a bubble in Spherical coordinates
vector<bubblePoint> bubbleProcess::convertBubXYZ2BubSpherical(std::vector<point> bubbleXYZ, double maxRange){
	
	// create the result vector
	vector<bubblePoint> result;

	// for all the points in XYZ bubble
	for(int i = 0; i < bubbleXYZ.size(); i++){
		
		bubblePoint bp;
		
		// Calculate panAngle
		bp.panAng = (int)round(((atan2(bubbleXYZ[i].y, bubbleXYZ[i].x))*(double)180/3.14159));

        if(bp.panAng < 0)bp.panAng += 360;
        else if(bp.panAng > 359) bp.panAng -=360;
		// Calculate the magnitude of XY projection of the laser ray
		double rXY = sqrt(bubbleXYZ[i].y*bubbleXYZ[i].y + bubbleXYZ[i].x*bubbleXYZ[i].x);

		// Calculate the tilt angle
		bp.tiltAng = (int)round(((atan2(bubbleXYZ[i].z, rXY))*(double)180/3.14159));

        if(bp.tiltAng < 0)bp.tiltAng += 360;
        else if(bp.tiltAng > 359) bp.tiltAng -=360;

		// Calculate the r value and normalize it 
        bp.val = (float)sqrt(bubbleXYZ[i].y*bubbleXYZ[i].y + bubbleXYZ[i].x*bubbleXYZ[i].x + bubbleXYZ[i].z*bubbleXYZ[i].z)/maxRange;

        if(bp.val > 0 && bp.val <1.0)
		result.push_back(bp);
	
	}
	// return resulting bubble
	return result;

}

// Converts a bubble in XYZ space to a bubble in Spherical coordinates
vector<bubblePoint> bubbleProcess::convertBubXYZ2BubSpherical(std::vector<point> bubbleXYZ, int heading, double maxRange){
	
	vector<bubblePoint> result;

	for(int i = 0; i < bubbleXYZ.size(); i++){
		
		bubblePoint bp;

        // calculate pan angles
		bp.panAng = (int)round(((atan2(bubbleXYZ[i].y, bubbleXYZ[i].x))*(double)180/3.14159)) - heading;

		double rXY = sqrt(bubbleXYZ[i].y*bubbleXYZ[i].y + bubbleXYZ[i].x*bubbleXYZ[i].x);

        // calculate tilt angles
		bp.tiltAng = (int)round(((atan2(bubbleXYZ[i].z, rXY))*(double)180/3.14159));

        // calculate the value
        bp.val = (float)sqrt(bubbleXYZ[i].y*bubbleXYZ[i].y + bubbleXYZ[i].x*bubbleXYZ[i].x + bubbleXYZ[i].z*bubbleXYZ[i].z)/maxRange;

        // constructing bubble space
		result.push_back(bp);
	
	}

	return result;

}

// a function to reduce the bubble by combining the bubble points with same pan and tilt angles
vector<bubblePoint> bubbleProcess::reduceBubble(std::vector<bubblePoint> bubble){
	
	vector<bubblePoint> result;

    double vals[360][360];

    double counts[360][360];

    // initializing value and count matrix as zero
    for(int i = 0; i < 360; i++){

        for(int j = 0; j< 360; j++){

            vals[i][j] = 0;
            counts[i][j] = 0;

        }
    }

	for(long i = 0; i < bubble.size(); i++){

		bubblePoint pt;

		if(bubble[i].val < 1){	
            // storing the pan and tilt angles of the points with value smaller than 1 and saving the number of them
            pt = bubble[i];
            vals[pt.panAng][pt.tiltAng] += pt.val;
            counts[pt.panAng][pt.tiltAng] += 1;

        }

	}

    for(int i = 0; i < 360; i++){

        for(int j = 0; j< 360; j++){

            if(vals[i][j] != 0)  {
                bubblePoint pt;

                pt.panAng = i;

                pt.tiltAng = j;

                if(counts[i][j] > 1){
                    // taking the average of value of the points with same pan and tilt angles
                    pt.val = vals[i][j]/counts[i][j];

                }

                result.push_back(pt);
            }
        }
    }
	
	return result;

}

vector<bubblePoint> bubbleProcess::convertlP2bP(vector<point> laserPoints, double panAng, double tiltAng){
	
	vector<bubblePoint> result;

	for(long i = 0; i < laserPoints.size(); i++){
		
		bubblePoint pt;
		pt.panAng = (int)((laserPoints[i].theta*(double)180)/3.14159 - panAng - 90);
		pt.tiltAng = tiltAng;
		pt.val = (double)laserPoints[i].r/6000;

		result.push_back(pt);
	
	}

	return result;

}

void bubbleProcess::saveBubble(QFile *file, std::vector<bubblePoint> bubble){

	QTextStream stream(file);

	for(long i = 0; i < bubble.size(); i++){
			
		// if val is in normal ranges save it
        if(bubble[i].val < 1 && bubble[i].val > 0)
		stream<<(int)bubble[i].panAng<<" "<<(int)bubble[i].tiltAng<<" "<<(double)bubble[i].val<<"\n";
		
	}

}

// a function to convert spherical bubble to XYZ bubble space
vector <bubblePointXYZ> bubbleProcess::convertBubSph2BubXYZ(vector<bubblePoint> bubble, double maxRange)
{

    vector <bubblePointXYZ> result;

    for(unsigned int i = 0; i < bubble.size(); i++){

        bubblePointXYZ pt;

        int pan =   bubble[i].panAng;

        int tilt =  bubble[i].tiltAng;

        float val = bubble[i].val;

        // calculating the x,y,z values from pan tilt angles and the value
        pt.z = val*maxRange*sin((float)tilt*3.14159/180);

        float xy =  val*maxRange*cos((float)tilt*3.14159/180);

        pt.x = xy*cos((float)pan*3.14159/180);

        pt.y = xy*sin((float)pan*3.14159/180);


        result.push_back(pt);

    }
    return result;
}

void bubbleProcess::setPositionData(vector<positionData> poseVec){


    robotPoses = poseVec;

}

vector <positionData> bubbleProcess::getPositionData(){

    return robotPoses;

}

// calculating the Euclidean difference between two bubble surfaces
std::vector< double > bubbleProcess::calculateEuclideanDiff(vector<bubblePoint> bubble1, vector<bubblePoint> bubble2)
{
    std::vector <double> result;


    double sum = -1000;

    double count = 0;

    for(unsigned long i = 0; i < bubble1.size(); i++){

        for(unsigned long j = 0; j < bubble2.size(); j++){

            if(bubble1[i].panAng == bubble2[j].panAng && bubble1[i].tiltAng == bubble2[j].tiltAng && bubble2[j].val < 1)
            {
                if(sum == -1000) sum = 0;

                sum += fabs(bubble1[i].val - bubble2[j].val);
                count++;
                bubble2[j].val = 1000;
            }

        }

    }

    double overlap = count/bubble1.size();

    qDebug()<<"count is: "<<count<<"bubble 1 size is: "<<bubble1.size()<<"sum is: "<<sum<<"overlap is: "<<overlap;

    if(overlap == 0 || overlap < 0.1) overlap = 0.000000001;

    if(sum == -1000) sum = 10000;

    // Sum over overlap
    result.push_back(sum);
    // Overlap
    result.push_back(overlap);
    // Sum over count
    result.push_back(sum/count);

    return result;

}
