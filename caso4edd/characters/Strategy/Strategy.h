
// metodos que todas las estrategias van a utilizar

#ifndef STRATEGY
#define STRATEGY 1

#include <iostream>
#include <queue>
#include "../../gamemap/List.h"
#include "../../gamemap/Door.h"
#include "../../gamemap/Camara.h"
#include "../../../avltree/Node.h"
#include "../../patron/Observable.h"

using namespace std;

class Strategy : Observable{
    protected:
        int characterCapacity;
        queue<Camara*> *walkedPath = new queue<Camara*>();
        vector<Observer *> observers;
        int* minerals;
        int state;
        Door *enteredDoor;
        List<Door> *listaDoors;
        enum strategyPetitions{
            statePetition = 0,
            checkPetition = 1,
            setPetition = 2,
            travelPetition = 3
        };

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

        void setCharacterCapacity(int pCharacterCapacity){
            this->characterCapacity = pCharacterCapacity;

        }


        queue<Camara*> *getWalkedPath(){
            return this->walkedPath;
        }
        void registerObserver(Observer *observer) override{
            observers.push_back(observer);

        };
        void removeObserver(Observer *observer) override{
            auto iterator = std::find(observers.begin(), observers.end(), observer);
            if (iterator != observers.end()) { // observer found
                observers.erase(iterator); // remove the observer
        }

        };
        void notifyObservers(int petition, int amount = 0) override{
            for (Observer *observer : observers) { // notify all observers
                if(petition == statePetition){
                    observer->updateState(state);
                }
                else if (petition == setPetition){
                    observer->setCurrentMinerals(amount);
                }
                else if(petition == travelPetition){
                    observer->travel(amount);
                }

                else{
                    observer->checkCurrentMinerals(walkedPath, enteredDoor, listaDoors);
                }
            }

        };
        
        void move(List<Door> *pListaDoors, string name, int* minerals) {
            cout << "ENTRO A MOVE" << endl;
            cout << pListaDoors->getSize() << endl;
            for (int currentDoor = 0; currentDoor < pListaDoors->getSize(); ++currentDoor){
                if (pListaDoors->find(currentDoor)->hasMine()){
                    cout << name << " entró a una puerta" << endl;
                    enteredDoor = pListaDoors->find(currentDoor);
                    Mina *characterInMine = enteredDoor->getMine();
                    cout << name << " entró a un túnel" << endl;
                    AVLTree<Camara> *bifurcaciones = characterInMine->getEstaMina();
                    // camara raiz
                    Node<Camara> *camaraRaiz = bifurcaciones->getRoot();
                    Node<Camara> *currentCamara;
                    for (int bifurcacion = 0; bifurcaciones->getSize(); ++bifurcacion){
                        // antes de decidir si caminar revisa que no sobrepase su capacidad de carga
                        notifyObservers(checkPetition);
                        currentCamara = decidePath(camaraRaiz);    // el personaje decide
                        /*
                        if(currentCamara == NULL){
                            cout << "El " << pCharacter->getName() << " se quedo quieto en la camara"<< endl;
                        }
                        */
                        getWalkedPath()->push(currentCamara->getContent());
                        notifyObservers(travelPetition, currentCamara->getContent()->getDistance());
                        // el personaje decide si minar o no la camara
                        if(decideMine() == true){
                            mine(currentCamara->getContent(), minerals);
                            // despues de minar el personaje revisa que no sobrepase su capacidad de carga
                            notifyObservers(checkPetition);
                            //verificar que la camara tenga cero
                            if(currentCamara->getContent()->getMinerales() == 0){
                                // se busca el nodo en el arbol
                                Node<Camara> *camaraToDelete = bifurcaciones->find(camaraRaiz, currentCamara->getData());
                                bifurcaciones->destroy(camaraToDelete);
                            }
                        }
                    }
                }
            }                    
        }

        virtual Node<Camara>* decidePath(Node<Camara>* pCamaraRaiz){
            Node<Camara> *currentCamara;
            return currentCamara;
        }

        virtual bool decideMine(){
            bool decision;
            return decision;
        }

        void mine(Camara *pCamara, int* minerals) {
            this->state = decidiendo;
            notifyObservers(statePetition);
            int amount = decideAmount(pCamara->getMinerales(), minerals);
            this->state = minando;
            notifyObservers(statePetition);
            pCamara->setMinerales(pCamara->getMinerales() - amount);
            notifyObservers(setPetition, amount);
        }

        virtual int decideAmount(int pCapacity, int* pCurrentMinerals){
            int amount;
            return amount;
        }

/*
        void returnMinerals(queue<Camara*> *pWalkedPath, Door *pEnteredDoor, List<Door> *pListaDoors){
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
*/
};
#endif