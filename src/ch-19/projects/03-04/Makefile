project: stackclient.o stackADT.o
	gcc -o project stackclient.o stackADT.o -g3

stackclient.o: stackclient.c stackADT.h
	gcc -c stackclient.c stackADT.h -g3

stackADT.o: stackADT.c stackADT.h
	gcc -c stackADT.c stackADT.h -g3
