//
// Created by djjor on 2021-11-17.
//

#include "LoadFuelCommand.h"
using namespace std;

LoadFuelCommand::LoadFuelCommand(Payload* s, Rocket* r):Command(s, r){

}

void LoadFuelCommand::execute(){
    if(this->rocketReceiver->GetFuel() < 100){
        this->rocketReceiver->LoadFuel();
    }
}