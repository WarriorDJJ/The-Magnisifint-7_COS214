#ifndef PAYLOAD_H
#define PAYLOAD_H

#include "SpaceCraft.h"

class Payload : public SpaceCraft {


public:
	virtual void Activate();
	virtual Payload * clone();
};

#endif
