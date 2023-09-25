FROM gcc:4.9
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN make clean
ARG BASE=10
RUN make
CMD ["./test.sh", "./calc", "make", "make clean"]