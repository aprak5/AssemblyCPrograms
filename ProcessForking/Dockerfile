FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o fork fork.c
RUN gcc -o name name.c
CMD ["./fork", "./name"]