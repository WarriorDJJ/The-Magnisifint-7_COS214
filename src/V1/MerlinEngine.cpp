#include "MerlinEngine.h"

void MerlinEngine::StartEngine() {
    //Merlin Engines have a 99.7% success rate
    double rand1 = rand() % 100 + 1;
    if(rand1 >=99.7 && rand1 <=100){
        std::cout << "Engine Failed!"<<std::endl;
        this->fail = true;
        this->update();
    }
    else {
        std::cout << "Engine started succesfully!"<<std::endl;
        this->fail = false;
        this->update();
    }
}

MerlinEngine::MerlinEngine() {
    chamberPressure = 10800000; // (Pa)
}

MerlinEngine *MerlinEngine::clone() {
    MerlinEngine * temp = new MerlinEngine();

    temp->chamberPressure = this->chamberPressure;
    temp->fail = this->fail;
    temp->spaceCraft = this->spaceCraft;

    return temp;
}
