#include <stdio.h>
#include <gmp.h>
#include "Jacobi.h"

int main(int argc, char** argv){
	mpz_t a,b;
	mpz_init(a);
	mpz_init(b);
	mpz_set_ui(a, 8721);
	mpz_set_ui(b, 4235);
	printf("%d\n", jacobi(a, b));
	//gmp_printf("%Zd\n", a);
	mpz_clear(a);
	mpz_clear(b);

	return 0;
}
