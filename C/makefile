CC=gcc
CFLAGS=-I. 
HDRS=vector.h matrix.h
OBJ=main.o matrix.o vector.o

%.o: %.c $(HDRS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -O3 -o a.out $^ $(CFLAGS)

clean:
	rm *.o *.out 
