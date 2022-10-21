#include "../Character.h"
#include "Door.h"

// metodos que todas las estrategias van a utilizar

class StrategyMethods{
    private:
        queue<Camara*> *walkedPath = new queue<Camara*>();
    public:

        queue<Camara*> *getWalkedPath(){
            return this->walkedPath;
        }

        void returnMinerals(Character *pCharacter, Door *pEnteredDoor, List<Door> *pListaDoors){
            int distance = 0;
            // se calcula la distancia para devolverse a la puerta
            while(this->walkedPath->size() > 0){
                distance += this->walkedPath->front()->getDistance();
                this->walkedPath->pop();
            }
            travel(pCharacter, distance);
            cout << "El " << pCharacter->getName() << " devolvio" << pCharacter->getCurrentMinerals() << endl;
            pEnteredDoor->setMinerals(pEnteredDoor->getMinerals() + pCharacter->getCurrentMinerals());
            pCharacter->resetCurrentMinerals();
        }

        void checkCurrentMinerals(Character *pCharacter, Door *pEnteredDoor, List<Door> *pListaDoors){
            if(pCharacter->getCurrentMinerals() == pCharacter->getLoadingCapacitys()){
                returnMinerals(pCharacter, pEnteredDoor, pListaDoors);
            }
        }

        void travel(Character *pCharacter, int distance){
            clock_t now = clock(); 
            float time = distance / pCharacter->getSpeed();     // se calcula lo que va a durar viajando
            cout << "El " << pCharacter->getName() << " esta caminando" << endl;
            while (clock() - now < time * CLOCKS_PER_SEC){
            }
            cout << "El " << pCharacter->getName() << " termino de caminar" << endl;
        }

};