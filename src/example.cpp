
#include "MainWindow.h"

int main(int argc, char **argv){

    QApplication app(argc,argv);

    ros::init(argc, argv, "ISLFramework");

    MainWindow mw;

    mw.show();

    return app.exec();
}
