#include "IStrategy.h"
#include "Mina.h"
#include "Character.h"

/*
doubtful strategy: el personaje abre cada puerta y hasta que se encuentre un tunel y decide aleatoriammente cual entrar y mina una cantidad aleatoria 
entre su capacidad y la cantidad que hay 
*/
using namespace std;

class DoubtfulStrategy : public IStrategy{
    private:
        enum path{
            left = 0,
            right = 1
        };
    public:
        void strategyMove(List<Door> *pListaDoors, Character *pCharacter){
            /*
            entra por la puerta raiz
            revisa las puertas hasta que alguna tenga tunel
            entra 
            hay que estar constantemente revisando de que el personaje devuelva los minerales apenas este al limite
            */
            for (int currentDoor = 0; currentDoor < pListaDoors->getSize(); ++currentDoor){
                if (pListaDoors->find(currentDoor)->hasMine()){
                    cout << pCharacter->getName() << " entró a una puerta" << endl;
                    Door *enteredDoor = pListaDoors->find(currentDoor);
                    Mina *characterInMine = enteredDoor->getMine();
                    
                    cout << pCharacter->getName() << " entró a un túnel" << endl;
                    AVLTree<Camara> *bifurcaciones = characterInMine->getEstaMina();
                    Node<Camara> *camaraRaiz = bifurcaciones->getRoot();
                    Node<Camara> *currentCamara;
                    for (int bifurcacion = 0; bifurcaciones->getSize(); ++bifurcacion){
                        int decision = decidePath();    // el personaje decide
                        if (decision == left){
                            currentCamara = camaraRaiz->getLeft();  
                            travel(pCharacter, currentCamara->getContent()->getDistance());
                        }

                    }
                    /*
                    pensar en como meter el personaje en el arbol
                    */
                    //bifurcaciones->
                    //for(int camara = 0; )
                    int decision = 1 + rand() % (3 - 1);
                    
                    
                    /*
                    characterInMine-> hacer que se

                    */
                    
                }
            }
        }

        void travel(Character *pCharacter, int distance){
            clock_t now = clock(); 
            int characterSpeed = pCharacter->getSpeed();
            //while(clock() - now < )


        }

        void strategyMine(Camara *pCamara){

        }

        bool decideMine(){
            bool decision = rand() % 2;
            return decision;
        }

        int decidePath(){
            int chosenPath = 1 + rand() % (3 - 1);
            return chosenPath;
        }

        int decideAmount(Character *pCharacter, int pAmount){
            int amount;
            if(pCharacter->getLoadingCapacitys() >= pAmount){
                amount = 0 + rand() % ((pAmount + 1) - 0);
            }
            else{
                int charcapacity = pCharacter->getLoadingCapacitys();
                amount = 0 + rand() % ((charcapacity + 1) - 0);
            }
            return amount;

        }


};