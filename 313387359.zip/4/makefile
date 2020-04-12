CC=gcc
CFLAGS=-I.

all:task3

task3:hello_ariel.h main_3.c lib2
	gcc main_3.c -L. -l Hello -o hello3 -ldl
lib2:hello_ariel.h hello_ariel.c
	gcc -shared hello_ariel.c -fPIC -o libHello.so
.PHONY:clean
clean:
	-rm hello1 hello2 hello3 libhello.so 2>/dev/null
