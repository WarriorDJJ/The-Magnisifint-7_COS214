#include "SingleRocketBuildStrategy.h"

SingleRocketBuildStrategy::SingleRocketBuildStrategy(RocketBuilder *b) {
    builder = b;
}

void SingleRocketBuildStrategy::build() {
    builder->createRocket();
    builder->createEngines();
}
