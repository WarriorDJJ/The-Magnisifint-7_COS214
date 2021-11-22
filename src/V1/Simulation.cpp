#include "Simulation.h"


Simulation::Simulation(Rocket* myRocket)
{
    rocketForSim = myRocket;
    state = new UntestedState(myRocket);
    //state->launch();
}

bool Simulation::launch()
{
    TestState* temp = state;
    state = state->launch();

    if(temp == state){
        return true;
    }
    return false;
//    vector<Engine*> engineList;
//    int numberOfEngines = engineList.size();
//
//    for (int i = 0; i < numberOfEngines; ++i)
//    {
//        rocketForSim->engines[i]->StartEngine();
//        if (rocketForSim->engines[i]->isFail())
//        {
//            //rocketForSim->rocketState = "faulty";
//            setState(false);
//            return;
//        }
//    }
//    setState(true);
}


/*void Simulation::setState(bool working)
{
    state = nullptr;

    if (working)
    {
        delete state;
        state = new WorkingState(rocketForSim);
        state->launch();
    }
    else
    {
        delete state;
        state = new BrokenState(rocketForSim);
        state->launch();
    }
}*/


