#include "Strategy.h"
#include <iostream>
#include <queue>

#ifndef DOUBTFUL_STRATEGY 
#define DOUBTFUL_STRATEGY 1


/*
doubtful strategy: conocido como estrategia del personaje indeciso, todo lo piensa un ramdom por el
el personaje abre cada puerta y hasta que se encuentre un tunel y decide aleatoriammente cual entrar y 
luego decide si minarla o no, mina una cantidad aleatoria entre su capacidad y la cantidad que hay 
*/
using namespace std;

class DoubtfulStrategy : public Strategy{
    private:
        enum path{
            left = 0,
            right = 1
        };

    public:    
        bool decideMine() override {
            bool decision = rand() % 2;
            return decision;
        }

        int decideAmount(int pAmount, int* pCurrentMinerals) override {
            //cout << "DOUBFUL" << endl;
            int amount;
            int posibleMineAmount = this->characterCapacity - *pCurrentMinerals;
            if(posibleMineAmount >= pAmount){
                amount = 0 + rand() % ((pAmount + 1) - 0);
            }
            else{
                amount = 0 + rand() % ((posibleMineAmount + 1) - 0);
            }
            return amount;
        }



};

#endif