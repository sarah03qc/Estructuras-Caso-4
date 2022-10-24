
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
        enum path{
            left = 0,
            right = 1
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
            for (int currentDoor = 0; currentDoor < pListaDoors->getSize(); ++currentDoor){
                int door = 1 + rand() % (5 - 1);
                cout << "El " << name << " entro a una puerta" << endl;
                if (pListaDoors->find(door)->hasMine()){
                    cout << "El " << name << " se mantuvo en la misma puerta" << endl;
                    enteredDoor = pListaDoors->find(currentDoor);
                    Mina *characterInMine = enteredDoor->getMine();
                    cout << "El " << name << " entro a un tunel" << endl;
                    AVLTree<Camara> *bifurcaciones = characterInMine->getEstaMina();
                    // camara raiz
                    Node<Camara> *camaraRaiz = bifurcaciones->getRoot();
                    Node<Camara> *currentCamara;
                    for (int bifurcacion = 0; bifurcaciones->getSize(); ++bifurcacion){
                        // antes de decidir si caminar revisa que no sobrepase su capacidad de carga
                        notifyObservers(checkPetition);
                        currentCamara = decidePath(camaraRaiz);    // el personaje decide
                        getWalkedPath()->push(currentCamara->getContent());
                        notifyObservers(travelPetition, currentCamara->getContent()->getDistance());
                        // el personaje decide si minar o no la camara
                        if(decideMine() == true){

                            mine(currentCamara->getContent(), minerals);
                            // despues de minar el personaje revisa que no sobrepase su capacidad de carga
                            notifyObservers(checkPetition);
                            //verificar que la camara tenga cero
                            if(currentCamara->getContent()->getMinerales() == 0){
                                leave(walkedPath, enteredDoor, pListaDoors);
                                // se busca el nodo en el arbol
                                Node<Camara> *camaraToDelete = bifurcaciones->find(camaraRaiz, currentCamara->getData());
                                bifurcaciones->destroy(camaraToDelete);
                            }
                        }
                    }
                }
            }                    
        }

        virtual void leave(queue<Camara*> *pWalkedPath, Door *pEnteredDoor, List<Door> *pListaDoors){
            bool leave;
        };

        // el personaje no le interesa mucho el decidir el camino
        Node<Camara>* decidePath(Node<Camara>* pCamaraRaiz){
            Node<Camara> *currentCamara;
            int chosenPath = 1 + rand() % (3 - 1);
            if (chosenPath == left){
                if(pCamaraRaiz->getLeft() != NULL){
                    currentCamara = pCamaraRaiz->getLeft();
                }else{
                    currentCamara = pCamaraRaiz->getRight();
                }
            }
            else{
                if(pCamaraRaiz->getRight() != NULL){
                    currentCamara = pCamaraRaiz->getRight();
                }else{
                    currentCamara = pCamaraRaiz->getLeft();
                }
            }
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

        virtual int decideAmount(int pAmount, int* pCurrentMinerals) {
            int amount;
            return amount;
        }

};
#endif