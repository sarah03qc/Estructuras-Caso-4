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
            int currentState;
            enum charStates{
                puertaRaiz = 0,
                tunel = 1,
                camara = 2
            };
            
    public:
            Character(string pName, int pLoadingCapacity, int pSpeed){
                this->name = pName;
                this->loadingCapacity = pLoadingCapacity;
                this->speed = pSpeed;
                this->currentMinerals = 0;
                this->currentState = puertaRaiz;

            }

            string getName(){
                return this->name;
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

            void startMoving(){

            }
            

            void mine(Camara *pCamara){
                this->currentState = camara;
                cout << "El " << name << "esta minando"<< endl;
                // codigo para sacar el mineral de la camara
                if(this->getLoadingCapacitys() - pCamara->getMinerales() >= 0) {
                //significa que segun su capacidad de carga, pueden tomar todo lo que hay en la camara
                    this->currentMinerals += pCamara->getMinerales();
                    pCamara->setMinerales(0);
                } else {
                    //se toma lo que se puede
                    this->currentMinerals += this->getLoadingCapacitys();
                    pCamara->setMinerales(pCamara->getMinerales() - this->getLoadingCapacitys());
                }
                cout << "El " << this->name << "tiene "<< currentMinerals << endl;
            }
 



            void showCurrentState(){
                cout << "El " << name << " esta en " << this->charStates[currentState] << endl; 
            }
         

};
#endif