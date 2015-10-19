// dfc.cpp : Defines the entry point for the console application.
//

#include "bubbleprocess.h"
#include <stdlib.h>    // exit(..), NULL
#include <stdio.h>     // FILE structure
#include <iostream>  // cin, cout objects & methods
#include <fstream>  // cin, cout objects & methods
#include <cmath>
#include <ctime>
#include <QDebug>
using namespace std;

#define PI 3.14

#define PLACES 77
#define STARTNO 1


// a function to calculate the DF coefficients from bubble and saving it
void bubbleProcess::calculateDFCoefficients(std::vector<bubblePoint> bubble, QString path, QString fileName, int itemNo, int harmonic1, int harmonic2)
{

    int M = harmonic1;

    int N = harmonic2;

    // to keep the time
    clock_t start,ends;

    float f1=45*PI/180,f2;
    float a[M][N],b[M][N],c[M][N],d[M][N];
    cout<<cos(f1)<<endl;

    float angle=5.5, rho;
    f1=angle*M/360;
    float angles[2];
    int angleIndex[2],fixations=0,newFixation=1;

    char coeffFile[150];
    cout<<int(angle)<<endl;

    // initializing the coefficients
    for (int m=0;m<M;m++)
        for (int n=0;n<N;n++) {
            a[m][n]=0;
            b[m][n]=0;
            c[m][n]=0;
            d[m][n]=0;
        }

    rho=10;

    // initializing the fixations
    fixations=0;

    sprintf(coeffFile,"basis.m");
    fstream file_basisRead(coeffFile,ios::in);
    if(file_basisRead.is_open()) qDebug()<<"Basis file has been read";

    for (int m=0;m<M;m++)
        for (int n=0;n<N;n++)
            file_basisRead>>m>>n>>a[m][n]>>b[m][n]>>c[m][n]>>d[m][n];
    file_basisRead.close();

    start = clock();

    // calculating the df coefficients a, b, c, d according to the pan, tilt angles and rho value
    for(int i = 0; i < bubble.size(); i++){

        angles[0] = bubble.at(i).panAng;
        angles[1] = bubble.at(i).tiltAng;
        rho = bubble.at(i).val;

        rho=(rho*10 + 5);

            while (angles[0]<0 || angles[0]>360) {
                if (angles[0]<0)
                    angles[0]=360+angles[0];
                if (angles[0]>360)
                    angles[0]=angles[0]-360;
            }
            while (angles[1]<0 || angles[1]>360) {
                if (angles[1]<0)
                    angles[1]=360+angles[1];
                if (angles[1]>360)
                    angles[1]=angles[1]-360;
            }
            angleIndex[0]=int(angles[0]);
            angleIndex[1]=int(angles[1]);

            if (newFixation==1) {

                fixations++;

                for (int m=0;m<M;m++)
                    for (int n=0;n<N;n++) {
                        f1=float(angleIndex[0]);
                        f2=float(angleIndex[1]);
                        a[m][n]=a[m][n]+rho*cos(m*f1*PI/180)*cos(n*f2*PI/180)*4;
                        b[m][n]=b[m][n]+rho*sin(m*f1*PI/180)*cos(n*f2*PI/180)*4;
                        c[m][n]=c[m][n]+rho*cos(m*f1*PI/180)*sin(n*f2*PI/180)*4;
                        d[m][n]=d[m][n]+rho*sin(m*f1*PI/180)*sin(n*f2*PI/180)*4;
                    }
            }
            newFixation=1;
        }

        ends = clock();

        qDebug() << "One bubble Running Time coefficients (100 fixes): " << (double) (ends - start)*1000 / CLOCKS_PER_SEC << " ms\n";

        qDebug()<<"writing to file coeffs...\n";

        QString fullPath = path;

        fullPath.append(fileName);

        fullPath.append("coeffs_");

        QString ss;

        ss.setNum(itemNo);

        fullPath.append(ss);

        fullPath.append(".m");


        QByteArray ba = fullPath.toLocal8Bit();
        const char *c_str2 = ba.data();

        sprintf(coeffFile,c_str2);
        fstream file_out(coeffFile,ios::out);

        // In how many fixations these coefficients are gotten
        file_out<<fixations<<endl;
        for (int m=0;m<M;m++)
            for (int n=0;n<N;n++)
                file_out<<m<<" "<<n<<" "<<a[m][n]<<" "<<b[m][n]<<" "<<c[m][n]<<" "<<d[m][n]<<endl;
        file_out.close();

}

// calculating the DF coefficients from bubble and harmonics number
DFCoefficients bubbleProcess::calculateDFCoefficients(std::vector<bubblePoint> bubble, int harmonic1, int harmonic2)
{

    int M = harmonic1;

    int N = harmonic2;

    DFCoefficients dfcoeff;

    dfcoeff.a.resize(M);
    dfcoeff.b.resize(M);
    dfcoeff.c.resize(M);
    dfcoeff.d.resize(M);

    for(int i = 0 ; i < M; i++)
    {

        dfcoeff.a[i].resize(N);
        dfcoeff.b[i].resize(N);
        dfcoeff.c[i].resize(N);
        dfcoeff.d[i].resize(N);
    }

    for(int i = 0 ; i < 0; i++)
    {
        for(int j = 0 ; j < 0; j++)
        {

            dfcoeff.a[i][j] = 0;
            dfcoeff.b[i][j] = 0;
            dfcoeff.c[i][j] = 0;
            dfcoeff.d[i][j] = 0;

        }

    }
    //To keep the time
    clock_t start,ends;
    float f1=45*PI/180,f2;
    cout<<cos(f1)<<endl;
    float angle=5.5, rho;
    f1=angle*M/360;
    float angles[2];
    int angleIndex[2],fixations=0,newFixation=1;
    char coeffFile[150];
    cout<<int(angle)<<endl;

    rho=10;

    // initialize the fixations
    fixations=0;

    sprintf(coeffFile,"basis.m");
    fstream file_basisRead(coeffFile,ios::in);

    if(file_basisRead.is_open())
    {

        qDebug()<<"Basis file has been read";

        for (int m=0;m<M;m++)
            for (int n=0;n<N;n++)
                file_basisRead>>m>>n>>dfcoeff.a[m][n]>>dfcoeff.b[m][n]>>dfcoeff.c[m][n]>>dfcoeff.d[m][n];

        file_basisRead.close();
    }
    start = clock();

    for(int i = 0; i < bubble.size(); i++)
    {

        angles[0] = bubble.at(i).panAng;
        angles[1] = bubble.at(i).tiltAng;
        rho = bubble.at(i).val;

            rho=(rho*10 + 5);

            while (angles[0]<0 || angles[0]>360) {
                if (angles[0]<0)
                    angles[0]=360+angles[0];
                if (angles[0]>360)
                    angles[0]=angles[0]-360;
            }
            while (angles[1]<0 || angles[1]>360) {
                if (angles[1]<0)
                    angles[1]=360+angles[1];
                if (angles[1]>360)
                    angles[1]=angles[1]-360;
            }
            angleIndex[0]=int(angles[0]);
            angleIndex[1]=int(angles[1]);


            if (newFixation==1)
            {

                fixations++;

                for (int m=0;m<M;m++)
                    for (int n=0;n<N;n++) {
                        f1=float(angleIndex[0]);
                        f2=float(angleIndex[1]);
                        dfcoeff.a[m][n]=dfcoeff.a[m][n]+rho*cos(m*f1*PI/180)*cos(n*f2*PI/180)*4;
                        dfcoeff.b[m][n]=dfcoeff.b[m][n]+rho*sin(m*f1*PI/180)*cos(n*f2*PI/180)*4;
                        dfcoeff.c[m][n]=dfcoeff.c[m][n]+rho*cos(m*f1*PI/180)*sin(n*f2*PI/180)*4;
                        dfcoeff.d[m][n]=dfcoeff.d[m][n]+rho*sin(m*f1*PI/180)*sin(n*f2*PI/180)*4;
                    }
            }
            newFixation=1;
        }

        ends = clock();

        qDebug() << "One bubble Running Time coefficients (100 fixes): " << (double) (ends - start)*1000 / CLOCKS_PER_SEC << " ms\n";

        return dfcoeff;
}
