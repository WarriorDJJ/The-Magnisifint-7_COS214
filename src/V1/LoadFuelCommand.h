//
// Created by djjor on 2021-11-17.
//

#ifndef INC_214PROJECT_LOADFUELCOMMAND_H
#define INC_214PROJECT_LOADFUELCOMMAND_H
#include "Command.h"

class LoadFuelCommand:public Command {
protected:
public:
    //SpaceCraft* getReceiver();
    LoadFuelCommand(SpaceCraft* s);
    void execute();
    //Command(SpaceCraft* s);
};


#endif //INC_214PROJECT_LOADFUELCOMMAND_H
