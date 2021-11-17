#ifndef SATELITE_H
#define SATELITE_H
#include "Payload.h"
class Satelite : public Payload {
private:
    Satelite* next;
public:
    Satelite();
    Satelite* getNextSatelite();

    void setNextSatelite(Satelite *pSatelite);
};

#endif
