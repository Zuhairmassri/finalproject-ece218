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


// Define TrafficLights objects for each intersection
TrafficLights TL1(D0, D1, D2);
TrafficLights TL2(D3, D4, D5);
TrafficLights TL3(D6, D7, D8);
TrafficLights TL4(D9, D10, D11);

// Timer object for managing traffic light phases
Timers timer;
Timers yellowTimer;
            

// Analog input for LDR sensors on the side road
AnalogIn ldrSideRoad1(A0); // LDR sensor for one direction
AnalogIn ldrSideRoad2(A1); // LDR sensor for the opposite direction

// Duration constants for traffic light phases (in milliseconds)
const long SIDE_ROAD_GREEN_DURATION = 30000; // 30 seconds
const long YELLOW_DURATION = 5000; // 5 seconds

// Flag to track if a vehicle has been detected on the side road
bool vehicleDetectedSideRoad = false;

// Initialize traffic light system
void trafficLightSystemInit() {
    // Initialize timer
    timer.timerInit();
    yellowTimer.timerInit();

    // Initialize LDR sensors
    ldrSensorInit();
}

// Update traffic light system
void trafficLightSystemUpdate() {
    if (timer.hasExpired()) {
        if (isSideVehicleDetected()) {
            // Transition main road green light to yellow then red
            mainRoadYellow();
            if(!yellowTimer.isRunning()){
                yellowTimer.start(YELLOW_DURATION);
            } else if(yellowTimer.hasExpired()){
                mainRoadRed();
            }
            sideRoadGreen();

            // Start timer for side road green phase
            timer.start(SIDE_ROAD_GREEN_DURATION);
            
        } else {
            // Transition main road green light to yellow then red
            sideRoadYellow();
            if(!yellowTimer.isRunning()){
                yellowTimer.start(YELLOW_DURATION);
            } else if(yellowTimer.hasExpired()){
                sideRoadRed();
            }
            mainRoadGreen();
                }
    }
    
}

static bool isSideVehicleDetected(){
    float ldrValue1 = ldrSideRoad1.read();
    float ldrValue2 = ldrSideRoad2.read();
    if (ldrValue1 < 0.5 || ldrValue2 < 0.5) {
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


