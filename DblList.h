/**
 * Tatiana Gasparre
 * CPSC350-01
 * A6 - Spanning the Gamut
 */
#ifndef DBL_LIST_H
#define DBL_LIST_H

#include "ListNode.h"

/**
 * DblList is a doubly linked list implementation that is used to create a priority queue in PQueue.h
 */
template<typename T>
class DblList{
    public:
        /**
         * DblList - the constructor
         */
        DblList();
        /**
         * ~DblList - the destructor
         */
        virtual ~DblList();
        /**
         * getSize - returns how many items are in the list
         * @return int size - the size of the list
         */
        int getSize();
        /**
         * isEmpty - checks if the list is empty
         * @return true if the list is empty and false otherwise
         */
        bool isEmpty();
        /**
         * get - returns the data stored in the node at the specified index
         * @param pos - the position of the item 
         * @return the data stored in the node at position pos
         */
        T get(int pos);
        /**
         * remove - removes and returns the node at the specified position
         * @param pos - the position of the node to be returned
         * @return the data stored in the removed node
         */
        T remove(int pos);
        /**
         * removeFront - removes the node from the front of the list and returns its data
         * @return the data contained within the removed node
         */
        T removeFront();
        /**
         * removeBack - removes the node from the back of the list and returns its data
         * @return the data contained within the removed node
         */
        T removeBack();
        /**
         * add - adds a node at the specified position containing the specified data value
         * @param pos - the position where the node will be added
         * @param data - the value that will be stored within the added node
         */
        void add(int pos, T data);
        /**
         * addFront - adds a node at the front of the list containing the specified data value
         * @param data - the value that will be stored within the added node
         */
        void addFront(T data);
        /**
         * addBack - adds a node at the back of the list containing the specified data value
         * @param data - the value that will be stored within the added node
         */
        void addBack(T data);
        /**
         * m_front - a pointer to the node at the front of the list
         */
        ListNode<T>* m_front;
    private:
        /**
         * m_back - a pointer to the node at the back of the list
         */
        ListNode<T>* m_back;
        /**
         * m_size - the size of the list
         */
        int m_size;
};

template<typename T>
DblList<T>::DblList(){
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
DblList<T> ::~DblList(){
    //to do - free memory - loop through the list and delete all nodes
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T> //O(1) - constant
int DblList<T>::getSize(){
    return m_size;
}

template<typename T> //O(1) - constant
bool DblList<T>::isEmpty(){
    return (m_size == 0);
}

template<typename T> 
void DblList<T>::addFront(T data){ //constant
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        m_front->m_prev = newNode;
        newNode->m_next = m_front;
    }else{
        m_back = newNode;
    }
    m_front = newNode;
    ++m_size;
}

template<typename T> 
void DblList<T>::addBack(T data){ //constant
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        m_back->m_next = newNode;
        newNode->m_prev = m_back;
    }else{
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template<typename T> 
void DblList<T>::add(int pos, T data){ //linear
    if(isEmpty()){
        addFront(data);
    }else if(pos == 0){
        addFront(data);
    }else if(pos >= m_size){
        addBack(data);
    }else{
        ListNode<T>* current = m_front;
        int cPos = 0;
        while(cPos != pos){
            current = current->m_next;
            ++cPos;
        }
        ListNode<T>* newNode = new ListNode<T>(data);
        current->m_prev->m_next = newNode;
        newNode->m_prev = current->m_prev;
        current->m_prev = newNode;
        newNode->m_next = current;
        ++m_size;
    }
}

template<typename T> 
T DblList<T>::removeFront(){ //constant
    //TODO: make sure not empty
    T data;
    data = m_front->m_data;
    if(m_size == 1){
        delete m_front; //since there's only one item, the back and front are the same memory
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currFront = m_front;
        m_front = m_front->m_next;
        m_front->m_prev = NULL;
        delete currFront;
    }
    --m_size;
    return data;
}

template<typename T>
T DblList<T>::removeBack(){ //constant
    T data;
    data = m_back->m_data;
    //TODO: make sure not empty
    if(m_size == 1){
        delete m_back; //could also use m_front, since m_back and m_front point to the same place
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currBack = m_back;
        m_back = m_back->m_prev;
        m_back->m_next = NULL;
        delete currBack;
    }
    --m_size;
    return data;
}

template<typename T> 
T DblList<T>::remove(int pos){ //linear
    //TODO: make sure not empty
    T data;
    if(pos == 0){
        data = removeFront();
    }else if(pos >= m_size){
        data = removeBack();

    }else{
        ListNode<T>* current = m_front;
        int cPos = 0;
        while(cPos != pos){
            current = current->m_next;
            ++cPos;
        }
        data = current->m_data;
        current->m_prev->m_next = current->m_next;
        current->m_next->m_prev = current->m_prev;
        delete current;
        --m_size;
    }
    return data;
}

template<typename T>
T DblList<T>::get(int pos){ //linear
    //TODO: make sure position is in range
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
    return current->m_data;
}

#endif

