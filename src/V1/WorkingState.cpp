#include "WorkingState.h"


WorkingState::WorkingState(Rocket *rocket) : TestState(rocket) {
    state = "Working";
}

WorkingState::WorkingState(WorkingState *s) : TestState(s->getRocket()->clone()) {
    state = "Working";
}

TestState *WorkingState::clone() {
    return new WorkingState(this);
}

TestState* WorkingState::launch()
{
    //cout<<"TEST SUCCESSFUL!"<<endl;
    //cout<<"Congratulations, your rocket is working perfectly and you can proceed to launch."<<endl;
    string yn;
    cout << "Would you like to run another static test before launching? y/n";
    cin >> yn;
    if(yn == "y" || yn == "yes"){
        if(runStaticTest()){
            cout << "ROCKET WORKING!" << endl;
        }else{
            cout << "ROCKET FAILED!" << endl;
            return new BrokenState(rocketForTest);
        }
    }
    cout << "Proceeding with launch..." << endl;
    getRocket()->Activate();
    return this;
}

bool WorkingState::runStaticTest() {
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
                return false;
            } else
            {
                cout<<"Engine failed to fire"<<endl;
            }
            //return false;
            return false;
        }
    }
    return true;
}
