#include "Circle.h"

Circle::Circle(double _x, double _y, double _z):x(_x),y(_y),z(_z),radius(100){}

bool Circle::contains(double ax, double ay, double az){

    double dx = x-ax;
    double dy = y-ay;
    double dz = z-az;

    /*
    Se obtiene la distancia minima entre cada abeja utilizando el teorema de pitagoras.
    Luego, si esta da menor al radio del circulo, quiere decir q estan en rango de colision (menor a 100m).
    */
    double distance = sqrt(pow(fabs(dx),2)+pow(fabs(dy),2)+pow(fabs(dz),2));

    if(distance<=100){

       return true;

    }else{

        return false;

    }

}

double Circle::getX(){return x;}

double Circle::getY(){return y;}

double Circle::getZ(){return z;}

int Circle::getR(){return radius;}