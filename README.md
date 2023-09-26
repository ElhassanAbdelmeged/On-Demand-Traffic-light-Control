# On-Demand Traffic Light System

**Project by:** Elhassan Abd El Meged Mohamed Ahmed

**Organization:** Egypt FWD

**System Description:**

The "On-Demand Traffic Light" project is designed to improve road safety by assisting pedestrians in crossing the street safely. It achieves this by allowing pedestrians to activate the traffic lights on-demand using a push button. Here are the hardware components and specifications:

**Hardware Components:**
- ATMEGA32 Microcontroller (1 MHz)
- Push Button
- 2 Red LEDs
- 2 Yellow LEDs
- 2 Green LEDs
- 6 Resistors (330 Ω each)
- 10 KΩ Resistor

**Functionality:**

The system controls the traffic lights and pedestrian crossing as follows:
1. The ATMEGA32 microcontroller is the brain of the system, operating at 1 MHz.
2. A push button is provided for pedestrians to request a crossing.
3. Two sets of traffic lights are used, each with red, yellow, and green LEDs.
4. The LEDs are controlled using GPIO pins and resistors to set the appropriate current.
5. A flow chart (not provided here) outlines the system's logic and decision-making process.

**On-Demand Traffic Light Control:**

The system operates as follows:
- When a pedestrian presses the push button, the system activates a pedestrian crossing request.
- The traffic lights change to red to stop incoming cars.
- The pedestrian is signaled to cross with a green light.
- After a set time, the green light turns to yellow.
- Finally, the yellow light turns to red, and the pedestrian crossing is complete.
- The system is ready for the next pedestrian request.

**Driver Requirements:**
- GPIO (General Purpose Input/Output)
- Timer
- External Interrupts
- LED Driver

**Microcontroller:**
- ATmega32

This project serves to enhance road safety and improve pedestrian access by allowing pedestrians to request traffic light changes for safe street crossings.

**schematic:**

![image](https://github.com/ElhassanAbdelmeged/On-Demand-Traffic-light-Control/assets/88130561/6367effa-9c88-44a0-9869-8614739b9ab9)
