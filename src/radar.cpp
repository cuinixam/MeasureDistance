#include "radar.h"
#include "hw_config.h"
#include <Arduino.h>

/**
 * Cut-off frequency: 100 Hz
 * Sampling frequency: 1000 Hz
 */
#define FILT_PARAM_A    0.38 // a
#define FILT_PARAM_B    0.61 // 1-a

Radar::Radar() {
   init();
}

int Radar::get_distance(void) {
   int distance_mm = 0;
   long time_us=0;
   
   digitalWrite(PIN_RADAR_TRIGGER, LOW);
   delayMicroseconds(3);
   digitalWrite(PIN_RADAR_TRIGGER, HIGH);
   delayMicroseconds(10);
   digitalWrite(PIN_RADAR_TRIGGER, LOW);
   time_us = pulseIn(PIN_RADAR_ECHO, HIGH);
   time_us = filter_low_pass(time_us, time_filt_prev);
   time_filt_prev = time_us;
   /* The time is for both ways, to the object and back */
   distance_mm = (int)(((float)time_us)*0.34/2);
   return(distance_mm);
}

long Radar::filter_low_pass(long value, long prev_value) {
   return (long)(FILT_PARAM_A*(float)value + FILT_PARAM_B*(float)prev_value);
}

void Radar::init(void) {
   pinMode(PIN_RADAR_TRIGGER, OUTPUT);
   pinMode(PIN_RADAR_ECHO, INPUT);
   time_filt_prev = 0;
}