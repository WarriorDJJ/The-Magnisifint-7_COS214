#ifndef ITERATOR_H
#define ITERATOR_H
#include "Satelite.h"
class Iterator {


public:
	virtual void first() = 0;

	virtual void next() = 0;

	virtual bool hasNext() = 0;

	virtual Satelite* current() = 0;
};

#endif
