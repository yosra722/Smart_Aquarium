/*
 * EXTI_private.h
 *
 *  Created on: Aug 4, 2026
 *      Author: Amena hassan
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define	MCUCR	*((volatile u8*)0x55)		// To set sense mode for INT0 , INT1
#define	MCUCSR	*((volatile u8*)0x54)		// To set sense mode for INT2
#define	GICR	*((volatile u8*)0x5B)		// To enable or disable interrupt
#define	GIFR	*((volatile u8*)0x5A)		// To set or clear flag interrupt

#define	ISC00	0		// INT0
#define	ISC01	1		// INT0
#define	ISC10	2		// INT1
#define	ISC11	3		// INT1
#define	ISC2	6		// INT2

#define	INT0_BIT	6		// Enable , Disable
#define	INT1_BIT	7
#define	INT2_BIT	5

#define	INTF0_BIT	6		// Flag
#define	INTF1_BIT	7
#define	INTF2_BIT	5


#endif /* EXTI_PRIVATE_H_ */
