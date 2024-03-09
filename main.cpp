#include "mbed.h"
#include "arm_book_lib.h"
#include "traffic_light_system.h"


int main() {

    trafficLightSystemInit();
    while(true){
        trafficLightSystemUpdate();
    }
}
