#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "bubbleprocess.h"
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QFile>
#include <QDir>

//#define DB_PATH "/home/hakan/Development/ISL/Datasets/ImageClef2012/training3v2.db"
//#define INVARIANTS_DB_PATH "/home/hakan/Development/ISL/Datasets/ImageClef2012/invariants.db"

#define LASER_TYPE 55
#define HUE_TYPE 56
#define SAT_TYPE 57
#define VAL_TYPE 58

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = 0);

   static bool openDB(QString filePath);

   static void closeDB();

   static bool deleteDB();

   static bool isOpen();

   static bool insertRowtoBubble(int type, int number, bubblePoint row);

   static bool insertRowtoBubble(int type, int number, int pan, int tilt, double val);

   static bool insertBubble(int type,int number, std::vector<bubblePoint> bubble);

   static bool insertInvariants(int type,int number, std::vector< std::vector<float> > invariants);

   static bool insertBubbleStatistics(int type, int number, bubbleStatistics stats);

   static std::vector<bubblePoint> readBubble(int type, int number);

   static void determinePlaceLabels(QString filePath);

   QSqlError lastError();

private:

signals:
    
public slots:
    
};

#endif // DATABASEMANAGER_H
