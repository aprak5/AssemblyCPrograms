# Linked List Insertion Program

## Overview

A program to read numbers from standard input inserting them into a list in sorted order as we read them.

## Build

To build, execute `docker build -t llinsertion .` on the command line.

## Run

To run, execute `docker run -it --rm --name llinsertion-running llinsertion ./insertion` to run the program on the command line.

To run with files, execute `docker run -i --rm --name llinsertion-running llinsertion ./insertion < <input-file> > <output-file>` replacing <input-file> with the appropriate input file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 

To compare program output with the expected program output, use `docker run -it --rm --name llinsertion-running llinsertion diff <expected-file> <output-file>` replacing <expected-file> with the appropriate expected file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 
