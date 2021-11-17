#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Iterator.h"
class LinkedList : public Iterator {


public:
	void first();

	void next();

	void isDone();

	void current();
};

#endif
