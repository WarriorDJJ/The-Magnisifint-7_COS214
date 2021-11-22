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
    void LoadFuel() override;
    double GetFuel() override;
    void VentFuel() override;
    void Activate() override;
    Payload *  clone() override;
};

#endif
