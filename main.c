#include <stdio.h>
#include <gmp.h>
#include "Jacobi.h"
#include "Sqm.h"

int main(int argc, char** argv){
	mpz_t a,b;
	mpz_init(a);
	mpz_init(b);
	mpz_set_ui(a, 4237);
	mpz_set_ui(b, 666);
	//printf("%d\n", jacobi(a, b));
	//gmp_printf("%Zd\n", a);

	mpz_t r,n;
	mpz_init(r);
	mpz_init(n);
	mpz_set_ui(n,49);
	square_and_mult(r,a,n,b);
	gmp_printf("%Zd\n",r);
	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(r);
	mpz_clear(n);
	return 0;
}
