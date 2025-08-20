rpn: rpn.o stack.o
	gcc -o rpn rpn.o stack.o

rpn.o: stack.h rpn.c
	gcc -c rpn.c

stack.o: stack.h stack.c
	gcc -c stack.c
