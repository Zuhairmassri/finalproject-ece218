#include "timer.h"

Timers::Timers() : duration(0), running(false) {
    mbed::RealTimeClock::init(); 
}

Timers::~Timers() {
    mbed::RealTimeClock::free(); 
}

void Timers::timerInit() {
    running = false;
    startTime = mbed::RealTimeClock::time_point(std::chrono::seconds(0));
    duration = std::chrono::seconds(0);
}

void Timers::start(long seconds) {
    this->duration = std::chrono::seconds(seconds);
    this->startTime = mbed::RealTimeClock::now();
    running = true;
}

enum TimerStatus {
    TIMER_NOT_RUNNING = -1,
    TIMER_RUNNING = 0,
    TIMER_EXPIRED = 1
};

int Timers::hasExpired() {
    if (!running) {
        return TIMER_NOT_RUNNING;
    }
    auto now = mbed::RealTimeClock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
    if (elapsed >= duration) {
        running = false;
        return TIMER_EXPIRED;
    }
    return TIMER_RUNNING;
}


void Timers::reset() {
    running = false;
    startTime = mbed::RealTimeClock::time_point(std::chrono::seconds(0));
    duration = std::chrono::seconds(0);
}
