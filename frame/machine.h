#ifndef machine_h
#define machine_h

#include "log.h"

#include <QDeclarativeView>
#include <QApplication>
#include <QMouseEvent>
#include <QBoxLayout>
#include <QStackedWidget>

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

class DaVinciApplication : public QApplication
{
    Q_OBJECT
public:
    DaVinciApplication(int &argc,char** argv);
    virtual ~DaVinciApplication();
    bool setup();
private:
    QDeclarativeView *m_view;
};

#endif
