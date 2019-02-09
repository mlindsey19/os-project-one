# Mitch (david) Lindsey
# cs4760
# 02-06-2019


CC = gcc
CFLAGS = -g -Wall

OBJ = main.o child.o parent.o checkArgs.o readFile.o writeFile.o

a.out: $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ)
main.o: main.c *.h
	$(CC)  $(CFLAGS) -c main.c

checkArgs.o: checkArgs.c
	$(CC) $(CFLAGS) -c checkArgs.c
parent.o: parent.c
	$(CC) $(CFLAGS) -c parent.c
child.o: child.c
	$(CC) $(CFLAGS) -c child.c
readFile.o: readFile.c
	$(CC) $(CFLAGS) -c readFile.c
writeFile.o: writeFile.c
	$(CC) $(CFLAGS) -c writeFile.c
clean:
	rm a.out $(OBJ)
