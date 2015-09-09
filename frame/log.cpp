#include "log.h"

log::log()
{
 	this->flagPrintLog = false;
	this->logPath = "~/log/";		
}

void log::startService()
{
	this->flagPrintLog = true;		
	signal(SIGALARM,sigAlarmLog);
	alarm(1);
	
}

void log::stopService()
{
	this->flagPrintLog = false;	
}

void log::changeLevel()
{
	
}

void log::changePath(string strPath)
{
	if(NULL != strPath)
	{
		this->logPath = strPath;	
	}
	return;	
}

void log::sigAlarmLog()
{
	
}
