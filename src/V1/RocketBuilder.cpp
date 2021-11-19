#include "RocketBuilder.h"

Rocket* RocketBuilder::getRocket() {
	return this->rocket;
}

void RocketBuilder::attachPayload(SpaceCraft* p) {
	rocket->appendStage(p);
}

void RocketBuilder::appStage(SpaceCraft *s) {
    rocket->appendStage(s);
}
