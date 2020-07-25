CC=g++
CFLAGS=-I.
HDRS=matrix.h
OBJ=main.o matrix.o

%.o: %.c $(HDRS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -O3 -o a.out $^ $(CFLAGS) 
	
clean:
	rm *.o *.out
