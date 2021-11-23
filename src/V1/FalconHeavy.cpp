#include "FalconHeavy.h"

using namespace std;

FalconHeavy::FalconHeavy(Rocket *lb, Rocket *rb) : LeftBooster(lb), RightBooster(rb), Rocket(){
    name = "FalconHeavy";
    this->statusCode = 0;
}

FalconHeavy::~FalconHeavy(){
    delete LeftBooster;
    delete RightBooster;
}

//Rocket * FalconHeavy::SeperateStage() {
//	if (this->LeftBooster != nullptr){
//        Rocket * tempLB = this->LeftBooster;
//        this->LeftBooster = nullptr;
//        cout<<"Left Booster Seperated"<<endl;
//        return tempLB;
//    } else if (this->RightBooster != nullptr){
//        Rocket * tempRB = this->RightBooster;
//        this->RightBooster = nullptr;
//        cout<<"Right Booster Seperated"<<endl;
//        return tempRB;
//    } else {
//        NextStage = nullptr;
//        cout<<"Stage Decoupled: "<< this->getName() <<endl;
//        return this;
//    }
//}

SpaceCraft * FalconHeavy::GetNextStageMain() {
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
        if (LeftBooster->getStatusCode() > statusCode && statusCode != 3) statusCode = LeftBooster->getStatusCode();
    }
    //cout<< "======Right Booster=====" <<endl;
    if (this->RightBooster != nullptr) {
        this->RightBooster->Activate();
        if (LeftBooster->getStatusCode() > statusCode && statusCode != 3) statusCode = RightBooster->getStatusCode();
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

    return newFH;
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

void FalconHeavy::LoadFuel() {
    if (this->LeftBooster != nullptr){
        LeftBooster->LoadFuel();
    }
    if (this->RightBooster != nullptr){
        RightBooster->LoadFuel();
    }
    Rocket::LoadFuel();
}

double FalconHeavy::GetFuel() {
    return Rocket::GetFuel();
}

void FalconHeavy::VentFuel() {
    if (this->LeftBooster != nullptr){
        LeftBooster->VentFuel();
    }
    if (this->RightBooster != nullptr){
        RightBooster->VentFuel();
    }
    Rocket::VentFuel();
}

void FalconHeavy::useFuel(double Percent) {
    SpaceCraft::useFuel(Percent);
    if (this->LeftBooster != nullptr){
        LeftBooster->setFuel(fuel);
    }
    if (this->RightBooster != nullptr){
        RightBooster->setFuel(fuel);
    }
}
