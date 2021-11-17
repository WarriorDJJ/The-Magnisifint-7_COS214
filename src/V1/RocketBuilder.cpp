#include "RocketBuilder.h"

Rocket* RocketBuilder::getRocket() {
	return this->rocket;
}

void RocketBuilder::attachPayload(SpaceCraft* p) {
	rocket->AddStage(p);
}
