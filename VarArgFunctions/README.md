# Functions with Variable Arguments Program

## Overview

A program to read a variable number of arguments and print them according to a string format specifier.

## Build

To build, execute `docker build -t varargfunc .` on the command line.

## Run

To run, execute `docker run -it --rm --name varargfunc-running varargfunc ./dprintf` to run the program on the command line.

To run with files, execute `docker run -it --rm --name varargfunc-running varargfunc ./p2p > <output-file>` replacing <output-file> with the appropriate output file name (with extension) to run the program on the command line. 

To compare program output with the expected program output, use `docker run -it --rm --name varargfunc-running varargfunc diff <expected-file> <output-file>` replacing <expected-file> with the appropriate expected file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 
