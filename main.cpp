#include "mbed.h"
#include "arm_book_lib.h"
#include "traffic_light_system.h"

#define TIME_INCREMENT_MS 100

int main() {

    trafficLightSystemInit();
    while(true){
        trafficLightSystemUpdate();
        delay(TIME_INCREMENT_MS);
    }
}
