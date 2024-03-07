//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "traffic_lights.h"


//=====[Implementations of public functions]===================================

void TrafficLights::green(){
    RedLed = OFF;
    YellowLed = OFF;
    GreenLed = ON;
}

void TrafficLights::yellow(){
    RedLed = OFF;
    YellowLed = ON;
    GreenLed = OFF; 
}

void TrafficLights::red(){
    RedLed = ON;
    YellowLed = OFF;
    GreenLed = OFF; 
}

//=====[Implementations of private functions]==================================
