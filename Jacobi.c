#include <gmp.h>
#include "jacobi.h"

int jacobi(mpz_t n, mpz_t m){
//m=m mod m   etape 1
	pz_t tmp;
	mpz_init(tmp);
	mpz_mod(m,m,n);
	if(mpz_mod_ui(tmp,m,2)==0){mpz_set(m,etape2(m,n));} //etape2
	if (mpz_cmp_d(m,1)==0){return 1;}
	if (mpz_cmp_d(pgcd(m,n),1)!=0){return 0;}
	if ((mpz_cmp_d(mpz_mod_ui(tmp,n,4),1)==0) || (mpz_cmp_d(mpz_mod_ui(tmp,m,4),1)==0)){
	return jacobi(m,n);}
	else {return -1*jacobi(m,n);}	
}
		

