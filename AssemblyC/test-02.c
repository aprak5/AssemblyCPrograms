/** @file test-02.c
  * @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
  * Test program for the swapGlobals assembly language function.
  */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Global variables to swap.
/**The first global variable to use in the program.*/
int globalA = 99;
/**The second global variable to use in the program.*/
int globalB = -45;

/** Prototype for our assembly language subroutine, so the
  * compiler knows how to call it.  This one takes two pointers
  * to ints and returns nothing.
  */
void swapGlobals();

/**
  * The main method has the functionality of the program.
  * @param argc The number of parameters.
  * @param argv The parameters' list.
  * @return Returns EXIT_SUCCESS if successful, otherwise EXIT_FAIL.
  */
int main( int argc, char *argv[] )
{
  // Report the values before the swap.
  printf( "Before variable swap: %d %d\n", globalA, globalB );

  // Swap the contents of the two functions in assembly.
  swapGlobals();

  // Report the values after the swap.
  printf( "After variable swap: %d %d\n", globalA, globalB );

  // Automated check.
  assert( globalA == -45 );
  assert( globalB == 99 );

  return EXIT_SUCCESS;
}

/** This program doesn't use the following variable, but the assembly
  * language code may expect to link with it, so we need to provide a
  * symbol with that name so this test code will build successfully.
  */
/** Here's the global variable that the assembly language subroutine is expected to modify.*/
int globalVar;

