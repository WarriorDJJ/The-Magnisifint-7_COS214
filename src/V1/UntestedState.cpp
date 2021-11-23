#include "UntestedState.h"

UntestedState::WorkingState(WorkingState *s) : TestState(s->getRocket()->clone()) {
    state = "Working";
}

TestState *WorkingState::clone() {
    return new WorkingState(this);
}

TestState* UntestedState::launch()
{
    string input;
    cout<<"Rocket is untested. It would be wise to fire all the engines briefly to make sure that they are working. Would you like to do that now?"<<endl;
    cout<<"y/n:";
    cin>>input;

    if (input == "y"||input == "yes" || input == "Y")
    {
        if(runStaticTest()){
            return new WorkingState(getRocket());
        }else{
            return new BrokenState(getRocket());
        }

        //return true;
    } else if(input == "n" || input == "no" || input == "N"){
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
        //return true;
    }else{
        cout << "Simulation Cancelled..." << endl;
        return this;
    }
}

UntestedState::UntestedState(Rocket *myRocket) : TestState(myRocket) {
    state = "Untested";
}

bool UntestedState::runStaticTest(){
    vector<Engine*> engineList;
    int numberOfEngines = engineList.size();
    rocketForTest->Activate();
    for (int i = 0; i < numberOfEngines; ++i)
    {
        if (rocketForTest->engines[i]->isFail())
        {
            cout<<"STATIC TEST FAILED!"<<endl;
            return false;
        }
    }
    cout << "STATIC TEST SUCCEEDED!" << endl;
    return true;
}


