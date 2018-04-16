#include "Sqm.h"
#include <gmp.h>


void square_and_mult(mpz_t r,mpz_t a,mpz_t n,mpz_t e){
	mpz_set(r,a);
	mp_bitcnt_t bi=0;


	for(bi;bi=0;bi<mpz_popcount(e)){
	mpz_mul(r,r,r);
		if(mpz_tstbit (r,bi)==1){
			mpz_mul(r,r,a);
			mpz_mod(r,r,n);
		}
	}


}