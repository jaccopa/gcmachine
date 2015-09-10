#include "log.h"

FILE *g_logFile = NULL;


log::log()
{
 	this->flagPrintLog = false;
	this->logPath	   = "~/log/";		
	this->loglevel	   = (loglvl)err;
    this->logCount     = 0;
}

log::~log()
{
}

bool log::startService()
{
    char fname[20]                  = {0};
    char temp[16]                   = {0};

    this->getTime(temp,TIME_FORMAT_FILENAME);
    sprintf(fname,"%s.log",temp);
    g_logFile = this->openFile(fname,"a+");

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

    if(NULL != g_logFile)
        this->closeFile(g_logFile);
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
		}
	}
	else
	{
		cout << "logfunction closed!!!" << endl;
	}
	return;	
}
*/

void log::writeLog(const char *fmt, ...)
{
    char fname[20]                  = {0};
    char temp[16]                   = {0};
	static char logStr[MAX_BUFSIZE] = {0};
    va_list args;

	va_start(args, fmt);
	vsprintf(logStr, fmt, args);
	va_end(args);			
	
    if(this->logCount >= 50000)
    {
        this->logCount = 0;
        this->closeFile(g_logFile);
        this->getTime(temp,TIME_FORMAT_FILENAME);
        sprintf(fname,"%s.log",temp);
        g_logFile = this->openFile(fname,"a+");
    }

	writeFile(g_logFile, logStr, 1);
}

#ifdef WIN32
#include <windows.h>
int log::getCurFilePath(char *lpOut)
{
	char chPath[MAX_BUFSIZE] = {0};
	int len = GetModuleFileName(NULL, chPath, MAX_BUFSIZE);
	if(len > 0)
	{
		strcpy(lpOut, chPath);
		return 1;
	}
	return 0;
}


int log::getCurDir(char *lpOutDir)				// get directory-path of current executable-file
{
	char chPath[MAX_BUFSIZE] = {0};
	char drive[4] = {0}, subdir[MAX_BUFSIZE] = {0}, fn[MAX_BUFSIZE] = {0}, ext[MAX_BUFSIZE] = {0};
	
	if(getCurFilePath(chPath) > 0)
	{
		_splitpath(chPath, drive, subdir, fn, ext);
		sprintf(lpOutDir, "%s%s", drive, subdir);
		return 1;
	}
	return 0;
}
#else
int log::getCurFilePath(char *lpOut)				// get full path of the executable file
{
	char chPath[MAX_BUFSIZE] = {0};
	int len = readlink("/proc/self/exe", chPath, sizeof(chPath)); // get full path of the current-executable file
	if(len >= 0)
	{
		strcpy(lpOut, chPath);
		return 1;
	}
	return 0;
}

int log::getCurDir(char *lpOutDir)				// get directory-path of current executable-file
{
	char chPath[MAX_BUFSIZE] = {0};
	if( getCurFilePath(chPath) > 0 )
	{
        //dirname(chPath);						// dirname will change value of "chPath"(contain result)
		strcpy(lpOutDir, chPath);				// copy result to out-param
		return 1;
	}

	return 0;
}
#endif

/*
	功能：		获取当前系统时间
	返回值：	0-成功，-1-失败
	out:		保存返回的系统时间，格式由fmt决定
	fmt:		0-返回：yyyy-mm-dd hh24:mi:ss, 1-返回：yyyy-mm-dd, 2-返回：hh24:mi:ss
*/
int log::getTime(char *out, int fmt)				// 获取当前系统时间
{
	time_t t;
	struct tm *tp;
    struct timeval tv;

	if(out == NULL)
		return -1;

	t = time(NULL);
	tp = localtime(&t);
    gettimeofday(&tv,NULL);
	if(fmt == TIME_FORMAT_DATETIME)
        sprintf(out, "%02d/%02d/%02d %02d:%02d:%02d %ld", tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec,tv.tv_usec/1000);
	else if(fmt == TIME_FORMAT_DATE)
		sprintf(out, "%02d/%02d/%02d", tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday);
	else if(fmt == TIME_FORMAT_TIME)
		sprintf(out, "%02d:%02d:%02d", tp->tm_hour, tp->tm_min, tp->tm_sec);
	else if(fmt == TIME_FORMAT_FILENAME)
		sprintf(out, "%02d%02d%02d_%02d%02d%02d", tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
	return 0;
}

FILE* log::openFile(const char *fileName, const char *mode)	// 打开文本文件
{
	FILE *fp = fopen(fileName, mode);
	return fp;
}

/*
	功能：		将str写入到文件
	返回值：	写文件成功返回0,否则返回-1
	fp:		文件指针
	str:		待写入的字符串
	bLog:		1-是日志文件，0-不是日志文件
	说明：		如果是日志文件，将会在str前加上当前时间(格式如：2011-04-12 12:10:20)
*/
int log::writeFile(FILE *fp, const char *str, int bLog)			// 写字符串到文件,bLog表明是否为日志文件
{
	char curTime[MAX_BUFSIZE] = {0};
	int ret = -1;
	if(bLog) // 获取当前系统时间
	{
		getTime(curTime, 0);
		ret = fprintf(fp, "[%s] %s\n", curTime, str);
	}
	else
		ret = fprintf(fp, "%s\n", str);

	if(ret >= 0)
	{
		fflush(fp);
        this->logCount++;
		return 0; 				// 写文件成功
	}
	else
		return -1;
}

int log::closeFile(FILE *fp)
{
	return fclose(fp);
}
