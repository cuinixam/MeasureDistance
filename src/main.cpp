#include <Arduino.h>
#include "display.h"
#include "radar.h"

Display display;
Radar   radar;

void setup() {
   Serial.begin(9600);
}

void loop() {
   int dist_mm;
   
   dist_mm = radar.get_distance();
   display.show(dist_mm);
   Serial.print("Distance ");
   Serial.print(dist_mm);
   Serial.println("[mm]");
}