/**
 * @file bitwise.c
 * @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
 * Code to modify bits using bitwise operations.
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/**The mask for clearing the high-order 6 bits*/
#define Mask1 0x03FF
/**The mask for setting the low-order 9 bits*/
#define Mask2 0x01FF
/**The mask for setting bit 7*/
#define Mask3 0x0080
/**The mask for clearing bit 7*/
#define Mask4 0xFF7F

/*
 * Clear the 6 high-order bits of the given short value, return the result.
 * @param v The short to clear the bits for.
 * @return The short with the cleared bits.
 */
unsigned short clear6( unsigned short v )
{
  return (unsigned short)(v & Mask1);
}

/*
 * Set the low-order 9 bits of the given short value, passed by address.
 * @param v The short to set the bits for.
 */
void set9( unsigned short *v )
{
  *v |= Mask2;
}

/*
 * Set just bit 7 (counting from low-order bit zero) to 1 if flag is true.
 * clear it otherwise.
 * @param v The short to set the bits for.
 * @param flag If true the bit is set, otherwise it is cleared.
 */
void set7( unsigned short *v, bool flag )
{
  if(flag)
    *v |= Mask3;
  else
    *v &= Mask4;  
}

/**
    * This method contains the main functionality of the program.
    * @return This returns the exit status, EXIT_SUCCESS or EXIT_FAIL.
    */
int main()
{
  // Try out our functions.  Don't change any of the lines below.  My test program may
  // automatically modify this part of your source code when it tests your implementation.

  printf( "----- clear6 -----\n" );

  printf( "%04x\n", clear6( 0xFFFF ) );
  printf( "%04x\n", clear6( 0x0000 ) );
  printf( "%04x\n", clear6( 0xA37D ) );
  printf( "%04x\n", clear6( 0x469E ) );

  printf( "----- set9 -----\n" );

  // For the next two functions, we need a real variable.
  unsigned short v;
  
  v = 0xFFFF;
  set9( &v );
  printf( "%04x\n", v );

  v = 0x0000;
  set9( &v );
  printf( "%04x\n", v );

  v = 0xB842;
  set9( &v );
  printf( "%04x\n", v );

  v = 0x19C0;
  set9( &v );
  printf( "%04x\n", v );

  printf( "----- set7 -----\n" );

  v = 0xFFFF;
  set7( &v, 0 );
  printf( "%04x\n", v );

  v = 0x0000;
  set7( &v, 1 );
  printf( "%04x\n", v );

  v = 0x5A70;
  set7( &v, 1 );
  printf( "%04x\n", v );

  v = 0x4F96;
  set7( &v, 1 );
  printf( "%04x\n", v );

  return 0;
}
