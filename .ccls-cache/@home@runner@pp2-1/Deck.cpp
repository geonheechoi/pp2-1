#include "Deck.hpp"
//Check the size
int Deck::size() const {
    return n;
}
//check the empty
bool Deck::empty() const {
    return D.empty();
}
//check front
const Elem& Deck::front() {
    return D.front();
}
//check the back
const Elem& Deck::back() {
    return D.back();
}

// insert new first element
void Deck::insertFront(const char& e) { 
    D.addFront(e); 
    n++;
}

// insert new last element
void Deck::insertBack(const char& e) { 
    D.addBack(e); 
    n++;
}

// remove first element
void Deck::removeFront() { 
    D.removeFront(); 
    n--;
}

// remove last element
void Deck::removeBack() { 
    D.removeBack(); 
    n--;
}
