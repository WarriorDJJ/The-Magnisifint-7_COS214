#include "RocketBuilderDirector.h"


RocketBuilderDirector::RocketBuilderDirector() {

}

void RocketBuilderDirector::setStrategy(BuildStrategy* s) {
    strategy = nullptr;
	this->strategy = s;
}

void RocketBuilderDirector::build() {
	strategy->build();
}
