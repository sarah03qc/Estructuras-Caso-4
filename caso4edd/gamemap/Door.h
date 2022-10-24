#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "Mina.h"

using namespace std;

#ifndef DOOR

#define DOOR 1

class Door {
    private: 
        int numDoorsConect = 0;  //a cuantas puertas se conecta this
        List<Door> *listadoors;  //lista de las conexiones que tiene
        bool tieneMina = false;  
        int minePosibilities = 0;
        int random;
        Mina *mine = NULL;
        int amountMinerals = 0;


    public:
        Door() {
            listadoors = new List<Door>();
            this->generarMinaPosibilidad();
        }

        void generarMinaPosibilidad() {
            //al crearse, se debe medir el 66% de si cuenta con una mina o no
            minePosibilities = rand() % (100 - 0) + 0;
            if(minePosibilities <= 66) {
                tieneMina = true;
            }
            if(tieneMina == true) {
                mine = new Mina();   //si se genero que tiene mina se crea, sino es NULL
            }
        }

        int generarConexiones(int nCreando) {
            //recursiva que genera nCreando cantidad de puertas conectadas a la inicial
            if(nCreando == 0) {
                return 0;
            }
            numDoorsConect = rand() % (5 - 2) + 2;

            while(nCreando - numDoorsConect < 0) {
                numDoorsConect = rand() % (5 - 2) + 2;
                if(nCreando == 1) {
                    for(int i = 0; i < listadoors->getSize(); i++) {
                        if(listadoors->find(i)->getConectionsNum() > 1 && listadoors->find(i)->getConectionsNum() < 4) {
                            //porque si la que falta es una, no se puede agregar a una puerta sin conexiones
                            //ya que el minimo es dos, y tampoco agregarse a una de 4 conexiones, porque ese es el max
                            cout << "Puerta creada" << endl;
                            Door *newDoor = new Door();
                            cout << "Tiene mina: " << newDoor->hasMine() << endl;
                            listadoors->find(i)->addDoorToDoor(newDoor);
                        }
                    }
                }
            }
            nCreando = nCreando - numDoorsConect;
     
            for(int i = 0; i < numDoorsConect; i++) {
                Door *puerta = new Door();
                listadoors->add(puerta);
            }

            int i = 0;
            while(i < nCreando) {
                //mientras estamos en el rango de las puertas que falta de crear
                //generamos numero aleatorio (hara de index) para ir creando en las puertas afiliadas a esta 
                int index = rand() % (listadoors->getSize() - 0) + 0;
                nCreando = listadoors->find(index)->generarConexiones(nCreando);
            }
            return nCreando;
        }

        void addDoorToDoor(Door *theDoor) {
            this->listadoors->add(theDoor);
        }

        List<Door>* getConnectedDoors() {
            return listadoors;
        }

        int getConectionsNum() {
            return numDoorsConect;
        }

        bool hasMine() {
            return tieneMina; //para ver si tiene on no 
        }

        Mina* getMine(){
            return mine;   //si tiene retorna una mina ya con todo (porque se genera en el constructor de mina), y si no tiene retorna NULL
        }
        
        void setMinerals(int pAmount){
            this->amountMinerals = pAmount;
        }

        int getMinerals(){
            return this->amountMinerals;
        }
};

#endif