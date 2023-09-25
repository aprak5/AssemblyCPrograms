# Bit Mask Program

## Overview

A program to use custom structs to take a list of measurements and return a sorted list.

## Build

To build, execute `docker build -t customstructs .` on the command line.

## Run

To run, execute `docker run -it --rm --name customstructs-running customstructs ./inventory` to run the program on the command line.

To run with files, execute `docker run -i --rm --name customstructs-running customstructs ./inventory < <input-file> > <output-file>` replacing <input-file> with the appropriate input file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 

To compare program output with the expected program output, use `docker run -it --rm --name customstructs-running customstructs diff <expected-file> <output-file>` replacing <expected-file> with the appropriate expected file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 
