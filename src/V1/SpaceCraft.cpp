#include "SpaceCraft.h"

void SpaceCraft::AddStage(SpaceCraft* s) {
	// TODO - implement SpaceCraft::AddStage
}

void SpaceCraft::SeperateStage() {
	// TODO - implement SpaceCraft::SeperateStage
}

SpaceCraft* SpaceCraft::GetNextStage() {
	// TODO - implement SpaceCraft::GetNextStage
    return nullptr;
}

SpaceCraft::SpaceCraft() {
    this->EnginesFailed = 0;
}

void SpaceCraft::AddEngine(Engine *engine) {
    //Nope, dont like you
}

void SpaceCraft::RemoveEngine(Engine * engine) {
    //Nope, dont like you
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
    //todo
}

double SpaceCraft::getThrust(double externalPressure) {
    return 0;
}
