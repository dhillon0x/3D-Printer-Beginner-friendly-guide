#pragma once

#define BAUDRATE 250000
#define DEFAULT_AXIS_STEPS_PER_UNIT { 80.0, 80.0, 400.0, 93.0 }
#define DEFAULT_MAX_FEEDRATE { 500, 500, 5, 25 }
#define DEFAULT_MAX_ACCELERATION { 1000, 1000, 100, 10000 }

#define X_STEP_PIN 25
#define X_DIR_PIN 23
#define X_ENABLE_PIN 27
#define X_MIN_PIN 3
#define Y_STEP_PIN 31
#define Y_DIR_PIN 33
#define Y_ENABLE_PIN 29
#define Y_MIN_PIN 14
#define Z_STEP_PIN 37
#define Z_DIR_PIN 39
#define Z_ENABLE_PIN 35
#define Z_MIN_PIN 18
#define E0_STEP_PIN 26
#define E0_DIR_PIN 28
#define E0_ENABLE_PIN 24
#define HEATER_0_PIN 10
#define HEATER_BED_PIN 8
#define TEMP_0_PIN 13
#define TEMP_BED_PIN 14
