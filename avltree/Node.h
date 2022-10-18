#include <iostream>
#include <string>
#include <sstream>

#ifndef NODE 

#define NODE 1

using namespace std;

template <class T>
class Node {
    private:
        T *data;
        int height = 1;
        int balance;
        Node *left;
        Node *right;  
        Node *parent;
    
    public:
        Node() {
            data = NULL;
            left = NULL;
            right = NULL;   
            parent = NULL;
            height = 1;
            balance = 0;
        }

        Node(T *pData) {
            this->data = pData;
            left = NULL;
            right = NULL; 
            parent = NULL; 
        }

        T* getData() {
            if(this == NULL) {
                return NULL;
            }
            return data;
        }

        void setData(T *pData) {
            this->data = pData;
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

        Node* getParent() {    
            return parent;     
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
            //cout << "pvalue es " << *pValue->getData() << endl;
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

        void setParent(Node<T> *pParent) {  
            this->parent = pParent;      
        } 
};

#endif