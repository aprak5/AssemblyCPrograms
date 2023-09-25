/** @file test-04.c
  * @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
  * Test program for the formula assembly language function.
  */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Global variables used by our assembly language function.*/
/**The first global variable to use in the program.*/
int globalA;
/**The second global variable to use in the program.*/
int globalB;

/** Prototype for our assembly language subroutine, so the compiler knows how to call it.
  * @param x The first parameter.
  * @param y The second parameter.
  * @return The result calculated as detailed in the formula in subroutine.s.
  */
int formula( int x, int y );

/**
  * The main method has the functionality of the program.
  * @param argc The number of parameters.
  * @param argv The parameters' list.
  * @return Returns EXIT_SUCCESS if successful, otherwise EXIT_FAIL.
  */
int main( int argc, char *argv[] )
{
  // Set the globals and call the assembly language subroutine.
  globalA = 5;
  globalB = 7;
  int result = formula( 11, 13 );

  // Report the result afterward.
  printf( "Result 1: %d\n", result );

  // Automated check to make sure it's right.
  assert( result == 532 );

  // Try some different values and evaluate the function.
  globalA = -17;
  globalB = -23;
  result = formula( -29, -31 );

  // Report the result afterward.
  printf( "Result 2: %d\n", result );

  // Automated check to make sure it's right.
  assert( result == 13970 );

  // Try some different values and evaluate the function.
  globalA = -70;
  globalB = 3;
  result = formula( 30, -60 );

  // Report the result afterward.
  printf( "Result 3: %d\n", result );

  // Automated check to make sure it's right.
  assert( result == -122973 );

  return EXIT_SUCCESS;
}

/* This program doesn't use the following variable, but the assembly
 * language code may expect to link with it, so we need to provide a
 * symbol with that name so this test code will build successfully.
 */
/** Here's the global variable that the assembly language subroutine is expected to modify.*/
int globalVar;
