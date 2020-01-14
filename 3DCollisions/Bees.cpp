#include "Bees.h"

Bees::Bees(double _x, double _y,double _z,Circle* c):x(_x),y(_y),z(_z),lim(c){}

double Bees::getX(){return x;}

double Bees::getY(){return y;}

double Bees::getZ(){return z;}

Circle* Bees::getCir(){return lim;}

void Bees::setState(int num){state=num;}

int Bees::getState(){return state;}

void Bees::addToList(Bees* b){
    inRangeBees.push_back(b);
}

//Metodo encargado de imprimir con que abejas choca cada abeja.

void Bees::printList(){

    cout<<"The bee in the position:     x = "<<x<<"     y = "<<y<<"    z = "<<z<<". Crashes with "<<inRangeBees.size()<<" Bees."<<endl;

    for(bit=inRangeBees.begin();bit!=inRangeBees.end();bit++){

        cout<<"\n The bee in the position:    x = "<<(*bit)->getX()<<"   y = "<<(*bit)->getY()<<"  z = "<<(*bit)->getZ()<<"\n"<<endl;
        cout<<"\n---------------------------------------------"<<endl;

    }

}