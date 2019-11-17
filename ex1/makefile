a.out: main.o power.o basicmath.o
		gcc -o a.out main.o power.o basicmath.o
		ar -rcs libmyMath.a power.o basicmath.o mylib.h
		gcc  -shared -o libmyMath.so power.o basicmath.o mylib.h

main.o: main.c mylib.h
	gcc -c main.c

power.o: power.c
	gcc -c power.c

basicMath.c:
	gcc -c basicmath.c

clean:
	rm -f *.o mains maind libmyMath.so libmyMath.a
