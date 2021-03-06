#ifndef machine_h
#define machine_h

#include "log.h"


typedef enum _machineStatus
{
	init,
	work,
}machineStatus;

typedef enum _retValue
{
	FAIL,
	SUCCESS,
}retValue;

class gcMachine:public Singleton<gcMachine>
{
public:
    machineStatus gcStatus;

	void rebootSystem();
    void working();

    bool flagOfInitWaterSuccess;
    bool flagOfInitMotionSuccess;
//protect:

private:
    gcMachine();
    ~gcMachine();

    retValue initWater();
    retValue initMotion();
    friend class Singleton<gcMachine>;
};



#endif
