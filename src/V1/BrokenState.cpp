#include "BrokenState.h"
#include <iostream>
#include <ctime>

using namespace std;

BrokenState::BrokenState(Rocket *rocket) : TestState(rocket)
{
    state = "Broken";
}

TestState* BrokenState::launch()
{
    runStaticTest();
    vector<Engine*> engineList;
    int numberOfEngines = engineList.size();

    for (int i = 0; i < numberOfEngines; ++i)
    {
        rocketForTest->engines[i]->StartEngine();
        if (rocketForTest->engines[i]->isFail())
        {
            cout<<"LAUNCH FAILED!"<<endl;

            int chance;
            srand ((unsigned)time(NULL));
            chance= rand() %100;

            if (chance > 89)
            {
                cout<<"Engine explodes and destroys the rocket"<<endl;
                rocketForTest->DestroyRocket();
                return nullptr;
            } else
            {
                cout<<"Engine failed to fire"<<endl;
            }
            //return false;
            return new BrokenState(getRocket());
        }
    }
    return new WorkingState(getRocket());
}

bool BrokenState::runStaticTest() {
    int numberOfEngines = rocketForTest->engines.size();
    cout<<"Repairing rocket..."<<endl;
    for (int i = 0; i < numberOfEngines; ++i)
    {
        if (rocketForTest->engines[i]->isFail())
        {
            rocketForTest->engines[i]->setFail(false);
        }
    }
    cout<<"Rocket has been repaired."<<endl;
    return true;
}
