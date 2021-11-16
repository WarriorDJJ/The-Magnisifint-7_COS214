#ifndef STARLINK_H
#define STARLINK_H

class Starlink {

private:
	vector<Satelite*> satelites;

public:
	void release();

	Iterator* createIterator();
};

#endif
