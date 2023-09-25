/**
* @file dprintf.c 
* @author Amit Prakash (aprakas5) and Dr. Sturgill (dbsturgi)
* Exercise to read a variable number of arguments and print them according to a string format specifier.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**The standard number system (denary)*/
#define BASE_SYS 10

/** Append a given character, ch, to the end of a resizable array of
    characters.  The representation for the resizable array (str (the
    array), len (number of elements used) and cap (capacity)) are all
    passed by address, so this function can change them if needed. */
void append( char **str, int *len, int *cap, char ch )
{
  // Grow the array if it's not big enough.
  if ( *len + 1 >= *cap ) {
    *cap *= 2;
    *str = (char *) realloc( *str, *cap );
  }

  // Add ch to the end (a little ugly because str, len and cap are
  // all passed by address).
  (*str)[ (*len) ++ ] = ch;
}
/**
* This prints a variable number of arguments given a format string.
* @param fmt This is the format string.
* @param ... These are the variable number of arguments.
* @return This returns the string formatted as specified with the given arguments as strings.
*/
char *d_printf( const char *fmt, ... )
{
  // Setup vararg processing
  // ...
  va_list argList;
  va_start( argList, fmt );
  

  // Resizable array of chars.
  int len = 0;
  int cap = 5;
  char *dest = (char *) malloc( cap );

  // Go through the format string.
  int pos = 0;
  while ( fmt[ pos ] ) {
    if ( fmt[ pos ] == '%' ) {
      // The current character is a %.  See if it's the start of %s,
      // %u or %% and handle it appropriately if it is.
      // ...
      if( fmt[ pos + 1 ] == '%' ) {
        append( &dest, &len, &cap, '%' );
      } 
      else if( fmt[ pos + 1 ] == 's' ) {
        char *temp = va_arg( argList, char * );
        for(int i = 0; temp[i]; i++) 
          append( &dest, &len, &cap, temp[i] );
      } 
      else if( fmt[ pos + 1 ] == 'u' ) {
        unsigned int tempNum = va_arg( argList, unsigned int );
        unsigned int tempNum2 = tempNum;
        unsigned int numDig = 1;
        while( tempNum2 >= BASE_SYS ) {
          tempNum2 /= BASE_SYS;
          numDig++;
        }  
        char *tempNumToStr = malloc( sizeof( char ) * numDig );
        for( int i = numDig; i >= 1; i-- ) {
          tempNumToStr[ i - 1 ] = (char)((tempNum % BASE_SYS) + '0');
          tempNum /= BASE_SYS;
        }
        for(int i = 0; i < numDig; i++) {
          append( &dest, &len, &cap, tempNumToStr[i] );
        }
        free(tempNumToStr);
      }
      // Advance past the next two characters in the format string,
      // unless we're at the end of the string already.
      if ( fmt[ pos + 1 ] )
        pos += 2;
      else
        pos += 1;
    } else {
      // Ordinary character, just copy it to the destination string.
      append( &dest, &len, &cap, fmt[ pos ] );
      pos += 1;
    }
  }

  // Null terminate the resulting string.
  append( &dest, &len, &cap, '\0' );
  
  // We're done processing arguments.
  // ...
  va_end( argList );

  // Return the string we made.
  return dest;
}

// Leave the rest of this unchanged.  This conditional compilation
// code will let me replace main() with a different test function for
// grading.
#ifndef OMIT_MAIN
/**
* This tests the d_printf function.
* @return The exit status, either EXIT_SUCCESS or EXIT_FAIL.
*/
int main()
{
  char *str;

  // Try a format string with no conversion specifications
  str = d_printf( "Testing\n" );
  printf( "%s", str );
  free(str);

  // A format string with a string conversion specification.
  char *name = "Bill";
  str = d_printf( "Hello %s.\n", name );
  printf( "%s", str );
  free( str );

  // A format string with an unsigned int conversion specification.
  unsigned int val = 72351;
  str = d_printf( "value: %u\n", val );
  printf( "%s", str );
  free( str );

  // A zero might be a special case when you print it.
  val = 0;
  str = d_printf( "A zero looks like \"%u\"\n", val );
  printf( "%s", str );
  free( str );

  // A format string that includes a literal % sign.
  val = 25;
  str = d_printf( "%u%% increase\n", val );
  printf( "%s", str );
  free( str );

  // A format string with a few different conversion specifications.
  str = d_printf( "Countdown: %u 4 %u %s %u 0. %s!\n",
                 5, 3, "2", 1, "blastoff" );
  printf( "%s", str );
  free( str );

  return EXIT_SUCCESS;
}

#endif
