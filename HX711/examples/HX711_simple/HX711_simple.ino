#include "HX711.h"

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library
float value;

void setup() {
  Serial.begin(38400);
  Serial.println("HX711 Demo");
  scale.set_scale(400.f);   // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();	// reset the scale to 0
  Serial.println("Readings:");
}

void loop() {
  Serial.print("one reading:\t");
  value=scale.get_units();
  Serial.print(value);

  Serial.print("\t| average:\t");
  value=scale.get_units(10);
  Serial.println(value);
  
  delay(100);
}
