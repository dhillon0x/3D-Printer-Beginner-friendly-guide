#include <Arduino.h>

void init_stepper_timer() {
    
    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11); 
    OCR1A = 125;                       
    TIMSK1 |= (1 << OCIE1A);           

ISR(TIMER1_COMPA_vect) {
   
}
