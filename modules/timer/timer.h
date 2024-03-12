#ifndef TIMER_H
#define TIMER_H

class Timers {
public:
    Timers();

    void reset();
    void update(int elapsedTimeMS);
    bool hasExpired(int durationMS);

private:
    int accumulatedTimeMS;
};

#endif // TIMER_H
