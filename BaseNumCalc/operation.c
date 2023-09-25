/**
  * @file operation.c
  * @author Amit Prakash (aprakas5)
  * This is the file for the main functionality of Base Calculator program. This file deals with the errors caught by performing operations.
  * This class is independent of base.c and operation.c.
  */

#include "base.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "operation.h"

/**
  * This adds two given numbers together and returns the value.
  * @param a This is the first number given to add.
  * @param b This is the second number given to add.
  * @return This is the sum of the two numbers.
  */
long plus( long a, long b )
{
     if(a > LONG_MAX || b > LONG_MAX)
          return FAIL_OVERFLOW;
     if((a + 1) < LONG_MIN || (b + 1) < LONG_MIN)
          return FAIL_OVERFLOW;     
     if(a > 0 && b > 0 && (a + b) < 0)
          return FAIL_OVERFLOW;
     if(a < 0 && b < 0 && (a + b) > 0)    
          return FAIL_OVERFLOW;
     if(a > 0 && b < 0 && (a + b) > a)
          return FAIL_OVERFLOW;
     if(a < 0 && b > 0 && (a + b) > b)
          return FAIL_OVERFLOW;          
     return (a + b);      
}

/**
  * This subtracts two given numbers and returns the value.
  * @param a This is the first number given to subtract from.
  * @param b This is the second number given to subtract.
  * @return This is the difference of the two numbers.
  */
long minus( long a, long b )
{
     if(a > LONG_MAX || b > LONG_MAX)
           return FAIL_OVERFLOW;
     if((a + 1) < LONG_MIN || (b + 1) < LONG_MIN)
           return FAIL_OVERFLOW;
     if(a > 0 && b < 0 && (a - b) < 0)
           return FAIL_OVERFLOW;
     if(a < 0 && b > 0 && (a - b) > 0)    
           return FAIL_OVERFLOW;
     if(a > 0 && b > 0 && (a - b) > a)
           return FAIL_OVERFLOW;
     if(a < 0 && b < 0 && (a - b) < a)
           return FAIL_OVERFLOW;          
     return (a - b);
}

/**
  * This mutiplies two given numbers together and returns the value.
  * @param a This is the first number given to multiply.
  * @param b This is the second number given to multiply.
  * @return This is the product of the two numbers.
  */
long times( long a, long b )
{
     if(a > LONG_MAX || b > LONG_MAX)
          return FAIL_OVERFLOW;
     if((a + 1) < LONG_MIN || (b + 1) < LONG_MIN)
          return FAIL_OVERFLOW;
     if(a > 0 && b > 0) {
          long x = LONG_MAX / b;
          long y = LONG_MAX / a;
     
          if(a > x)
               return FAIL_OVERFLOW;
          if(b > y)
               return FAIL_OVERFLOW;    
     } 
     
     if(a < 0 && b < 0) {
          long x = LONG_MAX / b;
          long y = LONG_MAX / a;
     
          if(a < x)
               return FAIL_OVERFLOW;
          if(b < y)
               return FAIL_OVERFLOW;    
     }
     
     if(a > 0 && b < 0) {
          long x = LONG_MIN / b;
          long y = LONG_MIN / a;
     
          if(a > x)
               return FAIL_OVERFLOW;
          if(b < y)
               return FAIL_OVERFLOW;    
     }
     
     if(a < 0 && b > 0) {
          long x = LONG_MIN / b;
          long y = LONG_MIN / a;
     
          if(a < x)
               return FAIL_OVERFLOW;
          if(b > y)
               return FAIL_OVERFLOW;    
     }        
     
     return (a * b);
}

/**
  * This divides two given numbers and returns the value.
  * @param a This is the first number given to divide from.
  * @param b This is the second number given to divide.
  * @return This is the quotient of the two numbers.
  */
long divide( long a, long b )
{
      if(a > LONG_MAX || b > LONG_MAX)
           return FAIL_OVERFLOW;
      if((a + 1) < LONG_MIN || (b + 1) < LONG_MIN)
           return FAIL_OVERFLOW;
      if(b == 0)
           return FAIL_DIV_BY_ZERO;
      return (a / b);    
}