#ifndef machine_h
#define machine_h

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

class gcMachine
{
public:
	machineStatus gcStatus;

	void rebootSystem();
	void working();
//protect:
	gcMachine();
	~gcMachine();

private:
	retValue initWater();
	retValue initMotion(); 

};

#endif
