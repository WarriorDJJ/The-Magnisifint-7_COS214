#include "FalconHeavy.h"

using namespace std;

FalconHeavy::FalconHeavy(Rocket *lb, Rocket *rb) : LeftBooster(lb), RightBooster(rb), Rocket(){
    name = "FalconHeavy";
}

Rocket * FalconHeavy::SeperateStage() {
	if (this->LeftBooster != nullptr){
        Rocket * tempLB = this->LeftBooster;
        this->LeftBooster = nullptr;
        return tempLB;
    } else if (this->RightBooster != nullptr){
        Rocket * tempRB = this->RightBooster;
        this->RightBooster = nullptr;
        return tempRB;
    } else return this;
}

SpaceCraft * FalconHeavy::GetNextStage() {
    if (this->LeftBooster != nullptr){
        return this;
    } else if (this->RightBooster != nullptr){
        return this;
    } else return NextStage;
}

void FalconHeavy::Activate() {
    //cout<< "======Core Booster======" <<endl;
	Rocket::Activate();
    //cout<< "======Left Booster======" <<endl;
    if (this->LeftBooster != nullptr) {
        this->LeftBooster->Activate();
        if (LeftBooster->getStatusCode() > 0){
            statusCode = LeftBooster->getStatusCode();
        }
    }
    //cout<< "======Right Booster=====" <<endl;
    if (this->RightBooster != nullptr) {
        this->RightBooster->Activate();
    }
}

FalconHeavy * FalconHeavy::clone() {
	Rocket * tempLB = LeftBooster->clone();
    Rocket * tempRB = RightBooster->clone();
    FalconHeavy * newFH = new FalconHeavy(tempLB, tempRB);

    newFH->length = this->length;
    newFH->diameter = this->diameter;
    newFH->wetMass = this->wetMass;
    newFH->dryMass = this->dryMass;
    newFH->name = this->name;

    for (int i=0;i<engines.size();i++){
        Engine * newEngine = engines[i]->clone();
        newEngine->setSpacecraft(newFH);
        newFH->AddEngine(newEngine);
    }

    if(this->NextStage!=nullptr){
        newFH->NextStage = this->NextStage->clone();
    }

    return nullptr;
}

double FalconHeavy::getThrust(double externalPressure) {
    double thrust = 0;
    thrust += Rocket::getThrust(externalPressure);
    if (this->LeftBooster != nullptr){
        thrust += LeftBooster->getThrust(externalPressure);
    }
    if (this->RightBooster != nullptr){
        thrust += RightBooster->getThrust(externalPressure);
    }
    return thrust;
}

Engine * FalconHeavy::getEngine(int i) {
    if (i>=0 && i<getNumEngines()){
        if(i<Rocket::getNumEngines()){
            return engines.at(i);
        } else{
            if (LeftBooster != nullptr){
                if(i<LeftBooster->getNumEngines()){
                    return LeftBooster->getEngine(i);
                } else{
                    return RightBooster->getEngine(i);
                }
            } else{
                return RightBooster->getEngine(i);
            }
        }
    }
    else return nullptr;
}

int FalconHeavy::getNumEngines() {
    int temp = 0;
    if (this->LeftBooster != nullptr){
        temp += LeftBooster->getNumEngines();
    }
    if (this->RightBooster != nullptr){
        temp += RightBooster->getNumEngines();
    }
    temp += Rocket::getNumEngines();

    return temp;
}
