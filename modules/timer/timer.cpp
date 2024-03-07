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
Timer Timer() : startTime(0), duration(0), running(false) {}

void Timer timerInit() {
    // Timer is initialized but not started.
    running = false;
}

void Timer start(long duration) {
    this->duration = duration;
    startTime = Kernel::Clock::now().time_since_epoch().count();
    running = true;
}

void Timer reset() {
    running = false; // Stop the timer
    startTime = 0; // Reset start time
    duration = 0; // Reset duration
}
//=====[Implementations of private functions]==================================
//comment
