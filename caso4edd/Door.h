#include <iostream>
#include <string>

using namespace std;

#ifndef DOOR

#define DOOR 1


class Door {
    private: 
        int numDoorsConect;


    public:
        Door() {
            
        }

        int generarConexiones(int nCreando) {
            srand((unsigned) time(NULL)); 
            numDoorsConect = rand() % (5 - 2) + 2;
            cout << numDoorsConect << endl;

            //creo otras puertas while usando el numero generado
            //y las pongo en un vector de puertas que se conectan a esta (global)
            //hacer un get para el vector
            //esas puertas nuevas que se generan hay que restarle al nCreando la cantidad creada y dependiendo del resul, hay casos distintos
            //pero eso se ve later, maybe nCreando se puede dividir en la cantidad de puertas que se generan en la inicial
            
            //luego el numero que se retorna es la cantidad de puertas que se crearon para restarselo al nCreando afuera

            return 0;
        }


};

#endif