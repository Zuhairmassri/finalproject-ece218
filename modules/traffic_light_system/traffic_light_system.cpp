//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "traffic_light_system.h"
#include "traffic_lights.h"
#include "timer.h"

//=====[Declaration of private defines]========================================

// Declare and initialize TrafficLights objects within the trafficLightSystemInit function

TrafficLights TL1(D0, D1, D2);
TrafficLights TL2(D3, D4, D5);
TrafficLights TL3(D6, D7, D8);
TrafficLights TL4(D9, D10, D11);

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void trafficLightSystemInit()
{

}

void trafficLightSystemUpdate()
{

}


//=====[Implementations of private functions]==================================


static void mainRoadGreen(){
    TL1.green();
    TL2.green();
}

static void sideRoadGreen(){
    TL3.green();
    TL4.green();
}

static void mainRoadRed(){
    TL1.red();
    TL2.red();
}

static void sideRoadRed(){
    TL3.red();
    TL4.red();
}

static void mainRoadYellow(){
    TL1.yellow();
    TL2.yellow();
}

static void sideRoadYellow(){
    TL3.yellow();
    TL4.yellow();
}
