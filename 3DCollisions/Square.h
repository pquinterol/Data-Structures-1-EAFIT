#ifndef SQUARE_H
#define SQUARE_H

#include "Bees.h"

class Square{

    double x;
    double y;
    double w;
    double h;

    public:
    Square(double _x,double _y, double _w, double _h);
    bool contains(Bees* b);
    bool intersects(Circle* c);
    double getX();
    double getY();
    double getW();
    double getH();

};

#endif