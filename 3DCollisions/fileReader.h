#ifndef FILEREADER_H
#define FILEREADER_H


#include <stdlib.h>
//For file management
#include <fstream>
//For string management
#include <string.h>
//For parsing strings into doubles
#include <cstddef>
//For mathematics
#include <cmath>
//Class Bees
#include "Quadtree.h"

#include <time.h>

#define  SUMX  75.6
#define  SUMY  6.300


class fileReader{

    private:

    double maxX,minX,maxY,minY,maxZ,minZ,aux;
    list<Bees*> lA;
    list<Bees*>::iterator itLA;
    list<Bees*>bcollided;

    public:
    fileReader();
    void write();
    void read(string path);
    void check();
    void maxLim(double& num1,double& num2);
    void minLim(double& num1, double& num2);
    void printCol();
    
};

#endif