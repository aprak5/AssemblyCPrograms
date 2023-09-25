# Threading and Forking Program

## Overview

A program to use forking and threading to find certain words in text files.

## Build

To build, execute `docker build -t pthreads .` on the command line.

## Run

To run, execute `docker run -it --rm --name pthreads-running pthreads ./find` to run the find program on the command line.
To run, execute `docker run -it --rm --name pthreads-running pthreads ./find2` to run the find2 program on the command line.

To run with files, execute `docker run -i --rm --name pthreads-running pthreads ./find < <input-file>` replacing <input-file> with the appropriate input file name (with extension) to run the program on the command line. 

To run with files, execute `docker run -i --rm --name pthreads-running pthreads ./find2 < <input-file>` replacing <input-file> with the appropriate input file name (with extension) to run the program on the command line. 

