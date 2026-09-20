/*
 * BIT_MATH.h
 *
 * Created: 9/20/2026 12:11:49 PM
 *  Author: Mariam.Kotb
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,BIT) (var|=(1<<BIT))
#define CLR_BIT(var,BIT) (var&=(~(1<<BIT)))
#define TOGGLE_BIT(var,BIT) (var^=(1<<BIT))
#define  GET_BIT(VAR,BIT)  ((VAR>>BIT)&1)





#endif /* BIT_MATH_H_ */