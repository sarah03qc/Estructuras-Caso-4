#include <iostream>
#include "Door.h"

/*
doubtful strategy: el personaje abre cada puerta y hasta que se encuentre un tunel y mina una cantidad aleatoria 
entre su capacidad y la cantidad que hay 

egocentric strategy: el personaje decide rapidamente de forma aleatoria a cual puerta entrar y no puede devolverse.
careful strategy: el personaje entra aleatoriamente a cualquier puerta y mina dejando siempre un mineral.
selfless strategy: el personaje se lleva todo el mineral de la camara sin importarle si puede haber algun 
otro personaje en la misma red.
*/

#ifndef ISTRATEGY
#define ISTRATEGY 1

class IStrategy{
        public: 
                virtual void strategyMove(List<Door> *pListaDoors) = 0;
                virtual void strategyMine()= 0;
                virtual void returnMinerals()= 0;
                virtual void setId()= 0;
        protected:
                int id;
};

#endif
