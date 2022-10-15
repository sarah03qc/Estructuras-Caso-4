#include <iostream>
#include <string>


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
            int strategyId;
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

            void setCharacterStrategy(){

            }
            void moveBack(){

            }
            void moveFoward(){
                /*
                Calcula la distancia que hay 
                */

            }

            void mine(){
                this->currentState = camara;
                cout << "El " << name << "esta minando"<< endl;
                // codigo para sacar el mineral de la camara
                cout << "El " << name << "tiene "<< currentMinerals << endl;
                //currentMinerals ++
            }

            void returnMineral(){

            }

            void showCurrentState(){
                cout << "El " << name << " esta en " << this->charStates[currentState] << endl; 
            }
         

};
#endif