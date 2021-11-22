#ifndef STARLINK_H
#define STARLINK_H
using namespace std;
#include "Satelite.h"
#include "Iterator.h"
#include <sstream>

class Starlink : public Payload {

protected:
	Satelite* root;
public:
    Starlink();
	void release();
    void addSat(Satelite* s);
    void removeSat(Satelite* s = nullptr, bool launch = false);
	Iterator* createIterator();
    bool isEmpty();

    //TODO
    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel();
    virtual void Activate();
    virtual Payload *  clone();
};

#endif
