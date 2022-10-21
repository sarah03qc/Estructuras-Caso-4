#include "IStrategy.h"
#include "Mina.h"
#include "../Character.h"
#include <iostream>
#include <queue>

/*
doubtful strategy: conocido como estrategia del personaje indeciso, todo lo piensa un ramdom por el
el personaje abre cada puerta y hasta que se encuentre un tunel y decide aleatoriammente cual entrar y 
luego decide si minarla o no, mina una cantidad aleatoria entre su capacidad y la cantidad que hay 
*/
using namespace std;

class DoubtfulStrategy : public IStrategy{
    private:
        enum path{
            left = 0,
            right = 1
        };

    public:
        DoubtfulStrategy(){

        }
        
        void strategyMove(List<Door> *pListaDoors, Character *pCharacter){
            moveLoop:
            for (int currentDoor = 0; currentDoor < pListaDoors->getSize(); ++currentDoor){
                if (pListaDoors->find(currentDoor)->hasMine()){
                    cout << pCharacter->getName() << " entró a una puerta" << endl;
                    Door *enteredDoor = pListaDoors->find(currentDoor);
                    Mina *characterInMine = enteredDoor->getMine();
                    
                    cout << pCharacter->getName() << " entró a un túnel" << endl;
                    AVLTree<Camara> *bifurcaciones = characterInMine->getEstaMina();
                    // camara raiz
                    Node<Camara> *camaraRaiz = bifurcaciones->getRoot();
                    Node<Camara> *currentCamara;
                    for (int bifurcacion = 0; bifurcaciones->getSize(); ++bifurcacion){
                        // antes de decidir si caminar revisa que no sobrepase su capacidad de carga
                        checkCurrentMinerals(pCharacter, enteredDoor, pListaDoors);
                        currentCamara = decidePath(camaraRaiz);    // el personaje decide
                        /*
                        if(currentCamara == NULL){
                            cout << "El " << pCharacter->getName() << " se quedo quieto en la camara"<< endl;
                        }
                        */
                        walkedPath->push(currentCamara->getContent());
                        travel(pCharacter, currentCamara->getContent()->getDistance());
                        // el personaje decide si minar o no la camara
                        if(decideMine() == true){
                            strategyMine(currentCamara->getContent(), pCharacter);
                            // despues de minar el personaje revisa que no sobrepase su capacidad de carga
                            checkCurrentMinerals(pCharacter, enteredDoor, pListaDoors);
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
            
        void returnMinerals(Character *pCharacter, Door *pEnteredDoor, List<Door> *pListaDoors){
            int distance = 0;
            // se calcula la distancia para devolverse a la puerta
            while(walkedPath->size() > 0){
                distance += walkedPath->front()->getDistance();
                walkedPath->pop();
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

        void strategyMine(Camara *pCamara, Character *pCharacter){
            cout << "El " << pCharacter->getName() << " esta decidiendo cuanto minar" << endl;
            // el personaje decide cuanto minar
            int amount = decideAmount(pCharacter, pCamara->getMinerales());
            cout << "El " << pCharacter->getName() << " esta minando la camara" << endl;
            pCamara->setMinerales(pCamara->getMinerales() - amount);
            pCharacter->setCurrentMinerals(pCharacter->getCurrentMinerals() + amount);
        }

        bool decideMine(){
            bool decision = rand() % 2;
            return decision;
        }

        Node<Camara> *decidePath(Node<Camara> *pCamaraRaiz){
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

        int decideAmount(Character *pCharacter, int pAmount){
            int amount;
            int posibleMineAmount = pCharacter->getLoadingCapacitys() - pCharacter->getCurrentMinerals();
            if(posibleMineAmount >= pAmount){
                amount = 0 + rand() % ((pAmount + 1) - 0);
            }
            else{
                amount = 0 + rand() % ((posibleMineAmount + 1) - 0);
            }
            return amount;

        }



};