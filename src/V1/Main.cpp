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
#include "LoadFuelCommand.h"
#include <stdlib.h>     /* srand, rand */
#include <sstream>

bool isTested = false;

bool rStatus(int i){
    bool fail = false;
    switch (i) {
        case 0:
            //no errors
            cout<<"No Errors"<<endl;
            break;
        case 1:
            cout<<"Some Errors"<<endl;
            //some errors
            break;
        case 2:
            //critical failure
            cout<<"Critical Failure"<<endl;
            fail = true;
            break;
        case 3:
            //Explosion
            cout<<"Exploded"<<endl;
            fail = true;
            break;
    }
    return fail;
}

void Launch(Payload* s, Rocket* r){
    cout<<"launch Start:-------------------------------------------------------------------------------"<<endl;
    //vars
    Rocket * current;
    Rocket * nextS;
    vector<SpaceCraft*> seperated;
    current = r;

    Command* launch = new LaunchCommand(s,r);
    Command* fuel = new LoadFuelCommand(s,r);
    Invoker* launchButton = new Invoker(launch);
    Invoker* fuelButton = new Invoker(fuel);
    //fuel->execute();
    //launch->execute();

    fuelButton->press();
    launchButton->press();
    isTested = true;

    //cout<<"loop-------------------"<<endl;
    //current->LoadFuel();
    //current->Activate();
    /*Rocket* temp = r->clone();
    while(temp->GetNextStage() != nullptr){
        temp = dynamic_cast<Rocket*>(r->GetNextStage());
        Command* test = new LaunchCommand(s, temp);
        if(test->getState()->checkState() == "Untested"){
            Invoker* buton = new Invoker(test);
            buton->press();
        }
    }*/

    cout<<"Launch:\t";
    int countdown = 11;
    while (countdown>0){
        countdown--;
        cout<<"T-"<<countdown<<"\t";
    }
    cout<<endl;
    current->Activate();

    //here
    double pressure = 101325;
    cout << "Current Thrust: "<<current->getThrust(pressure)<<endl;

    int rstatus1 = current->getStatusCode();
    if(!rStatus(rstatus1)) {
        while (current != nullptr) {
            while (current->GetFuel() > 11) {
                current->useFuel(10);
            }
            //stage seperation

            nextS = dynamic_cast<Rocket *>(r->GetNextStage());
            seperated.push_back(current->SeperateStage());

            current = nextS;

            Command *launch = new LaunchCommand(s, current);
            Invoker *launchButton = new Invoker(launch);
            if (current != nullptr && current != current->GetNextStage()) {
                current->Activate();
                pressure = pressure/2;
                cout << "Current Thrust: "<<current->getThrust(pressure)<<endl;
                //launchButton->press();
            }
        }

        /*
        //==================================================================================================================
        cout<<"Would you like to edit the rocket? y/n>"<<endl;
        string edit;
        cin>>edit;
        if (edit == "y")
        {
            Rocket* tempHolder = r;
            Rocket* myNewRocket;

            cout<<"Change payload: 0 = Cargo Dragon, 1 = Crew Dragon, 2 = StarLink"<<endl;
            string editPayload;
            cin>>editPayload;

            delete s;
            if (editPayload == "0")
            {
                string temp1;
                double mass;
                bool valid = false;
                while(!valid){
                    cout << "\nHow much does the cargo weigh(kg)? \n> ";
                    cin >> temp1;
                    stringstream intV(temp1);
                    intV >> mass;
                    if(mass > 0){
                        valid = true;
                    }else{
                        cout << "Invalid Choice!" << endl;
                    }
                }
                s = new CargoDragon(mass);
            } else if (editPayload == "1")
            {
                string temp1;
                int next;
                bool valid = false;
                while(!valid){
                    cout << "\nHow many crew members (Min: 2, Max: 4)? \n> ";
                    cin >> temp1;
                    stringstream  intV(temp1);
                    intV >> next;
                    if(next >= 2 && next <= 4){
                        valid = true;
                    }else{
                        cout << "Invalid Choice!" << endl;
                    }
                }
                s = new CrewDragon(next);
            } else
            {
                s = new Starlink();
            }

            cout<<"Change rocket: 0 = Falcon9, 1 = Falcon Heavy"<<endl;
            string editRocket;
            cin>>editRocket;

            if (editRocket == "0")
            {
                ControlCenter::instance().setBuild(s, "Falcon9");
                myNewRocket = ControlCenter::instance().build();
            } else
            {
                ControlCenter::instance().setBuild(s, "FalconHeavy");
                myNewRocket = ControlCenter::instance().build();
            }
            delete r;
            r = myNewRocket;
        }

        //==================================================================================================================
        */

        r->Activate();
        cout << "Current Thrust: "<<r->getThrust(pressure)<<endl;

        if (r->getStatusCode() < 2) {
            cout << "Booster landed safely back on earth." << endl;
        } else {
            cout << "Booster unfortunately missed the landing pad and exploded." << endl;
        }

        s->Activate();
        cout << "Launch completed!" << endl;
    }
}
int Save(Payload* s, Rocket* r){
    Command* launch = new LaunchCommand(s, r);
    return ControlCenter::instance().storeSim(launch->getState(), launch->getPayload());
}


void LaunchSim(Payload* p, Rocket *r){
    cout << "Storing Spacecraft: " << endl;
    int index = Save(p, r);
    Launch(p, r);
    cout << "Retrieving Backup: " << endl;
    p = ControlCenter::instance().getSimPayload(index);
    r = ControlCenter::instance().getSimState(index)->getRocket();
}

void TestMode(Payload *p, Rocket *r){
    cout << "Storing Spacecraft: " << endl;
    int index = Save(p, r);
    cout<<"launch Start:-------------------------------------------------------------------------------"<<endl;
    //vars
    Rocket * current;
    Rocket * nextS;
    vector<SpaceCraft*> seperated;
    current = r;

    Command* launch = new LaunchCommand(p,r);
    Command* fuel = new LoadFuelCommand(p,r);
    Invoker* launchButton = new Invoker(launch);
    Invoker* fuelButton = new Invoker(fuel);
    //fuel->execute();
    //launch->execute();

    fuelButton->press();
    launchButton->press();
    isTested = true;

    //cout<<"loop-------------------"<<endl;
    //current->LoadFuel();
    //current->Activate();
    /*Rocket* temp = r->clone();
    while(temp->GetNextStage() != nullptr){
        temp = dynamic_cast<Rocket*>(r->GetNextStage());
        Command* test = new LaunchCommand(s, temp);
        if(test->getState()->checkState() == "Untested"){
            Invoker* buton = new Invoker(test);
            buton->press();
        }
    }*/

    cout<<"Launch:\t";
    int countdown = 11;
    while (countdown>0){
        countdown--;
        cout<<"T-"<<countdown<<"\t";
    }
    cout<<endl;
    current->Activate();
    while (current != nullptr) {
        while (current->GetFuel() > 11) {
            current->useFuel(10);
        }
        //stage seperation

        nextS = dynamic_cast<Rocket *>(r->GetNextStage());
        seperated.push_back(current->SeperateStage());

        current = nextS;

        Command* launch = new LaunchCommand(p, current);
        Invoker* launchButton = new Invoker(launch);
        if(current != nullptr && current != current->GetNextStage()){
            current->Activate();
            //launchButton->press();
        }
    }

    //==================================================================================================================
    cout<<"Would you like to edit the rocket? y/n>"<<endl;
    string edit;
    cin>>edit;
    if (edit == "y")
    {
        Rocket* tempHolder = r;
        Rocket* myNewRocket;

        cout<<"Change payload: 0 = Cargo Dragon, 1 = Crew Dragon, 2 = StarLink"<<endl;
        string editPayload;
        cin>>editPayload;

        delete p;
        if (editPayload == "0")
        {
            string temp1;
            double mass;
            bool valid = false;
            while(!valid){
                cout << "\nHow much does the cargo weigh(kg)? \n> ";
                cin >> temp1;
                stringstream intV(temp1);
                intV >> mass;
                if(mass > 0){
                    valid = true;
                }else{
                    cout << "Invalid Choice!" << endl;
                }
            }
            p = new CargoDragon(mass);
        } else if (editPayload == "1")
        {
            string temp1;
            int next;
            bool valid = false;
            while(!valid){
                cout << "\nHow many crew members (Min: 2, Max: 4)? \n> ";
                cin >> temp1;
                stringstream  intV(temp1);
                intV >> next;
                if(next >= 2 && next <= 4){
                    valid = true;
                }else{
                    cout << "Invalid Choice!" << endl;
                }
            }
            p = new CrewDragon(next);
        } else
        {
            p = new Starlink();
        }

        cout<<"Change rocket: 0 = Falcon9, 1 = Falcon Heavy"<<endl;
        string editRocket;
        cin>>editRocket;

        if (editRocket == "0")
        {
            ControlCenter::instance().setBuild(p, "Falcon9");
            myNewRocket = ControlCenter::instance().build();
        } else
        {
            ControlCenter::instance().setBuild(p, "FalconHeavy");
            myNewRocket = ControlCenter::instance().build();
        }
        delete r;
        r = myNewRocket;
    }

    //==================================================================================================================

    r->Activate();

    if (r->getStatusCode() < 2) {
        cout << "Booster landed safely back on earth." << endl;
    } else
    {
        cout << "Booster unfortunately missed the landing pad and exploded." << endl;
    }

    p->Activate();
    cout<<"Launch completed!"<<endl;
    string out;
    cout << "Would you like to retrieve from the backup? y/n > ";
    cin >> out;
    if(out == "y"){
        cout << "Retrieving Backup: " << endl;
        p = ControlCenter::instance().getSimPayload(index);
        r = ControlCenter::instance().getSimState(index)->getRocket();
    }
}


//hi suh dud our ce ayyy gay, yes
                          //the person reading our comments be like 0.0
//still better than our readme lol
void runnyBoi(Payload* s, Rocket* r){
    bool valid;
    int next;
    string temp1 = "";
    valid = false;
    bool done = false;
    while(!done){
        while(!valid){
            cout << "\nWhat type of launch would you like to do with your rocket? Test Mode = 0, Launch Sim = 1, Actual Launch = 2, Save it for later = 3, Exit = 4 > ";
            cin >> temp1;
            stringstream intV(temp1);
            intV >> next;
            if(next >= 0 && next <= 4){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
        switch(next){
            case 0:
                TestMode(s,r);
                valid = false;
                break;
            case 1:
                LaunchSim(s,r);
                valid = false;
                break;
            case 2:
                Launch(s, r);
                done = true;
                break;
            case 3:
                cout << "Rocket saved at index " << Save(s, r) << ". REMEMBER THIS INDEX TO REFERENCE IT LATER" << endl;
                done = true;
            case 4:
                done = true;
        }
    }
}

void loadRocket(){
    bool valid;
    int next;
    string temp1 = "";
    valid = false;
    bool done = false;
    while(!valid){
        cout << "\nEnter the index of the rocket you would like to retrieve > (-1 to cancel)";
        cin >> temp1;
        stringstream intV(temp1);
        intV >> next;
        if(next == -1){
            return;
        }
        else if(next < -1){
            cout << "Invalid Choice!" << endl;
        }
        else{
            if(ControlCenter::instance().getSimState(next) != nullptr){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
    }
    runnyBoi(ControlCenter::instance().getSimPayload(next), ControlCenter::instance().getSimState(next)->getRocket());
}



void StarlinkSim(){
    cout << "Starlink" << endl;
    Starlink* s = new Starlink();
    ControlCenter::instance().setBuild(s, "Falcon9");
    Rocket* starlink = ControlCenter::instance().build();
    cout << "Starlink Created!";
    runnyBoi(s, starlink);
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
            cout << "\nWhat type of payload would you like to create? Crew Dragon = 0, Cargo Dragon = 1, Starlink = 2 >";
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
                cout << "\nHow many crew members (Min: 2, Max: 4)? \n> ";
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
            cout << ".--::--===--<||  Crew Dragon - Falcon9 Created!  ||>--===--::--." << endl;
            runnyBoi(pay, crewFalc9);
        }else if(payload == "Cargo"){
            double mass;
            valid = false;
            while(!valid){
                cout << "\nHow much does the cargo weigh(kg)? \n> ";
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
            cout << ".--::--===--<||  Cargo Dragon - Falcon9 Created!  ||>--===--::--." << endl;
            runnyBoi(pay, cargoFalc9);
        }else if(payload == "Starlink"){
            Starlink* pay = new Starlink();
            ControlCenter::instance().setBuild(pay, "Falcon9");
            Rocket* starFalc9 = ControlCenter::instance().build();
            cout << ".--::--===--<||  Starlink - Falcon9 Created!  ||>--===--::--." << endl;
            runnyBoi(pay, starFalc9);
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
        ControlCenter::instance().setBuild(pay, "FalconHeavy");
        Rocket* crewFalcHeav = ControlCenter::instance().build();
        cout << ".--::--===--<||  Crew Dragon - Falcon Heavy Created!  ||>--===--::--." << endl;
        runnyBoi(pay, crewFalcHeav);
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
        ControlCenter::instance().setBuild(pay, "FalconHeavy");
        Rocket* cargoFalcHeav = ControlCenter::instance().build();
        cout << ".--::--===--<||  Cargo Dragon - Falcon Heavy Created!  ||>--===--::--." << endl;
        runnyBoi(pay, cargoFalcHeav);
    }else if(payload == "Starlink"){
        Starlink* pay = new Starlink();
        ControlCenter::instance().setBuild(pay, "FalconHeavy");
        Rocket* starFalcHeav = ControlCenter::instance().build();
        cout << ".--::--===--<||  Starlink - Falcon Heavy Created!  ||>--===--::--." << endl;
        runnyBoi(pay, starFalcHeav);
    }else{
        cout << "wut" << endl;
    }
}



int main() {
    cout << endl << endl << "                ..________________.."
                 << endl << "   .--::--===--<||  Main Running  ||>--===--::--." << endl <<endl;
    bool done = false;
    bool valid;
    int next;
    string temp1 = "";
    while(!done){
        valid = false;
        while(!valid){
            cout << "\nWhat type of rocket would you like to create? Finish = 0, Falcon9 = 1, FalconHeavy = 2, Starlink = 3, Load Rocket = 4 > ";
            cin >> temp1;
            stringstream intV(temp1);
            intV >> next;
            if(next >= 0 && next <= 4){
                valid = true;
            }else{
                cout << "Invalid Choice!" << endl;
            }
        }
        valid = false;
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
            case 4:
                loadRocket();
                break;
        }
    }
    //Main Testing

    //Starlink* s = new Starlink();
    //ControlCenter::instance().setBuild(s, "Falcon9");
    //Rocket* starlinkR = ControlCenter::instance().build();
    //cout << ".--::--===--<||  Starlink Created!  ||>--===--::--." << endl << endl;

    //Command* c = new LaunchCommand(starlinkR);
    //StarlinkSimulationAdapter* adapter = new StarlinkSimulationAdapter(s, starlinkR);
    //adapter->launch();
    //Payload* p = new CrewDragon(2);

    //ControlCenter::instance().setBuild(p, "FalconHeavy");
    //Rocket* crewDragFalc9 = ControlCenter::instance().build();

//    RocketBuilder* FHbuilder = new FalconHeavyBuilder();
//    RocketBuilder* F9Builder = new FalconBuilder();
//    SpaceCraft* myPayload = new CrewDragon(2);
//    BuildStrategy* myStrat1 = new FullStackBuildStrategy(FHbuilder , myPayload);
//    BuildStrategy* myStrat2 = new FullStackBuildStrategy(F9Builder , myPayload);
//
//    RocketBuilderDirector* director1 = new RocketBuilderDirector();
//    RocketBuilderDirector* director2 = new RocketBuilderDirector();
//
//    director1->setStrategy(myStrat1);
//    director2->setStrategy(myStrat2);
//    director1->build();
//    director2->build();
//    cout<<"Build successful!"<<endl;
//    Rocket* crewDragFalc9 = FHbuilder->getRocket();
//    Rocket* crewDragFalc92 = F9Builder->getRocket();

    //Command* c = new LaunchCommand(p,crewDragFalc9);
    //Invoker* launchButton = new Invoker(c);
    //Command* load = new LoadFuelCommand(p, crewDragFalc9);
    //Invoker* loadButton = new Invoker(load);
    //loadButton->press();
    //launchButton->press();
    //TestMode(p, crewDragFalc9);
   // Launch(p, crewDragFalc9);

    //StarlinkSim();

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
