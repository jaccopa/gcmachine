#include "machine.h"
#include <iostream>
#include "comm.h"
using namespace::std;

gcMachine::gcMachine()
{
    this->gcStatus                = (machineStatus)init;
    this->flagOfInitMotionSuccess = false;
    this->flagOfInitWaterSuccess  = false;
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
    char funcname[50] = {0};
    const char * name = "gcMachine::initWater()";
    strcpy(funcname,name);
    if(true == LOGTRACE(info))
    {
        log::instance().writeLog("file:%s--function:%s---line:%d---[%s]",__FILE__,funcname,__LINE__,"entering gcMachine::initWater()");
    }

	return SUCCESS;
}

retValue gcMachine::initMotion()
{
    char funcname[50] = {0};
    const char * name = "gcMachine::initMotion()";
    strcpy(funcname,name);
    if(true == LOGTRACE(info))
    {
        log::instance().writeLog("file:%s--function:%s---line:%d---[%s]",__FILE__,funcname,__LINE__,"entering gcMachine::initWater()");
    }


	return SUCCESS;
}

void gcMachine::working()
{
	char funcname[50] = {0};
    const char * name = "gcMachine::working()";
	strcpy(funcname,name);
    if(true == LOGTRACE(info))
    {
        log::instance().writeLog("file:%s--function:%s---line:%d---[%s]",__FILE__,funcname,__LINE__,"entering gcMachine::working()");
    }

	machineStatus ms = (machineStatus)gcStatus;
	switch(ms)
	{
		case init:
            if(true == LOGTRACE(debug))
            {
                log::instance().writeLog("file:%s-----line:%d---[%s]",__FILE__,__LINE__,"entering gcMachine state--init !!!");
            }

            if(false == flagOfInitWaterSuccess)
            {
                if(FAIL == this->initWater())
                {
                    flagOfInitWaterSuccess = false;
                    cout << "initWaterFailed" << endl;
                    if(true == LOGTRACE(err))
                    {
                        log::instance().writeLog("file:%s-----line:%d---[%s]",__FILE__,__LINE__,"initWaterFailed!!!");
                    }
                }
                else
                {
                    flagOfInitWaterSuccess = true;
                    cout << "initWaterSuccess" << endl;
                    if(true == LOGTRACE(debug))
                    {
                        log::instance().writeLog("file:%s-----line:%d---[%s]",__FILE__,__LINE__,"initWaterSuccess!!!");
                    }
                }
            }

            if(false == flagOfInitMotionSuccess)
            {
                if(FAIL == this->initMotion())
                {
                    flagOfInitMotionSuccess = false;
                    cout << "initMotionFailed" << endl;
                    if(true == LOGTRACE(debug))
                    {
                        log::instance().writeLog("file:%s-----line:%d---[%s]",__FILE__,__LINE__,"initMotionFailed!!!");
                    }
                }
                else
                {
                    flagOfInitMotionSuccess = true;
                    cout << "initMotionSuccess" << endl;
                    if(true == LOGTRACE(debug))
                    {
                        log::instance().writeLog("file:%s-----line:%d---[%s]",__FILE__,__LINE__,"initMotionSuccess!!!");
                    }
                }
            }

            if(false == flagOfInitWaterSuccess && flagOfInitMotionSuccess)
            {
                gcMachine::instance().gcStatus = (machineStatus)init;
                gcMachine::instance().working();
            }
            else
            {
                gcMachine::instance().gcStatus = (machineStatus)work;
                gcMachine::instance().working();
            }
        break;

		case work:
            if(true == LOGTRACE(debug))
            {
                log::instance().writeLog("file:%s-----line:%d---[%s]",__FILE__,__LINE__,"entering gcMachine state--work !!!");
            }
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
    log::instance().writeLog("file:%s--function:%s---line:%d---[%s]",__FILE__,funcname,__LINE__,cause);

    gcMachine::instance().gcStatus = (machineStatus)init;
    gcMachine::instance().working();

    log::instance().stopService();
	cout << "OK" << endl;
	return 0;
}
