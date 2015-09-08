#include "machine.h"
#include <iostream>

gcMachine::gcMachine()
{
	this->gcStatus = _machineStatus.init;	
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
	return _retValue.SUCCESS;
}

retValue gcMachine::initMotion()
{
	return _retValue.SUCCESS;
}


