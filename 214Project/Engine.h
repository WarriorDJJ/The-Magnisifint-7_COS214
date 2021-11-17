#ifndef ENGINE_H
#define ENGINE_H

class Engine {
protected:
    int thrust;
public:
    Engine(int thrust);
    virtual int getThrust(int a);
	virtual Engine * clone();
};

#endif
