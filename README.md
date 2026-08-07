# 🐟 Smart Aquarium System

Welcome to the **Smart Aquarium System**! This is our NTI Graduation Project, built entirely from scratch using the ATmega32 microcontroller and Embedded C. 

Maintaining a healthy environment for fish can be a daily hassle, so we decided to automate it. This system acts as a smart caretaker that monitors water levels, maintains the right temperature, and even handles feeding time automatically!

## Meet the Team ("قاع الهامور")
This project was proudly developed by:
- Khadija Naji
- Amena Hassan
- Yossra Omar
- Eslam Eid

---

## What Does It Do?

- **Keeps the Water Comfortable:** We use an LM35 sensor to constantly check the temperature. If the water gets too cold, the system automatically fires up the heater (represented by a Red LED/Lamp in our simulation) to warm things up.
- **Prevents Overflows:** An HC-SR04 ultrasonic sensor keeps an eye on the water level. By using hardware interrupts to capture the echo, we get precise distance readings and automatically control a DC water pump when needed.
- **Feeds the Fish:** You don't have to worry about missing feeding time. A servo motor, controlled by a highly accurate PWM signal, rotates $180^\circ$ to release food into the tank at scheduled intervals.
- **Live Updates:** A clean 16x2 LCD screen acts as the system's dashboard, displaying real-time temperature and water level readings so you always know what's going on.

---

## Under the Hood (Software Architecture)

We wrote the code following a clean, layered architecture. This keeps our drivers modular, easy to read, and simple to debug:

*   **APP Layer:** Contains the main application logic and the time-tracking system (Stopwatch).
*   **HAL Layer:** Hardware Abstraction Layer for our external modules (LCD, LM35, Servo, Ultrasonic).
*   **MCAL Layer:** The core ATmega32 peripheral drivers (DIO, ADC, EXTI, Timers, GIE).
*   **STD_LIB:** Our standard custom types and bit-manipulation macros.

---

## Hardware Pinout (Quick Reference)

If you're checking the schematic, here is how everything is wired to the ATmega32:

| Component | MCU Pin | Role in the System |
| :--- | :--- | :--- |
| **LM35 Temp Sensor** | `PA0` (ADC0) | Reads analog temperature data |
| **Heater (Lamp)** | `PC0` | Output pin to trigger the heating relay |
| **Ultrasonic Trigger**| `PD0` | Sends the sound pulse |
| **Ultrasonic Echo** | `PD2` (INT0) | Captures the bouncing wave via external interrupt |
| **Water Pump** | `PB0` | Drives the pump via a 2N2222 BJT Transistor |
| **Feeder Servo** | `PD5` (OC1A) | Outputs the Timer1 PWM signal for rotation |

---

## How to Run the Simulation

Want to see it in action? Follow these steps:

1. **Build the Code:** Open the project in your preferred IDE (like Eclipse or Microchip Studio). Compile the source code using the AVR-GCC toolchain to generate the `.hex` executable file.
2. **Open the Schematic:** Launch the provided Proteus simulation file (`.pdsprj`).
3. **Flash the MCU:** Double-click on the ATmega32 microcontroller in Proteus, and under "Program File," browse and select your generated `.hex` file.
4. **Play:** Hit the run button and watch the system manage the aquarium!
