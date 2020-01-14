#ifndef QUADTREE_H
#define QUADTREE_H

#include "Square.h"
#include <ctime>
#include <algorithm>

class Quadtree{

    list<Bees*>lBees;
    list<Bees*>::iterator it;
    list<Bees*>* col;
    list<Bees*>::iterator icrash;
    Square* sq;
    bool divided;
    long capacity;
    const bool hypo;
    int init = 0;

    Quadtree* NW;
    Quadtree* NE;
    Quadtree* SW;    
    Quadtree* SE;

    public:

    Quadtree(Square* _sq, list<Bees*>& collision);
    bool insert(Bees* b);
    void subdivide();
    void query(Bees* bc, list<Bees*>& crash);

};

#endif