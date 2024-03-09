//=====[Libraries]=============================================================

#include "mbed.h"

#include "timer.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
Timers::Timers() : startTime(0), duration(0), running(false) {}

void Timers::timerInit() {
    // Timer is initialized but not started.
    running = false;
}

void Timers::start(long duration) {
    this->duration = duration;
    startTime = Kernel::Clock::now().time_since_epoch().count();
    running = true;
}

bool Timers::hasExpired() {
    if (!running) {
        return false; // Timer is not running.
    }
    auto now = Kernel::Clock::now().time_since_epoch().count();
    if ((now - startTime) >= duration) {
        running = false; // Automatically stop the timer
        return true; // Timer has expired
    }
    return false; // Timer is still running
}

bool Timers::isRunning(){
    return running;
}

void Timers::reset() {
    running = false; // Stop the timer
    startTime = 0; // Reset start time
    duration = 0; // Reset duration
}
//=====[Implementations of private functions]==================================
//comment
