#ifndef ITERATOR_H
#define ITERATOR_H
#include "Satelite.h"
class Iterator {


public:
	virtual void first();

	virtual void next();

	virtual bool hasNext();

	virtual Satelite* current();
};

#endif
