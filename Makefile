CFLAGS =-Wall -g -c

run: compil
	./crypto_s-s

compil: Jacobi.o main.o
	gcc -Wall -o crypto_s-s Jacobi.o main.o -lgmp

main.o: main.c Jacobi.h
	gcc $(CFLAGS) main.c -lgmp

Jacobi.o: Jacobi.c Jacobi.h
	gcc $(CFLAGS) Jacobi.c -lgmp

clean:
	rm -f *.o
	rm -f crypto_s-s
