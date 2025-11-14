#include "lgpio_port.h"

static int gpio_handle = -1;

static bool gpio_check()
{
    if (gpio_handle < 0)
    {
        gpio_handle = lgGpiochipOpen(0);
        if (gpio_handle >= 0)
            return true;
        else 
            std::cout << "GPIO FAILIURE TO OPEN CHIP. ret = " << gpio_handle << std::endl; 

    }
    else
    {
        return true;
    }

}

static bool lg_ret_check(const int retval)
{
    if (retval >= 0)
        return true;
    else
    {
        std::cout << "RET FAIL : RET = " << retval << std::endl;
        return false;
    }

}

iostate digitalRead(int gpio_pin)
{
    if (!gpio_check())
        return LOW;



}

void digitalWrite(int gpio_pin, iostate = LOW)
{
    if (!gpio_check())
        return;

}

void pinMode(int gpio_pin, mode pin_mode)
{
    if (!gpio_check())
        return;

    switch (pin_mode)
    {
    case (INPUT):
    {
        lg_ret_check(lgGpioClaimInput(gpio_handle, LG_SET_PULL_NONE, gpio_pin));
        break;
    }
    case (OUTPUT):
    {
        lg_ret_check(lgGpioClaimOutput(gpio_handle, LG_SET_PULL_NONE, gpio_pin, 0));
    }
    case (INPUT_PULLUP):
    {
        lg_ret_check(lgGpioClaimInput(gpio_handle, LG_SET_PULL_UP, gpio_pin));
    }
    default:
    {
        break;
    }

    }
    


}

unsigned long millis(){}
void noInterrupts(void){}
void interrupts(void){}