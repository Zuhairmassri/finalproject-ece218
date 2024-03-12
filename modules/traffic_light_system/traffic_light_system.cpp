//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "traffic_light_system.h"

#include "timer.h"
#include "ldr_sensor.h"


class TrafficLights {
private:
    DigitalOut RedLed;
    DigitalOut YellowLed;
    DigitalOut GreenLed;

public:

    TrafficLights(PinName redPin, PinName yellowPin, PinName greenPin) : RedLed(redPin), YellowLed(yellowPin), GreenLed(greenPin) {
        GreenLed = OFF;
        RedLed = OFF;
        YellowLed = OFF;
    }

    void green() {
        GreenLed = ON;
        RedLed = OFF;
        YellowLed = OFF;
    }

    void yellow() {
        GreenLed = OFF;
        RedLed = OFF;
        YellowLed = ON;
    }

    void red() {
        GreenLed = OFF;
        RedLed = ON;
        YellowLed = OFF;
    }
};


//=====[Declaration of private defines]========================================

TrafficLights TL1(D0, D1, D2);
TrafficLights TL2(D3, D4, D5);
TrafficLights TL3(D6, D7, D8);
TrafficLights TL4(D9, D10, D11);

Timers trafficTimer;


AnalogIn ldrSideRoad1(A0);
AnalogIn ldrSideRoad2(A1); 


bool vehicleDetectedSideRoad = false;
bool isSideRoadYellow = false;
bool isMainRoadYellow = false;
bool isSideRoadGreen = false;
bool isMainRoadGreen = false;
bool isSideRoadRed = false;
bool isMainRoadRed = false;

const int TIME_INCREMENT_MS = 100; 

const int MAIN_ROAD_GREEN_DURATION_MS = 10000;
const int YELLOW_DURATION_MS = 2000;         
const int SIDE_ROAD_GREEN_DURATION_MS = 6000;

int accumulatedTimeMS = 0;

enum TrafficLightState {
    MAIN_ROAD_GREEN,
    MAIN_ROAD_YELLOW,
    MAIN_ROAD_RED,
    SIDE_ROAD_GREEN,
    SIDE_ROAD_YELLOW,
};

TrafficLightState currentState = MAIN_ROAD_GREEN;



void trafficLightSystemInit() {

    ldrSensorInit();
    mainRoadGreen();
    sideRoadRed();
    accumulatedTimeMS = 0;
    currentState = MAIN_ROAD_GREEN; 
}



void trafficLightSystemUpdate() {
    trafficTimer.update(TIME_INCREMENT_MS);

    switch (currentState) {
        case MAIN_ROAD_GREEN:
            if (isSideVehicleDetected()) {
                mainRoadYellow();
                trafficTimer.reset();
                currentState = MAIN_ROAD_YELLOW;
            }
            break;

        case MAIN_ROAD_YELLOW:
            if (trafficTimer.hasExpired(YELLOW_DURATION_MS)) {
                mainRoadRed();
                trafficTimer.reset();
                currentState = MAIN_ROAD_RED;
            }
            break;

        case MAIN_ROAD_RED:
            sideRoadGreen();
            trafficTimer.reset();
            currentState = SIDE_ROAD_GREEN;
            break;

        case SIDE_ROAD_GREEN:
            if (trafficTimer.hasExpired(SIDE_ROAD_GREEN_DURATION_MS)) {
                sideRoadYellow();
                trafficTimer.reset();
                currentState = SIDE_ROAD_YELLOW;
            }
            break;
        case SIDE_ROAD_YELLOW:
            if (trafficTimer.hasExpired(YELLOW_DURATION_MS)) {
                sideRoadRed();
                mainRoadGreen();
                trafficTimer.reset();
                currentState = MAIN_ROAD_GREEN;
            }
            break;
    }
}


static void updateMainLightStatus() {
    if (isMainRoadRed) {
        isMainRoadGreen = false;
        isMainRoadYellow = false;
    } else if (isMainRoadYellow) {
        isMainRoadGreen = false;
        isMainRoadRed = false;
    } else if (isMainRoadGreen) {
        isMainRoadYellow = false;
        isMainRoadRed = false;
    }
}

static void updateSideLightStatus() {
    if (isSideRoadRed) {
        isSideRoadGreen = false;
        isSideRoadYellow = false;
    } else if (isSideRoadYellow) {
        isSideRoadGreen = false;
        isSideRoadRed = false;
    } else if (isSideRoadGreen) {
        isSideRoadYellow = false;
        isSideRoadRed = false;
    }
}


static bool isSideVehicleDetected(){
    float ldrValue1 = ldrSideRoad1.read();
    float ldrValue2 = ldrSideRoad2.read();
    if (ldrValue1 < 0.2 || ldrValue2 < 0.2) {
        return true;
    }
    return false;
}

static void mainRoadYellow() {
    TL1.yellow();
    TL2.yellow();
}

static void sideRoadYellow() {
    TL3.yellow();
    TL4.yellow();
}


static void mainRoadGreen() {
    TL1.green();
    TL2.green();
}

static void sideRoadGreen() {
    TL3.green();
    TL4.green();
}

static void mainRoadRed() {
    TL1.red();
    TL2.red();
}

static void sideRoadRed() {
    TL3.red();
    TL4.red();
}


