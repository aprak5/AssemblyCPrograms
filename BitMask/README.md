# Bit Mask Program

## Overview

A program to use bitmasking to modify individual bits on variables.

## Build

To build, execute `docker build -t bitmask .` on the command line.

## Run

To run, execute `docker run -it --rm --name bitmask-running bitmask ./bitwise` to run the program on the command line.

To run with files, execute `docker run -it --rm --name bitmask-running bitmask ./bitwise > <output-file>` replacing <output-file> with the appropriate output file name (with extension) to run the program on the command line. 

To compare program output with the expected program output, use `docker run -it --rm --name bitmask-running bitmask diff <expected-file> <output-file>` replacing <expected-file> with the appropriate expected file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 
