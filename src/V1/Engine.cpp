#include "Engine.h"
#include <stdlib.h>
using namespace std;

double Engine::getThrust(double externalPressure){
    return 0;
}

 Engine * Engine::clone(){
	Engine * newEngine = new Engine();

    newEngine->spaceCraft = this->spaceCraft;
    newEngine->fail = this->fail;

    return newEngine;
}

Engine::Engine(){
    this->fail = false;
    this->spaceCraft = nullptr;
}

void Engine::setSpacecraft(SpaceCraft *spacecraft) {
    this->spaceCraft = spacecraft;
}

void Engine::update() {
    if(spaceCraft== nullptr) cout<<"spacecraft not set"<<endl;
    else this->spaceCraft->notify(this);
}

void Engine::StartEngine() {
    int rand1 = rand() % 100 + 1;
    if(rand1 >=95 && rand1 <=100){
        cout << "Engine Failed!"<<endl;
        this->fail = true;
        this->update();
    }
    else {
        cout << "Engine started successfully!"<<endl;
        this->fail = false;
    }
}

bool Engine::isFail() const {
    return fail;
}

void Engine::setFail(bool fail) {
    Engine::fail = fail;
}

SpaceCraft *Engine::getSpaceCraft() const {
    return spaceCraft;
}
