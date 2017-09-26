#include <bcm2835.h>
#include <stdio.h>
#include "pin.hpp"

Pin::Pin(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6) : ms_delay(30), 
	pin1(pin1), pin2(pin2), pin3(pin3), pin4(pin4), pin5(pin5), pin6(pin6),
	color1(0), color2(0), color3(0), color4(0), color5(0), color6(0)
{
    bcm2835_gpio_fsel(pin1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pin2, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pin3, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pin4, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pin5, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(pin6, BCM2835_GPIO_FSEL_OUTP);
}

Pin::~Pin()
{
}

void Pin::SetColor(int color1, int color2, int color3, int color4, int color5, int color6)
{


    while(this->color1 != color1
    	|| this->color2 != color2
    	|| this->color3 != color3
    	|| this->color4 != color4
    	|| this->color5 != color5
    	|| this->color6 != color6)
    {

		printf("%d %d %d %d\n", 
			this->color1, 
			this->color2, 
			this->color3, 
			this->color4, 
			this->color5, 
			this->color6);

        if (this->color1 != color1) { bcm2835_gpio_write(this->pin1, HIGH); }
        if (this->color2 != color2) { bcm2835_gpio_write(this->pin2, HIGH); }
        if (this->color3 != color3) { bcm2835_gpio_write(this->pin3, HIGH); }
        if (this->color4 != color4) { bcm2835_gpio_write(this->pin4, HIGH); }
        if (this->color5 != color5) { bcm2835_gpio_write(this->pin5, HIGH); }
        if (this->color6 != color6) { bcm2835_gpio_write(this->pin6, HIGH); }

        bcm2835_delay(this->ms_delay);

        if (this->color1 != color1) { bcm2835_gpio_write(this->pin1, LOW); }
        if (this->color2 != color2) { bcm2835_gpio_write(this->pin2, LOW); }
        if (this->color3 != color3) { bcm2835_gpio_write(this->pin3, LOW); }
        if (this->color4 != color4) { bcm2835_gpio_write(this->pin4, LOW); }
        if (this->color5 != color5) { bcm2835_gpio_write(this->pin5, LOW); }
        if (this->color6 != color6) { bcm2835_gpio_write(this->pin6, LOW); }

        bcm2835_delay(this->ms_delay);

        if (this->color1 != color1) { this->color1 = (this->color1 + 1) % 17; }
        if (this->color2 != color2) { this->color2 = (this->color2 + 1) % 17; }
        if (this->color3 != color3) { this->color3 = (this->color3 + 1) % 17; }
        if (this->color4 != color4) { this->color4 = (this->color4 + 1) % 17; }
        if (this->color5 != color5) { this->color5 = (this->color5 + 1) % 17; }
        if (this->color6 != color6) { this->color6 = (this->color6 + 1) % 17; }
        
    }
}
