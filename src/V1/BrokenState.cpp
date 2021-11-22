#include "BrokenState.h"
#include <iostream>
#include <ctime>

using namespace std;

BrokenState::BrokenState(Rocket *rocket) : TestState(rocket)
{
    myRocket = rocket;
}

void BrokenState::launch()
{
    cout<<"TEST FAILED!"<<endl;

    int chance;
    srand ((unsigned)time(NULL));
    chance= rand() %100;

    if (chance > 89)
    {
        cout<<"Engine explodes and destroys the rocket"<<endl;
        myRocket->DestroyRocket();
    } else
    {
        cout<<"Engine failed to fire"<<endl;
    }
}
