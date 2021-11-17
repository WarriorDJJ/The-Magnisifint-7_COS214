#ifndef STARLINK_H
#define STARLINK_H
using namespace std;
#include "Satelite.h"
#include "Iterator.h"

class Starlink {

protected:
	Satelite* root;
public:
    Starlink();
	void release();
    void addSat(Satelite* s);
    void removeSat(Satelite* s = nullptr, bool launch = false);
	Iterator* createIterator();
    bool isEmpty();
};

#endif
