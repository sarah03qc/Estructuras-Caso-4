
#include <iostream>
#include <string>
#include <sstream>
#include "AVLTree.h"
#include "Node.h"

using namespace std;


int main() {

    AVLTree<int>* arbol = new AVLTree<int>();
    Node<int>* nodo1 = NULL;

    nodo1 = arbol->add(nodo1,new int(32));
    nodo1 = arbol->add(nodo1,new int(5));
    nodo1 = arbol->add(nodo1,new int(3));
    nodo1 = arbol->add(nodo1,new int(60));
    nodo1 = arbol->add(nodo1,new int(50));

    arbol->inorder(nodo1);  //imprime el arbol en orden

    Node<int>* nuevo = arbol->find(nodo1, new int(50));  //para hallar nodos
    //buscamos nodo de data 50 para destruirlo con sus hijos
    arbol->destroy(nuevo);   //elimina el nodo dado y todos sus hijos

    arbol->inorder(nodo1);  //ahora solo deberian aparecer bien 3 y 5

    return 0;
}