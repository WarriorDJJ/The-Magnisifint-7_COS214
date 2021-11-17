#ifndef STARLINK_H
#define STARLINK_H
using namespace std;
#include <vector>
#include "Satelite.h"
#include "Iterator.h"

class Starlink {

private:
	vector<Satelite*> satelites;

public:
	void release();

	Iterator* createIterator();
};

#endif
