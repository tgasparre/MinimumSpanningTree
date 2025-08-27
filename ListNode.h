/**
 * Tatiana Gasparre
 * CPSC350-01
 * A6 - Spanning the Gamut
 */
#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;
/**
 * ListNode is used to create a node for DblList, each node can contain data of any type
 */
template<typename T>
class ListNode{
    public:
        /**
         * ListNode - the constructor, creates the object
         * @param data - the data the node will contain
         */
        ListNode(T data);
        /**
         * ~ListNode - the destructor
         */
        virtual ~ListNode();
        /**
         * m_data - the data the node will contain
         */
        T m_data;
        /**
         * m_next - a pointer to the next node (in a list)
         */
        ListNode<T>* m_next; //recursive data structure, points to instances of itself
        /**
         * m_prev - a pointer to the previous node (in a list)
         */
        ListNode<T>* m_prev;
};

template<typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = NULL;
    m_prev = NULL;
}

template<typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_prev = NULL;
}

#endif
