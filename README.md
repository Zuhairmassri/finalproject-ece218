# Automated Traffic Light Control System

Zuhair AlMassri, Spencer Aldrich

This project implements an automated traffic light control system at an intersection between a main road and a side road. The system uses traffic signals controlled by a microcontroller, with input from Light Dependent Resistor (LDR) sensors to detect vehicle presence and adjust signal timing accordingly.

## Project Components

### Hardware Components

- **Microcontroller (Nucleo board)**
- **LEDs:** 4x Red (D2, D5, D8, D11), 4x Yellow (D1, D4, D7, D10), 4x Green (D0, D3, D6, D9)
- **LDR Sensors:** 2x (A0, A1)

### Software Modules

1. **LDR Sensor Input Module:** Detects vehicle presence and signals the traffic flow logic module for light state changes.
2. **Timer Module:** Manages the duration of each traffic light phase using a software-based timer that accumulates delays.
3. **Traffic Light System Module:** Acts as the system's brain, making decisions for traffic signal changes based on sensor input and timer information.

## System Design

The code structure is divided into several key components, each responsible for a distinct aspect of the traffic light control process.

### TrafficLights Class

Represents a single set of traffic lights, encapsulating control over the red, yellow, and green LEDs. It ensures only the appropriate light is active at any given time.

#### Key Features
- **Initialization:** Requires pin names for the red, yellow, and green LEDs during instantiation. Initializes all LEDs to the OFF state.
- **Control Methods:** Provides methods `green()`, `yellow()`, and `red()` to turn on the respective light while ensuring the other two are turned off, simulating the behavior of a physical traffic light.

### Timers Class

Provides a software-based timer mechanism by accumulating delays. It's crucial for managing state transition durations within the traffic light control system.

#### Key Features
- **Reset Timer:** Resets the accumulated time to zero.
- **Update Timer:** Increments the accumulated time by the elapsed time since the last update.
- **Check Expiration:** Determines if the accumulated time has reached or exceeded the specified duration, indicating the timer has expired.

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

## Testing and Validation

The system was rigorously tested under various scenarios to ensure its reliability and effectiveness in managing traffic flow. A critical issue related to the timer module was resolved by implementing a software-based timer that accurately manages state transitions.

## Future Enhancements

The system is designed with flexibility and scalability in mind, allowing for future enhancements such as integrating more sophisticated vehicle detection methods or expanding to manage multiple intersections.

The system could also possibly be enhance to account for pedestrian crossing the streets in order to simulate a more real daily implementation of a traffic lights system. This implementation could possibly allow for the integration of an LED Display and sound system that instructs the pedestrians on crossing the streets.

## Conclusion

This Automated Traffic Light Control System presents a robust solution for managing traffic at intersections. Through careful testing and innovative solutions like the software-based timer, it demonstrates a high degree of reliability and efficiency in optimizing traffic flow.
