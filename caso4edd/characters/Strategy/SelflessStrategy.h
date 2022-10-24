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
            // siempre decide minar
            bool decision = true;
            return decision;
        }
        
        int decideAmount(int pAmount, int* pCurrentMinerals) override {
            //cout << "DECIDE AMOUNT" << endl;
            int amount;
            int posibleMineAmount = this->characterCapacity - *pCurrentMinerals;
            //cout << "PERSONAJE CAPACITY: " << this->characterCapacity << endl;
            //cout << "CURRENT MINERALS: " << *pCurrentMinerals << endl;
            //cout << "POSIBLE AMOUNT: " << posibleMineAmount << endl;
            if(posibleMineAmount >= pAmount){
                // aun que pueda llevar mas no hay suficiente mineral
                // entonces lleva todo el mineral que hay
                amount = pAmount;
            }
            else{
                // su capacidad no le deja llevarse todo, entonces se lleva lo que puede
                amount = posibleMineAmount;
            }
            return amount;
        }

};
#endif