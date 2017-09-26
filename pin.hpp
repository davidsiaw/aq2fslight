#ifndef PIN_HPP
#define PIN_HPP

class Pin
{
    int color1;
    int color2;
    int color3;
    int color4;
    int color5;
    int color6;
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    int pin5;
    int pin6;
    int ms_delay;
    
public:
    Pin(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6);
    virtual ~Pin();
    void SetColor(int color1, int color2, int color3, int color4, int color5, int color6);
};

#endif // PIN_HPP
