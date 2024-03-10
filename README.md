
Spencer Aldrich and Zuhair AlMassri - Automated Traffic Light system
3-9-24


A summary of the behavior of this code in your system:

The system is designed to manage traffic at an intersection between a main road and a side road, 
using traffic signals (LEDs) controlled by a microcontroller, with input from Light Dependent Resistor 
(LDR) sensors to detect vehicle presence and adjust signal timing accordingly.

A list of the code modules and a bried description of which each module does:

1. Sensor Input Module

    -The sensor input module is in charge of detecting the presence of a vehicle. Once the presence of a vehicle is detected, 
    a signal is sent to the traffic flow logic module, letting it know that a light state must change. 

2. Timer Module
    
    -The timer module controls the duration of each traffic light phase. This involves determining how long the light remains
    green to let cars on the side road go before switching back to red. 

3. Traffic Flow Logic Module
   
    -The traffic flow logic module acts as the brain of the system, and analyzes data from both the timer module and sensor input
    module to make decisions for when and how traffic signals should change. 


If the code is a) written from scratch, b) based on textbook code or c) based on code found online:

The code for the timer module is based on the timer content we learned in chapter 8 of the textbook. 


A list of the hardware components connected to the Nucleo board, and the pins for each component:
    
    -4x Red LED
        
        -D2, D5, D8, D11
   
    -4x Yellow LED
        
        -D1, D4, D7, D10
    
    -4x Green LED
       
        -D0, D3, D6, D9
    
    -2x LDR Sensors
        
        -A0, A1



### Project Test Summary

#### Testing Approach

A series of tests were conducted to validate the functionality of the Traffic Light Control System under various scenarios, including:

1. **Vehicle Detection Response:** Testing how the system responds to vehicle detection on the side road when the main road light is green. Expected behavior is a transition from green to yellow, then red on the main road, followed by the side road turning green.
2. **Timer-Based Transitions:** Verifying that transitions between traffic light states occur within predefined durations, especially the change from yellow to red and green to yellow.
3. **System Recovery:** Assessing the system's ability to return to the initial state (main road green, side road red) after a complete cycle of state transitions.

#### Test Results

The tests revealed a critical issue within the Traffic Light Control System:

- **Stuck in State:** During testing, it was observed that the traffic lights could become stuck in one of the states and would not progress through the intended sequence. This was most apparent when expecting a transition from yellow to red or when the side road was supposed to turn green after the main road light had turned red.

#### Root Cause Analysis

Upon investigation, the problem was traced back to a likely malfunction within the Timer module, which is crucial for managing state transition durations. The Timer module's `hasExpired` method, intended to signal when it was time to change the traffic light state, did not always perform as expected. This malfunction could cause the system to miss the transition triggers, leading to the observed issue of lights being stuck in a single state.

The Timer module uses a Real-Time Clock (RTC) peripheral to keep track of time elapsed and determines if the set duration for a light state has expired. However, inconsistencies in the Timer's behavior suggest issues with either the initialization of the RTC, the calculation of elapsed time, or the handling of timer states (running, expired).

#### Conclusion and Next Steps

The testing phase, while uncovering a significant flaw due to the Timer module, has provided valuable insights into the robustness of the Traffic Light Control System. The next steps involve a thorough review and debugging of the Timer module to address the faults in its implementation. Rectifying this issue is crucial for ensuring reliable operation of the traffic light control system, as accurate timing is fundamental to its functionality.

Future tests will need to specifically target the Timer module's accuracy, responsiveness, and reliability in various operational scenarios. Once the Timer module is verified to be fault-free, additional rounds of system-wide testing will be conducted to confirm that the traffic light control system performs as intended under all expected traffic conditions.


### Overview of the Traffic Light Control System Code

The Traffic Light Control System is designed to manage traffic lights at an intersection, alternating between the main road and the side road based on vehicle detection and pre-defined timing. This section provides an overview of the main components of the code, aiding users in understanding its functionality and structure.

#### TrafficLights Class

The `TrafficLights` class represents a single set of traffic lights. It encapsulates the functionality to control the red, yellow, and green LEDs that constitute a traffic light. Each instance of the class is associated with a specific set of pins on the microcontroller, which are connected to the LEDs.

**Key Features:**
- **Initialization:** Requires pin names for the red, yellow, and green LEDs during instantiation. Initializes all LEDs to the OFF state.
- **Control Methods:** Provides methods `green()`, `yellow()`, and `red()` to turn on the respective light while ensuring the other two are turned off, simulating the behavior of a physical traffic light.

#### Timers Class

The `Timers` class is an abstraction over the microcontroller's Real-Time Clock (RTC), providing a simple interface for timing events in the traffic light control system. It is critical for managing the duration of each traffic light state.

**Key Features:**
- **Start Timer:** Allows setting a timer with a specific duration in seconds. Once started, the timer keeps track of elapsed time using the RTC.
- **Check Expiration:** Offers a method to check if the timer has expired, which is used to trigger transitions between traffic light states.
- **Timer Status:** Integrates a tri-state logic (using -1, 0, 1) to indicate if the timer is not running, running but not expired, or has expired, enhancing the control logic's decision-making.

#### Traffic Light System Update Function

The `trafficLightSystemUpdate` function is the core of the traffic light control logic, implementing a state machine to manage the transitions between different states of the traffic lights based on vehicle detection and timer expirations.

**Key Features:**
- **State Machine:** Manages states such as `MAIN_ROAD_GREEN`, `MAIN_ROAD_YELLOW`, `MAIN_ROAD_RED`, `SIDE_ROAD_GREEN`, and `SIDE_ROAD_YELLOW`. Transitions between these states control the traffic flow.
- **Vehicle Detection:** Checks for vehicle presence on the side road to initiate a change from the main road being green to yellow, then red, allowing the side road to turn green.
- **Timer Management:** Utilizes the `Timers` class to wait for specific durations before transitioning between states, ensuring that lights remain in each state for an appropriate amount of time.

#### Additional Details

- **Flexibility and Modularity:** The design separates concerns into distinct classes (`TrafficLights` and `Timers`), allowing for easy modifications, such as changing timing durations or adding more traffic lights.
- **Scalability:** The system can be scaled to manage multiple intersections by instantiating more `TrafficLights` objects and managing them within an expanded state machine logic.
- **Debugging and Maintenance:** The clear separation of functionality and the use of descriptive state names aid in debugging and future maintenance of the system.

This overview aims to provide users with a foundational understanding of the Traffic Light Control System's code structure and key functionalities, supporting further exploration, modification, or integration into larger projects.
