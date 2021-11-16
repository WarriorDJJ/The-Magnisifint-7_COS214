#ifndef BELL_H
#define BELL_H

class Bell : Engine {

private:
	int len;
	int diameter;
	Engine motor;

public:
	int getThrust(int a);

	void clone();
};

#endif
