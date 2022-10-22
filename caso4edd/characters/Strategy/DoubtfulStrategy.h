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

        Node<Camara>* decidePath(Node<Camara>* pCamaraRaiz) override {
            Node<Camara> *currentCamara;
            int chosenPath = 1 + rand() % (3 - 1);
            if (chosenPath == left){
                currentCamara = pCamaraRaiz->getLeft();
                }
            else{
                currentCamara = pCamaraRaiz->getRight();
            }
            return currentCamara;
        }

        int decideAmount(int pCapacity, int* pCurrentMinerals) override {
            int amount;
            int posibleMineAmount = this->characterCapacity - *pCurrentMinerals;
            if(posibleMineAmount >= pCapacity){
                amount = 0 + rand() % ((pCapacity + 1) - 0);
            }
            else{
                amount = 0 + rand() % ((posibleMineAmount + 1) - 0);
            }
            return amount;
        }



};

#endif