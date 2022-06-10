#ifndef DL_HPP
#define DL_HPP
#include "DL.hpp"

// Deque as doubly Linked List
typedef char Elem;
class Deck {
public:
    //const StringElem front_has() const;
    int size() const;
    bool empty() const;
    const Elem& front(); // first element 
    const Elem& back(); // last element
    void insertFront(const Elem& e); // insert new first element 
    void insertBack(const Elem& e); // insert new last element 
    void removeFront(); // remove first element 
    void removeBack(); // remove last element
private:
    DLinkedList D; // doubly linked list of elements
    int n=0; // number of elements
    friend class NotationConverter;
};
#endif