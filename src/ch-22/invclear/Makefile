invclear: invclear.o inv.o
	gcc -o ./invclear invclear.o inv.o

invclear.o: invclear.c inv.h
	gcc -c invclear.c inv.h

inv.o: inv.c inv.h
	gcc -c inv.c inv.h
