FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o test-01 test-01.c subroutines.s
RUN gcc -o test-02 test-02.c subroutines.s
RUN gcc -o test-03 test-03.c subroutines.s
RUN gcc -o test-04 test-04.c subroutines.s
CMD ["./test-01", "./test-02", "./test-03", "./test-04"]