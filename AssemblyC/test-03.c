/** @file test-03.c
  * @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
  * Test program for the sixParams assembly language function.
  */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/** Prototype for our assembly language subroutine, so the
  * compiler knows how to call it.  This one takes six integer
  * parameters and returns an integer result.
  * @param a The first parameter.
  * @param b The second parameter.
  * @param c The third parameter.
  * @param d The fourth parameter.
  * @param e The fifth parameter.
  * @param f The sixth parameter.
  * @return The result calculated with the assembly language subroutine (result detailed in subroutine.s).
  */
int sixParams( int a, int b, int c, int d, int e, int f );

/**
  * The main method has the functionality of the program.
  * @param argc The number of parameters.
  * @param argv The parameters' list.
  * @return Returns EXIT_SUCCESS if successful, otherwise EXIT_FAIL.
  */
int main( int argc, char *argv[] )
{
  // Call the assembly language subroutine.
  int result = sixParams( 5, 10, 15, 20, 25, 30 );

  // Report the result afterward.
  printf( "Result 1: %d\n", result );

  // Automated check to make sure it's right.
  assert( result == -100 );

  // Try another call with different parameters
  result = sixParams( -3, -2, 8, 5, -7, -13 );

  // Report the result afterward.
  printf( "Result 2: %d\n", result );

  // Automated check to make sure it's right.
  assert( result == 103 );

  // Try with larger parameter values.  These won't overflow, but
  // they'll get close.
  result = sixParams( 58382, 22341, 24526, 23825, 33295, 13372 );

  // Report the result afterward.
  printf( "Result 3: %d\n", result );

  // Automated check to make sure it's right.
  assert( result == 1806833073 );

  return EXIT_SUCCESS;
}

// This program doesn't use the following variables, but the assembly
// language code may expect to link with them, so we need to provide a
// symbol with that name so this test code will build successfully.
/**The first global variable to use in the program.*/
int globalA;
/**The second global variable to use in the program.*/
int globalB;
/** Here's the global variable that the assembly language subroutine is expected to modify.*/
int globalVar;

