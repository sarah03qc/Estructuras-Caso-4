#include <iostream>
#include <string>
#include "../../avltree/AVLTree.h"
#include "../../avltree/Node.h"
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
            cantidadCamaras = rand() % (30 - 3) + 3;  //un rango del numero de camaras, pero se puede cambiar
            Node<Camara> *nodo = NULL;
            cout << "Cantidad generada de camaras es: " << cantidadCamaras << endl;
            for(int i = 0; i < cantidadCamaras; i++) {
                //se va creando la cantidad generada por el random
                Camara *chamber = new Camara();
                int potencia = chamber->calcularPotencial();  //dentro de esta tambien se generan minerales y distancia
                alturaTotal = alturaTotal + chamber->getDistance();
                if(alturaTotal >= 720) {
                    cout << "Se para porque se pasa del limite" << endl;
                    alturaTotal = alturaTotal - chamber->getDistance(); 
                    break;
                }
                nodo = estaMina->add(nodo, new int(potencia));   //se agrega nodo a la mina con el potencial
                cout << "agregando nodo al arbol" << endl;
                Node<Camara> *found = estaMina->find(nodo, new int(potencia));     //se busca para asignarle "contenido", que es la camara
                found->setContent(chamber);
                cout << "minerals " << found->getContent()->getMinerales() << endl;
                cout << "Camara set " << i << endl;
            }
            //estaMina->getRoot()->getContent()->setMinerales(0);
            //nodo->getContent()->setMinerales(0); //ponemos los minerales de la root en cero, porque no debe tener
        }
        AVLTree<Camara> *getEstaMina(){
            return this->estaMina;
        } 
};
#endif