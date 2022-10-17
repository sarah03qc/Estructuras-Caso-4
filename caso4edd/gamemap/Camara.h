#include <iostream>
#include <string>
#include "../characters/Character.h"

using namespace std;

#ifndef CAMARA

#define CAMARA 1

class Camara {
    private: 
        int minerales = 0;
        int distanceUpperChamber = 0;
        int potencialMinado = 0;

    public:
        Camara() {

        }

        void generateMinerales() {
            minerales = rand() % (20 - 1) + 1;
            cout << "Los minerales generados son: " << minerales << endl;
        }
        
        void generateDistance() {
            distanceUpperChamber = rand() % (80 - 10) + 10;
            cout << "La distancia generada desde la camara superior es: " << distanceUpperChamber << endl;
        }

        int calcularPotencial() {
            potencialMinado = minerales * distanceUpperChamber;
            cout << "El potencial de minado es: " << potencialMinado << endl; 
            return potencialMinado;
        }

        int takeMinerales(Character personaje) {
            int bolso;
            if(personaje.getLoadingCapacitys() - minerales >= 0) {
                //significa que segun su capacidad de carga, pueden tomar todo lo que hay en la camara
                bolso = minerales;
                personaje.mine();
                //hay que ponerle algo al personaje para cambiar los minerales que tiene y pasarselos desde aca
                minerales = 0;
                return bolso;
            } else {
                //se toma lo que se puede
                bolso = personaje.getLoadingCapacitys();
                personaje.mine();
                minerales = minerales - personaje.getLoadingCapacitys();
                return bolso;
            }
            
        }

};

#endif