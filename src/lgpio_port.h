#ifndef __LGPIO_PORT_H_
#define __LGPIO_PORT_H_

#include <lgpio.h>

#include <cstdint>
#include <chrono>
#include <thread>
#include <iostream>


enum iostate {
    LOW = 0,
    HIGH = 1
};
enum mode{
    INPUT,
    OUTPUT,
    INPUT_PULLUP
};

typedef uint8_t byte;

// Arduino Functions 
iostate digitalRead(int gpio_pin);
void digitalWrite(int gpio_pin, iostate = LOW);
void pinMode(int gpio_pin, mode);
void delay(int ms);
unsigned long millis();
void noInterrupts(void);
void interrupts(void);
#endif
