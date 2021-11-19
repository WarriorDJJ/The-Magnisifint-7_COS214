#include "StandardBell.h"

double StandardBell::getThrust(double externalPressure) {
    return Nozzle::getThrust(externalPressure);
}

StandardBell *StandardBell::clone() {
    StandardBell * temp = new StandardBell();
    temp->motor = this->motor->clone();

    temp->diameter = this->diameter;
    temp->length = this->length;
    temp->nozzleArea = this->nozzleArea;
    temp->throatArea = this->throatArea;
    return temp;
}
