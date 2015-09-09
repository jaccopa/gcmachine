#include "machine.h"
#include <iostream>
using namespace::std;

gcMachine::gcMachine()
{
	this->gcStatus = (machineStatus)init;
}

gcMachine::~gcMachine()
{
}

void rebootSystem()
{
	cout << "rebootSystem" << endl;
}

retValue gcMachine::initWater()
{
	return SUCCESS;
}

retValue gcMachine::initMotion()
{
	return SUCCESS;
}

void gcMachine::working()
{
	machineStatus ms = (machineStatus)gcStatus;
	switch(ms)
	{
		case init:
			if(FAIL == this->initWater())
			{
				cout << "initWaterFailed" << endl;
			}		
			else
			{
				cout << "initWaterSuccess" << endl;
			}

			if(FAIL == this->initMotion())
			{
				cout << "initMotionFailed" << endl;
			}		
			else
			{
				cout << "initMotionSuccess" << endl;
			}

		case work:
		break;
		
		default:
		break;
	}	
}

int main()
{
	gcMachine *gc = new gcMachine();
	gc->working();						
	delete gc;
	cout << "OK" << endl;
	return 0;
}
