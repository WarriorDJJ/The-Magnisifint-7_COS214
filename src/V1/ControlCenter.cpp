//
// Created by djjor on 2021-11-19.
//

#include "ControlCenter.h"

ControlCenter* ControlCenter::instance()
{
    if(cc != nullptr)
    {
        cc = new ControlCenter();
        FHBuilder = new FalconHeavyBuilder();
        F9Builder = new FalconBuilder();
        return cc;
    }
    else
    {
        cout<<"Control center already exsists!"<<endl;
        return nullptr;
    }
}

ControlCenter::ControlCenter() {
    director = new RocketBuilderDirector();
    isHeavy = false;
}

ControlCenter::~ControlCenter() {
    if(cc != nullptr)
    {
        delete cc;
        cc = nullptr;
    }

    if(buildStrat != nullptr)
    {
        delete buildStrat;
        buildStrat = nullptr;
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

void ControlCenter::setBuild(SpaceCraft* payload) {
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