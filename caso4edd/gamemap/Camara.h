#include <iostream>
#include <string>

using namespace std;

#ifndef CAMARA

#define CAMARA 1

class Camara {
    private: 
        int minerales = 0;
        int distanceUpperChamber = 0;
        int potencialMinado = 0;

        void generateMinerales() {
            minerales = rand() % (20 - 1) + 1;
            cout << "Los minerales generados son: " << minerales << endl;
        }
        
        void generateDistance() {
            distanceUpperChamber = rand() % (80 - 10) + 10;
            cout << "La distancia generada desde la camara superior es: " << distanceUpperChamber << endl;
        }

    public:

        int calcularPotencial() {
            this->generateMinerales();
            this->generateDistance();
            potencialMinado = minerales * distanceUpperChamber;
            cout << "El potencial de minado es: " << potencialMinado << endl; 
            return potencialMinado;
        }

        int getMinerales() {
            return this->minerales;
        }

        int getDistance() {
            return this->distanceUpperChamber;
        }

        void setMinerales(int pCantidad) {
            cout << "cantidad de minerales recibida " << pCantidad << endl;
            this->minerales = pCantidad;
        }
};
#endif