#ifndef TRAFFIC_LIGHTS_H
#define TRAFFIC_LIGHTS_H

#include "mbed.h"

class TrafficLights {
private:
    DigitalOut RedLed;
    DigitalOut YellowLed;
    DigitalOut GreenLed;

public:
    TrafficLights(PinName Red, PinName Yellow, PinName Green);
    void green();
    void yellow();
    void red();
};

#endif // TRAFFIC_LIGHTS_H
