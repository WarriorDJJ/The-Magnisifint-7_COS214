#include "Engine.h"
#include <stdlib.h>
using namespace std;

int Engine::getThrust(int a){
    return this->thrust;
}

 Engine * Engine::clone(){
	Engine * newEngine = new Engine(this->thrust);
    return newEngine;
}

Engine::Engine(int thrust){
    int rand1 = rand() % 100 + 1;
    if(rand1 >=95 && rand1 <=100){
        this->fail = true;
    }
    else
        this->fail = false;
    this->thrust = thrust;
}
