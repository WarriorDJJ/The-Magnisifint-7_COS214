//
// Created by djjor on 2021-11-19.
//

#ifndef COS214_PROJECT_CONTROLCENTER_H
#define COS214_PROJECT_CONTROLCENTER_H

#include "Command.h"
#include "SpaceCraft.h"
#include "RocketBuilderDirector.h"
#include "FalconHeavyBuilder.h"
#include "FalconBuilder.h"
#include "SingleRocketBuildStrategy.h"
#include "FullStackBuildStrategy.h"
#include "SimStore.h"
#include <vector>

using namespace std;

class ControlCenter{
private:
    RocketBuilderDirector* director;
    BuildStrategy* buildStrat;
    RocketBuilder* FHBuilder;
    RocketBuilder* F9Builder;
    bool isHeavy;
    vector<SimStore*> mainStore;

protected:
    ControlCenter();
    ~ControlCenter();

public:
    static ControlCenter& instance();
    Rocket* build();
    int storeSim(TestState* sim, Payload* payload);
    void setBuild();//Falcon 9
    void setBuild(SpaceCraft* payload, string rocket);//Falcon Heavy
    TestState* getSimState(int i);
    Payload* getSimPayload(int i);

};


#endif //COS214_PROJECT_CONTROLCENTER_H
