/*
 * Std_Types.h
 *
 *  Created on: May 16, 2026
 *      Author: Seif
 */

#ifndef INC_STD_TYPES_H_
#define INC_STD_TYPES_H_

/* Unsigned Types */
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned long       uint32;

/* Signed Types */
typedef signed char         sint8;
typedef signed short        sint16;
typedef signed long         sint32;

/* Floating Point Types */
typedef float               float32;
typedef double              float64;

/* Boolean Values */
#define TRUE                1U
#define FALSE               0U
/* NULL Pointer */
#define NULL_PTR            ((void *)0)

#endif /* INC_STD_TYPES_H_ */
