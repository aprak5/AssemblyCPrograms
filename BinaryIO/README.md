# Binary I/O Program

## Overview

A program to read and write binary files; it takes numbers and writes their cosines.

## Build

To build, execute `docker build -t binaryio .` on the command line.

## Run

To run, execute `docker run -it --rm --name binaryio-running binaryio ./readAndPrint` to run the program on the command line.

To run with files, execute `docker run -it --rm --name binaryio-running binaryio ./readAndPrint > <output-file>` replacing <output-file> with the appropriate output file name (with extension) to run the program on the command line. 

To compare program output with the expected program output, use `docker run -it --rm --name binaryio-running binaryio diff <expected-file> <output-file>` replacing <expected-file> with the appropriate expected file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 

