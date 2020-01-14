#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <math.h>

using namespace std;

class Circle{

    const int radius;
    double x,y,z;

    public:
    Circle(double _x,double _y, double _z);
    bool contains(double ax, double ay, double az);
    double getX();
    double getY();
    double getZ();
    int getR();

};

#endif