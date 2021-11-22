#include "LaunchCommand.h"

LaunchCommand::LaunchCommand(Payload *s, Rocket* r) : Command(s, r) {
	// TODO - implement LaunchCommand::LaunchComman
}

void LaunchCommand::execute() {
    if (this->receiver->GetFuel() == 100){
        this->launch();
    }
    else{
        this->receiver->LoadFuel();
        this->launch();
        cout << "" << endl;
    }
}
