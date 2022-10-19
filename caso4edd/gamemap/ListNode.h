#include <iostream>

#ifndef LISTNODE 

#define LISTNODE 1

using namespace std;

template <class T>
class ListNode {
    private:
        T *data;
        ListNode *next;
        ListNode *previous;   
    
    public:
        ListNode() {
            data = NULL;
            next = NULL;
            previous = NULL;   
        }

        ListNode(T *pData) {
            this->data = pData;
            next = NULL;
            previous = NULL;  
        }

        T* getData() {
            return data;
        }

        ListNode* getNext() {
            return next;
        }

        ListNode* getPrevious() {   
            return previous;   
        }

        void setNext(ListNode *pValue) {
            this->next = pValue;
        }

        void setPrevious(ListNode *pValue) {   
            this->previous = pValue;       
        }
        
};

#endif