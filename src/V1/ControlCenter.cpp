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

void ControlCenter::storeSim(TestState *sim) {
    mainStore.push_back(new SimStore())
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