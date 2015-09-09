#include "machine.h"
#include <iostream>
#include "comm.h"
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
	string msg;
	msg        += "__gcMachine::working()__";
	msg		   += "__FILE__";
	msg		   += __FILE__;
	msg		   += "__LINE__";
	msg		   += __LINE__;	
	log::instance().sigAlarmLog((loglvl)debug,msg);
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
	log::instance().startService();
	log::instance().changeLevel((loglvl)debug);
	gcMachine *gc = new gcMachine();
	gc->working();						
	delete gc;
	cout << "OK" << endl;
	return 0;
}
