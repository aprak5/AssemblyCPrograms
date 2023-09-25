/**
* @file inventory.c
* @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
* This program takes in different products with given measurements in imperial or metric, returns a sorted list by ascending order in measurement.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// One inch equals this many meters.
#define INCHES_TO_METERS 0.0254
// One millimeter equals this many meters.
#define MM_TO_METERS 0.001

/** Representation for for an imperial measurement, as a length in
* inches.  The length is represented as a mixed numeral, with an
* integer number of inches and a simple fraction represented as
* numerator and denominator.  So, in inches, the length would be
* equivalent to inches + numerator / denominator.
*/
typedef struct {
  int inches;
  int numerator;
  int denominator;
} ImperialLength;

/** Representation for a type of item in our inventory, with
* a length that's measured in metric or imperial units.
*/
typedef struct {
  // Unique ID for this type of item.
  int sku;

  // Enumeration to indicate whether this is a metric or an imperial
  // measurement.
  enum { metric, imperial } mtype;

  // Length, represented in either imperial units (as an instance of
  // ImperialLength) or metric (as a double).  The mtype field says
  // which element of this union we're using.
  union {
    double mval;
    ImperialLength ival;
  } length;
} Item;

// Print a usage message, and exit unsuccessfully.
static void usage()
{
  fprintf( stderr, "usage: inventory <inventory-file>\n" );
  exit( EXIT_FAILURE );
}

/** Complain if the inventory file is bad.*/
static void invalid()
{
  fprintf( stderr, "Invalid inventory file\n" );
  exit( EXIT_FAILURE );
}

/** Comparison function for sorting items.
* @param pA The first item in the function.
* @param pB The second item in the function.
* @return The number indicating the relative order of the first parameter with respect to the second parameter.
*/
int itemComp( void const *pA, void const *pB )
{
  // These two pointers are really pointers to items.
  Item const *itemA = (Item *) pA;
  Item const *itemB = (Item *) pB;

  // Compare the length of the items pointed to by itemA and itemB.
  // ...
  if((itemA->mtype) == 0) {
    double itemAMLen;
    memcpy(&itemAMLen, &(itemA->length), sizeof(double));
    if((itemB->mtype) == 0) {
      double itemBMLen;
      memcpy(&itemBMLen, &(itemB->length), sizeof(double));
      return (int)((itemAMLen - itemBMLen) / MM_TO_METERS);
    }
    else { //if((itemB->mtype) == 1)
      ImperialLength itemBILen;
      memcpy(&itemBILen, &(itemB->length), sizeof(ImperialLength));  
      double itemBMetLen = (((double)(((itemBILen.denominator) * (itemBILen.inches)) + (itemBILen.numerator))) / (itemBILen.denominator)) * INCHES_TO_METERS;
      return (int)((itemAMLen - itemBMetLen) / MM_TO_METERS);
    }
  }
  else { //if((itemA->mtype) == 1)
    ImperialLength itemAILen;
    memcpy(&itemAILen, &(itemA->length), sizeof(ImperialLength));
    double itemAMetLen = (((double)(((itemAILen.denominator) * (itemAILen.inches)) + (itemAILen.numerator))) / (itemAILen.denominator)) * INCHES_TO_METERS;
    if((itemB->mtype) == 0) {
      double itemBMLen;
      memcpy(&itemBMLen, &(itemB->length), sizeof(double));
      return (int)((itemAMetLen - itemBMLen) / MM_TO_METERS);
    }
    else { //if((itemB->mtype) == 1)
      ImperialLength itemBILen;
      memcpy(&itemBILen, &(itemB->length), sizeof(ImperialLength));  
      double itemBMetLen = (((double)(((itemBILen.denominator) * (itemBILen.inches)) + (itemBILen.numerator))) / (itemBILen.denominator)) * INCHES_TO_METERS;
      return (int)((itemAMetLen - itemBMetLen) / MM_TO_METERS);
    }
  }
}
/**
  * The main method has the functionality of the program.
  * @param argc The number of parameters.
  * @param argv The parameters' list.
  * @return Returns EXIT_SUCCESS if successful, otherwise EXIT_FAIL.
  */
int main( int argc, char *argv[] )
{
  // Validate input arguments, and open the inventory input file.
  if ( argc != 2 )
    usage();

  FILE *fp = fopen( argv[ 1 ], "r" );
  if ( !fp ) {
    fprintf( stderr, "Can't open input file: %s\n", argv[ 1 ] );
    exit( EXIT_FAILURE );
  }

  // Read the inventory, first the number of items.
  int icount;
  if ( fscanf( fp, "%d", &icount ) != 1 )
    invalid();

  // Then, read all the inventory items.
  Item *ilist = (Item *) malloc( icount * sizeof( Item ) );
  for ( int i = 0; i < icount; i++ ) {
    // Read an item and store it in element i of ilist.
    // ...
    Item tempItem;
    fscanf(fp, "%d", &(tempItem.sku));
    char mOrI = 0;
    fscanf(fp, " %c", &mOrI);
    if(mOrI == 'i') {
      tempItem.mtype = imperial;
      ImperialLength newILen;
      fscanf(fp, "%d %d / %d", &(newILen.inches), &(newILen.numerator), &(newILen.denominator));
      memcpy(&(tempItem.length), &newILen, sizeof(ImperialLength));
    }
    if(mOrI == 'm') {
      tempItem.mtype = metric;
      double newMLen;
      fscanf(fp, "%lf", &newMLen);
      memcpy(&(tempItem.length), &newMLen, sizeof(double));
    }
    ilist[i] = tempItem;
  }
  //Print output for itemComp
  //printf("%d\n", itemComp(&ilist[0], &ilist[1]));

  // Sort the items by length.
  qsort( ilist, icount, sizeof( Item ), itemComp );

  // Print out the sorted list, in the same format as the input.
  printf( "%d\n", icount );
  for ( int i = 0; i < icount; i++ ) {
    // Print item i from ilist, with a real-valued length if it's metric, or
    // as a mixed numeral if it's imperial.
    // ...
    printf("%d ", ilist[i].sku);
    if(ilist[i].mtype == 0) {
      double mLen;
      memcpy(&mLen, &(ilist[i].length), sizeof(double));
      printf("%c %f\n", 'm', mLen);
    }
    if(ilist[i].mtype == 1) {
      ImperialLength iLen;
      memcpy(&iLen, &(ilist[i].length), sizeof(ImperialLength));
      printf("%c %d %d / %d\n", 'i', (iLen.inches), (iLen.numerator), (iLen.denominator));
    }
  }

  // Free the resources and exit successfully.
  free( ilist );
  fclose( fp );
  return EXIT_SUCCESS;
}
