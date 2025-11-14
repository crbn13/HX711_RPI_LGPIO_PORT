/**
 *
 * HX711 library for Arduino - example file
 * https://github.com/bogde/HX711
 *
 * MIT License
 * (c) 2018 Bogdan Necula
 *
**/
#include "HX711.h"
#include <iostream>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 23;
const int LOADCELL_SCK_PIN = 24;



HX711 scale;

void setup() {
  // Serial.begin(38400);
  std::cout <<"HX711 Demo" << std::endl;

  std::cout <<"Initializing the scale" << std::endl;

  // Initialize library with data output pin, clock input pin and gain factor.
  // Channel selection is made by passing the appropriate gain:
  // - With a gain factor of 64 or 128, channel A is selected
  // - With a gain factor of 32, channel B is selected
  // By omitting the gain factor parameter, the library
  // default "128" (Channel A) is used here.
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  std::cout <<"Before setting up the scale:" << std::endl;
  std::cout <<"read: \t\t";
  std::cout <<scale.read() << std::endl;			// print a raw reading from the ADC

  std::cout <<"read average: \t\t";
  std::cout <<scale.read_average(20) << std::endl;  	// print the average of 20 readings from the ADC

  std::cout <<"get value: \t\t";
  std::cout <<scale.get_value(5) << std::endl;		// print the average of 5 readings from the ADC minus the tare weight (not set yet)

  std::cout <<"get units: \t\t";
  std::cout <<scale.get_units(5) << std::endl;	// print the average of 5 readings from the ADC minus tare weight (not set) divided
						// by the SCALE parameter (not set yet)

  scale.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();				        // reset the scale to 0

  std::cout <<"After setting up the scale:" << std::endl;

  std::cout <<"read: \t\t";
  std::cout <<scale.read() << std::endl;                 // print a raw reading from the ADC

  std::cout <<"read average: \t\t";
  std::cout <<scale.read_average(20) << std::endl;       // print the average of 20 readings from the ADC

  std::cout <<"get value: \t\t";
  std::cout <<scale.get_value(5) << std::endl;		// print the average of 5 readings from the ADC minus the tare weight, set with tare()

  std::cout <<"get units: \t\t";
  std::cout <<scale.get_units(5)<< std::endl;        // print the average of 5 readings from the ADC minus tare weight, divided
						// by the SCALE parameter set with set_scale

  std::cout <<"Readings:" << std::endl;
}

void loop() {
  std::cout <<"one reading:\t";
  std::cout <<scale.get_units(), 1;
  std::cout <<"\t| average:\t";
  std::cout <<scale.get_units(10)<< std::endl;

  scale.power_down();			        // put the ADC in sleep mode
  delay(5000);
  scale.power_up();
}
