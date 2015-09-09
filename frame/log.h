#ifndef log_h
#define log_h

#include <iostream>
#include <string>
#include <unistd.h>
#include <signal.h>
using namespace std;

#define MAX_BUFSIZE 250

enum TimeForMat
{
	TIME_FORMAT_DATETIME,
	TIME_FORMAT_TIME,
	TIME_FORMAT_DATE,
	TIME_FORMAT_FILENAME
}

template <class T>
class Singleton
{
public:
	static T& instance()
	{
		static T _instance;
		return _instance;
	}

protected:
	Singleton(void){}
	virtual ~Singleton(void){}
	Singleton(const Singleton<T>&);
	Singleton<T>& operator=(const Singleton<T>&);
};

typedef enum _loglevel
{
	err,
	warning,
	info,
	debug,
}loglvl; 

class log:public Singleton<log>
{
public:
	bool 	startService();
	void 	stopService();
	void 	changeLevel(loglvl);	
	void 	changePath(string);
	//void    sigAlarmLog(loglvl lvl,string logmsg);	
	void 	writeLog(char *fmt,...);
	loglvl  getLogLevel();
	
private:
	log();
	~log();

	int		getCurFilePath(char *lpOut);
	int		getCurDir(char *lpOutDir);		
	int 	getTime(char *out,int fmt);
	int		writeFile(FILE *fp,const char *str,int bLog);
	int		closeFile(FILE *fp);
	FILE*	openFile(const char *fileName,const char *mode);

	bool  		 flagPrintLog;
	friend class Singleton<log>;
	loglvl		 loglevel;
	string 		 logPath;
};

#endif
