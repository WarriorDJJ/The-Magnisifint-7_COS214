//
// Created by djjor on 2021-11-19.
//

#include "ControlCenter.h"

ControlCenter& ControlCenter::instance()
{
    static ControlCenter cc;
    return cc;
    /*
    if(cc != nullptr)
    {
        cc = new ControlCenter();
        return cc;
    }
    else
    {
        return cc;
    }*/
}

ControlCenter::ControlCenter() {
    director = new RocketBuilderDirector();
    FHBuilder = new FalconHeavyBuilder();
    F9Builder = new FalconBuilder();
    isHeavy = false;
}

int ControlCenter::storeSim(TestState* sim, Payload* payload) {
    SimStore* tempSS = new SimStore();
    StoredSim* storedSIM = new StoredSim(sim, payload);
    tempSS->storeSim(storedSIM);
    mainStore.push_back(tempSS);
    return mainStore.size()-1;
}

Payload* ControlCenter::getSimPayload(int i) {
    if(i >= mainStore.size()){
        return nullptr;
    }
    return mainStore.at(i)->getSim()->getState()->getPayload()->clone();
}

TestState* ControlCenter::getSimState(int i) {
    if(i >= mainStore.size()){
        return nullptr;
    }
    return mainStore.at(i)->getSim()->getState()->getTestState()->clone();
}

ControlCenter::~ControlCenter() {
    /*
    if(cc != nullptr)
    {
        delete cc;
        cc = nullptr;
    }*/

    if(buildStrat != nullptr)
    {
        delete buildStrat;
        buildStrat = nullptr;
    }

    for(int i = 0; i < mainStore.size(); i++)
    {
        delete mainStore.at(i);
    }
    if(director !=nullptr)
    {
        delete director;
    }

    if(F9Builder != nullptr)
    {
        delete F9Builder;
    }

    if(FHBuilder != nullptr)
    {
        delete FHBuilder;
    }
}

Rocket* ControlCenter::build(){
    director->setStrategy(buildStrat);
    director->build();
   if(isHeavy)
    {
        return FHBuilder->getRocket();
    }
    else
    {
        return F9Builder->getRocket();
    }
}

void ControlCenter::setBuild() {
    if(buildStrat == nullptr)
    {
        buildStrat = new SingleRocketBuildStrategy(F9Builder);
        isHeavy = false;
    }
    else
    {
        delete buildStrat;
        buildStrat = nullptr;
        buildStrat = new SingleRocketBuildStrategy(F9Builder);
        isHeavy = false;
    }
}

void ControlCenter::setBuild(SpaceCraft* payload, string rocket) {
    if(rocket == "Falcon9")
    {
        if(buildStrat == nullptr)
        {
            buildStrat = new FullStackBuildStrategy(F9Builder , payload);
            isHeavy = false;
        }
        else
        {
            delete buildStrat;
            buildStrat = nullptr;
            buildStrat = new FullStackBuildStrategy(F9Builder , payload);
            isHeavy = false;
            //i am here
            //the power of presence
        }
    }
    else if(rocket == "FalconHeavy")
    {
        if(buildStrat == nullptr)
        {
            buildStrat = new FullStackBuildStrategy(FHBuilder , payload);
            isHeavy = true;
        }
        else
        {
            delete buildStrat;
            buildStrat = nullptr;
            buildStrat = new FullStackBuildStrategy(FHBuilder , payload);
            isHeavy = true;
            //i am here
            //the power of presence
        }
    }
}