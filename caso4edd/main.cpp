#include <iostream>
#include <string>
#include <sstream>
#include "Door.h"

using namespace std;


int main() {

    Door* puerta = new Door();
    cout << "Faltan: " << puerta->generarConexiones(3) << endl;
    cout << "Se generaron: " << puerta->getConectionsNum() << " conexiones a la puerta inicial" << endl;


    for(int i = 0; i < puerta->getConnectedDoors()->getSize(); i++) {
        cout << "Puerta " << i + 1 << " conectada a la inicial tiene: " << puerta->getConnectedDoors()->find(i)->getConectionsNum() << " conectadas" << endl;
        
        if(puerta->getConnectedDoors()->find(i)->getConectionsNum() != 0) {
            cout << "Entrando a revisar puerta " << i + 1 << endl;
            for(int j = 0; j < puerta->getConnectedDoors()->find(i)->getConectionsNum(); j++) {
                cout << "Puerta interna conectada tiene: " << puerta->getConnectedDoors()->find(i)->getConnectedDoors()->find(j)->getConectionsNum() << " conexiones" << endl;
            }
        }
        
    }
 

    return 0;
}