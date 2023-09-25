CC = gcc
CFLAGS = -Wall -std=c99 -DBASE=$(BASE)

calc: base.o
calc: operation.o

calc.o: operation.h
calc.o: base.h
base.o: operation.h

 
clean:
	rm -f calc.o operation.o base.o
	rm -f calc