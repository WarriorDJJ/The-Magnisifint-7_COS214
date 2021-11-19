#include "FalconHeavy.h"

using namespace std;

FalconHeavy::FalconHeavy(Rocket *lb, Rocket *rb) : LeftBooster(lb), RightBooster(rb), Rocket(0, 0, 0, "FalconHeave"){

}

void FalconHeavy::SeperateStage() {
	// TODO - implement FalconHeavy::SeperateStage
	throw "Not yet implemented";
}

void FalconHeavy::Activate() {
	// TODO - implement FalconHeavy::Activate
    cout<< "======Core Booster======" <<endl;
	Rocket::Activate();
    cout<< "======Left Booster======" <<endl;
    this->LeftBooster->Activate();
    cout<< "======Right Booster=====" <<endl;
    this->RightBooster->Activate();
}

FalconHeavy * FalconHeavy::clone() {
	// TODO - implement FalconHeavy::clone
	throw "Not yet implemented";
}
