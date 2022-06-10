#include "DL.hpp"

DLinkedList::DLinkedList() { // constructor
   header = new DNode; // create sentinels
   trailer = new DNode;
   header->next = trailer; // have them point to each other
   trailer->prev = header;
}

DLinkedList::~DLinkedList() { // destructor
    while (!empty()) 
        removeFront(); // remove all but sentinels
    delete header; // remove the sentinels
    delete trailer;
}


bool DLinkedList::empty() const {
   return (header->next == trailer);
}

const Elem& DLinkedList::front() const {
   return header->next->elem;
}

const Elem& DLinkedList::back() const {
   return trailer->prev->elem;
}

// add to front of list
void DLinkedList::addFront(const Elem& e) {
   add(header->next, e);
}

// add to front of list
void DLinkedList::addBack(const Elem& e) {
   add(trailer, e);
}

void DLinkedList::removeFront(){
    remove(header->next);
}

void DLinkedList::removeBack(){
    remove(trailer->prev);
}
/*
// insert new node before v
void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;
    u->elem = e; //create new node for e
    u->next = v; // link u in between v
    u->prev = v->prev; // ...and v->prev
    v->prev->next = u;
    v->prev -> u;
}
*/
 // add to back of list
 void DLinkedList::remove(DNode* v) { // remove node v
   DNode* u = v->prev; // predecessor
   DNode* w = v->next; // successor
   u->next = w; // unlink v from list
   w->prev = u;
   delete v;
 }

void DLinkedList::add(DNode* v, const Elem& e) {
	DNode* u = new DNode; /*Make new node*/
	u->elem = e;/*Sets the value of that node*/
	u->next = v; /*points the new node to the node passed*/
	u->prev = v->prev; /*Set its previous to olds previos*/
	v->prev->next = u; /*Change pointer of old's node next to new node*/
	v->prev = u; /*Pointer reverse pointer to the new node*/
}