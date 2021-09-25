/*
 * BIT_MATH.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Shady
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(REG,INDEX)    ((REG>>INDEX)&0X01)
#define TOGGLE_BIT(REG,PIN)   REG^=(1<<(PIN))
#define SET_BIT(REG,BIT)      REG|=(1<<BIT)
#define CLEAR_BIT(REG,BIT)	  REG=(REG&(~(1<<BIT)))


#endif /* BIT_MATH_H_ */
