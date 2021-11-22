#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Iterator.h"
#include "Satelite.h"
class LinkedList : public Iterator {
    Satelite* root;
    Satelite* curr;

public:
    LinkedList(Satelite* s);

	virtual void first() ;

	virtual void next();

	virtual bool hasNext();

	virtual Satelite* current();
};

#endif
