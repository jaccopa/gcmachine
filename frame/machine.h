#ifndef machine_h
#define machine_h

typedef enum _machineStatus
{
	init,
	working,
}machineStatus;

typedef enum _retValue
{
	FAIL,
	SUCCESS,
}retValue;

class gcMachine
{
public:
	void rebootSystem();
protect:
	gcMachine();
	~gcMachine();

private:
	retValue initWater();
	retValue initMotion(); 

	static machineStatus gcStatus;
}
