#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Iterator.h"
#include "Satelite.h"
class LinkedList : public Iterator {
    Satelite* root;
    Satelite* curr;

public:
    LinkedList(Satelite* s);
	void first() override;

	void next() override;

	bool hasNext() override;

	Satelite* current() override;
};

#endif
