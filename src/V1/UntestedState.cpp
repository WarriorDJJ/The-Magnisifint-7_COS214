#include "UntestedState.h"

TestState UntestedState::launch()
{
    string input;
    cout<<"Rocket is untested. It would be wise to fire all the engines briefly to make sure that they are working. Would you like to do that now?"<<endl;
    cout<<"y/n:";
    cin>>input;

    if (input == "y"||input == "yes")
    {
        vector<Engine*> engineList;
        int numberOfEngines = engineList.size();

        for (int i = 0; i < numberOfEngines; ++i)
        {
            thisRocket->engines[i]->StartEngine();
            if (thisRocket->engines[i]->isFail())
            {
                //TODO: change state
                setState(false);
                return;
            }
        }
        setState(true);
    } else cout<<"Simulation was cancelled."<<endl;
}

UntestedState::UntestedState(Rocket *myRocket) : TestState(myRocket) {
    thisRocket = myRocket;

}
