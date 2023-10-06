/*
 * bitwseOperations.h
 *
 *  Created on: Aug 13, 2023
 *      Author: hanyt
 */

#ifndef TIVA_DIO_BITWSEOPERATIONS_H_
#define TIVA_DIO_BITWSEOPERATIONS_H_


#define READ_BIT(reg, bit)                  ((((reg)&(1<<(bit)))>>(bit)))   /*((reg >> bit) & 0x01)*/
#define TOGGLE_BIT(reg, bit)                ((reg)^=(1<<(bit)))
#define readOffset(reg, bit)                (((reg)<<(bit))>>(bit))
#define EXTRACT_BITS(reg, offset, num_bits) (((reg) >> (offset)) & ((1 << (num_bits)) - (1)))
#define INSERT_BIT(reg, bit, value)         ((value)? ((reg)|=(1<<(bit))) : ((reg)&=(~(1<<(bit)))))
#define INSERT_BITS(reg, value, offset, num_bits) \
                                            ((reg) & ~(((1 << (num_bits)) - 1) << (offset))) | ((value) << (offset))


#endif /* TIVA_DIO_BITWSEOPERATIONS_H_ */
