#include <iostream>
#include "Door.h"
#include <queue>

/*
careful strategy: el personaje entra aleatoriamente a cualquier puerta y mina dejando siempre un mineral.
selfless strategy: el personaje se lleva todo el mineral de la camara sin importarle si puede haber algun 
otro personaje en la misma red.
*/

#ifndef ISTRATEGY
#define ISTRATEGY 1

class IStrategy{
        public: 
                virtual void strategyMove(List<Door> *pListaDoors, Character *pCharacter) = 0;
                virtual void strategyMine(Camara *pCamara) = 0;

};

#endif
