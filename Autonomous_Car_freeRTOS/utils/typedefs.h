/*
 *  typedefs.h
 *
 *  Created on: Aug 24, 2023
 *  Author: hany nagy
 */

#ifndef TIVA_DIO_TYPEDEFS_H_
#define TIVA_DIO_TYPEDEFS_H_


typedef signed char __int8_t ;
typedef unsigned char __uint8_t ;
#define ___int8_t_defined 1

typedef signed short __int16_t;
typedef unsigned short __uint16_t;
#define ___int16_t_defined 1

typedef signed int __int32_t;
typedef unsigned int __uint32_t;
#define ___int32_t_defined 1

typedef signed long long __int64_t;
typedef unsigned long long __uint64_t;
#define ___int64_t_defined 1

typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
#define ___int_least8_t_defined

typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
#define ___int_least16_t_defined

typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
#define ___int_least32_t_defined

typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
#define ___int_least64_t_defined

typedef __int64_t __intmax_t;
typedef __uint64_t __uintmax_t;



#ifdef ___int8_t_defined
#ifndef _INT8_T_DECLARED
typedef __int8_t int8_t ;
#define _INT8_T_DECLARED
#endif
#ifndef _UINT8_T_DECLARED
typedef __uint8_t uint8_t ;
#define _UINT8_T_DECLARED
#endif
#define __int8_t_defined 1
#endif /* ___int8_t_defined */

#ifdef ___int16_t_defined
#ifndef _INT16_T_DECLARED
typedef __int16_t int16_t ;
#define _INT16_T_DECLARED
#endif
#ifndef _UINT16_T_DECLARED
typedef __uint16_t uint16_t ;
#define _UINT16_T_DECLARED
#endif
#define __int16_t_defined 1
#endif /* ___int16_t_defined */

#ifdef ___int32_t_defined
#ifndef _INT32_T_DECLARED
typedef __int32_t int32_t ;
#define _INT32_T_DECLARED
#endif
#ifndef _UINT32_T_DECLARED
typedef __uint32_t uint32_t ;
#define _UINT32_T_DECLARED
#endif
#define __int32_t_defined 1
#endif /* ___int32_t_defined */

#ifdef ___int64_t_defined
#ifndef _INT64_T_DECLARED
typedef __int64_t int64_t ;
#define _INT64_T_DECLARED
#endif
#ifndef _UINT64_T_DECLARED
typedef __uint64_t uint64_t ;
#define _UINT64_T_DECLARED
#endif
#define __int64_t_defined 1
#endif /* ___int64_t_defined */




#endif /* TIVA_DIO_TYPEDEFS_H_ */
