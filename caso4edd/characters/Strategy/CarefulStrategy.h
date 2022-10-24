#include "Strategy.h"
#include "../Character.h"

using namespace std;

/*
siempre mina dejando un mineral
*/

class CarefulStrategy : public Strategy{
    public: 
        bool decideMine() override {
            // siempre decide minar
            bool decision = true;
            return decision;
        }
        
        int decideAmount(int pAmount, int* pCurrentMinerals) override {
            int amount;
            int posibleMineAmount = this->characterCapacity - *pCurrentMinerals;
            if(posibleMineAmount >= pAmount){
                // se lleva los minerales dejando solo uno
                amount = pAmount - 1;
            }
            else{
                // si es menor la cantidad que puede llevar que la que hay, solo se lleva lo que puede
                amount = posibleMineAmount;
            }
            return amount;
        }



};