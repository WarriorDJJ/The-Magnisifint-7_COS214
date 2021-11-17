#include "LinkedList.h"

LinkedList::LinkedList(Satelite *s) {
    root = s;
    curr = root;
}

void LinkedList::first() {
	curr = root;
}

void LinkedList::next() {
	if(hasNext()){
        curr = curr->getNextSatelite();
    }
}

bool LinkedList::hasNext() {
	if(hasNext()){
        return curr->getNextSatelite() != nullptr;
    }
    return false;
}

Satelite* LinkedList::current() {
	return curr;
}
