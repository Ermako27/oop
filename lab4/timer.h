#ifndef TIMER_H
#define TIMER_H

#include <unistd.h>

class Timer
{
public:
    Timer() {}
    inline static void process(int s)
    {
        usleep(1000000*s);
    }
};


#endif // TIMER_H
