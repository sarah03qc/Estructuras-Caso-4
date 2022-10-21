#include <iostream>
#include <string>
#include "../gamemap/Camara.h"


using namespace std;
#ifndef CHARACTER
#define CHARACTER 1



class Character{
    private:
            string charStates[3] = {"puerta raiz", "tunel", "camara"};
            string name;
            int currentMinerals;
            int loadingCapacity;
            int speed;
            IStrategy *characterStrategy;
            /*
            creo que lo voy a quitar
            enum charStates{
                puertaRaiz = 0,
                tunel = 1,
                camara = 2
            };
            */
            
    public:
            Character(string pName, int pLoadingCapacity, int pSpeed){
                this->name = pName;
                this->loadingCapacity = pLoadingCapacity;
                this->speed = pSpeed;
                this->currentMinerals = 0;

            }

            string getName(){
                return this->name;
            }

            void resetCurrentMinerals(){
                this->currentMinerals = 0;
            }

            void setCurrentMinerals(int pAmount){
                this->currentMinerals = pAmount;
            }

            int getCurrentMinerals(){
                return this->currentMinerals;
            }

            int getLoadingCapacitys(){
                return this->loadingCapacity;
            }
            
            int getSpeed(){
                return this->speed;
            }

            void setCharacterStrategy(IStrategy *chosedStrategy){
                this->characterStrategy = chosedStrategy;
            }
};
#endif