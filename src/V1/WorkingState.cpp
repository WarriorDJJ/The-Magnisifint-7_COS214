#include "WorkingState.h"


WorkingState::WorkingState(Rocket *rocket) : TestState(rocket) {}

void WorkingState::launch()
{
    cout<<"TEST SUCCESSFUL!"<<endl;
    cout<<"Congratulations, your rocket is working perfectly and you can proceed to launch."<<endl;
}
