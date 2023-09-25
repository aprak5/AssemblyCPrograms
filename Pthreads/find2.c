// @file find2.c
// @author Amit Prakash (aprakas5)
// This program uses threads in a for-loop to search files for a given word (string),
// printing out found lines by file in the findWord() function.
// Main functionality in main() for dealing with threads and Console I/O.

// All libraries used are imported below, to deal with threads, strings, and Console I/O.
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines error code for usage
#define EXIT_ERROR_USAGE -1
// Defines error code for argument type
#define EXIT_ERROR_ARGS_TYPE -2
// Defines maximum line length in a file
#define FILE_MAX_LINE_LEN 120


// This function finds a word given a fileName of type (void *).
// Casting fileName to (char *), it prints out all matching lines with word (char *) to stdout via printf().
// @param (void *) fileName This is the fileName to look for (char *) word in, retrieved via main() from command line arguments ((char *) argv[]).
// @return (void *) Returns a value of variable type, needed for pthread_exit() and thread termination, all other output in the method is to stdout via printf().
void * findWord(void * fileName);

// Global variable to store the word to search for in.
char * word;

// This function contains the main functionality of the program, dealing with Console I/O and threading.
// This function takes in the number of command line arguments and their contents, passes those to findWord() 
// via (char *) word and (void *) fileName, and creates/executes/joins a thread for each file passed.
// @param int argc This is the number of command line arguments 
// @param (char *) argv[] This is the command line arguments passed (stored as an array of strings).
// @return int This is the pred-defined exit code returned (either EXIT_SUCCESS (0) or defined above).
int main(int argc, char * argv[])
{

   // Create thread id and attribute variables, so a thread can be created.
   pthread_t tid;
   pthread_attr_t attr;

  // Verify that the argument number is valid, if not print an error message and exit with appropriate error code.
   if(argc < 3 || argc > 7) {
      printf("Usage: ./find <word> <1-5 file name(s)>\n");
      return EXIT_ERROR_USAGE;
   }
   // For-loop to create/execute/join threads based on the number of file(s) (parameters 3-7 in (char *) argv[], with parameters 4-7 being optional)
   for(int i = 2; i < argc; i++) {
     // Check if the fileName string(s) are valid, if not print an error message and exit with appropriate error code.
     if(strlen(argv[i]) <= 0 || strlen(argv[1]) <= 0) {
        printf("Argument(s) must be greater than length 0 and of type: String.\n");
        return EXIT_ERROR_ARGS_TYPE;
     }
     // Assign the word to look for to the global word variable. Note: this is always (char *) argv[1], according the program format.
     word = argv[1];
     
     // Create a thread for each file
     pthread_attr_init(&attr);
     pthread_create(&tid, &attr, findWord, argv[i]);
    
     // Join the thread using pthread_join().
     pthread_join(tid, NULL);
   }  
   // Exit the program successfully.
   return EXIT_SUCCESS;
}

// This function finds a word given a fileName of type (void *).
// Casting fileName to (char *), it prints out all matching lines with word (char *) to stdout via printf().
// @param (void *) fileName This is the fileName to look for (char *) word in, retrieved via main() from command line arguments ((char *) argv[]).
// @return (void *) Returns a value of variable type, needed for pthread_join() and thread termination, all pther output in the method is to stdout via printf().
void * findWord(void * fileName)
{
   // Define the (char *) currFileName from the (void *) fileName.
   char * currFileName = (char *) fileName;
   // Define a (FILE *) searchFile, by opening currFileName in read-only mode.
   FILE * searchFile = fopen(currFileName, "r");
   // Define the (char *) currLine, dynamically storing the variable with a maximum capacity 
   // of the maximum file line length (FILE_MAX_LINE_LEN (predefined above as 120)).
   char * currLine = (char *) malloc(sizeof(char) * FILE_MAX_LINE_LEN);
   // If the searchFile is not properly accessible, print an error message and exit with appropriate error code.
   if(searchFile == NULL) {
     printf("File with name: %s cannot be accessed with read-only permissions.", currFileName);
   }
   // Otherwise, print the currFileName, search every line (with a maximum capacity 
   // of the maximum file line length (FILE_MAX_LINE_LEN (predefined above as 120)) 
   // in the currFileName for the (char *) word via fgets() and print the line if the word is found. 
   else {
      printf("\n%s: \n\n", currFileName);
      while(fgets(currLine, FILE_MAX_LINE_LEN, searchFile) != NULL) {
        if(strstr(currLine, word) != NULL) {
          printf("%s", currLine);
        }
      }
   }
   // After the last line is found, print a new line, free the dynamic storage for currLine, close the searchFile, and exit the thread successfully.
   printf("\n");
   free(currLine);
   fclose(searchFile);
   pthread_exit(0);
}

// Note: Ran on Unix/Linux box via MobaXterm/SSH; Compilation command: gcc -Wall -std=c99 -pthread -g find2.c -o find2; Test command ./find2 <word> <files>
