# Custom RAMPS 1.4 3D Printer Firmware

A lightweight, modular, and custom-built 3D printer firmware designed from scratch for **Arduino Mega 2560** and **RAMPS 1.4** hardware stacks. Built for makers, students, and DIY project builders looking to understand low-level printer architecture.

## Hardware Specifications
* **Microcontroller:** ATmega2560 (16 MHz, 256KB Flash)
* **Shield:** RAMPS 1.4
* **Drivers:** Step-stick style steppers (A4988 / DRV8825 compatible)
* **Kinematics:** Cartesian (GT2 Belts on X/Y axes, T8 Lead Screw on Z-axis)
* **Bed & Hotend:** Standard 12V/24V heated PCB bed and thermistor hotend

---

## Project Structure
```text
├── include/
│   └── Configuration.h    # Pin mappings, step resolutions, and limits
├── src/
│   ├── main.cpp           # System bootstrap and main loop execution
│   ├── GCodeParser.hpp    # Serial command interpreter (G & M codes)
│   └── Stepper.cpp        # High-frequency timer interrupt pulse generator
└── README.md
