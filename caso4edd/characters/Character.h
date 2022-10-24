#ifndef CHARACTER
#define CHARACTER 1

#include <iostream>
#include <string>
#include "../gamemap/Camara.h"
#include "../gamemap/List.h"
#include "../gamemap/Door.h"
#include "../patron/Observer.h"
#include "Strategy/Strategy.h"

using namespace std;


class Character : public Observer{
    private:
            string charStates[7] = {" en puerta raiz", "en puerta", "en tunel", "en camara", "decidiendo", "minando", "caminando"};
            string name;
            int currentMinerals;
            int loadingCapacity;
            int speed;
            int currentState;
            Strategy *characterStrategy = new Strategy();
            enum charStates{
                enpuertaRaiz = 0,
                puerta = 1,
                tunel = 2,
                camara = 3,
                decidiendo = 4,
                minando = 5,
                caminando = 6
            }; 

  
            
    public:
            Character(string pName, int pLoadingCapacity, int pSpeed){
                this->name = pName;
                this->loadingCapacity = pLoadingCapacity;
                this->speed = pSpeed;
                this->currentMinerals = 0;
            }

            void play(List<Door> *pListaDoors){
                cout << "El " << name << " empezo a moverse" << endl;
                this->characterStrategy->move(pListaDoors, this->name, &currentMinerals);
            }

            void showCurrentState(){
                cout << "El " << this->name << " esta " << charStates[this->currentState] << endl;
                
            }

            void updateState(int pState) override{
                this->currentState = pState;
                showCurrentState();
            }

            void leave(queue<Camara*> *pWalkedPath, Door *pEnteredDoor, List<Door> *pListaDoors){
                returnMinerals(pWalkedPath, pEnteredDoor, pListaDoors);
            
            };

            void travel(int distance) override{
                clock_t now = clock(); 
                float time = distance / this->speed;     // se calcula lo que va a durar viajando
                updateState(caminando);
                while (clock() - now < time * CLOCKS_PER_SEC){
                }
            }

            void returnMinerals(queue<Camara*> *pWalkedPath, Door *pEnteredDoor, List<Door> *pListaDoors){
                int distance = 0;
                // se calcula la distancia para devolverse a la puerta
                while(pWalkedPath->size() > 0){
                    distance += pWalkedPath->front()->getDistance();
                    pWalkedPath->pop();
                }
                travel(distance);
                updateState(enpuertaRaiz);
                cout << "El " << this->name << " devolvio " << this->currentMinerals << endl;
                pEnteredDoor->setMinerals(pEnteredDoor->getMinerals() + this->currentMinerals);
                this->resetCurrentMinerals();
                play(pListaDoors);
            }

            void checkCurrentMinerals(queue<Camara*> *pWalkedPath , Door *pEnteredDoor, List<Door> *pListaDoors) override{
                if(this->getCurrentMinerals() == this->getLoadingCapacitys()){
                    returnMinerals(pWalkedPath, pEnteredDoor, pListaDoors);
                }
            }

            string getName(){
                return this->name;
            }

            void resetCurrentMinerals(){
                this->currentMinerals = 0;
            }

            void setCurrentMinerals(int pAmount) override{
                cout << "El " << this->name << " mino " << pAmount << " minerales" << endl;
                this->currentMinerals += pAmount;
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

            void setCharacterStrategy(Strategy *chosedStrategy){
                this->characterStrategy = chosedStrategy;
                characterStrategy->setCharacterCapacity(this->loadingCapacity);
            }
};
#endif