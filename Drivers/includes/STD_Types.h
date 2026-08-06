/************************************************/
/********* Author: Khadija Naji *****************/
/********* Date  : 29/07/2026   *****************/
/********* File  : STD Types Library   **********/
/************************************************/

#ifndef STD_LIB_H_
#define STD_LIB_H_

typedef unsigned char      u8;
typedef unsigned short int u16;
typedef unsigned int       u32;

typedef signed char        s8;
typedef signed short int   s16;
typedef signed int         s32;

typedef float              f32;
typedef double             f64;
typedef long double        f128;

typedef void  (*pf)     (void) ; // pointer to function
typedef void  (*pf_u8) (u8)    ;

#endif
