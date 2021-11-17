#include "LaunchCommand.h"

LaunchCommand::LaunchCommand(SpaceCraft *s) : Command(s) {
	// TODO - implement LaunchCommand::LaunchComman
}

void LaunchCommand::execute() {
    if (this->receiver->GetFuel() == 100){
        this->receiver->Activate();
    }
    else{
        this->receiver->LoadFuel();
        this->receiver->Activate();
    }
}
