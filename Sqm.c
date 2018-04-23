#include "Sqm.h"
#include <gmp.h>
#include <stdio.h>

/* Fonction de calcul d'exponentiation modulaire square and multiply
* r : resultat intermédiaire puis final 
* a : entier
* n : le module
* e : l'exposant
*/
void square_and_mult_mod(mpz_t r, mpz_t a, mpz_t n, mpz_t e){
	mpz_set(r,a); //r <- a
	mp_bitcnt_t bi; //compteur pour le parcours des bits de l'exposant
	
	//parcours de l'exposant en binaire 
	for(bi=mpz_sizeinbase(e,2)-1;bi>0;bi--){
		
		// r <- r² mod n
		mpz_mul(r,r,r);
		mpz_mod(r,r,n);
		
		// si le bit bi de l'exposant vaut 1
		if(mpz_tstbit(e,bi-1)==1){
			// r <- r*a mod n 
			mpz_mul(r,r,a);
			mpz_mod(r,r,n);
		}
	}
}

/* Fonction de calcul d'exponentiation square and multiply
* r : resultat intermédiaire puis final 
* a : entier
* e : l'exposant
*/
void square_and_mult(mpz_t r, mpz_t a, mpz_t e){
	mpz_set(r,a); // r <- a
	mp_bitcnt_t bi; //compteur pour le parcours des bits de l'exposant
	
	//parcours de l'exposant en binaire 
	for(bi=mpz_sizeinbase(e,2)-1;bi>0;bi--){
		
		// r <- r² 
		mpz_mul(r,r,r);
		
		// si le bit bi de l'exposant vaut 1
		if(mpz_tstbit(e,bi-1)==1){
			// r <- r*a  
			mpz_mul(r,r,a);
		}
	}
}
