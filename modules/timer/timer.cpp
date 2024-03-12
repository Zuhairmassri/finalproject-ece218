#include "timer.h"

Timers::Timers() : accumulatedTimeMS(0) {}

void Timers::reset() {
    accumulatedTimeMS = 0;
}

void Timers::update(int elapsedTimeMS) {
    accumulatedTimeMS += elapsedTimeMS;
}

bool Timers::hasExpired(int durationMS) {
    return accumulatedTimeMS >= durationMS;
}
