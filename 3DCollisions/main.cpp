/*

Este codigo a sido hecho en base a la informacion obtenida de las siguientes fuentes:

TheCodeTrain: 
http://www.youtube.com/watch?v=OJxEcs0w_kE   (En estos videos se crea una estructura Quadtree usando el lenguaje JavaScript y fue tomado como base para entender y empezar la progrmacion en C++)


Wikipedia:
http://en.m.wikipedia.org/wiki/Quadtree

Otros:
http://www.cplusplus.com  (Mucha de la informacion sobre librerias y su respectivo uso fue obtenida de este sitio).

*/


#include "fileReader.h"
#include <limits>

int main(void){

//Se genera un menu interactivo con el ususrio donde este decide que numero de abejas desea escanear.
    cout<<"\t\t\tEnter the number of bees too be sacanned"<<endl;
    cout<<"THE OPTIONS ARE! :  10, 100, 1000, 10000, 1000000"<<endl;
    
    fileReader fM;
    int num;
    cin>>num;

    while(!(num==10 || num==100 || num==1000 || num==10000 || num==100000 || num==1000000)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid number of bees. Enter it again."<<endl;
        cin>>num;
    }

    switch(num){

        case 10:
           fM.read("ConjuntoDeDatosCon10abejas.txt");
           fM.check();
           break;
        
        case 100:
           fM.read("ConjuntoDeDatosCon100abejas.txt");
           fM.check();
           break;

        case 1000:
           fM.read("ConjuntoDeDatosCon1000abejas.txt");
           fM.check();
           break;

        case 10000:
           fM.read("ConjuntoDeDatosCon10000abejas.txt");
           fM.check();
           break;

        case 100000:
           fM.read("ConjuntoDeDatosCon100000abejas.txt");
           fM.check();
           break;

        case 1000000:
           fM.read("ConjuntoDeDatosCon1000000abejas.txt");
           fM.check();

    }

    cout<<"Now the colitions of each bee will be printed"<<endl;
    system("pause");

    fM.printCol();


    system("pause");

    return 0;


}