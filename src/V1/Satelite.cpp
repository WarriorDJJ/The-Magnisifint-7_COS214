//
// Created by djjor on 2021-11-17.
//

#include "Satelite.h"

Satelite::Satelite() {
    next = nullptr;
}

Satelite *Satelite::getNextSatelite() {
    return next;
}

void Satelite::setNextSatelite(Satelite *s) {
    next = s;
}

void Satelite::release() {
    cout << "Satellite released..." << endl;
}

