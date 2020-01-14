#include "Quadtree.h"

/*
El Quadtree es un algoritmo que divide un area en 4 subcuadrados, este algoritmo es muy utilizado para detectar colisiones en videojuegos.
Esta estructura trabaja en 2D, pero siendo nuestro caso el analisis de 2 variables, el manejo del Quadtree se da en 2D y el anlisis en 3D lo hace cada circulo respectivamente.
*/

Quadtree::Quadtree(Square* _sq,list<Bees*>& collision)
:sq(_sq),divided(false),capacity(300),hypo(hypot(pow((*sq).getX(),2),pow((*sq).getY(),2))>42.4264),col(&collision){}

bool  Quadtree::insert(Bees* b){
   
   if((*sq).contains(b)){

       if(!hypo){

                for(it=lBees.begin();it!=lBees.end();it++){

                    icrash = find((*col).begin(),(*col).end(),(*it));

                    if(icrash!=(*col).end()){

                    }else{
                       (*col).push_back((*it));
                    } 
                    
                }
      
        }else if(lBees.size()>=capacity){

            if(!divided && hypo){

               subdivide();
               divided = true;
            }

            /*if(lBees.size()>0 && init==0){

               for(it=lBees.begin();it!=lBees.end();it++){

                   if((*NW).insert((*it))){

                   }else if((*NE).insert((*it))){

                   }else if((*SW).insert((*it))){

                   }else if((*SE).insert((*it))){

                   }

                }
            }

            */

            if((*NW).insert(b)){
                init++;
                return true;

             }else if((*NE).insert(b)){
                 init++;
                 return true;

             }else if((*SW).insert(b)){
                 init++;
                 return true;
                 init++;
             }else if((*SE).insert(b)){
                 init++;
                 return true;

             }
    
          

        }else{

             lBees.push_back(b);

        }

   }else{
       //cout<<"no esta en este cuadrado"<<endl;
       return false;
   }

   //cout<<lBees.size()<<endl;

}

void Quadtree::subdivide(){

    //Se crean los cuadrdos respectivos para cada Quadtree.
    Square* nw = new Square((*sq).getX() , ((*sq).getH()+(*sq).getY())/2 , ((*sq).getW()+(*sq).getX())/2 , (*sq).getH());
    Square* ne = new Square(((*sq).getX()+(*sq).getW())/2 , ((*sq).getY()+(*sq).getH())/2 , (*sq).getW() , (*sq).getH());
    Square* sw = new Square((*sq).getX() , (*sq).getY() , ((*sq).getX()+(*sq).getW())/2 , ((*sq).getY()+(*sq).getH())/2);
    Square* se = new Square(((*sq).getX()+(*sq).getW())/2 , (*sq).getY() , (*sq).getW() , ((*sq).getY()+(*sq).getH())/2);

    //Se crean los Quadtree ingresandoles su cuadrado respectivo.
    NW = new Quadtree(nw, (*col));
    NE = new Quadtree(ne, (*col));
    SW = new Quadtree(sw, (*col));
    SE = new Quadtree(se, (*col));

}

//La funcion query toma como parametros una abeja y la lista de chocadas.
//Esta funcion utiliza los cicrculos de cada abeja para obtener el area (esfera) con la cual debe hacer la comparacion en 3D.

void Quadtree::query(Bees* bc, list<Bees*>& crash){

    Circle* crashZone = (*bc).getCir();

    if(!(*sq).intersects(crashZone)){

        

    }else{

        for(it=lBees.begin();it!=lBees.end();it++){

            double ax,ay,az,cx,cy,cz;

            ax = (*it)->getX();
            ay = (*it)->getY();
            az = (*it)->getZ();

            cx = (*crashZone).getX();
            cy = (*crashZone).getY();
            cz = (*crashZone).getZ();

            //Se analiza que las coordenadas de la abeja a leer no sean iguales a las de la abeja del circulo, ya que esto quedria decir que son la misma.

            if((*crashZone).contains(ax,ay,az) && (cx!=ax && cy!=ay && cz!=az)){

                (*bc).addToList((*it));

                icrash = find(crash.begin(),crash.end(),(*it));

                if(icrash!=crash.end()){

                }else{
                    crash.push_back((*it));
                } 

            }


        }

        if(divided){

            (*NW).query(bc,crash);
            (*NE).query(bc,crash);
            (*SW).query(bc,crash);
            (*SE).query(bc,crash);

        }

    }

}