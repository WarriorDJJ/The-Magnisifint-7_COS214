#include "Rocket.h"

Rocket::Rocket(double f, double wm, double dm, string n) : fuel(f), wetMass(wm), dryMass(dm), name(n){
    rocketState = "untested";
}

void Rocket::DestroyRocket()
{

    for(int i=0;i<engines.size();i++)
    {

        RemoveEngine(engines[i]);
    }
}


void Rocket::Activate() {
	// TODO - implement Rocket::Activate
	for(int i=0;i<engines.size();i++){
        cout<< to_string(i+1) + ": ";
        engines[i]->StartEngine();
    }
}

Rocket * Rocket::clone() {
	Rocket * newRocket = new Rocket(this->fuel, this->wetMass, this->dryMass, this->name);
    for (int i=0;i<engines.size();i++){
        Engine * newEngine = engines[i]->clone();
        newEngine->setSpacecraft(newRocket);
        newRocket->AddEngine(newEngine);
    }
    if(this->NextStage!=nullptr){
        SpaceCraft* newStage = NextStage->clone();
        this->NextStage = newStage;
    }
    else{
        this->NextStage = nullptr;
    }
    return newRocket;
}

void Rocket::AddStage(SpaceCraft *s) {
    //
}

void Rocket::SeperateStage() {
    SpaceCraft::SeperateStage();
}

SpaceCraft *Rocket::GetNextStage() {
    return SpaceCraft::GetNextStage();
}

void Rocket::LoadFuel() {

}

int Rocket::GetFuel() {
    return 0;
}

void Rocket::VentFuel() {

}

void Rocket::notify(Engine * engine) {
    SpaceCraft::notify(engine);
}

Rocket::Rocket(){
}

void Rocket::AddEngine(Engine *engine) {
    engines.push_back(engine);
}

void Rocket::RemoveEngine(Engine * engine) {
    vector<Engine*>::iterator ptr;
    for (ptr = engines.begin(); ptr < engines.end(); ptr++){
        if(*ptr==engine){
            engines.erase(ptr);
        }
    }
    
}

Engine * Rocket::getEngine(int i){
    if(i<engines.size()){
        return engines.at(i);
    }
    else return nullptr;
}

int Rocket::getNumEngines() {
    return engines.size();
}

Rocket::~Rocket() {

}
