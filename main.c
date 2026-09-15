#include<lpc21xx.h>
#define led1 1<<5
#define led2 1<<6
#define led3 1<<7
#define water 1<<8
int main()
{
int water_level,soilmoisture,temperature,ldr;
adc_init();
lcd_init();
uart0_init(9600);
IODIR0=led1;
IODIR0=led2;
IODIR0=led3;
while(1)
{
temperature=adc_read(1);
temperature=(temperature*330)/1023;
uart0_integer(temperature);
soilmoisture=adc_read(2);
uart0_integer(soilmoisture);
if(IOPIN0&water)
uart0_string("detected");
else
uart0_string("not detected");
ldr=adc_read(3);
if(ldr<=512)
uart0_string("normal");
else
uart0_string("dark");
delay_ms(100);
}

}main.c
