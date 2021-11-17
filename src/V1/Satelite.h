#ifndef SATELITE_H
#define SATELITE_H
#include "Payload.h"
#include <iostream>
using namespace std;
class Satelite : public Payload {
private:
    Satelite* next;
public:
    Satelite();
    Satelite* getNextSatelite();
    void release();
    void setNextSatelite(Satelite *s);
};

#endif
