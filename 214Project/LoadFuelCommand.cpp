//
// Created by djjor on 2021-11-17.
//

#include "LoadFuelCommand.h"
using namespace std;

LoadFuelCommand::LoadFuelCommand(SpaceCraft* s):Command(s){

}

void LoadFuelCommand::execute(){
    if(this->receiver->GetFuel()<100){
        this->receiver->LoadFuel();
    }
}