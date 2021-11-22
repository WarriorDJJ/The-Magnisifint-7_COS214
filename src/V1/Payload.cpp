#include "Payload.h"

string Payload::getName(){
    return "(payload)"; //damian told me to code it this way// noice
}

void Payload::LoadFuel() {
    SpaceCraft::LoadFuel();
}

double Payload::GetFuel() {
    return SpaceCraft::GetFuel();
}
