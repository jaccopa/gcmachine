#include "log.h"

FILE *g_logFile = NULL;


log::log()
{
 	this->flagPrintLog = false;
	this->logPath	   = "~/log/";		
	this->loglevel	   = (loglvl)err;
}

log::~log()
{
}

bool log::startService()
{
	if(true == this->flagPrintLog)
	{
		cout << "logService Aready Strated!!!" << endl;	
		return true;
	}
	this->flagPrintLog = true;		
	return true;	
}

void log::stopService()
{
	this->flagPrintLog = false;	
}

void log::changeLevel(loglvl lv)
{
	this->loglevel = (loglvl)lv;				
}

void log::changePath(string strPath)
{
	this->logPath = strPath;	
	return;	
}

loglvl log::getLogLevel()
{
	return this->loglevel;	
}

/*
void log::sigAlarmLog(loglvl lvl,string logmsg)
{
	if(true == this->flagPrintLog)
	{
		if(this->getLogLevel() >= lvl)
		{
		cout << logmsg				  << endl;
		cout << "logfunction test!!!" << endl;
		}
	}
	else
	{
		cout << "logfunction closed!!!" << endl;
	}
	return;	
}
*/


void writeLog(char *fmt, ...)
{
	va_list args;
	static char logStr[MAX_BUFSIZE] = {0};
	
	va_start(args, fmt);
	vsprintf(logStr, fmt, args);
	va_end(args);			
	
	writeFile(g_logFile, logStr, 1);
}

#ifdef WIN32
#include <windows.h>
int getCurFilePath(char *lpOut)
{
	char chPath[MAX_BUFSIZE] = {0};
}	
