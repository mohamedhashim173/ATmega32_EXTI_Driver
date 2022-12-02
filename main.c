/*
 * main.c
 *
 *  Created on: Oct 21, 2022
 *      Author: MSAEED99
 */


// Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL
#include "DIO_interface.h"
#include "EXTI_interface.h"


// Prototypes
void LED_ON_ISR(void);


/*
 * Turn ON LED using EXTI and execute ISR with a callback function
 */
void main(void)
{
	// Activate pull-up resistor for INT0 pin (Connect INT0 to a tactile switch to connect to ground)
	DIO_voidSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_INPUT);
	DIO_voidSetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_HIGH);

	// Set the LED pin to be output
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_OUTPUT);

	/*********** Initialize INT0 ***********/
	// pre-build configuration
	// EXTI_voidINT0Init();
	// post-build configuration
	u8 local_u8ErrorCode;
	local_u8ErrorCode = EXTI_u8INT0Init(INT0_FALLING_EDGE);

	// Enable GIE
	GIE_voidEnable();


	// Call back function that passes the address of user function to ISR in program.c
	EXTI_u8SetCallBackINT0(&LED_ON_ISR);

	while(1)
	{
		// Super Loop
	}
}


// LED_ON_ISR Function (implemented by user) to be executed from program.c
void LED_ON_ISR(void)
{
	// Set LED pin to high
	DIO_voidSetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_HIGH);
}



