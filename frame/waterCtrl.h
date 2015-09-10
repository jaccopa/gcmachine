#ifndef waterCtrl_h
#define waterCtrl_h

#include "comm.h"

class water:public Singleton<water>
{
public:

private:
    water();
    ~water();

    friend class Singleton<water>;

};

#endif
