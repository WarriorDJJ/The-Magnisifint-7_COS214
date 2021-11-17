#include "Engine.h"

int Engine::getThrust(int a){
    return this->thrust;
}

 Engine * Engine::clone(){
	Engine * newEngine = new Engine(this->thrust);
    return newEngine;
}

Engine::Engine(int thrust) {
    this->thrust = thrust;
}
