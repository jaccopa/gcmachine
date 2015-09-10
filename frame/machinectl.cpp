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
	char funcname[50] = {0};
    const char * name = "gcMachine::working()";
	strcpy(funcname,name);
    if(loglvl(info) <= log::instance().getLogLevel())
        log::instance().writeLog("file:%s--function:%s---line:%d---[%s]",__FILE__,funcname,__LINE__,"gcMachine working");

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
    char funcname[50] = {0};
    const char *name = "main() ";
    const char *cause= "system starting";
	log::instance().startService();
	log::instance().changeLevel((loglvl)debug);
    strcpy(funcname,name);
    if(loglvl(info) <= log::instance().getLogLevel())
    {
        log::instance().writeLog("file:%s--function:%s---line:%d---[%s]",__FILE__,funcname,__LINE__,cause);
    }

	gcMachine *gc = new gcMachine();
    gc->working();
	delete gc;

    log::instance().stopService();
	cout << "OK" << endl;
	return 0;
}
