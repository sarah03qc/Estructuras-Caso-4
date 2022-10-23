#include "Strategy.h"
#include "../Character.h"



/*
Siempre decide minar y mina todo siempre que pueda sin impotarle si hay alguien mas 
*/
using namespace std;

#ifndef SELFLESS_STRATEGY
#define SELFLESS_STRATEGY 1
class SelflessStrategy : public Strategy{
    public: 

        bool decideMine() override {
            bool decision = true;
            return decision;
        }
        
        int decideAmount(int pCapacity, int* pCurrentMinerals) override {
            int amount;
            int posibleMineAmount = this->characterCapacity - *pCurrentMinerals;
            if(posibleMineAmount >= pCapacity){
                amount = posibleMineAmount;
            }
            else{
                amount = 0 + rand() % ((posibleMineAmount + 1) - 0);
            }
            return amount;
        }



};
#endif