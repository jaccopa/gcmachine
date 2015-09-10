#ifndef motionCtrl_h
#define motionCtrl_h


#include "comm.h"


class motion:public Singleton<motion>
{
public:

private:
    motion();
    ~motion();

    friend class Singleton<motion>;

};


#endif
