justify: justify.o word.o line.o
	gcc -o justify justify.o word.o line.o -g3

justify.o: justify.c word.h line.h
	gcc -c justify.c -g3

word.o: word.c word.h
	gcc -c word.c -g3

line.o: line.c line.h
	gcc -c line.c -g3
