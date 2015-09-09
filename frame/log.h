#ifndef log_h
#define log_h

#include <iostream>
#include <string>
#include <unistd.h>
#include <signal.h>

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
}

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
	void startService();
	void stopService();
	void changeLevel(loglvl);	
	void changePath(string);
private:
	log();
	~log();
	
	static bool  flagPrintLog;
	friend class Singleton<log>;
	loglvl loglevel = (loglvl)err;
	string logPath;
	void   sigAlarmLog(int);	
}
#endif
