#ifndef FALCON9TS_H
#define FALCON9TS_H

#include "TestStrat.h"

class Falcon9TS : public TestStrat {


public:
	void launch() override;

	void staticTest() override;
};

#endif
