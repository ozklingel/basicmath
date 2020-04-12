cc=gcc
FLAG=-Wall

all: myBanklib mains

myBanklib:myBanklib.a

mains: main_1.o myBanklib.a
	$(cc) $(FLAG) -g -o mains main_1.o myBanklib.a

myBanklib.a: hello_ariel.o
	ar rcs -o myBanklib.a hello_ariel.o

main_1.o:hello_ariel.h main_1.c
	$(cc) $(FLAG) -g -c -FPIC main_1.c

hello_ariel.o:hello_ariel.c
	$(cc) $(FLAG) -g -c -FPIC hello_ariel.c

.PHONY: all clean myBanklib


clean:
	rm -f *.o *.a *.so mains
