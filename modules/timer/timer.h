//=====[#include guards - begin]===============================================

#ifndef TIMER_H
#define TIMER_H

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================
class Timer {
public:
    Timer(); // Constructor
    void timerInit(); // Initializes the timer without setting a duration
    void start(long duration); // Starts the timer with a specified duration in milliseconds
    void reset(); // Resets the timer to its initial state


private:
    Timer(const Timer&); // Prevent copying
    Timer& operator=(const Timer&); // Prevent assignment

    long startTime; // Start time of the timer
    long duration; // Duration of the timer
    bool running; // Indicates if the timer is running
};
//=====[Declarations (prototypes) of public functions]=========================

//=====[#include guards - end]=================================================

#endif // TIMER_H