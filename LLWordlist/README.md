# Linked List Words Program

## Overview

A program to read words from input file and find matches of phrases in the file.

## Build

To build, execute `docker build -t llwordlist .` on the command line.

## Run

To run, execute `docker run -it --rm --name llwordlist-running llwordlist ./wordlist` to run the program on the command line.

To run with files, execute `docker run -i --rm --name llwordlist-running llwordlist ./wordlist < <input-file> > <output-file>` replacing <input-file> with the appropriate input file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 

To compare program output with the expected program output, use `docker run -it --rm --name llwordlist-running llwordlist diff <expected-file> <output-file>` replacing <expected-file> with the appropriate expected file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the program on the command line. 
