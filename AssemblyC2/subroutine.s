### @file subroutines.s
### @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
### Subroutine to find a given character in a string and return
### its index. All functions described below.
### Fill in the rest of this file.

     ## Expose the names of all of our subroutines.
    .global findChar
	
	## Code goes in the text section.
    .text
	
## Implementation of findChar
findChar:
    # Put the address of the string/first character (from rdi) in rcx on the stack and make a counter out of r15.
    push %rcx; 
	lea (%rdi), %rcx;
	mov $0, %r15;
    # Make the loop jump function.
	searchLoop:
	 # Each time compare each character and increment and go to appropriate function.
	  movb (%rcx), %dl
	  cmp $0, %dl;
	  je charNotFound;
	  cmp %dl, %sil;
	  je charFound;
	  inc %rcx;
	  inc %r15;
	jmp searchLoop;
	# If found return index, then go to the end of this function.
	charFound: 
	  mov %r15, %rax;
	  jmp endOfFnc;
	# Otherwise, return -1, then go to the end of this function.
	charNotFound: 
	  mov $-1, %rax;
	  jmp endOfFnc;
	# End of function pop rcx from stack and return rax.
	endOfFnc:  
	  pop %rcx;
    ret;
	