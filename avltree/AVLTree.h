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
            if(upper->getParent() != NULL) {
                Node<T> *parent = upper->getParent();
                temp->setParent(parent);
                upper->setParent(temp);

                if(parent->getLeft() == upper) {
                    parent->setLeft(temp);
                } else {
                    parent->setRight(temp);
                }
            }

            temp = upper->getRight();
            if(temp->getLeft() != NULL) {
                upper->setRight(temp->getLeft());
            }
            if(temp->getLeft() != NULL) {
                temp->getLeft()->setParent(upper);
            }
            temp->setLeft(upper);

            upper->setHeight(maximo(upper->getLeft()->getHeight(), upper->getRight()->getHeight()) + 1);
            temp->setHeight(maximo(temp->getLeft()->getHeight(), temp->getRight()->getHeight()) + 1);

            
            cout<<"Right-Right Rotation";
            return temp;
        }


        Node<T>* llRotac(Node<T> *upper) {
            Node<T> *temp;
            if(upper->getParent() != NULL) {
                Node<T> *parent = upper->getParent();
                temp->setParent(parent);
                upper->setParent(temp);

                if(parent->getLeft() == upper) {
                    parent->setLeft(temp);
                } else {
                    parent->setRight(temp);
                }
            }
            temp = upper->getLeft();
            if(temp->getRight() != NULL) {
                upper->setLeft(temp->getRight());
            }
            if(temp->getRight() != NULL) {
                temp->getRight()->setParent(upper);
            }
            temp->setRight(upper);

            temp->setHeight(maximo(temp->getLeft()->getHeight(), temp->getRight()->getHeight()) + 1);
            upper->setHeight(maximo(upper->getLeft()->getHeight(), upper->getRight()->getHeight()) + 1);

            cout<<"Left-Left Rotation";
            return temp;
        }

        Node<T>* lrRotac(Node<T> *upper) {
            Node<T> *temp;
            temp = upper->getLeft();
            upper->setLeft(rrRotac(temp));
            cout<<"Left-Right Rotation";
            return this->llRotac(upper);
        }

        Node<T>* rlRotac(Node<T> *upper) {
            Node<T> *temp;
            temp = upper->getRight();
            upper->setRight(llRotac(temp));
            cout<<"Right-Left Rotation";
            return this->rrRotac(upper);
        }

        Node<T>* checkbalance(Node<T> *temp, T *pData) {
            int balanceFactor = temp->getRight()->getHeight() - temp->getLeft()->getHeight();
            temp->setBalance(balanceFactor);
            //el problema es que aveces temp->getRight() va a ser null, pero siendo null no se
            //puede hacerle ->getData() porque da segmentationfault 
            //y si le hago una condicion extra de que eso no sea null, simplemente no entra a la 
            //condicion y se va a hacer la otra
            if(balanceFactor < -1) {
                if(temp->getRight() != NULL && *pData > *temp->getRight()->getData()) {
                    temp = this->llRotac(temp);
                } else {
                    temp = this->lrRotac(temp);
                }
            } else if(balanceFactor > 1) {
                if(temp->getLeft() != NULL && *pData > *temp->getLeft()->getData()) {
                    temp = this->rlRotac(temp);
                } else {
                    temp = this->rrRotac(temp);
                }
            }
            return temp;
        }

        Node<T>* add(Node<T> *currentt, T *pData) {
            
            if(currentt == NULL) {
                Node<T> *newNode = new Node<T>(pData);
                cout << "root es " << root << endl;
                if(root->getData() == NULL) {
                    root = newNode;
                }
                return newNode;
            } else if(*pData < *currentt->getData()) {
                currentt->setLeft(add(currentt->getLeft(), pData));
                currentt->setHeight(1 + maximo(currentt->getLeft()->getHeight(), currentt->getRight()->getHeight()));
                this->checkbalance(currentt, pData);
                quantity++;
            } else if(*pData >= *currentt->getData()) {
                currentt->setRight(add(currentt->getRight(), pData));
                currentt->setHeight(1 + maximo(currentt->getLeft()->getHeight(), currentt->getRight()->getHeight()));
                this->checkbalance(currentt, pData);
                quantity++;
            } return currentt;
        }
            
        

                /*  version iterativa funcional guardada por si acaso
                while(current != newNode) {
                    currentlevel++;
                    if(*newNode->getData() < *current->getData() && current->getLeft() != NULL) {
                        current = current->getLeft();
                        
                    } else if(*newNode->getData() < *current->getData() && current->getLeft() == NULL) {
                        current->setLeft(newNode);
                 
                        current = newNode;
                        
                    } else if(*newNode->getData() > *current->getData() && current->getRight() != NULL) {
                        current = current->getRight();
                        
                    } else if(*newNode->getData() > *current->getData() && current->getRight() == NULL) {
                        current->setRight(newNode);
             
                        current= newNode;
                    }
                }
                */


        Node<T>* getRoot() {
            return this->root;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }

};

#endif