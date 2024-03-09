//=====[#include guards - begin]===============================================

#ifndef TIMERS_H
#define TIMERS_H

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================
class Timers {
public:
    Timers(); // Constructor
    void timerInit(); // Initializes the timer without setting a duration
    void start(long duration); // Starts the timer with a specified duration in milliseconds
    bool hasExpired(); // Checks if the timer has exceeded its duration
    void reset(); // Resets the timer to its initial state
    bool isRunning();


private:
    Timers(const Timers&); // Prevent copying
    Timers& operator=(const Timers&); // Prevent assignment

    long startTime; // Start time of the timer
    long duration; // Duration of the timer
    bool running; // Indicates if the timer is running
};
//=====[Declarations (prototypes) of public functions]=========================

//=====[#include guards - end]=================================================

#endif // TIMERS_H
