#include <iostream>
#include <string>
#include <sstream>
#include "Door.h"
#include "Mina.h"
#include "Camara.h"

using namespace std;


int main() {

    srand((unsigned) time(NULL));
    Mina *mine = new Mina();
    
    
    /*  //prueba de generar puertas y sus conexiones, funciona
    Door* puerta = new Door();
    
    cout << "Faltan: " << puerta->generarConexiones(10) << endl;
    cout << "Puerta principal tiene mina: " << puerta->hasMine() << endl;
    cout << "Se generaron: " << puerta->getConectionsNum() << " conexiones a la puerta inicial" << endl;


    for(int i = 0; i < puerta->getConnectedDoors()->getSize(); i++) {
        cout << "Puerta " << i + 1 << " conectada a la inicial tiene: " << puerta->getConnectedDoors()->find(i)->getConectionsNum() << " conectadas" << endl;
        cout << "Tiene mina: " << puerta->getConnectedDoors()->find(i)->hasMine() << endl;
        
        if(puerta->getConnectedDoors()->find(i)->getConectionsNum() != 0) {
            cout << "Entrando a revisar puerta " << i + 1 << endl;
            
            for(int j = 0; j < puerta->getConnectedDoors()->find(i)->getConectionsNum(); j++) {
                cout << "Puerta interna conectada tiene: " << puerta->getConnectedDoors()->find(i)->getConnectedDoors()->find(j)->getConectionsNum() << " conexiones" << endl;
                cout << "Tiene mina: " << puerta->getConnectedDoors()->find(i)->getConnectedDoors()->find(j)->hasMine() << endl;
                if(puerta->getConnectedDoors()->find(i)->getConnectedDoors()->find(j)->getConectionsNum() != 0) {
                    cout << "Entrando a revisar puerta " << j + 1 << endl;
                    for(int p = 0; p < puerta->getConnectedDoors()->find(i)->getConnectedDoors()->find(j)->getConectionsNum(); p ++) {
                        cout << "Puerta sub-interna conectada tiene: " << puerta->getConnectedDoors()->find(i)->getConnectedDoors()->find(j)->getConnectedDoors()->find(p)->getConectionsNum() << " conexiones" << endl;
                        cout << "Tiene mina: " << puerta->getConnectedDoors()->find(i)->getConnectedDoors()->find(j)->getConnectedDoors()->find(p)->hasMine() << endl;
                    }
                }
            }
        }
    }
    */

    return 0;
}