# Mitch (david) Lindsey
# cs4760
# 02-06-2019


CC = gcc
CFLAGS = -g -Wall

OBJ = main.o child.o parent.o checkArgs.o readFile.o writeFile.o
TARGET = a.out
.SUFFIXES: .c .o

a.out: $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ)
%.o: %.c *.h
	$(CC) $(CFLAGS) -c $*.c -o $*.o

clean:
	rm $(TARGET) *.o output.dat
