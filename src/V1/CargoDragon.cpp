//
// Created by djjor on 2021-11-22.
//

#include "CargoDragon.h"

CargoDragon::CargoDragon(double m) : mass(m){

}

void CargoDragon::Activate() {

}

void CargoDragon::VentFuel() {

}

void CargoDragon::LoadFuel() {
    Dragon::LoadFuel();
}

double CargoDragon::GetFuel() {
    return Dragon::GetFuel();
}

Payload *CargoDragon::clone() {
    return new CargoDragon(this->mass);
}