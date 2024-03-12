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

### Timers Class

Abstraction over a software-based timer mechanism. It accumulates delays from the main loop and checks against defined thresholds to manage state transitions.

### trafficLightSystemUpdate Function

Implements the traffic light control logic as a state machine, managing transitions based on vehicle detection and timer expirations.

## Testing and Validation

The system was rigorously tested under various scenarios to ensure its reliability and effectiveness in managing traffic flow. A critical issue related to the timer module was resolved by implementing a software-based timer that accurately manages state transitions.

## Future Enhancements

The system is designed with flexibility and scalability in mind, allowing for future enhancements such as integrating more sophisticated vehicle detection methods or expanding to manage multiple intersections.

The system could also possibly be enhance to account for pedestrian crossing the streets in order to simulate a more real daily implementation of a traffic lights system. This implementation could possibly allow for the integration of an LED Display and sound system that instructs the pedestrians on crossing the streets.

## Conclusion

This Automated Traffic Light Control System presents a robust solution for managing traffic at intersections. Through careful testing and innovative solutions like the software-based timer, it demonstrates a high degree of reliability and efficiency in optimizing traffic flow.
