#include "Deck.hpp"

int Deck::size() const {
    return n;
}

bool Deck::empty() const {
    return D.empty();
}

const Elem& Deck::front() {
    return D.front();
}

const Elem& Deck::back() {
    return D.back();
}

// insert new first element
void Deck::insertFront(const Elem& e) { 
    D.addFront(e); 
    n++;
}

// insert new last element
void Deck::insertBack(const Elem& e) { 
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
/*
const StringElem Deck::front_has() const {
	if (is_empty()) {
		throw("front_has() failed.\n");
	}
	return (D.front());
}
*/