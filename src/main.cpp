#include <Arduino.h>
#include "../include/Configuration.h"
#include "GCodeParser.hpp"
void init_stepper_timer();

GCodeParser parser;

void setup() {
    parser.init();
    pinMode(X_STEP_PIN, OUTPUT);
    pinMode(X_DIR_PIN, OUTPUT);
    pinMode(X_ENABLE_PIN, OUTPUT);
    
    pinMode(Y_STEP_PIN, OUTPUT);
    pinMode(Y_DIR_PIN, OUTPUT);
    pinMode(Y_ENABLE_PIN, OUTPUT);
    
    pinMode(Z_STEP_PIN, OUTPUT);
    pinMode(Z_DIR_PIN, OUTPUT);
    pinMode(Z_ENABLE_PIN, OUTPUT);
  
    digitalWrite(X_ENABLE_PIN, LOW);
    digitalWrite(Y_ENABLE_PIN, LOW);
    digitalWrite(Z_ENABLE_PIN, LOW);

    init_stepper_timer();
}

void loop() {
    parser.poll();
}
