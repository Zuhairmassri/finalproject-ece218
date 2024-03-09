//=====[#include guards - begin]===============================================

#ifndef _TRAFFIC_LIGHT_SYSTEM_H_
#define _TRAFFIC_LIGHT_SYSTEM_H_

//=====[Declaration of public defines]=========================================


//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void trafficLightSystemInit();
void trafficLightSystemUpdate();

static void mainRoadYellow();
static void sideRoadYellow();
static void mainRoadGreen();
static void sideRoadGreen();
static void mainRoadRed();
static void sideRoadRed();
static bool isSideVehicleDetected();

//=====[#include guards - end]=================================================

#endif // _TRAFFIC_LIGHT_SYSTEM_H_
