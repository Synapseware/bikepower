#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>
#include <avr/power.h>
#include <math.h>


//-----------------------------------------------------------------------------
void init()
{
	// configure Timer0 for PWM output on PB0 & PB1 (OC0A & OC0B)
	// running @ max timer clock (resolution = fcpu/256)
	GTCCR	=	(0<<TSM)	|
				(0<<PSR0);

	TCCR0A	=	(1<<COM0A1)	|	// Inverting output on OC0A
				(1<<COM0A0)	|
				(1<<COM0B1)	|	// Invertint output on OC0B
				(1<<COM0B0)	|
				(1<<WGM01)	|	// Fast PWM
				(1<<WGM00);

	TCCR0B	=	(0<<FOC0A)	|
				(0<<FOC0B)	|
				(0<<WGM02)	|	// Fast PWM
				(0<<CS02)	|	// fCPU/1
				(0<<CS01)	|
				(1<<CS00);

	TIMSK	=	(0<<OCIE0A)	|	// No interrupts necessary
				(0<<OCIE0B)	|
				(0<<TOIE0);


	// setup 0CR0a/b to output 2.0v via PWM
	OCR0A	=	(1.0 / (5.0 / 256));	// set OC0A ~= 2.0v
	OCR0B	=	(1.8 / (5.0 / 256));	// set OC0B ~= 2.8v

	DDRB	=	(1<<PB1)	|	// PB1 & PB0 should be outputs
				(1<<PB0);
}


//-----------------------------------------------------------------------------
int main(void)
{
	init();

	while(1)
	{

	}
}

