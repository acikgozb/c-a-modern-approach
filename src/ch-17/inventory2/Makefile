inventory: inventory.o readline.o
	gcc -o inventory inventory.o readline.o

inventory.o: inventory2.c readline.h
	gcc -c inventory2.c

readline.o: readline.c readline.h
	gcc -c readline.c
