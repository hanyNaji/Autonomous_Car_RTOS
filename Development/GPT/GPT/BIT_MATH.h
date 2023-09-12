
/*======================================================================================
=======================  guard of file will call on time in .c	========================
========================================================================================*/



 #ifndef BIT_MATH_H_
 #define BIT_MATH_H_


#define SET_BIT(REG , BITNUM) REG |= 1U<<BITNUM
#define CLR_BIT(REG , BITNUM) REG &= ~(1U<<BITNUM)
#define TOG_BIT(REG , BITNUM) REG ^= 1U<<BITNUM
#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1U )
#define INSERT_BIT(REG,BITNUM,value)    ((value)?((REG)|=(1U<<(BITNUM))):((REG)&=~(1U<<(BITNUM))))

 #endif /* BIT_MATH_H_ */
