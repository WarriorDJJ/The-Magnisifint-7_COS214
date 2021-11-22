//
// Created by djjor on 2021-11-22.
//

#include "CargoDragon.h"

CargoDragon::CargoDragon(double m) : mass(m){

}

void CargoDragon::Activate() {

}

Payload *CargoDragon::clone() {
    return new CargoDragon(this->mass);
}