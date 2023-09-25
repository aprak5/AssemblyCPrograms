/**
  * @file operation.h
  * @author Amit Prakash (aprakas5)
  * This is the file for the prototypes for operation. This file deals with the functions in operation.c.
  */

/**This is the exit status for an overflow error.*/
#define FAIL_OVERFLOW 100
/**This is the exit status for a divide by zero error.*/
#define FAIL_DIV_BY_ZERO 101
/**This is the maximum value that can be stored in a long.*/
#define LONG_MAX  9223372036854775807
/**This is 1 + the minimum value that can be stored in a long.*/
#define LONG_MIN -9223372036854775807

/**This is a prototype of plus() in operation.c.*/
long plus(long a, long b);

/**This is a prototype of minus() in operation.c.*/
long minus(long a, long b);

/**This is a prototype of times() in operation.c.*/
long times(long a, long b);

/**This is a prototype of divide() in operation.c.*/
long divide(long a, long b);