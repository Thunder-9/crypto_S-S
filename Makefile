FLAGS = -c -g -Wall 

run: compil
	./crypto_s-s

compil: SS.o Jacobi.o
	gcc $(CFLAGS) -o crypto_s-s *.o -lgmp

SS.o: SS.c
	gcc $(CFLAGS) SS.c -lgmp

Jacobi.o: Jacobi.c Jacobi.h
	gcc $(CFLAGS) -o Jacobi.o Jacobi.c -lgmp
clean:
	rm -f *.o
	rm -f crypto_s-s
