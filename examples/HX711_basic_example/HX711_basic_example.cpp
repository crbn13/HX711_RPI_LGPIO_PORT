#include "HX711.h"
#include <iostream>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 23;
const int LOADCELL_SCK_PIN = 24;

HX711 scale;

void setup() {
  // Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (scale.is_ready()) {
    long reading = scale.read();
    // Serial.print("HX711 reading: ");
    std::cout << "HX711 reading : " << reading << std::endl;
    // Serial.println(reading);
  } else {
    // Serial.println("HX711 not found.");
    std::cout << "HX711 not found." << std::endl;
  }

  delay(1000);
  
}

int main()
{
  setup();
  loop();
  loop();
  loop();
  loop();
  loop();
}