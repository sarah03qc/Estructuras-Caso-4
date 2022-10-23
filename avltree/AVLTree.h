#include "Node.h"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

#ifndef AVLTREE 

#define AVLTREE 1

template <class T>
class AVLTree {
    private:
        Node<T> *root;
        int quantity;
        int counterForFind = 0;

    public:
        AVLTree() {
            root = NULL;
            quantity = 0;
        }

        int maximo(int first, int second) {
            return std::max(first, second);
        }

        Node<T>* rrRotac(Node<T> *upper) {
            Node<T> *temp;
            
            temp = upper->getRight();
            if(temp->getLeft() != NULL) {
                upper->setRight(temp->getLeft());
            }
            else{
                upper->setRight(NULL);
            }
            temp->setLeft(upper);

            upper->setHeight(maximo(upper->getLeft()->getHeight(), upper->getRight()->getHeight()) + 1);
            temp->setHeight(maximo(temp->getLeft()->getHeight(), temp->getRight()->getHeight()) + 1);

            
            cout<<"Right-Right Rotation" << endl;
            return temp;
        }


        Node<T>* llRotac(Node<T> *upper) {
            Node<T> *temp;
            
            temp = upper->getLeft();
            if(temp->getRight() != NULL) {
                upper->setLeft(temp->getRight());
            }
            else{
                upper->setLeft(NULL);
            }
            temp->setRight(upper);

            temp->setHeight(maximo(temp->getLeft()->getHeight(), temp->getRight()->getHeight()) + 1);
            upper->setHeight(maximo(upper->getLeft()->getHeight(), upper->getRight()->getHeight()) + 1);

            cout<<"Left-Left Rotation" << endl;;
            return temp;
        }

        Node<T>* lrRotac(Node<T> *upper) {
            Node<T> *temp;
            temp = upper->getLeft();
            upper->setLeft(rrRotac(temp));
            cout<<"Left-Right Rotation" << endl;;
            return this->llRotac(upper);
        }

        Node<T>* rlRotac(Node<T> *upper) {
            Node<T> *temp;
            temp = upper->getRight();
            upper->setRight(llRotac(temp));
            cout<<"Right-Left Rotation" << endl;
            return this->rrRotac(upper);
        }

        Node<T>* checkbalance(Node<T> *temp, int *pData) {
            int balanceFactor =  temp->getLeft()->getHeight() - temp->getRight()->getHeight();
            temp->setBalance(balanceFactor);

            if(balanceFactor < -1) {
                if(*pData > *temp->getRight()->getData()) {
                    temp = this->rrRotac(temp);
                } else {
                    temp = this->rlRotac(temp);
                }
            } else if(balanceFactor > 1) {
                if(*pData > *temp->getLeft()->getData()) {
                    temp = this->lrRotac(temp);
                } else {
                    temp = this->llRotac(temp);
                }
            }
            return temp;
        }

        Node<T>* add(Node<T> *currentt, int *pData) {
            
            if(currentt == NULL) {
                Node<T> *newNode = new Node<T>(pData);
                if(root->getData() == NULL) {
                    root = newNode;
                }
                return newNode;
            } else if(*pData < *currentt->getData()) {
                currentt->setLeft(add(currentt->getLeft(), pData));
                currentt->setHeight(1 + maximo(currentt->getLeft()->getHeight(), currentt->getRight()->getHeight()));
                currentt = this->checkbalance(currentt, pData);
                root = currentt;
                quantity++;
            } else if(*pData >= *currentt->getData()) {
                currentt->setRight(add(currentt->getRight(), pData));
                currentt->setHeight(1 + maximo(currentt->getLeft()->getHeight(), currentt->getRight()->getHeight()));
                currentt = this->checkbalance(currentt, pData);
                root = currentt;
                quantity++;
            } return currentt;
        }

        Node<T>* getRoot() {
            return this->root;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }

        void inorder(Node<T> *temp) {
            //recibe root de param
            if(temp != NULL) {
                inorder(temp->getLeft());
                cout << "Elemento: " << *temp->getData() << endl;
                inorder(temp->getRight());
            }
        }

        void destroy(Node<T> *toDestroy) {
            //aca no tenemos un delete normal, le pusimos destroy porque tambien destruye todos los hijos
            if(toDestroy != NULL) {
                destroy(toDestroy->getLeft());
                destroy(toDestroy->getRight());
                cout << "Destruyendo " << *toDestroy->getData() << endl;
                delete toDestroy;
            }
        }

        Node<T>* find(Node<T> *temp, int *searching) {
            //recibe root de param, y los datos del nodo que se busca

            //la situacion de esta es que da un warning por el return que solo esta en caso de que encuentra el elemento
            //de momento no afecta si se corre por la terminal, pero estamos viendo como lo manejamos
            //ya que es recursiva
            if(temp != NULL) {
                find(temp->getLeft(), searching);
                counterForFind++;
                if(*temp->getData() == *searching) {
                    cout << "Elemento ha sido encontrado: " << *temp->getData() << endl;
                    return temp;
                }
                find(temp->getRight(), searching);
            }
        }
};

#endif