//
// Created by djjor on 2021-11-22.
//

#include "CrewDragon.h"

CrewDragon::CrewDragon(int cc) : crewCount(cc){
    //it's already done in the above line

}

void CrewDragon::Activate() {

}

void CrewDragon::VentFuel() {

}

void CrewDragon::LoadFuel() {

}

double CrewDragon::GetFuel() {
    return 0;
}

Payload *CrewDragon::clone()
{  //<--- this is god tier
    return new CrewDragon(this->crewCount);
}


