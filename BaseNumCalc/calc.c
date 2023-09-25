/**
  * @file calc.c
  * @author Amit Prakash (aprakas5)
  * This is the main (top-level) file for the Base Calculator program. This file deals with the errors caught by the other classes and with consolidating the other classes.
  * This class is dependent on base.c and operation.c.
  */
#include "base.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "operation.h"

/**
  * This method is the main method for the class and it consolidates methods from operation.c and base.c by reading user input and giving output, while matching characters passed in to operations in operation.c.
  * @return EXIT_STATUS: If the exit is successful, the exit status is 0 (or normal), otherwise the exit_status is changed based on the error made or given.
  */
int main() {
     long answer = readValue();
     
     int opSymbol = skipSpace();
     
     if(opSymbol != '\n') {
     
          long val1 = readValue();
     
          if(val1 == FAIL_OVERFLOW)
               return FAIL_OVERFLOW;
          if(val1 == FAIL_DIV_BY_ZERO)
               return FAIL_DIV_BY_ZERO;     
          if(val1 == FAIL_INPUT)     
               return FAIL_INPUT;
     
          while(opSymbol != '\n') {
         
               if(opSymbol == '+')
                     answer = plus(answer, val1);
               if(opSymbol == '-')
                     answer = minus(answer, val1);  
               if(opSymbol == '*')
                     answer = times(answer, val1);
               if(opSymbol == '/')
                     answer = divide(answer, val1);
               if(answer == FAIL_OVERFLOW)
                     return FAIL_OVERFLOW;
               if(answer == FAIL_DIV_BY_ZERO)
                     return FAIL_DIV_BY_ZERO;     
               if(answer == FAIL_INPUT)     
                     return FAIL_INPUT;
               if(val1 == FAIL_OVERFLOW)
                     return FAIL_OVERFLOW;
               if(val1 == FAIL_DIV_BY_ZERO)
                     return FAIL_DIV_BY_ZERO;     
               if(val1 == FAIL_INPUT)     
                     return FAIL_INPUT;
               opSymbol = skipSpace();      
               val1 = readValue();     
         }
     }
     writeValue(answer);
     printf("\n");
     return EXIT_SUCCESS;
}