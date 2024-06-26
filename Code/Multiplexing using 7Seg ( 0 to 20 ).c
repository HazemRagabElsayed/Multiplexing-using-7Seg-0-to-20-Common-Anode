/*
 * Multiplexing_using_7Seg___0_to_20__.c
 *
 * Created: 06/05/2024 01:44:29 م
 *  Author: Hazem Ragab Elsayed
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
#include"DIO.h"
#include"seven_segment.h"
unsigned char counter = 0,i = 0;
int main(void)
{
	seven_seg_vinit('A');
	DIO_vsetPINDir('C',0,1);
	DIO_vsetPINDir('C',1,1);
    while(1)
    {
		if(counter > 20)
		{
			counter = 0;
		}
		for(i = 1;i<=50;i++)
		{
			DIO_write('C',0,1);
			DIO_write('C',1,0);
			seven_seg_write('A',counter%10);
			_delay_ms(10);
			DIO_write('C',0,0);
			DIO_write('C',1,1);
			seven_seg_write('A',counter/10);
			_delay_ms(10);
		}
		
		counter++;
    }
}