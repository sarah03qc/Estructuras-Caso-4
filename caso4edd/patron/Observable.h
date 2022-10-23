#include "Observer.h"

#ifndef OBSERVABLE
#define OBSERVABLE 1 



class Observable{
    public:
        virtual void registerObserver(Observer *observer) = 0;
        virtual void removeObserver(Observer *observer) = 0;
        virtual void notifyObservers(int petition, int amount = 0) = 0;
};
#endif