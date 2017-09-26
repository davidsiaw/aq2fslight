#include <bcm2835.h>
#include <stdio.h>

#include "pin.hpp"
#include "pi_defines.h"

enum Girl
{
    None,
    Chika,
    Riko,
    Kanan,
    Dia,
    You,
    Yohane,
    Maru,
    Mari,
    Ruby 
};

int main()
{
    if (!bcm2835_init())
    {
        printf("crap.\n");
        return 1;
    }

    Pin a(PIN21, PIN16, PIN12, PIN1, PIN8, PIN24);

    int i=0;
    while(true)
    {
        a.SetColor(TEAL, PURPLE, RED1, TEAL, ORANGE, ORANGE);
        delay(2500);
        a.SetColor(PURPLE, RED1, TEAL, PURPLE, SAKURA, SAKURA);
        delay(2500);
        a.SetColor(RED1, TEAL, PURPLE, RED1, CLEAR_BLUE, CLEAR_BLUE);
        delay(2500);
    }

    a.SetColor(OFF, OFF, OFF, OFF, OFF, OFF);

    bcm2835_close();
    return 0;
}
