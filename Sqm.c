#include "Sqm.h"
#include <gmp.h>
#include <stdio.h>


void square_and_mult(mpz_t r, mpz_t a, mpz_t n, mpz_t e){
	mpz_set(r,a);
	mp_bitcnt_t bi;
	//	printf("%ld\n",bi);
	// int f=mpz_sizeinbase(e,2);
	// printf("%d\n",f );
	// int g=mpz_tstbit(e,3);
	// 	printf("%d\n",g );
	//printf("%ld\n",mpz_popcount(e));
	//printf("%d\n",mpz_sizeinbase(e,2));
	for(bi=mpz_sizeinbase(e,2)-1;bi!=0;bi--){
	//printf("%ld\n",bi);	1
	mpz_mul(r,r,r);
	mpz_mod(r,r,n);
	gmp_printf("%Zd\n",r);
	//printf("1");
		if(mpz_tstbit(e,bi-1)==1){

			//printf("2	");
			mpz_mul(r,r,a);
			mpz_mod(r,r,n);
			gmp_printf("%Zd\n",r);
		}
	}


}