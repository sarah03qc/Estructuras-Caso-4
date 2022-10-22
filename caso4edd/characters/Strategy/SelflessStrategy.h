#include "Strategy.h"
#include "../Character.h"


using namespace std;

#ifndef SELFLESS_STRATEGY
#define SELFLESS_STRATEGY 1
class SelflessStrategy : public Strategy{
    public: 

        void strategyMove(List<Door> *pListaDoors, Character *pCharacter){

        }

        void strategyMine(Camara *pCamara, Character *pCharacter){

        }

};
#endif