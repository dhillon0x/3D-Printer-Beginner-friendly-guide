# Custom RAMPS 1.4 3D Printer Firmware & Engineering Documentation

Building custom printer firmware from the ground up transforms standard off-the-shelf automation into a rigorous exercise in embedded systems design, hardware abstraction, and real-time control theory. This project serves as a cornerstone piece for a technical project portfolio, demonstrating low-level C++ programming, timer-driven hardware interrupts, precise kinematic calculations, and peripheral interfacing without relying on monolithic legacy source codebases.

1 Portfolio Value & Engineering Impact

For technical recruiters and engineering evaluators, implementing firmware from bare metal highlights distinct competencies:
* Real-Time Embedded Systems: Demonstrates direct manipulation of microcontroller registers, hardware timers (such as ATmega2560 Timer 1), and high-frequency Interrupt Service Routines (ISRs) to guarantee jitter-free step generation.
* Kinematics & Mathematical Modeling: Proves the ability to translate abstract Cartesian coordinates into physical stepper motor displacements using fundamental mechanical design equations.
* Systems Architecture: Showcases modular separation of concerns through isolated layers for serial G-code parsing, hardware abstraction, and thermal PID safety loops.

Inspiration & Origins

Standard firmware suites like Marlin or RepRapFirmware contain hundreds of thousands of lines of code designed to support thousands of diverse motherboard combinations. While powerful, this complexity often obscures how the underlying microcontroller actually interacts with physical hardware. The inspiration for this repository stemmed from the desire to strip away software bloat and build a transparent, highly understandable educational pipeline where every single line of code—from the serial buffer to the stepper pulse generator—is fully traceable and open for customization.

 2 Hardware Bill of Materials (BOM)

* Microcontroller: Arduino Mega 2560 (ATmega2560 running at 16 MHz with 256KB Flash)
* Shield Interface: RAMPS 1.4 Expansion Board (Red PCB layout)
* Motion Drivers: Step-stick drivers (A4988 / DRV8825 compatible) configured to 16 microsteps
* Kinematic Elements: 
  * X & Y Axis: GT2 timing belts driven by 20-tooth pulleys
  * Z Axis: T8 precision lead screw (8mm lead per revolution)
* Thermal System: 12V/24V PCB heated bed and thermistor-based extrusion hotend

 3 Mathematical Calculations & Kinematics

To ensure accurate spatial positioning, the firmware computes axis resolutions using mechanical gear ratios:

* X and Y Axis (GT2 Belt, 20-Tooth Pulley, 16 Microsteps):
  Steps per mm = (Steps per Revolution * Microsteps) / (Pulley Teeth * Belt Pitch) = (200 * 16) / (20 * 2) = 80.00 steps/mm

* Z Axis (T8 Lead Screw, 8mm Lead, 16 Microsteps):
  Steps per mm = (Steps per Revolution * Microsteps) / Lead Pitch = (200 * 16) / 8 = 400.00 steps/mm

4 Getting Started & Installation

1. Clone Repository:
   git clone https://github.com/dhillon0x/3D-Printer-Beginner-friendly-guide.git
2. Build Environment: Open the folder in VS Code using the PlatformIO extension.
3. Upload Firmware: Connect your Arduino Mega 2560 via USB and flash the compiled binary.
4. Host Connection: Interface via Pronterface or OctoPrint at 250000 baud.

 5 Helpful Video Resources
* RAMPS 1.4 Marlin Configuration Guide: https://www.youtube.com/watch?v=b2D7KZJu3tU
