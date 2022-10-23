#include "../gamemap/Door.h"

// character mira a strategy
#ifndef OBSERVER
#define OBSERVER 1 

class Observer{
    public: 
        virtual void updateState(int pState) = 0;
        virtual void checkCurrentMinerals(queue<Camara*> *pWalkedPath, Door *pEnteredDoor, List<Door> *pListaDoors) = 0;
        virtual void setCurrentMinerals(int pAmount) = 0;
        virtual void travel(int distance) = 0;
};
#endif