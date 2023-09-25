# Multiple Number System Calculator 

## Overview

This is a calculator which can do basic arithmetic (left to right, not in the standard order of operations) in any number system from Base 2 to 37. 

## Build

To build, execute `docker build -t basenumcalc . --build-arg BASE=10` in terminal. To run in a particular number system, replace 10 with the desired base for the number system. 

To build locally, after the docker build command, execute `docker run -it --rm --name basenumcalc-running basenumcalc make`.

To clean locally, after the docker build command, execute `docker run -it --rm --name basenumcalc-running basenumcalc make clean`.

## Run

To run, execute `docker run -it --rm --name basenumcalc-running basenumcalc ./calc` to run the calc program on the command line. 

To run, with files execute `docker run -i --rm --name basenumcalc-running basenumcalc ./calc < <input-file> > <output-file>` replacing <input-file> with the appropriate input file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the calc program on the command line. 

To compare program output with the expected program output, use `docker run -i --rm --name basenumcalc-running basenumcalc diff <expected-file> <output-file>` replacing <expected-file> with the appropriate expected file name (with extension) and <output-file> with the appropriate output file name (with extension) to run the calc program on the command line. 


## Test

To test, execute `docker run -it --rm --name basenumcalc-running basenumcalc ./test.sh` to run the unit test script on the command line. 

