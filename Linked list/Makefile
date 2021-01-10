all: single_LL.o double_LL.o app.o
	gcc single_LL.o double_LL.o app.o -o a

single_LL.o: single_LL.c single_LL.h 
	gcc -c single_LL.c 

double_LL.o: double_LL.c double_LL.h
	gcc -c double_LL.c

app.o: app.c linked_list.h
	gcc -c app.c

clean:
	rm *o *exe