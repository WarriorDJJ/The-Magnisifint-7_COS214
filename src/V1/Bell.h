#ifndef BELL_H
#define BELL_H

#include "Engine.h"

class Bell : public Engine {

private:
	int len;
	int diameter;
	Engine motor;

public:
	int getThrust(int a);

	void clone();
};

#endif
