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
    return false;
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
    
    int ret = lgGpioRead(gpio_handle, gpio_pin);
    if (lg_ret_check(ret))
        return (iostate)ret;
    else
        return LOW;
}

void digitalWrite(int gpio_pin, iostate)
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
    case INPUT:
    {
        lg_ret_check(lgGpioClaimInput(gpio_handle, LG_SET_PULL_NONE, gpio_pin));
        break;
    }
    case OUTPUT:
    {
        lg_ret_check(lgGpioClaimOutput(gpio_handle, LG_SET_PULL_NONE, gpio_pin, 0));
    }
    case INPUT_PULLUP:
    {
        lg_ret_check(lgGpioClaimInput(gpio_handle, LG_SET_PULL_UP, gpio_pin));
    }
    default:
    {
        std::cout << "error incorrect mode specified?" << std::endl;
        break;
    }

    }
}

unsigned long millis()
{
    auto ret = std::chrono::steady_clock::now().time_since_epoch().count();
    std::cout << "ret = " << ret << std::endl;
    return ret;
}

void noInterrupts(void){}
void interrupts(void){}

void delay(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
void delayMicroseconds(int us)
{
    std::this_thread::sleep_for(std::chrono::microseconds(us));
}