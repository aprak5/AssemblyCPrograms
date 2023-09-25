/**
  * @file base.h
  * @author Amit Prakash (aprakas5)
  * This is the file for the prototypes for base. This file deals with the functions in base.c.
  */


/** Exit status indicating that the program was given invalid input. */
/**This is the exit status for incorrect input.*/
#define FAIL_INPUT 102
/**This is the number of possible digits 10 for 0-9 and 26 for A-Z.*/
#define NUM_POSSIBLE_DIGITS 36
/**This is the maximum amount of bits in a long.*/
#define MAX_BITS_LONG 64
/**This is the exit status for an overflow error.*/
#define FAIL_OVERFLOW 100

/**The is a prototype of the skipSpace() in base.c.*/
int skipSpace();
/**The is a prototype of the readValue() in base.c.*/
long readValue();
/**The is a prototype of the writeValue() in base.c.*/
void writeValue(long value);