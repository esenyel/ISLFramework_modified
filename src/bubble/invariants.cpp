// invariants.cpp : Defines the entry point for the console application.
//
#include "bubbleprocess.h"
//#include "stdafx.h"
#include <stdlib.h>    // exit(..), NULL
#include <stdio.h>     // FILE structure
//#include <conio.h>     // clrscr(), getch()
#include <iostream>  // cin, cout objects & methods
#include <fstream>  // cin, cout objects & methods
#include <cmath>
#include <ctime>
#include <QDebug>
using namespace std;

#define PI 3.14
#define PLACES 63
#define STARTNO 0

using namespace std;

// calculating the invariants from df coefficients
std::vector< std::vector< float > > bubbleProcess::calculateInvariants(vector<bubblePoint> bubble, QString path, QString fileName , int itemNo, int harmonic1, int harmonic2)
{

    std::vector< std::vector<float> > result;

    result.resize(harmonic1);

    for(int i = 0; i < harmonic1;i++)
    {
        result[i].resize(harmonic2);
    }

    int M = harmonic1;

    int N = harmonic2;

    char invariantFile[150],coeffFile[150];

    float a[M][N],b[M][N],c[M][N],d[M][N],I[M][N];

    int analyzed_points=0;

    QString fullPath = path;

    fullPath.append("coeffs_");

    QString ss;

    ss.setNum(itemNo);

    fullPath.append(ss);

    fullPath.append(".m");


    QByteArray ba = fullPath.toLocal8Bit();
    const char *c_str2 = ba.data();

    sprintf(coeffFile, c_str2);
    qDebug()<<coeffFile<<"\n";

    fullPath = path;

    fullPath.append(fileName);
    fullPath.append(ss);
    fullPath.append(".m");

    ba = fullPath.toLocal8Bit();
    const char *c_str3 = ba.data();

    sprintf(invariantFile,c_str3);
    qDebug()<<invariantFile<<"\n";

    fstream file_in(coeffFile,ios::in);

    if(file_in.is_open()){

        file_in>>analyzed_points;

        for (int m=0;m<M;m++)
            for (int n=0;n<N;n++)
                file_in>>m>>n>>a[m][n]>>b[m][n]>>c[m][n]>>d[m][n];
        file_in.close();

        for (int m=0;m<M;m++)

            for (int n=0;n<N;n++)
            {

                if (m==0)
                    I[m][n]=a[m][n]*a[m][n]+c[m][n]*c[m][n];
                else
                    I[m][n]=a[m][n]*a[m][n]+b[m][n]*b[m][n]+c[m][n]*c[m][n]+d[m][n]*d[m][n];

                result[m][n] = I[m][n];
            }
    }

   return result;

}

// calculating the bubble invariants from DF coefficients
std::vector< std::vector< float > > bubbleProcess::calculateInvariants(std::vector <bubblePoint> bubble, DFCoefficients coeff, int harmonic1, int harmonic2)
{

    std::vector< std::vector<float> > result;

    result.resize(harmonic1);

    for(int i = 0; i < harmonic1;i++)
    {
        result[i].resize(harmonic2);
    }

    int M = harmonic1;

    int N = harmonic2;

    float I[M][N];


    for (int m=0;m<M;m++)

        for (int n=0;n<N;n++)
        {

            if (m==0)
                I[m][n]=coeff.a[m][n]*coeff.a[m][n]+coeff.c[m][n]*coeff.c[m][n];
            else
                I[m][n]=coeff.a[m][n]*coeff.a[m][n]+coeff.b[m][n]*coeff.b[m][n]+coeff.c[m][n]*coeff.c[m][n]+coeff.d[m][n]*coeff.d[m][n];

            result[m][n] = I[m][n];
        }

    return result;

}

