#include "IStrategy.h"

/*
doubtful strategy: el personaje abre cada puerta y hasta que se encuentre un tunel y mina una cantidad aleatoria 
entre su capacidad y la cantidad que hay 
*/
using namespace std;

class DoubtfulStrategy : public IStrategy{
    public: 

        void strategyMove(List<Door> *pListaDoors){
            /*
            entra por la puerta raiz
            revisa las puertas hasta que alguna tenga tunel
            entra 
            ramdon del numero a minar
            si la cantidad de minerales que hay es es menor a la capacidad, ramdom entre 0 a la cantidad
            si la cantidad es mayor a la cpacidad, random entre 0 a la capacidad

            hay que estar constantemente revisando de que el personaje devuelva los minerales apenas este al limite
            */
            for (int currentDoor = 0; currentDoor < pListaDoors->getSize(); ++currentDoor){
                if (pListaDoors->find(currentDoor)->hasMine()){
                    Door *enteredDoor = pListaDoors->find(currentDoor);
                    


                }


            }




        }
        void strategyMine(){

        }
        void returnMinerals(){

        }
        void setId(){

        }

};