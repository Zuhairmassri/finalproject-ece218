#ifndef TIMER_H
#define TIMER_H

#include "mbed.h"
#include "RealTimeClock.h"
#include <chrono>

class Timers {
public:
    Timers();
    ~Timers();

    void timerInit();
    void start(long seconds);
    int hasExpired();
    bool isRunning();
    void reset();

private:
    mbed::RealTimeClock::time_point startTime;
    std::chrono::seconds duration;
    bool running;
};

#endif // TIMER_H
