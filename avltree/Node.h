#include <iostream>
#include <string>
#include <sstream>

#ifndef NODE 

#define NODE 1

using namespace std;

template <class T>
class Node {
    private:
        int *data;  //es int porque ya sabemos en este caso que se ordena por critero de potencial de minado
        T *content; //esto es generico porque es para almacenar la camara, y tener ese acceso a ella
        int height = 1;  //aca tomamos que cada nodo tiene inicialmente 1
        int balance;
        Node *left;
        Node *right;  
    
    public:
        Node() {
            data = 0;
            left = NULL;
            right = NULL;   
            height = 1;
            balance = 0;
        }

        Node(int *pData) {
            this->data = pData;
            left = NULL;
            right = NULL; 
        }

        int* getData() {
            if(this == 0) {
                return NULL;
            }
            return data;
        }

        T* getContent() {
            return content;
        }

        void setData(int *pData) {
            this->data = pData;
        }

        void setContent(T *pcontent) {
            this->content = pcontent;
        }

        Node* getLeft() {
            if(this == NULL || left == NULL) {
                return NULL;
            }
            return left;
        }

        Node* getRight() {    
            if(this == NULL || right == NULL) {
                return NULL;
            }
            return right;     
        }

        int getHeight() {
            if(this == NULL) {
                return 0;
            }
            return height;
        }

        int getBalance() {
            if(this == NULL) {
                return 0;
            }
            return balance;
        }

        void setLeft(Node<T> *pValue) {
            this->left = pValue;
        }

        void setRight(Node<T> *pValue) {  
            this->right = pValue;      
        } 

        void setHeight(int newh) {
            this->height = newh;
        }

        void setBalance(int newb) {
            this->balance = newb;
        }
};

#endif