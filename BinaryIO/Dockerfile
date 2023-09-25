FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o readAndPrint readAndPrint.c
CMD ["./readAndPrint"]