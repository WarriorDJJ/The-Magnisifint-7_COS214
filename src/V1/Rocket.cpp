#include "Rocket.h"

Rocket::Rocket(double f, double wm, double dm, string n) : fuel(f), wetMass(wm), dryMass(dm), name(n){

}

void Rocket::Activate() {
	// TODO - implement Rocket::Activate
	for(int i=0;i<engines.size();i++){
        cout<< to_string(i) + ": " << endl;
        engines[i]->StartEngine();
    }
}

Rocket * Rocket::clone() {
	// TODO - implement Rocket::clone
	throw "Not yet implemented";
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
    this->EnginesFailed++;
}

Rocket::Rocket(){
    this->EnginesFailed = 0;
}

void Rocket::AddEngine(Engine *engine) {
    engines.push_back(engine);
}

void Rocket::RemoveEngine(Engine *engine) {
    vector<Engine*> vec;
}
