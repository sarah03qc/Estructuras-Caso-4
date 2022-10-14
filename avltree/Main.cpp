
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

    return 0;
}