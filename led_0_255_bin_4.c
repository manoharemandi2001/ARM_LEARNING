/*
4) Write an ECP to display binary equivalent of 0-255 on 8-leds (4-active high led’s and 4-active low led’s)  
*/

#include <LPC21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"

#define leds 17

s32 main()
{
	u16 i=0;

	
	IODIR1|=(0xFF<<leds); //cfg as output
	
	//INITIAL LEDS OFF (upper nibble-AL, lower nibble-AH)
	IOPIN1 = (IOPIN1&(~(0XFF<<leds))) | (0X0F<<leds);
	

		for(i=0; i<=255; i++)
		{

				IOPIN1=  (IOPIN1&(~(0xff <<leds))) | ((i^(0x0F))<<leds);
				delay_ms(100);
		}

}
