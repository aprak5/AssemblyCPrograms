// @file name.c
// @author Amit Prakash (aprakas5)
// This program uses synchonous system calls (parent and child)
// to print out my last name, first name, using exit and wait
// system calls all implemented in the (int) main method.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// This is the main method to run all code necessary for the program.
// Takes no parameters, and returns the exit status (0 - success, !=0 - fail).
// @return The exit status, as predefined in C macros.
int main() 
{
  
  // Make two strings for the first name and last name and store them into first_name and last_name respectively
  char * first_name = "Amit";
  char * last_name = "Prakash";
  
  // Fork the current process and store the generated process id into process_id
  int process_id = fork();
  
  // Is it the child or the parent process?
  if(process_id == 0) {
    // This is the child process
    // We print out the last name to stdout  
    printf("%s", last_name);
  }
  else {
    // This is the parent process
    // Wait for the child process to execute and terminate
    wait(&process_id);
    // We print out the first name to stdout with some formatting characters as well
    printf(", %s\n", first_name);
  }
  // The program ran successfully, so we return EXIT_SUCCESS (predefined C Macro, which is equal to zero)
  return EXIT_SUCCESS;
}