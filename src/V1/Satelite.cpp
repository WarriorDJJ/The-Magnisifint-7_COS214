//
// Created by djjor on 2021-11-17.
//

#include "Satelite.h"

Satelite::Satelite(string s) : name(s){
    next = nullptr;
}


Satelite *Satelite::getNextSatelite() {
    return next;
}

void Satelite::setNextSatelite(Satelite *s) {
    next = s;
}

void Satelite::release() {
    cout <<"    "<< name <<" released..." << endl;
}

/*//TODO
void Satelite::LoadFuel() {

}

void Satelite::VentFuel() {

}

double Satelite::GetFuel() {//should almost definitely be double but yeah someone else oughta fix it
    return 0;
}

void Satelite::notify(Engine *engine) {

}*/