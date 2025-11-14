#ifndef __LGPIO_PORT_H_
#define __LGPIO_PORT_H_

#include <cstdint>
#include <lgpio>

static enum iostate {
    LOW = 0,
    HIGH = 1
};
static enum mode{
    INPUT,
    OUTPUT,
    INPUT_PULLUP
};

typedef uint8_t byte;

iostate digitalRead(int gpio_pin);
void digitalWrite(int gpio_pin, iostate = LOW);
void pinMode(int gpio_pin, mode);

#endif
