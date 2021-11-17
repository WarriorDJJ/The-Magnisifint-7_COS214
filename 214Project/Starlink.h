#ifndef STARLINK_H
#define STARLINK_H

#include <vector>
class Starlink {

private:
	vector<Satelite*> satelites;

public:
	void release();

	Iterator* createIterator();
};

#endif
