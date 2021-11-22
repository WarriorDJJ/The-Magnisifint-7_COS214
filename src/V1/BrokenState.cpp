#include "BrokenState.h"
#include <iostream>
#include <ctime>

using namespace std;
bool BrokenState::launch(Rocket* myRocket)
{
	// TODO - implement BrokenState::launch
    cout<<"TEST FAILED!"<<endl;

    int chance;
    srand ((unsigned)time(NULL));
    chance= rand() %100;

    if (chance > 89)
    {
        cout<<"Engine explodes and destroys the rocket"<<endl;
        //myRocket->DestroyRocket();
        return false;
    } else
    {
        cout<<"Engine failed to fire"<<endl;
        return true;
    }
}

BrokenState::BrokenState(Rocket *rocket) : TestState(rocket) {}
