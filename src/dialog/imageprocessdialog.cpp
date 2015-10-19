#include "imageprocessdialog.h"
#include "ui_imageprocessdialog.h"
#include "kinectutility.h"
#include "pcprocessing.h"
#include "imageprocess.h"
#include "bubbleprocess.h"

#include <QFileDialog>
#include <QCheckBox>
#include <QDebug>
#include <QListView>
#include <QAbstractItemModel>
#include <QStringListModel>
#include <QKeyEvent>
#include <ctime>
#include "databasemanager.h"

QString filterpath ;

ImageProcessDialog::ImageProcessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageProcessDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Image Process Dialog");

    initView();

}
ImageProcessDialog::ImageProcessDialog(QWidget *parent, PCprocessing *pcprocess):QDialog(parent),ui(new Ui::ImageProcessDialog)
{
    this->pcProcess = pcprocess;

    ui->setupUi(this);

    this->setWindowTitle("Image Process Dialog");

    initView();
}
ImageProcessDialog::ImageProcessDialog(QWidget *parent, int imageWidth, int imageHeight, int focalLengthPixels):QDialog(parent),ui(new Ui::ImageProcessDialog)
{

    ui->setupUi(this);

    this->setWindowTitle("Image Process Dialog");

    this->focalLengthPixels = focalLengthPixels;

    this->imageHeight = imageHeight;

    this->imageWidth = imageWidth;

    initView();

}
void ImageProcessDialog::initView()
{
    //specifying harmonics number
    ui->lEditNoHarmonicsInvariant_4->setText("10");

    // calculating image pan and tilt angles according to the image width, height and focal length specified in main window
    bubbleProcess::calculateImagePanAngles(focalLengthPixels,imageWidth,imageHeight);

    bubbleProcess::calculateImageTiltAngles(focalLengthPixels,imageWidth,imageHeight);

    ui->labelOrgImage->setScaledContents(true);

    ui->labelProcessedImage->setScaledContents(true);

    //specifying the lower and upper values of saturation and value
    ui->lEditSatLower->setText(QString::number(ui->horsliderSatLower->value()));

    ui->lEditSatUpper->setText(QString::number(ui->horsliderSatUpper->value())) ;

    ui->lEditValLower->setText(QString::number(ui->horsliderValLower->value()));

    ui->lEditValUpper->setText(QString::number(ui->horsliderValUpper->value()));

    ui->rButHue_4->setChecked(true);
    ui->rButFilter_4->setChecked(false);
}

ImageProcessDialog::~ImageProcessDialog()
{
    delete ui;
}

void ImageProcessDialog::setPCprocessing(PCprocessing *pcprocess){

    this->pcProcess = pcprocess;

}
// a function to load and image and show it on original image window
void ImageProcessDialog::on_but_LoadImage_4_clicked()
{
    // Get the root directory
    QString path =   QFileDialog::getOpenFileName(this,"Open Image File","/home/hakan/Development",NULL);

    if(path != NULL)
    {

        QImage* image = new QImage(path);

        if(image != NULL)
        {
            ui->labelOrgImage->setPixmap(QPixmap::fromImage(*image));

            Mat img = cv::imread(path.toStdString(),1);

            ImageProcess::setImage(img);

       }
    }
}

// a function to set the path of images
void ImageProcessDialog::on_butSetDSetPath_4_clicked()
{
    QString path = PCprocessing::getDataSetPath();

    if(path != NULL){

        ImageProcess::setDataSetPath(path);

        ui->lEditDSetPath_4->setText(path);

        if(this->imageFileNames.size() > 0){

            this->imageFileNames.clear();

            QAbstractItemModel* model = new QStringListModel(this->imageFileNames);

            ui->listViewInputFileNames->setModel(model);

        }

        return;

    }

    path = QFileDialog::getExistingDirectory(this,"Set dataset path","/home/hakan",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if(path != NULL)
    {
        path.append("/");

        ImageProcess::setDataSetPath(path);

        ui->lEditDSetPath_4->setText(path);

    }

}
// load the selected filter
void ImageProcessDialog::on_butLoadFilter_4_clicked()
{
    // Get the root directory
    filterpath =   QFileDialog::getOpenFileName(this,"Open Filter File","/home/hakan/Development", tr("*.txt"));

    if(filterpath != NULL)
        ImageProcess::readFilter(filterpath, 29,false,false,true);

}

// a function to apply all selected filters and hue images to the all selected images
// and calculating their bubble surfaces, invariants and statistics and writing on the database
void ImageProcessDialog::on_butApplyAll_clicked()
{
    if(this->imageFileNames.size() <= 0) return;

    clock_t start,ends;

    // This part is for OmniDirectional Camera Images
    if(ui->cBoxOmni_4->isChecked())
    {
        bool okAngle = false;
        bool okNoImages = false;

        // specifying the number of images in panoramic image and the angle difference between them
        double angleOffset =  ui->lEditAngleOffsetOmni_4->text().toDouble(&okAngle);
        int noImages = ui->lEditNoImagesOmni_4->text().toInt(&okNoImages);

        qDebug()<<"Params Omni"<<angleOffset<<noImages;

        if(!okAngle || !okNoImages)
        {
            qDebug()<<"Parameters are not entered correctly!! Returning...";
            return;
        }

        // Find the number of basepoints
        int noBasePoints = this->imageFileNames.size()/noImages;
        qDebug()<<"Number of base points"<<this->imageFileNames.size()<<noImages<<noBasePoints;

        // calculating the hue part of the bubble space construction
        if(ui->rButHue_4->isChecked())
        {

            qDebug()<<"Hue part is active";

            if(!DatabaseManager::isOpen())
            {

                qDebug()<<"Bubble Database Could not be opened!! returning...";

                return;

            }

            for(int i = 0; i < noBasePoints ; i++)
            {
                vector<bubblePoint> hueBubbleWhole;
                vector<bubblePoint> satBubbleWhole;
                vector<bubblePoint> valBubbleWhole;

                for(int j = 0; j < noImages; j++)
                {
                    QString fullPath = imageFileNames[i*noImages+j];

                    qDebug()<<"Full Path: "<<fullPath;

                    Mat img = ImageProcess::loadImage(fullPath,false);

                    if(img.empty())
                    {
                        qDebug()<<"Error!! Image could not be loaded, returning...";
                        return;
                    }

                    int satLower =  ui->horsliderSatLower->value();

                    int satUpper =  ui->horsliderSatUpper->value();

                    int valLower =  ui->horsliderValLower->value();

                    int valUpper = ui->horsliderValUpper->value();

                    Mat hueChannel= ImageProcess::generateChannelImage(img,0,satLower,satUpper,valLower,valUpper);

                    /************************** Perform filtering and obtain resulting mat images ***********************/
                    Mat satChannel= ImageProcess::generateChannelImage(img,1,satLower,satUpper,valLower,valUpper);
                    Mat valChannel= ImageProcess::generateChannelImage(img,2,satLower,satUpper,valLower,valUpper);
                    /*****************************************************************************************************/

                    QImage* image = new QImage(hueChannel.data,hueChannel.cols,hueChannel.rows,hueChannel.step,QImage::Format_Mono);

                    // showing the processed image on processed image window
                    ui->labelProcessedImage->setPixmap(QPixmap::fromImage(*image));

                    /*************************** Convert images to bubbles ***********************************************/

                    vector<bubblePoint> hueBubble = bubbleProcess::convertGrayImage2Bub(hueChannel,focalLengthPixels,180, j*angleOffset);
                    vector<bubblePoint> satBubble = bubbleProcess::convertGrayImage2Bub(satChannel,focalLengthPixels,255, j*angleOffset);
                    vector<bubblePoint> valBubble = bubbleProcess::convertGrayImage2Bub(valChannel,focalLengthPixels,255, j*angleOffset);

                    /*****************************************************************************************************/

                    hueBubbleWhole.insert(hueBubbleWhole.end(),hueBubble.begin(),hueBubble.end());

                    valBubbleWhole.insert(valBubbleWhole.end(),valBubble.begin(),valBubble.end());

                    satBubbleWhole.insert(satBubbleWhole.end(),satBubble.begin(),satBubble.end());
                }

                int noHarmonics = ui->lEditNoHarmonicsInvariant_4->text().toInt();

                vector<bubblePoint> reducedHueBubble = bubbleProcess::reduceBubble(hueBubbleWhole);

                // We want to add bubbles to the database
                if(ui->cBoxBubble_4->isChecked())
                {
                    qDebug()<<"Calculating bubble for hue";

                    DatabaseManager::insertBubble(HUE_TYPE, i+1,reducedHueBubble);
                }

                if(ui->cBoxInvariants_4->isChecked())
                {
                    qDebug()<<"Calculating invariants for hue";

                    DFCoefficients dfcoeff = bubbleProcess::calculateDFCoefficients(reducedHueBubble,noHarmonics,noHarmonics);

                    std::vector< std::vector<float> > invariants = bubbleProcess::calculateInvariants(reducedHueBubble, dfcoeff,noHarmonics, noHarmonics);

                    DatabaseManager::insertInvariants(HUE_TYPE,i+1,invariants);

                }

                if(ui->cBoxBubbleStats_4->isChecked())
                {
                    qDebug()<<"Calculating stats for hue";

                    /***************** Reduce the bubbles ********************************************************/
                    vector<bubblePoint> reducedSatBubble = bubbleProcess::reduceBubble(satBubbleWhole);
                    vector<bubblePoint> reducedValBubble = bubbleProcess::reduceBubble(valBubbleWhole);

                    // Calculate statistics
                    bubbleStatistics statsHue =  bubbleProcess::calculateBubbleStatistics(reducedHueBubble,180);
                    bubbleStatistics statsSat =  bubbleProcess::calculateBubbleStatistics(reducedSatBubble,255);
                    bubbleStatistics statsVal =  bubbleProcess::calculateBubbleStatistics(reducedValBubble,255);

                    DatabaseManager::insertBubbleStatistics(HUE_TYPE,i+1,statsHue);
                    DatabaseManager::insertBubbleStatistics(SAT_TYPE,i+1,statsSat);
                    DatabaseManager::insertBubbleStatistics(VAL_TYPE,i+1,statsVal);


                }

            } // End an omni-directional image

        } // End Hue Part


        // Calculating bubble surfaces and invariants for selected filters
        else if(ui->rButFilter_4->isChecked())
        {
            qDebug()<<"Filter part is active";

            if(!DatabaseManager::isOpen())
            {

                qDebug()<<"Database could not be opened!! returning...";

                return;
            }
            if(filters.size() == 0)
            {
                qDebug()<<"There are no filters selected!! returning...";

                return;
            }

            // For each filter
            for(int i = 0; i < filters.size(); i++)
            {
                int filterNumber = ImageProcess::getFrameNumber(filters.at(i));

                if(filterNumber == -1)
                {
                    qDebug()<<"Error!! Filter number could not be determined, returning...";
                    return;
                }

                ImageProcess::readFilter(filters.at(i),29,false,false,false);

                for(int k = 0; k < noBasePoints ; k++)
                {
                    vector<bubblePoint> filterBubbleWhole;

                    for(int j = 0; j < noImages; j++)
                    {
                        QString tempPath = imageFileNames[k*noImages+j];

                        qDebug()<<"Temp path: "<<tempPath;

                        Mat img = ImageProcess::loadImage(tempPath,false);

                        Mat image_gray;

                        cv::cvtColor(img,image_gray,CV_BGR2GRAY);

                        Mat result = ImageProcess::applyFilter(image_gray);

                        vector<bubblePoint> imgBubble = bubbleProcess::convertGrayImage2Bub(result,focalLengthPixels,255, j*angleOffset);

                        filterBubbleWhole.insert(filterBubbleWhole.end(),imgBubble.begin(),imgBubble.end());
                    }

                        vector<bubblePoint> image_reduced ;

                        image_reduced = bubbleProcess::reduceBubble(filterBubbleWhole);

                        // We want to add bubbles to the database
                        if(ui->cBoxBubble_4->isChecked())
                        {
                            qDebug()<<"Calculating bubble for filter";

                            DatabaseManager::insertBubble(filterNumber,k+1,image_reduced);
                        }

                        if(ui->cBoxInvariants_4->isChecked())
                        {
                            int noHarmonics = ui->lEditNoHarmonicsInvariant_4->text().toInt();

                            DFCoefficients dfcoeff =  bubbleProcess::calculateDFCoefficients(image_reduced,noHarmonics,noHarmonics);

                            std::vector< std::vector< float > > invariants =  bubbleProcess::calculateInvariants(image_reduced,dfcoeff,noHarmonics,noHarmonics);

                            DatabaseManager::insertInvariants(filterNumber,k+1,invariants);
                        }

                        if(ui->cBoxBubbleStats_4->isChecked())
                        {
                            qDebug()<<"Calculating stats for filter";

                            bubbleStatistics stats =  bubbleProcess::calculateBubbleStatistics(image_reduced,255);

                            DatabaseManager::insertBubbleStatistics(filterNumber,k+1,stats);

                        }


                } // END an omnidirectional image

            } // END FOR all filters

        } // End Filter Part


        return;

    }
    // this part is for images that are not omnidirectional
    if(ui->rButHue_4->isChecked())
    {

        qDebug()<<"Hue part is active";

        if(!DatabaseManager::isOpen())
        {

            qDebug()<<"Bubble Database Could not be opened!! returning...";

            return;

        }
        for(unsigned int i = 1; i <= imageFileNames.size(); i++)
        {
            QString fullPath = imageFileNames[i-1];

            qDebug()<<"Full Path: "<<fullPath;

            int frameNumber = ImageProcess::getFrameNumber(fullPath);

            if(frameNumber == -1)
            {
                qDebug()<<"Error!! Frame number could not be determined, returning...";
                return;
            }

            Mat img = ImageProcess::loadImage(fullPath,false);

            if(img.empty())
            {
                qDebug()<<"Error!! Image could not be loaded, returning...";
                return;
            }

            int satLower =  ui->horsliderSatLower->value();

            int satUpper =  ui->horsliderSatUpper->value();

            int valLower =  ui->horsliderValLower->value();

            int valUpper = ui->horsliderValUpper->value();

            Mat hueChannel= ImageProcess::generateChannelImage(img,0,satLower,satUpper,valLower,valUpper);

            QImage* image = new QImage(hueChannel.data,hueChannel.cols,hueChannel.rows,hueChannel.step,QImage::Format_Mono);

            ui->labelProcessedImage->setPixmap(QPixmap::fromImage(*image));

            start = clock();

            vector<bubblePoint> hueBubble = bubbleProcess::convertGrayImage2Bub(hueChannel,focalLengthPixels,180);

            vector<bubblePoint> reducedHueBubble = bubbleProcess::reduceBubble(hueBubble);

            ends = clock();

            qDebug()<<"Hue bubble generation time"<<((float)(ends-start)*1000/CLOCKS_PER_SEC)<<" ms";

            int noHarmonics = ui->lEditNoHarmonicsInvariant_4->text().toInt();

            // We want to add bubbles to the database
            if(ui->cBoxBubble_4->isChecked())
            {
                qDebug()<<"Calculating bubble for hue";

                DatabaseManager::insertBubble(HUE_TYPE, frameNumber,reducedHueBubble);

                /************************** Perform filtering and obtain resulting mat images ***********************/
                Mat satChannel= ImageProcess::generateChannelImage(img,1,satLower,satUpper,valLower,valUpper);
                Mat valChannel= ImageProcess::generateChannelImage(img,2,satLower,satUpper,valLower,valUpper);
                /*****************************************************************************************************/

                /*************************** Convert images to bubbles ***********************************************/

                vector<bubblePoint> satBubble = bubbleProcess::convertGrayImage2Bub(satChannel,focalLengthPixels,255);
                vector<bubblePoint> valBubble = bubbleProcess::convertGrayImage2Bub(valChannel,focalLengthPixels,255);

                /*****************************************************************************************************/

                /***************** Reduce the bubbles ********************************************************/
                vector<bubblePoint> reducedSatBubble = bubbleProcess::reduceBubble(satBubble);
                vector<bubblePoint> reducedValBubble = bubbleProcess::reduceBubble(valBubble);

                DatabaseManager::insertBubble(SAT_TYPE, frameNumber,reducedSatBubble);

                DatabaseManager::insertBubble(VAL_TYPE, frameNumber,reducedValBubble);
            }

            if(ui->cBoxInvariants_4->isChecked())
            {
                qDebug()<<"Calculating invariants for hue";

                DFCoefficients dfcoeff = bubbleProcess::calculateDFCoefficients(reducedHueBubble,noHarmonics,noHarmonics);

                std::vector< std::vector<float> > invariants = bubbleProcess::calculateInvariants(reducedHueBubble, dfcoeff,noHarmonics, noHarmonics);

                DatabaseManager::insertInvariants(HUE_TYPE,frameNumber,invariants);

            }

            if(ui->cBoxBubbleStats_4->isChecked())
            {
                qDebug()<<"Calculating stats for hue";

                /************************** Perform filtering and obtain resulting mat images ***********************/
                Mat satChannel= ImageProcess::generateChannelImage(img,1,satLower,satUpper,valLower,valUpper);
                Mat valChannel= ImageProcess::generateChannelImage(img,2,satLower,satUpper,valLower,valUpper);
                /*****************************************************************************************************/

                /*************************** Convert images to bubbles ***********************************************/

                vector<bubblePoint> satBubble = bubbleProcess::convertGrayImage2Bub(satChannel,focalLengthPixels,255);
                vector<bubblePoint> valBubble = bubbleProcess::convertGrayImage2Bub(valChannel,focalLengthPixels,255);

                /*****************************************************************************************************/

                /***************** Reduce the bubbles ********************************************************/
                vector<bubblePoint> reducedSatBubble = bubbleProcess::reduceBubble(satBubble);
                vector<bubblePoint> reducedValBubble = bubbleProcess::reduceBubble(valBubble);

                // Calculate statistics
                bubbleStatistics statsHue =  bubbleProcess::calculateBubbleStatistics(reducedHueBubble,180);
                bubbleStatistics statsSat =  bubbleProcess::calculateBubbleStatistics(reducedSatBubble,255);
                bubbleStatistics statsVal =  bubbleProcess::calculateBubbleStatistics(reducedValBubble,255);

                DatabaseManager::insertBubbleStatistics(HUE_TYPE,frameNumber,statsHue);
                DatabaseManager::insertBubbleStatistics(SAT_TYPE,frameNumber,statsSat);
                DatabaseManager::insertBubbleStatistics(VAL_TYPE,frameNumber,statsVal);
            }
        }
       return;
    } // END HUE PART

    // calculating bubble space and invariants for filters
    else if(ui->rButFilter_4->isChecked())
    {
        qDebug()<<"Filter part is active";

        if(!DatabaseManager::isOpen())
        {

            qDebug()<<"Database could not be opened!! returning...";

            return;
        }
        if(filters.size() == 0)
        {
            qDebug()<<"There are no filters selected!! returning...";

            return;
        }

        // For each filter
        for(int i = 0; i < filters.size(); i++)
        {

            int filterNumber = ImageProcess::getFrameNumber(filters.at(i));

            if(filterNumber == -1)
            {
                qDebug()<<"Error!! Filter number could not be determined, returning...";
                return;
            }

            ImageProcess::readFilter(filters.at(i),29,false,false,false);

            for(int j = 1; j <= this->imageFileNames.size(); j++)
            {

                QString tempPath = imageFileNames.at(j-1);

                qDebug()<<"Temp path: "<<tempPath;

                QString fullFilePath =tempPath;

                int frameNumber = ImageProcess::getFrameNumber(fullFilePath);

                if(frameNumber == -1){

                    qDebug()<<"Error!! Frame number could not be determined, returning...";
                    return;
                }

                start = clock();

                Mat img = ImageProcess::loadImage(tempPath,false);

                Mat image_gray;

                cv::cvtColor(img,image_gray,CV_BGR2GRAY);

                Mat result = ImageProcess::applyFilter(image_gray);

                vector<bubblePoint> imgBubble = bubbleProcess::convertGrayImage2Bub(result,focalLengthPixels,255);

                vector<bubblePoint> image_reduced ;

                image_reduced = bubbleProcess::reduceBubble(imgBubble);

                // We want to add bubbles to the database
                if(ui->cBoxBubble_4->isChecked())
                {
                    qDebug()<<"Calculating bubble for filter";

                    DatabaseManager::insertBubble(filterNumber,frameNumber,image_reduced);

                }

                if(ui->cBoxInvariants_4->isChecked())
                {
                    int noHarmonics = ui->lEditNoHarmonicsInvariant_4->text().toInt();

                    DFCoefficients dfcoeff =  bubbleProcess::calculateDFCoefficients(image_reduced,noHarmonics,noHarmonics);

                    std::vector< std::vector< float > > invariants =  bubbleProcess::calculateInvariants(image_reduced,dfcoeff,noHarmonics,noHarmonics);

                    DatabaseManager::insertInvariants(filterNumber,frameNumber,invariants);
                }

                if(ui->cBoxBubbleStats_4->isChecked())
                {
                    qDebug()<<"Calculating stats for filter";

                    bubbleStatistics stats =  bubbleProcess::calculateBubbleStatistics(image_reduced,255);

                    DatabaseManager::insertBubbleStatistics(filterNumber,frameNumber,stats);

                }

            } // END FOR

        } // END FOR

    }
}

//functions to add and remove input and filter file names

void ImageProcessDialog::on_butAddtoInputFileNames_clicked()
{

    QString path = ImageProcess::getDataSetPath();

    if(path == NULL) return;

    QDir dirPath(path);

    dirPath.setFilter(QDir::NoDotAndDotDot | QDir::Files);

    QFileDialog dialog(this);
    dialog.setDirectory(dirPath);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setOption(QFileDialog::DontUseNativeDialog, true);
    dialog.setNameFilter(tr("Images(*.ppm *.png *.jpeg *.jpg)"));
    QStringList fileNames;

    if(this->imageFileNames.size() > 0) this->imageFileNames.clear();

    if (dialog.exec())
        this->imageFileNames = dialog.selectedFiles();

    QAbstractItemModel* mod = new QStringListModel(this->imageFileNames);

    ui->listViewInputFileNames->setModel(mod);

}

void ImageProcessDialog::on_butAddtoFilterNames_clicked()
{
    QString path = ImageProcess::getDataSetPath();

    if(path == NULL) return;

    QDir dirPath(path);

    dirPath.setFilter(QDir::NoDotAndDotDot | QDir::Files);

    QFileDialog dialog(this);
    dialog.setDirectory(dirPath);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter("All filter files (*.txt)");

    if (dialog.exec())
        this->filters = dialog.selectedFiles();

    QAbstractItemModel* mod = new QStringListModel(this->filters);

    ui->listViewVisFilterNames->setModel(mod);

}

void ImageProcessDialog::on_butRemoveInputFileNames_clicked()
{

    if(ui->listViewInputFileNames->model())
    {
        ui->listViewInputFileNames->model()->removeRow(ui->listViewInputFileNames->currentIndex().row());

        QStringListModel* sss = (QStringListModel*)ui->listViewInputFileNames->model();

        this->imageFileNames.clear();

        this->imageFileNames = sss->stringList();

        qDebug()<<this->imageFileNames;

    }
}

void ImageProcessDialog::on_butRemoveFilterNames_clicked()
{

    if(ui->listViewVisFilterNames->model()){

        ui->listViewVisFilterNames->model()->removeRow(ui->listViewVisFilterNames->currentIndex().row());

        QStringListModel* sss = (QStringListModel*)ui->listViewVisFilterNames->model();

        this->filters.clear();

        this->filters = sss->stringList();

        qDebug()<<this->filters;

    }

}

//functions to change the slider values of value and saturation for hue image generation

void ImageProcessDialog::on_horsliderSatUpper_valueChanged(int value)
{
    ui->lEditSatUpper->setText(QString::number(value)) ;

    int satlower = ui->horsliderSatLower->value();

    int vallower = ui->horsliderValLower->value();

    int valupper =ui->horsliderValUpper->value();

    Mat hueChannel = ImageProcess::generateHueImage(satlower,value,vallower,valupper);

    QImage* image = new QImage(hueChannel.data,hueChannel.cols,hueChannel.rows,hueChannel.step,QImage::Format_Indexed8);

    ui->labelProcessedImage->setPixmap(QPixmap::fromImage(*image));

}

void ImageProcessDialog::on_horsliderSatLower_valueChanged(int value)
{

    ui->lEditSatLower->setText(QString::number(value));

    int satlower = value ;

    int satupper = ui->horsliderSatUpper->value();

    int vallower = ui->horsliderValLower->value();

    int valupper =ui->horsliderValUpper->value();

    Mat hueChannel = ImageProcess::generateHueImage(satlower,satupper,vallower,valupper);

    QImage* image = new QImage(hueChannel.data,hueChannel.cols,hueChannel.rows,hueChannel.step,QImage::Format_Indexed8);

    ui->labelProcessedImage->setPixmap(QPixmap::fromImage(*image));

}

void ImageProcessDialog::on_horsliderValUpper_valueChanged(int value)
{
    ui->lEditValUpper->setText(QString::number(value));

    int satlower = ui->horsliderSatLower->value();

    int satupper = ui->horsliderSatUpper->value();

    int vallower = ui->horsliderValLower->value();

    int valupper = value;

    Mat hueChannel = ImageProcess::generateHueImage(satlower,satupper,vallower,valupper);

    QImage* image = new QImage(hueChannel.data,hueChannel.cols,hueChannel.rows,hueChannel.step,QImage::Format_Indexed8);

    ui->labelProcessedImage->setPixmap(QPixmap::fromImage(*image));

}

void ImageProcessDialog::on_horsliderValLower_valueChanged(int value)
{

    ui->lEditValLower->setText(QString::number(value));

    int satlower = ui->horsliderSatLower->value();

    int satupper = ui->horsliderSatUpper->value();

    int vallower = value;

    int valupper =ui->horsliderValUpper->value();

    Mat hueChannel = ImageProcess::generateHueImage(satlower,satupper,vallower,valupper);

    QImage* image = new QImage(hueChannel.data,hueChannel.cols,hueChannel.rows,hueChannel.step,QImage::Format_Indexed8);

    ui->labelProcessedImage->setPixmap(QPixmap::fromImage(*image));

}

// a function to apply the loaded filter to the loaded image and show it on processed image window and construct and save the bubble
// from filtered image
void ImageProcessDialog::on_butApplyFilter_4_clicked()
{
    // getting the loaded filter and image
    Mat orgImg= ImageProcess::getImage();

    Mat loadedFilter = ImageProcess::getFilter();

    if(loadedFilter.empty()) return;

    if(orgImg.empty()) return;

    Mat grImg;

    cv::cvtColor(orgImg,grImg,CV_BGR2GRAY);

    Mat result = ImageProcess::applyFilter(grImg);

    imwrite("filterResult.jpg",result);

    // constructing bubble surface and saving it
    vector<bubblePoint> initialBubble =  bubbleProcess::convertGrayImage2Bub(result,focalLengthPixels,255);

    vector<bubblePoint> reducedBubble= bubbleProcess::reduceBubble(initialBubble);

    bubbleProcess::calculateBubbleStatistics(reducedBubble,255);

    QFile file("bubbleFiltResult.txt");

    file.open(QFile::WriteOnly);

    bubbleProcess::saveBubble(&file,reducedBubble);

    QImage* image = new QImage(result.data,result.cols,result.rows,result.step,QImage::Format_Mono);

    ui->labelProcessedImage->setPixmap(QPixmap::fromImage(*image));
    file.close();
}


