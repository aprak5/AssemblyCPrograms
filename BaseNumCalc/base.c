/**
  * @file base.c
  * @author Amit Prakash (aprakas5)
  * This is the main io file for the Base Calculator program. This file deals with the errors caught in reading or writing output.
  * This class is dependent on operation.c.
  */

#include "base.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "operation.h"

// This preprocessor syntax makes it so we can override the value of BASE with
// a compiler option.  For some desired base, n, we can compile with: -DBASE=n
// Don't change these three lines of preprocessor directives.
#ifndef BASE
/** Base this program uses for input and output. */
#define BASE 7
#endif

/**
  * This method gives the first non-whitespace character.
  * @return ch: The first non-whitespace character.
  */
int skipSpace() 
{
     int ch = ' '; 
     while(ch == ' ') {
          ch = getchar();
     } 
     return ch;
}

/**
  * This method checks to see whether or not the given character is valid or not.
  * @param ch This is the character to see if it is valid of not.
  * @return This returns true if valid, otherwise false.
  */
bool isValidDigit(int ch) 
{
int validDigits[NUM_POSSIBLE_DIGITS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
     for(int i = 0; i < NUM_POSSIBLE_DIGITS; i++) {
          if(ch == validDigits[i]) 
               if(i < BASE) 
                    return true;             
     }
     return false;
}

/**
  * This converts a character to a digit using a for-loop.
  * @param ch This is the character given, with its unique ASCII code.
  * @return The numerical value of the character given.
  */
int charToDigit(int ch) 
{
     int validDigits[NUM_POSSIBLE_DIGITS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
     for(int i = 0; i < NUM_POSSIBLE_DIGITS; i++) {
          if(ch == validDigits[i])
               return i;     
     }
     return 0;
}

/**
  * This converts a digit to a character using a for-loop.
  * @param digit This is the digit given.
  * @return The ASCII value of the digit given as a character.
  */
int digitToChar(int digit) 
{
     int validDigits[NUM_POSSIBLE_DIGITS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
     return validDigits[digit];
}

/**
  * This raises the given base to the power of the exponentiation given and performs the according calculation.
  * @param base This is the base of the exponentiation calculation.
  * @param exp This is the exponent of the exponentiation calculation.
  * @return This is the answer to the given calculation.
  */
long numToPow(int base, int exp)
{
      long answer = 1; //any nonzero number to the zeroth power is 1
      for(int i = exp; i > 0; i--) {
           answer *= base;
      }
      return answer;
}

/**
  * This reads in a value using getchar() from a given number system (with the numbering system base as BASE) and outputs the number in denary.
  * @return value This is the value the user inputted in denary.
  */
long readValue()
{
     // Value we've parsed so far.
     long value = 0; //Initial value is zero
  
     // Get the next input character.
     int ch = skipSpace();
     int sizeOfValue = 0;
     bool isNeg = false;
     int valueChars[MAX_BITS_LONG + 1];
  
     for(int i = 0; i < MAX_BITS_LONG + 1; i++) {
          valueChars[i] = 0;
     }
  
     if(ch == '-') {
          isNeg = true;
          ch = getchar();
     }
  
     if(ch == '+' || ch == '-' || ch == '*' || ch == '/') 
          return FAIL_INPUT; 

     int i = 0; //counter
     bool isOverflow = false;
     while (isValidDigit(ch) && !isOverflow) {
          if(sizeOfValue < MAX_BITS_LONG + 1) {
               valueChars[i] = ch;
               ch = getchar();
               sizeOfValue++;
          }
          else {
               isOverflow = true;
          }
          i++;     
     } 
     
     if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
           ungetc(ch, stdin); 
     } 
     else {
           if((!isValidDigit(ch) && (ch != ' ' && ch != '\n')) || isOverflow) {
                if(isOverflow)
                     return FAIL_OVERFLOW;
                else
                     return FAIL_INPUT;     
           }          
     }
     
     if(ch == '\n')
          ungetc(ch, stdin);
  
     //Array of characters' ASCII codes to store the number
     int copyValueChars[sizeOfValue];
  
     for(int i = 0; i < sizeOfValue; i++) {
          copyValueChars[i] = valueChars[i];
     }
  
     // Keep reading as long as we're seeing digits
     int j = 0; //counter
  
     for(int i = sizeOfValue - 1; i >= 0; i--) {
          // Convert from ASCII code for the next digit into the value
          // of that digit.  For example 'A' -> 10 or '7' -> 7
          int d = charToDigit(copyValueChars[i]);
          value = plus(value, (d * (numToPow(BASE, j))));
          j++;
     }
  
     if(isNeg)
          value *= -1;       
     return value;
}

/**
  * This writes a value given in denary using putchar() in the number system given by BASE.
  * @param value This is the value given in denary to write out.
  */
void writeValue(long value)
{
     int sizeOfValue = 0;
     long orgVal = value;
     long parVal = value;
   
     if(value == 0) {
          putchar('0');
          return;
     }
   
     if(orgVal < 0) {
          sizeOfValue++;
          if((orgVal + 1) != LONG_MIN) {
                orgVal *= -1;
          }     
          else {
                orgVal++;
                orgVal *= -1;
          }         
     }

     while (value != 0) {
          value = value / BASE;
          sizeOfValue++;
     }     
   
     int valueChars[sizeOfValue];    
     int i = sizeOfValue - 1;
   
     // While there are more digits to print.
     while (orgVal != 0 && i >= 0) {  
    
           // Convert it to a character, e.g, 13 -> 'D' or 3 -> '3'
           int ch = digitToChar(orgVal % BASE);
           valueChars[i] = ch;
    
           // Slide remaining digits to the right.
           orgVal = orgVal / BASE;
           i--;   
     }
 
     if((parVal + 1) == LONG_MIN) 
           valueChars[(sizeOfValue - 1)]++;
  
     if(parVal < 0) 
           valueChars[0] = '-';    
 
     if(parVal != 0) {
           for(int i = 0; i < sizeOfValue; i++) {
                  putchar(valueChars[i]);
           }
     }
}