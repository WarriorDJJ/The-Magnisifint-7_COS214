#include <iostream>
using namespace std;
#include "ControlCenter.h"
#include "Nozzle.h"
#include "BrokenState.h"
#include "BuildStrategy.h"
#include "CargoDragon.h"
#include "Command.h"
#include "CrewDragon.h"
#include "Dragon.h"
#include "Engine.h"
#include "EngineFactory.h"
#include "FalconBuilder.h"
#include "FalconHeavy.h"
#include "FalconHeavyBuilder.h"
#include "FullStackBuildStrategy.h"
#include "Invoker.h"
#include "Iterator.h"
#include "LaunchCommand.h"
#include "LinkedList.h"
#include "MerlinEngine.h"
#include "MerlinEngineFactory.h"
#include "Payload.h"
#include "Rocket.h"
#include "RocketBuilder.h"
#include "RocketBuilderDirector.h"
#include "RocketMotor.h"
#include "Satelite.h"
#include "SimStore.h"
#include "Simulation.h"
#include "SingleRocketBuildStrategy.h"
#include "SpaceCraft.h"
#include "StandardBell.h"
#include "StandardSimulation.h"
#include "Starlink.h"
#include "StarlinkSimulationAdapter.h"
#include "StoredSim.h"
#include "StoredSimState.h"
#include "TestState.h"
#include "UntestedState.h"
#include "UpperStageBuilder.h"
#include "VacuumBell.h"
#include "WorkingState.h"
#include <stdlib.h>     /* srand, rand */
#include <sstream>

vector<Rocket*> rockets;
//hi suh dude ayyy
void runnyBoi(Rocket* r){
    bool valid;
    int next;
    string temp1 = "";
    valid = false;
    bool done = false;
    while(!done){
        while(!valid){
            cout << "\nWhat type of launch would you like to do with your new rocket hottie? Test Mode = 0, Launch Sim = 1, Actual Launch = 2, Save it for later = 3 > ";
            cin >> temp1;
            stringstream intV(temp1);
            intV >> next;
            if(next >= 0 && next <= 3){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
        switch(next){
            case 0:
                TestMode(r);
                break;
            case 1:
                LaunchSim(r);
                break;
            case 2:
                Launch(r);
                break;
            case 3:
                Save(r);
        }
    }

}

void StarlinkSim(){
    cout << "Starlink" << endl;
    Starlink* s = new Starlink();
    ControlCenter::instance().setBuild(s, "Falcon9");
    Rocket* starlink = ControlCenter::instance().build();
    cout << "Starlink Created!";
    runnyBoi(starlink);
}

void Falcon9Sim(){
    cout << "Falcon9" << endl;
    //bool done = false;
    bool valid;
    int next;
    string temp1 = "";
    valid = false;
    string payload = "";
    while(!valid){
            cout << "\nWhat type of payload would you like to create? Crew Dragon = 0, Cargo Dragon = 1, Starlink = 2 > ";
            cin >> temp1;
            stringstream intV(temp1);
            intV >> next;
            if(next >= 0 && next <= 2){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
        switch(next){
            case 0:
                payload = "Crew";
                break;
            case 1:
                payload = "Cargo";
                break;
            case 2:
                payload = "Starlink";
                break;
        }
        if(payload == "Crew"){
            valid = false;
            while(!valid){
                cout << "\nHow many crew members (Min: 2, Max: 4)? > ";
                cin >> temp1;
                stringstream  intV(temp1);
                intV >> next;
                if(next >= 2 && next <= 4){
                    valid = true;
                }else{
                    cout << "Invalid Choice!" << endl;
                }
            }
            CrewDragon* pay = new CrewDragon(next);
            ControlCenter::instance().setBuild(pay, "Falcon9");
            Rocket* crewFalc9 = ControlCenter::instance().build();
            cout << "Crew Dragon - Falcon9 Created!" << endl;
            runnyBoi(crewFalc9);
        }else if(payload == "Cargo"){
            double mass;
            valid = false;
            while(!valid){
                cout << "\nHow much does the cargo weigh(kg)? > ";
                cin >> temp1;
                stringstream intV(temp1);
                intV >> mass;
                if(mass > 0){
                    valid = true;
                }else{
                    cout << "Invalid Choice!" << endl;
                }
            }
            CargoDragon* pay = new CargoDragon(mass);
            ControlCenter::instance().setBuild(pay, "Falcon9");
            Rocket* cargoFalc9 = ControlCenter::instance().build();
            cout << "Cargo Dragon - Falcon9 Created!" << endl;
            runnyBoi(cargoFalc9);
        }else if(payload == "Starlink"){
            Starlink* pay = new Starlink();
            ControlCenter::instance().setBuild(pay, "Falcon9");
            Rocket* starFalc9 = ControlCenter::instance().build();
            cout << "Starlink - Falcon9 Created!" << endl;
            runnyBoi(starFalc9);
        }else{
            cout << "wut" << endl;
        }
}

void FalconHeavySim(){
    cout << "FalconHeavy" << endl;
    //bool done = false;
    bool valid;
    int next;
    string temp1 = "";
    valid = false;
    string payload = "";
    while(!valid){
        cout << "\nWhat type of payload would you like to create? Crew Dragon = 0, Cargo Dragon = 1, Starlink = 2 > ";
        cin >> temp1;
        stringstream intV(temp1);
        intV >> next;
        if(next >= 0 && next <= 2){
            valid = true;
        }else{
            cout << "Invalid Choice!" << endl;
        }
    }
    switch(next){
        case 0:
            payload = "Crew";
            break;
        case 1:
            payload = "Cargo";
            break;
        case 2:
            payload = "Starlink";
            break;
    }
    if(payload == "Crew"){
        valid = false;
        while(!valid){
            cout << "\nHow many crew members (Min: 2, Max: 4)? > ";
            cin >> temp1;
            stringstream  intV(temp1);
            intV >> next;
            if(next >= 2 && next <= 4){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
        CrewDragon* pay = new CrewDragon(next);
        ControlCenter::instance().setBuild(pay, "Falcon9");
        Rocket* crewFalcHeav = ControlCenter::instance().build();
        cout << "Crew Dragon - Falcon Heavy Created!" << endl;
        runnyBoi(crewFalcHeav);
    }else if(payload == "Cargo"){
        double mass;
        valid = false;
        while(!valid){
            cout << "\nHow much does the cargo weigh(kg)? > ";
            cin >> temp1;
            stringstream intV(temp1);
            intV >> mass;
            if(mass > 0){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
        CargoDragon* pay = new CargoDragon(mass);
        ControlCenter::instance().setBuild(pay, "Falcon9");
        Rocket* cargoFalcHeav = ControlCenter::instance().build();
        cout << "Cargo Dragon - Falcon Heavy Created!" << endl;
        runnyBoi(cargoFalcHeav);
    }else if(payload == "Starlink"){
        Starlink* pay = new Starlink();
        ControlCenter::instance().setBuild(pay, "Falcon9");
        Rocket* starFalcHeav = ControlCenter::instance().build();
        cout << "Starlink - Falcon Heavy Created!" << endl;
        runnyBoi(starFalcHeav);
    }else{
        cout << "wut" << endl;
    }
}



int main() {
    cout << endl << endl << "   .--::--===--<||  Main Running  ||>--===--::--." << endl <<endl;
    bool done = true;
    bool valid;
    int next;
    string temp1 = "";
    while(!done){
        valid = false;
        while(!valid){
            cout << "\nWhat type of rocket would you like to create? Finish = 0, Falcon9 = 1, FalconHeavy = 2, Starlink = 3 > ";
            cin >> temp1;
            stringstream intV(temp1);
            intV >> next;
            if(next >= 0 && next <= 3){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
        switch(next){
            case 0:
                done = true;
                break;
            case 1:
                Falcon9Sim();
                break;
            case 2:
                FalconHeavySim();
                break;
            case 3:
                StarlinkSim();
                break;
        }
    }
    //Main Testing

    Starlink* s = new Starlink();
    ControlCenter::instance().setBuild(s, "Falcon9");
    Rocket* starlinkR = ControlCenter::instance().build();
    cout << "Starlink Created!" << endl;

    //Command* c = new LaunchCommand(starlinkR);
    StarlinkSimulationAdapter* adapter = new StarlinkSimulationAdapter(s, starlinkR);
    adapter->launch();












    //MotorFactory* merlinFact = new MerlinFactory();
    //RocketMotor* yeet = merlinFact->createMotor();
    //cout << yeet->getChamberPressure();

    //Keelan testing his Builder and Strategy
    /*
    RocketBuilder* FHbuilder = new FalconHeavyBuilder();
    SpaceCraft* myPayload = nullptr;
    BuildStrategy* myStrat = new FullStackBuildStrategy(FHbuilder , myPayload);
    RocketBuilderDirector* director = new RocketBuilderDirector();

    director->setStrategy(myStrat);
    director->build();
    cout<<"Build successful!"<<endl;

    Rocket* TestRocket = FHbuilder->getRocket();
    for(int i = 0; i < TestRocket->getNumEngines(); i++)
    {
        cout<<"Thrust on engine " << i + 1 << " : " << TestRocket->getEngine(i)->getThrust(0) << endl;
    }

    TestRocket->Activate();
    delete director;
    //*/






    /*
    SpaceCraft* myPayload = new CrewDragon(2);
    //SpaceCraft* myPayload2 = new Satelite();

    //ControlCenter* myCC = ControlCenter::instance();
    //myCC->setBuild(myPayload);
    //myCC->build
    ControlCenter::instance().setBuild(myPayload, "FalconHeavy");//FullStack
    //ControlCenter::instance().setBuild(myPayload2, "Falcon9");//FUllStack
    //ControlCenter::instance().setBuild();//SingleStack - Falcon9
    Rocket* myRocket = ControlCenter::instance().build();

    myRocket->Activate();

    for(int i = 0; i < myRocket->getNumEngines(); i++)
    {
        cout<<"   Thrust on engine " << i + 1 << " : " << myRocket->getEngine(i)->getThrust(69) << endl;
    }

    delete myPayload;

    //*/
    return 0;
}
