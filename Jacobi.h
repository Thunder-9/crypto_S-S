#ifndef JACOBI_H
#define JACOBI_H
#include <gmp.h>
#include "Jacobi.c"

	int jacobi(mpz_t n, mpz_t m);
	void pgcd(mpz_t res, mpz_t a, mpz_t b);
	int etape2 (mpz_t n, mpz_t m);  



#endif
