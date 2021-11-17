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
    }
}

MerlinEngine::MerlinEngine() {
    chamberPressure = 10800000; // (Pa)
}
