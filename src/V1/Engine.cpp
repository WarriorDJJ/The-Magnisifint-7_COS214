#include "Engine.h"
#include <stdlib.h>
using namespace std;

int Engine::getThrust(int a){
    return 0;
}

 Engine * Engine::clone(){
	Engine * newEngine = new Engine();
    return newEngine;
}

Engine::Engine(){
    this->fail = false;
}

void Engine::setSpacecraft(SpaceCraft *spacecraft) {
    this->spaceCraft = spacecraft;
}

void Engine::update() {
    this->spaceCraft->notify(this);
}

void Engine::StartEngine() {
    int rand1 = rand() % 100 + 1;
    if(rand1 >=95 && rand1 <=100){
        cout << "Engine Failed!"<<endl;
        this->fail = true;
        this->update();
    }
    else {
        cout << "Engine started succesfully!"<<endl;
        this->fail = false;
    }
}
