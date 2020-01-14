#ifndef BEES_H
#define BEES_H

#include "Circle.h"
#include <list>

class Bees{

    double x,y,z;
    int state = 0;
    list<Bees*>inRangeBees;
    list<Bees*>::iterator bit;
    Circle* lim;

    public:

    Bees(double _x,double _y,double _z,Circle* c);
    double getX();
    double getY();
    double getZ();
    Circle* getCir();
    void setState(int num);
    int getState();
    void addToList(Bees* b);
    void printList();

};

#endif