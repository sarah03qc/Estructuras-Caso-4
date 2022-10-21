#include "IStrategy.h"
#include "../Character.h"
#include "StrategyMethods.h"


using namespace std;

class SelflessStrategy : public IStrategy, public StrategyMethods{
    public: 

        void strategyMove(List<Door> *pListaDoors, Character *pCharacter){

        }

        void strategyMine(Camara *pCamara){

        }

};