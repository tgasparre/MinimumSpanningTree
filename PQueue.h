/**
 * Tatiana Gasparre
 * CPSC350-01
 * A6 - Spanning the Gamut
 */
#ifndef P_QUEUE_H
#define p_QUEUE_H
#include "DblList.h"
/**
 * a priority queue implementation using a linked list
 */
template <typename T>
class PQueue{
    public:
        /**
         * PQueue - the constructor 
         * @param isMin - a boolean representing if the queue is a minqueue
         */
        PQueue(bool isMin); //min q or not
        /**
         * ~PQeueue - the destructor 
         */
        virtual ~PQueue();
        /**
         * add - adds an item to the priority queue
         * @param data - the item to be added
         */
        void add(T data);
        /**
         * remove - removes and returns the item at the front of the queue
         * @return the item at the front of the queue
         */
        T remove();
        /**
         * size - the size of the priority queue
         * @return the number of items in the queue
         */
        int size();
        /**
         * isEmpty - checks if the priority queue is empty
         * @return true if the queue is empty and false otherwise
         */
        bool isEmpty();
        /**
         * peek - returns the first item in the queue
         * @return the item at the front of the queue
         */
        T peek();
    
    private:
        /**
         * isMinQ - a boolean representing if the queue is a minqueue or not
         */
        bool isMinQ;
        /**
         * m_list - the underlying list that makes up the queue
         */
        DblList<T>* m_list;
};

template <typename T>
PQueue<T>::PQueue(bool isMin){
    isMinQ = isMin;
    m_list = new DblList<T>();
}

template <typename T>
PQueue<T>::~PQueue(){
    // new code below
    
}

template <typename T>
T PQueue<T>::remove(){
    if(isMinQ){
        return m_list->removeFront(); //smallest always at the front
    }else{
        return m_list->removeBack(); //largets always at the back
    }
}

template <typename T>
void PQueue<T>::add(T d){
    if(isEmpty()){
        m_list->addFront(d);
    }else{
        ListNode<T>* newNode = new ListNode<T>(d);
        int currIdx = 0;
        ListNode<T>* currNode = m_list->m_front;
        while(currNode != NULL && currNode->m_data < d){
            ++currIdx;
            currNode = currNode->m_next;
        }
        m_list->add(currIdx, d);
    }
}

template <typename T>
int PQueue<T>::size()
{
    return m_list->getSize();
}

template <typename T>
bool PQueue<T>::isEmpty()
{
    return m_list->isEmpty();
}

template <typename T>
T PQueue<T>::peek()
{
    if (isMinQ)
    {
        return m_list->m_front->m_data;
    }
    int lastPos = m_list->getSize() - 1;
    return m_list->get(lastPos);
}
#endif
