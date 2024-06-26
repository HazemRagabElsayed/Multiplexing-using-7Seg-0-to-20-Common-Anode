
#include "DIO.h"
void seven_seg_vinit(unsigned char port_name)
{
	DIO_set_port_direction(port_name,0xFF);
}

void seven_seg_write(unsigned char portname,unsigned char number)
{
unsigned char arr[]={ 0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

DIO_write_port(portname,arr[number]);
}