all: app.o stack.o
	gcc app.o stack.o -o a

app.o: app.c stack.h
	gcc -c app.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm *o *exe