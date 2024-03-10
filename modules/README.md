
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


A list of the hardware components connected to the Nucleo board, and the pins for each component:
    
    -4x Red LED
        
        -D2, D5, D8, D11
   
    -4x Yellow LED
        
        -D1, D4, D7, D10
    
    -4x Green LED
       
        -D0, D3, D6, D9
    
    -2x LDR Sensors
        
        -A0, A1



A description of the tests you performed on the system, and the results:


Any other details that will help the reader understand your code:
