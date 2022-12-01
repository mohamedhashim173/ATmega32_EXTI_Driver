/*
 * INT_interface.h
 *
 *  Created on: Oct 20, 2022
 *      Author: MSAEED99
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/**************Initializing INT0, INT1 and INT2 Using Pre-build configuration**************/
// INT0 initialization
void EXTI_voidINT0Init(void);
// INT1 initialization
void EXTI_voidINT1Init(void);
// INT2 initialization
void EXTI_voidINT2Init(void);


/**************Initializing INT0, INT1 and INT2 Using Post-build configuration*************/
// INT0 initialization
u8 EXTI_u8INT0Init(u8 copy_u8SenseControl);
// INT1 initialization
u8 EXTI_u8INT1Init(u8 copy_u8SenseControl);
// INT2 initialization
u8 EXTI_u8INT2Init(u8 copy_u8SenseControl);



/****************************Enable of Disable Interrupt (GIE)*****************************/
// Global Interrupt Enable (GIE)
// Enable GIE
void GIE_voidEnable(void);
// Disable GIE
void GIE_voidDisable(void);



/***********************************Set Callback Function***********************************/

/*return: the error code, if return 1, means no errors
 	 	 	 	 	 	  if return 2, NULL user function
 * Parameters: pointer to function (address of a function
 */
u8 EXTI_u8SetCallBackINT0(void (*copy_pvUserFunc)(void));





/*******Sense Control Options for INT0, INT1 and INT2 Using Post-build configuration*******/
// INT0 Sense Control
#define INT0_LOW_LEVEL 		3
#define INT0_ON_CHANGE		4
#define INT0_FALLING_EDGE	5
#define INT0_RISING_EDGE	6

// ================================
// INT0 Sense Control
#define INT1_LOW_LEVEL 		9
#define INT1_ON_CHANGE		10
#define INT1_FALLING_EDGE	11
#define INT1_RISING_EDGE	12

// ================================
// INT2 Sense Control
#define INT2_FALLING_EDGE	15
#define INT2_RISING_EDGE	16


#endif /* EXTI_INTERFACE_H_ */

