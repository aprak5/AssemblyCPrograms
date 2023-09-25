/**
* @file readAndPrint.c 
* @author Amit Prakash (aprakas5) and Dr. Sturgill (dbsturgi)
* Exercise to read a sequence of doubles stored in binary format from
* a file, and then write the cosine of each to a file (in text)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**The maximum capacity of values is 100*/
#define VALUES_CAP 100

/**
  * This is the main method of the whole program, handling any errors, otherwise exiting successfully. 
  * @param argc This is the number of arguments in argv.
  * @param This is the arguments given into the program.
  * @return Returns EXIT_SUCCESS or EXIT_FAIL depending on outcome. 
  */
int main( int argc, char *argv[] )
{
  // Open the the input file in binary mode
  // ...
  FILE *inputFile = fopen("doubles.bin", "rb");

  // Open the the output file in text mode
  // ...
  FILE *outputFile = fopen("output.txt", "w");

  // Read double values from the input file using fread().  Use an array
  // that's large enough to hold 100 values, and use the return value
  // of fread to tell how many you successfully read.
  double values[ VALUES_CAP ];
  int numRead = fread(values, sizeof(double), VALUES_CAP, inputFile);
  // ...

  // Loop over the list of values and print the cosine of each
  // to the output file, one value per line with 4 fractional digits
  // of precision.
  // ...
  for(int i = 0; i < numRead; i++) {
    fprintf(outputFile, "%.4f\n", cos(values[i])); 
  }

  // Close both of the files.
  // ...
  fclose(inputFile);
  fclose(outputFile);

  return EXIT_SUCCESS;
}
