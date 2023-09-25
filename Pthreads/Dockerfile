FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -Wall -std=c99 find.c -o find
RUN gcc -Wall -std=c99 -pthread find2.c -o find2
CMD ["./find", "./find2"]