#include "Bell.h"

using namespace std;
int Bell::getThrust(int a){
    return this->thrust;
}

Engine * Bell::clone() {
	// TODO - implement Bell::clone
	return Engine::clone();
}

Bell::Bell(int thrust, int len, int diameter) : Engine(thrust), len(len), diameter(diameter) {}


