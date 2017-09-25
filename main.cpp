#include <bcm2835.h>
#include <stdio.h>

#define PIN17 RPI_GPIO_P1_11

#define OFF 0
#define RED 16
#define GREEN 15
#define BLUE 14
#define PINK 13
#define WHITE 12
#define YELLOW 11
#define CLEAR_BLUE 10
#define TEAL 9
#define PURPLE 8
#define ORANGE 7
#define SAKURA 6
#define BLUE2 5
#define LIGHTYELLOW 4
#define CYAN 3
#define RED1 2
#define RED2 1

class State
{
	int color;
	int ms_delay;
public:
	State();
	void SetColor(int color);
};

State::State() : color(0), ms_delay(21)
{}

void State::SetColor(int color)
{
	while(this->color != color)
	{
                bcm2835_gpio_write(PIN17, HIGH);
                bcm2835_delay(this->ms_delay);
                bcm2835_gpio_write(PIN17, LOW);
                bcm2835_delay(this->ms_delay);
		this->color = (this->color + 1) % 17;
	}
}

int main()
{
	if (!bcm2835_init())
	{
		printf("crap.\n");
		return 1;
	}
	bcm2835_gpio_fsel(PIN17, BCM2835_GPIO_FSEL_OUTP);

	State s;
	int i=0;
	for(i=0;i<5;i++)
	{
		s.SetColor(TEAL);
		delay(500);
	        s.SetColor(PURPLE);
        	delay(500);
	        s.SetColor(RED);
        	delay(500);
	}

	s.SetColor(OFF);


	//bcm2835_gpio_write(PIN17, HIGH);
	//bcm2835_delay(2000);
	//bcm2835_gpio_write(PIN17, LOW);

	//bcm2835_delay(25);
        //bcm2835_gpio_write(PIN17, HIGH);
        //bcm2835_delay(2000);
        //bcm2835_gpio_write(PIN17, LOW);

	bcm2835_close();
	return 0;
}
