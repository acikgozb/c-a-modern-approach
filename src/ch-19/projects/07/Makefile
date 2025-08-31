project: queueclient.o queueADT.o
	gcc -o project queueclient.o queueADT.o -g3

queueclient.o: queueclient.c queueADT.h
	gcc -c queueclient.c queueADT.h -g3

queueADT.o: queueADT.c queueADT.h
	gcc -c queueADT.c queueADT.h -g3
