//aca se va a juntar todo y generarse automaticamente el mapa de juego cuando se instancie esta clase
//luego en otra clase, se va a medir el tiempo de player 1 en su propia instancia de 
//game map, y al acabar ira automaticamente a correr el tiempo de player 2 con su propia instancia
//generada del game map

#include "Door.h"

using namespace std;

#ifndef GAMEMAP

#define GAMEMAP 1

class GameMap {
    private:
        Door* puerta;

    public:
        GameMap(int nDoors) {
            puerta = new Door(); 
            puerta->generarConexiones(nDoors);  //con crear esto todo se debe generar
        }    

        Door* getPuerta(){
            return this->puerta;
        }


};
#endif