### @file subroutines.s
### @author Amit Prakash (aprakas5) and Dr. Sturgil (dbsturgi)
### Subroutines called from C. Called by all the text-0X programs. All functions described below.
    
### You should be able to compile this with each of the
### test programs to try out each of the functions.
    
    ## Expose the names of all of our subroutines.
    .global setGlobal
	.global swapGlobals
	.global sixParams
	.global formula

    ## Code goes in the text section.
    .text

### Implementation of setGlobal, assign 47 to a global variable.
setGlobal:
    # ...
	mov $globalVar, %eax
    movl $47, (%eax)
    ret                         # Return to the caller.
    
### Implementation of swapGlobals, exchange the value of two global variables
swapGlobals:
    # ...
	movl globalA, %eax
	movl globalB, %ecx
	movl %ecx, globalA
	movl %eax, globalB
    ret
	
### Implementation of sixParams, computes the signed int value of a * d + b * e - c * f
sixParams:
    # ...
    mov %edi, %eax #eax = a (edi)
    imul %ecx, %eax #eax = a = a * d (ecx)  
	mov %esi , %ebx #ebx = b (esi)
	imul %r8d, %ebx #ebx = b = b * e (r8d)
	add %ebx, %eax #eax = (a * d) + (b * e)
	mov %edx, %r10d #r10d = c (edx)
	imul %r9d, %r10d #r10d = c * f (r9d)
	sub %r10d, %eax #eax = eax - r10d = (a * d) + (b * e) - (c * f)
	ret
	
### Implementation of formula, computes the result of x * ( 100 - globalA * y ) + 3 * globalB * globalB
formula:
    # ...
	mov globalA, %eax 
	mov globalB, %ecx
	imul %ecx, %ecx
	imul $3, %ecx
	mov $100, %edx
	imul %esi, %eax
	sub %eax, %edx
	imul %edi, %edx
	add %edx, %ecx
	mov %ecx, %eax
	ret
	

