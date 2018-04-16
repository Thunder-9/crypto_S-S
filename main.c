#include <stdio.h>
#include <gmp.h>
#include "Jacobi.h"
#include "Sqm.h"


int solovay_strassen(mpz_t n, int k){
	//Initialisation
	mpz_t rand_num, sqr, e, tmp_n1, tmp_n3,tmp_n,tmp_r;
	gmp_randstate_t rand;
	int r;
	mpz_init(rand_num);
	mpz_init(sqr);
	mpz_init(e);
	mpz_init(tmp_n);
	mpz_init(tmp_n1);
	mpz_init(tmp_n3);
	mpz_init(tmp_r);
	gmp_randinit_default(rand);
	for (int i = 0; i < k;i++){
		mpz_set(tmp_n,n);
		mpz_sub_ui(tmp_n1, n, 1);
		mpz_div_ui(e, tmp_n1, 2);
		mpz_sub_ui(tmp_n3, n, 3);
		//rand_num = rand(2, n-1)
		mpz_urandomm(rand_num, rand, tmp_n3);
		mpz_add_ui(rand_num, rand_num, 2);
		mpz_set(tmp_r,rand_num);
		r = jacobi(tmp_r, tmp_n);
		//a^(n-1)/2 mod n != 1 || != n-1
		square_and_mult(sqr, rand_num, n, e);
		if(r == 0 ||    (r==1 && (mpz_cmp_ui(sqr, 1) != 0)) || (r==-1 &&(mpz_cmp(sqr, tmp_n1) != 0))){
			mpz_clear(sqr);
			mpz_clear(rand_num);
			mpz_clear(e);
			mpz_clear(tmp_n1);
			mpz_clear(tmp_n3);
			gmp_randclear(rand);
		       	return 0;
		}
	}
	mpz_clear(sqr);
	mpz_clear(rand_num);
	mpz_clear(e);	
	mpz_clear(tmp_n1);	
	mpz_clear(tmp_n3);
	gmp_randclear(rand);	
	return 1;
}

int main(int argc, char** argv){
	mpz_t a;
	mpz_init(a);
	mpz_set_ui(a,13);
	printf("%d\n", solovay_strassen(a, 10));
	mpz_clear(a);
	return 0;
}
	