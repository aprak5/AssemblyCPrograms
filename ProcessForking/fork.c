#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

// @file fork.c
// @author Amit Prakash (aprakas5)
// This program uses synchonous system calls (parent and child)
// to increment global, static, and local variables
// system calls all implemented in the (int) main method.
 
// Define the global variable 
int global = 5;  
 
void foo();  
 
// This is the main method to run all code necessary for the program.
// Takes no parameters, and returns the exit status (0 - success, !=0 - fail).
// @return The exit status, as predefined in C macros.
int main() {  
    
    //Define id
    int id = -2;  

    //Print out the value of the global variable
    printf("main(): global = %d\n" , global);  
    //Run foo() twice so static and local variables are incremented by 2    
    foo();      
    foo();  
    //Store the id of the forked (child) process
    id = fork();  
    //Increment global on the parent process, then wait for the child process to terminate
    if (id != 0) {        
       global++;  
       wait(NULL);  
    }  
    
   //Increment and print global 
   global++;  
   printf( "main(): global = %d\n" , global) ;    

   // The program ran successfully, so we return EXIT_SUCCESS (predefined C Macro, which is equal to zero)
  return EXIT_SUCCESS;
}  
 
// This is the foo method to make, increment, and print the values of a static and local variable.
// Takes no parameters, and returns nothing (void).
void foo() {  
    static int staticInt = 3;      
    int localInt = 1;      
    printf("foo(): staticInt = %d \n" , staticInt);      
    printf("foo(): localInt = %d \n" , localInt);      
    staticInt++;  
    localInt++;  
} 
