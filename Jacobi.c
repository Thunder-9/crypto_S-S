#include <gmp.h>

// calcul du pgcd(a,b) récursivement
void pgcd(mpz_t res, mpz_t a, mpz_t b){
	//calcul a mod b et met le résultat dans a
	//si a mod b == 0, le pgcd vaut b
	//sinon appel récursif de la fonction pgcd(b, a mod b)
	mpz_mod(res, a, b);
	if(mpz_cmp_d(res, 0) != 0)
		pgcd(res, b, res);
}

int etape2(mpz_t m, mpz_t n){
	return 1;
}

int jacobi(mpz_t n, mpz_t m){
	//m=m mod m   etape 1
	int sign = 1; //le signe de jacobi pour l'étape 2
	mpz_t tmp, tmp2;
	mpz_init(tmp);
	mpz_init(tmp2);
	mpz_mod(m,m,n);
	//étape 2
	if(mpz_mod_ui(tmp,m,2)==0){
		sign =  etape2(m,n);
	}
	//etape 3
	//si m == 1 jacobi = 1
	if (mpz_cmp_d(m,1)==0){
		return sign*1;
	}
	//si m et n ne sont pas premieris entre eux, jacobi = 0
	pgcd(tmp, m, n);
	if (mpz_cmp_d(tmp,1)!=0){
		return 0;
	}
	//étape 4
	//rappel récursivement la fonction jacobi en inversant n et m
	if ((mpz_mod_ui(tmp,n,4) == 0) || (mpz_mod_ui(tmp,m,4) == 0)){ //etape 4 recursive avec inversement
		return sign*jacobi(m,n);
	}
	else {
		return -1*sign*jacobi(m,n);
	}
	mpz_clear(tmp);	
	mpz_clear(tmp2);	
}
		

