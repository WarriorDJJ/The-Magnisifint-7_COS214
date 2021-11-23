#include "Rocket.h"

Rocket::Rocket(string name, double length, double diameter, double wetMass, double dryMass) : Rocket(){
    this->length = length;
    this->diameter = diameter;
    this->wetMass = wetMass;
    this->dryMass = dryMass;
    this->name = name;
}

Rocket::Rocket(){
    this->rocketState = "untested";
    this->EnginesFailed = 0;
    this->statusCode = 0;
    this->isFinalStage = false;
    this->NextStage = nullptr;

    this->length = 0;
    this->diameter = 0;
    this->wetMass = 0;
    this->dryMass = 0;

}

void Rocket::DestroyRocket()
{
    //Todo
    for(int i=0;i<engines.size();i++)
    {
        RemoveEngine(engines[i]);
    }
}

string Rocket::getName()
{
    return this->name;
}

void Rocket::Activate() {
    cout<<name<<":"<<endl;
	for(int i=0;i<engines.size();i++){
        cout<<"\t"<< to_string(i+1) + ": ";
        engines[i]->StartEngine();
    }
}

Rocket * Rocket::clone() {
	Rocket * newRocket = new Rocket(this->name, this->length, this->diameter, this->wetMass, this->dryMass);

    for (int i=0;i<engines.size();i++){
        Engine * newEngine = engines[i]->clone();
        newEngine->setSpacecraft(newRocket);
        newRocket->AddEngine(newEngine);
    }

    if(this->NextStage!=nullptr){
        newRocket->NextStage = this->NextStage->clone();
    }

    return newRocket;
}

void Rocket::AddStage(SpaceCraft *s) {
    this->NextStage = s;
}

Rocket * Rocket::SeperateStage() {
    NextStage = nullptr;
    cout<<"Stage Decoupled: "<< this->getName() <<endl;
    return this;
}

SpaceCraft * Rocket::GetNextStage() {
    return NextStage;
}

SpaceCraft * Rocket::GetNextStageMain() {
    return NextStage;
}

void Rocket::LoadFuel() {
    this->fuel = 100;
    cout << "Loading in Fuel onto "<< getName() << endl;
    if(NextStage != nullptr) NextStage->LoadFuel();
}

double Rocket::GetFuel() {
    return fuel;
}

void Rocket::VentFuel() {
    this->fuel = 0;
    cout << "Venting Fuel from "<< getName() << endl;
    if(NextStage != nullptr) NextStage->VentFuel();
}

void Rocket::notify(Engine * engine) {
    if(engine->isFail()){
        this->EnginesFailed++;

        int rand1 = rand() % 100 + 1;
        if(rand1 >=50 && rand1 <=100){
            statusCode = 3;//Explodes
        }
    }

    if(statusCode != 3) {
        if (EnginesFailed > 0) {
            statusCode = 1;
        } else if (EnginesFailed >= 0.5 * getNumEngines()) {
            statusCode = 2;
        }
    }
}

void Rocket::AddEngine(Engine *engine) {
    engines.push_back(engine);
}

void Rocket::RemoveEngine(Engine * engine) {
    vector<Engine*>::iterator ptr;
    for (ptr = engines.begin(); ptr < engines.end(); ptr++){
        if(*ptr==engine){
            engines.erase(ptr);
        }
    }
}

Engine * Rocket::getEngine(int i){
    if(i>=0 && i<getNumEngines()){
        return engines.at(i);
    }
    else return nullptr;
}

int Rocket::getNumEngines() {
    return engines.size();
}

Rocket::~Rocket() {
    delete this->NextStage;
}

void Rocket::appendStage(SpaceCraft *s) {
    if(this->GetNextStage() != nullptr)
    {

        this->GetNextStage()->appendStage(s);
    }
    else
    {
        this->AddStage(s);
    }
}

double Rocket::getThrust(double externalPressure) {
    double thrust = 0;
    for(int i=0;i<engines.size();i++){
        thrust += engines[i]->getThrust(externalPressure);
    }
    return thrust;
}
