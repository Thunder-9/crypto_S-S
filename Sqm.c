#include "Sqm.h"
#include <gmp.h>
#include <stdio.h>


void square_and_mult(mpz_t r, mpz_t a, mpz_t n, mpz_t e){
	mpz_set(r,a);
	mp_bitcnt_t bi;
	
	for(bi=mpz_sizeinbase(e,2)-1;bi!=0;bi--){
	mpz_mul(r,r,r);
	mpz_mod(r,r,n);
		if(mpz_tstbit(e,bi-1)==1){

			mpz_mul(r,r,a);
			mpz_mod(r,r,n);
		}
	}


}
