#ifndef SATELITE_H
#define SATELITE_H
#include "Payload.h"
#include <iostream>
using namespace std;
class Satelite{
private:
    Satelite* next;
    string name;
public:
    Satelite(string n);
    Satelite* getNextSatelite();
    void release();
    void setNextSatelite(Satelite *s);

    /*TODO
    virtual void LoadFuel();
    virtual double GetFuel();
    virtual void VentFuel();
    virtual void notify(Engine * engine);*/
};

#endif
