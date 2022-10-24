#include "ListNode.h"

#ifndef LIST 

#define LIST 1

template <class T>
class List {
    private:
        ListNode<T> *first;
        ListNode<T> *last;
        int quantity;
        bool empty;
        ListNode<T> *searchPosition = NULL;
        ListNode<T> *searchBehind = NULL;

    public:
        List() {
            first = NULL;
            last = NULL;
            quantity = 0;
            empty = true;
        }

        void add(T *pData) {
            ListNode<T> *newNode = new ListNode<T>(pData);

            if (quantity>0) {
                this->last->setNext(newNode);
                newNode->setPrevious(this->last); 
            } else {
                this->first = newNode;
            }
            this->last = newNode;

            empty = false;
            quantity++;
        }

        ListNode<T>* getFirst() {
            return this->first;
        }

        int getSize() {
            if (this == NULL){
                return 0;
            }
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }

        T* find(int pPosition) {
            T* result = NULL;
            searchPosition = this->first;
            searchBehind = NULL;

            if (pPosition<getSize()) {
                while(pPosition>0) {
                    searchPosition = searchPosition->getNext();
                    searchBehind = searchPosition->getPrevious();   
                    
                    pPosition--;
                }
                result = searchPosition->getData();
            }

            return result;
        }

        void insert(int pPosition, T *pData) {
            
            if (pPosition<getSize() && first!=NULL) {
                ListNode<T> *newNodo = new ListNode<T>(pData);

                T* result = find(pPosition);
                
                newNodo->setNext(searchPosition);
                searchPosition->setPrevious(newNodo); 
                if (searchBehind!=NULL) {
                    searchBehind->setNext(newNodo);
                    newNodo->setPrevious(searchBehind);  
                } else {
                    this->first = newNodo;
                }
                
                quantity++;
            } else {
                add(pData);
            }
        }

        bool remove(int pPosition) {
            bool result = false;
            if (first!=NULL && pPosition<getSize()) {
                ListNode<T> *search = first;
                if (pPosition!=0) {
                    T* data = find(pPosition);

                    searchBehind->setNext(searchPosition->getNext());
                    if(searchPosition->getNext()!=NULL) { 
                        searchPosition->getNext()->setPrevious(searchBehind);  
                    }

                    if (searchPosition==last) {
                        last = searchPosition->getPrevious();
                    }
                    searchPosition->setNext(NULL);
                    searchPosition->setPrevious(NULL); 
                } else {
                    first = first->getNext();
                    first->setPrevious(NULL);  
                    search->setNext(NULL);
                    delete search;
                }
                quantity--;
            }
            return result;
        } 
};

#endif