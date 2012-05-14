#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define SEVEN_SEGMENT_PORT PORTD
#define SEVEN_SEGMENT_DDR DDRD

void sevensegment(uint8_t n, uint8_t dp)
{
	if(n < 10)
	{
		switch(n)
		{
			case 0:
			SEVEN_SEGMENT_PORT = 0b11111101;
			break;
			case 1:
			SEVEN_SEGMENT_PORT = 0b01100001;
			break;
			case 2:
			SEVEN_SEGMENT_PORT = 0b11011011;
			break;
			case 3:
			SEVEN_SEGMENT_PORT = 0b11110011;
			break;
			case 4:
			SEVEN_SEGMENT_PORT = 0b01100111;
			break;
			case 5:
			SEVEN_SEGMENT_PORT = 0b10110111;
			break;
			case 6:
			SEVEN_SEGMENT_PORT = 0b10111111;
			break;
			case 7:
			SEVEN_SEGMENT_PORT = 0b11100001;
			break;
			case 8:
			SEVEN_SEGMENT_PORT = 0b11111111;
			break;
			case 9:
			SEVEN_SEGMENT_PORT = 0b11100111;
			break;
		}
		
		if(dp)
		{
			SEVEN_SEGMENT_PORT&=0b11111110;
		}
	}
	else 
	{
		SEVEN_SEGMENT_PORT=0b11111101;
	}
}

void wait()
{
	uint8_t i;
	for(i = 0; i < 46; i++)
	{
		_delay_loop_2(0);
	}
}

int main()
{
	SEVEN_SEGMENT_DDR=0xFF; // All output
	SEVEN_SEGMENT_PORT=0xFF; // All segment off
	
	uint8_t count=0;
	
	while(1)
	{
		sevensegment(count, 0);
		
		count++;
		
		if(count == 10)
		{
			count = 0;
		}
		
		wait();
	}
	
	return 0;
}