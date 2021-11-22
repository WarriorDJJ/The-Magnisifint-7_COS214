#include "SpaceCraft.h"
using namespace std;

void SpaceCraft::AddStage(SpaceCraft* s) {
	//does nothing
}

SpaceCraft * SpaceCraft::SeperateStage() {
    return this;
}

SpaceCraft* SpaceCraft::GetNextStage() {
    return nullptr;
}

SpaceCraft::SpaceCraft() {
    this->EnginesFailed = 0;
    this->isFinalStage = true;
}

void SpaceCraft::AddEngine(Engine *engine) {
    //Does Nothing
}

void SpaceCraft::RemoveEngine(Engine * engine) {
    //Does Nothing
}

Engine * SpaceCraft::getEngine(int i){
   return nullptr;
}

int SpaceCraft::getNumEngines(){
    return 0;
}

void SpaceCraft::notify(Engine * engine){
    this->EnginesFailed++;
}

void SpaceCraft::appendStage(SpaceCraft *s) {
    //Does Nothing
}

double SpaceCraft::getThrust(double externalPressure) {
    return 0;
}

int SpaceCraft::getStatusCode() {
    return statusCode;
}

void SpaceCraft::LoadFuel(){
    this->fuel = 100;
    cout << "Loading in Fuel" << endl;

}

double SpaceCraft::GetFuel() {
    return this->fuel;
}

void SpaceCraft::VentFuel() {
    this->fuel = 0;
    cout << "Venting Fuel" << endl;
}