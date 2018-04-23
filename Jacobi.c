#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "Jacobi.h"

/* Fonction qui calcule le pgcd
 * Elle prend en argument :
 * res : le résultat du pgcd
 * n et d : les deux entiers pour lesquels le pgcd est calculé 
 * */
void pgcd(mpz_t res, mpz_t n, mpz_t d){
	//Initialisation
	mpz_t tmp_n, tmp_d;
	mpz_inits(tmp_n, tmp_d, NULL);
	mpz_set(tmp_n, n);
	mpz_set(tmp_d, d);
	// Calcul du pgcd avec la propriété pgcd(n,d) = pgcd(d, n mod d) tant que (n mod d != 0)
	do{
		mpz_mod(res, tmp_n, tmp_d); // res <- n mod d
		mpz_set(tmp_n, tmp_d);      // n <- d
		mpz_set(tmp_d, res);		// d <- res
	}while(mpz_cmp_ui(res,0) != 0);
	mpz_set(res, tmp_n);  //res <- n
	mpz_clears(tmp_n, tmp_d, NULL);
}

/* L'étape 2 de l'agorithme pour calculer le symbole de Jacobi.
 * Elle décompose l'entier m en facteur de 2 (propriété 2)
 * puis simplifie le symbole de Jacobi à l'aide de la propriété 5.
 * n et m sont les deux nombres qui composent le symbole de Jacobi (m/n).
 * Elle renvoie le signe que donne la simplification de la propriété 5 : 1 ou -1.
 * La variable m est également modifiée :  elle est le résultat de la simplification
 * par une puissance de 2. 
 * */
int etape2(mpz_t m, mpz_t n){

	mpz_t tmp;
	int nb_pow = 0; //le nombre de puissance de 2 par lequel on peut décomposer m
	mpz_init(tmp);
	// tant que m mod 2 = 0
	while(mpz_mod_ui(tmp, m, 2) == 0){
		mpz_cdiv_q_ui(m, m, 2); // m <- m/2
		nb_pow++;
	}	// si (n mod 8 = 3  ou  n mod 8 = 5)  et nb_pow n'est pas multiple de 2 
	if((mpz_mod_ui(tmp, n, 8) == 3 || mpz_mod_ui(tmp, n, 8) == 5) && nb_pow%2 == 1){
		mpz_clear(tmp);
		return -1; //signe négatif
	}
	mpz_clear(tmp);
	return 1; //signe positif
}

/* Calcule le symbole de Jacobi
 * m et n sont les entiers qui composent le symbole de Jacobi
 * La fonction renvoie la valeur du symbole de Jacobi
 * Attention m et n sont modifiés par la fonction. 
 * */
int jacobi(mpz_t m, mpz_t n){
	//Initialisation
	int signe = 1; //le signe de jacobi utilisé pour les appels récursifs
	mpz_t tmp; 
	mpz_init(tmp);

	//m=m mod m   etape 1
	mpz_mod(m,m,n);
	
	//étape 2
	// si m mod 2 = 0 
	if(mpz_mod_ui(tmp,m,2)==0)
		signe =  etape2(m,n);
	
	//etape 3
	//si m == 1 jacobi = 1
	if (mpz_cmp_ui(m,1)==0){
		mpz_clear(tmp);	
		return signe*1;
	}
	//si m et n ne sont pas premiers entre eux, jacobi = 0
	pgcd(tmp, m, n);
	if (mpz_cmp_ui(tmp,1)!=0){
		mpz_clear(tmp);	
		return 0;
	}
	
	//étape 4
	//rappel récursivement la fonction jacobi en inversant n et m
	//si  n mod 4 = 1  ou  m mod 4 = 1, le signe de change pas
	if ((mpz_mod_ui(tmp,n,4) == 1) || (mpz_mod_ui(tmp,m,4) == 1)){
		mpz_clear(tmp);	
		return signe*jacobi(n,m);
	}// sinon le signe change 
	else {
		mpz_clear(tmp);	
		return -1*signe*jacobi(n,m);
	}
}
		

