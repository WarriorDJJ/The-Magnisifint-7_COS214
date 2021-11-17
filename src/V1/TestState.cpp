#include "TestState.h"



TestState* TestState::getWorkingState()
{
	// TODO - implement TestState::getWorkingState
	throw "Not yet implemented";
}

TestState* TestState::getBrokenState()
{
	// TODO - implement TestState::getBrokenState
	throw "Not yet implemented";
}

TestState::TestState(Rocket *rocketForTest)
{
    this->rocketForTest = rocketForTest;
    stateOfRocket = rocketForTest->rocketState;
    checkState();
}


void TestState::checkState() {}
//{
//    if (stateOfRocket == "untested")
//    {
//        Simulation* testRocket = new Simulation;
//        testRocket->launch(rocketForTest);
//    }
//
//    if (stateOfRocket == "faulty")
//    {
//        BrokenState* brokenRocket = new BrokenState(rocketForTest);
//        brokenRocket->launch(rocketForTest);
//    }
//
//    if (stateOfRocket == "tested")
//    {
//        //TODO: launching of rocket
//    }
//}


