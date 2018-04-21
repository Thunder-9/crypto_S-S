CFLAGS =-Wall -g -c

compil: Jacobi.o Sqm.o main.o
	gcc -Wall -o crypto_s-s *.o -lgmp

main.o: main.c Jacobi.h Sqm.h
	gcc $(CFLAGS) main.c -lgmp

Jacobi.o: Jacobi.c Jacobi.h
	gcc $(CFLAGS) Jacobi.c -lgmp

Sqm.o: Sqm.c Sqm.h
		gcc $(CFLAGS) Sqm.c -lgmp

clean:
	rm -f *.o
	rm -f crypto_s-s
