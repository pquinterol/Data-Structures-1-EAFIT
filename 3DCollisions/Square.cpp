#include "Square.h"

/*
x = punto de inicio del cuadrado
y = punto de inicio de la altura del cuandrado.
w = valor max de la anchura.
h = valor maximo de la altura.
*/
Square::Square(double _x, double _y, double _w, double _h):x(_x),y(_y),w(_w),h(_h){}


//Se evalua si la x de la abeja a insertar es major q la x del cuandrado(limite a la izquierda) e igual con los otros limites.

bool Square::contains(Bees* b){return ((*b).getX()>=x && (*b).getX()<=w) && ((*b).getY()>=y && (*b).getY()<=h);}

bool Square::intersects(Circle* c){

    return !((*c).getX()+(*c).getR()<x || (*c).getX()-(*c).getR()>w || (*c).getY()+(*c).getR()<y || (*c).getY()+(*c).getR()>h);

}

double Square::getX(){return x;}

double Square::getY(){return y;}

double Square::getW(){return w;}

double Square::getH(){return h;}