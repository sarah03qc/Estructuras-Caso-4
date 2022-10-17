#include <iostream>
#include <string>
#include "../../avltree/AVLTree.h"
#include "Camara.h"

using namespace std;

#ifndef MINA

#define MINA 1

class Mina {
    private: 
        AVLTree<Camara> *estaMina = new AVLTree<Camara>();
        int alturaTotal = 0;
        int cantidadCamaras = 0;

    public:
        Mina() {
            cantidadCamaras = rand() % (72 - 9) + 9;
            Node<Camara>* nodo1 = NULL;
            for(int i = 0; i < cantidadCamaras; i++) {
                Camara *chamber = new Camara();
                chamber->generateMinerales();
                chamber->generateDistance();
                //nodo1 = estaMina->add(nodo1,chamber->calcularPotencial());    //hay que hacer algo en nodo y arbol para guardar data pero basarse en algo 
                //                                                              especifico (potencial minado) para ordenarlos, porque el arbol actual ordena segun la data
            }
        }

     
};

#endif