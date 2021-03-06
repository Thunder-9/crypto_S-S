#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <gmp.h>
#include "Jacobi.h"
#include "Sqm.h"

/* Fonction qui affiche l'aide sur la sortie standard. */
void help(){
	printf("\t-n, --number \n\t\t Le nombre à tester avec l'algorithme de Solovay-Strassen\n"
		"\t -k, --itteration (optionnel)\n\t\t Le nombre d'ittérations pour l'execution algorithme. Il est initialisé à 10 de base.\n"
		"\t-t ou --two, suivie d'un nombre x : calcul (2^x)-1 et vérifie sa primalité (utile pour les très grands nombres)," 
		" l'option -t écrase l'option -n si utilisé en même temps");
		
}

/* Algorithme de Solovay-Strassen qui teste de manière heuristique
 * si un entier est premier.
 * n est le nombre à tester.
 * k est le nombre d'ittérations de la boucle.
 * retourne 0 si le nombre n'est pas premier.
 * retourne 1 si le nombre est premier.
 * */
int solovay_strassen(mpz_t n, int k){
	//Initialisation des variables
	mpz_t rand_num, sqr, e, tmp_n1, tmp_n3,tmp_n,tmp_r;
	gmp_randstate_t rand;
	int r;
	mpz_inits(rand_num, sqr, e, tmp_n, tmp_n1, tmp_n3, tmp_r, NULL);
	gmp_randinit_default(rand);
	mpz_sub_ui(tmp_n1, n, 1); // tmp_n1 <-  n-1
	mpz_sub_ui(tmp_n3, n, 3); // tmp_n3 <-  n-3
	mpz_div_ui(e, tmp_n1, 2); //    e   <- (n-1)/2
	
	//Boucle du test
	for (int i = 0; i < k;i++){
		mpz_set(tmp_n,n);
		mpz_urandomm(rand_num, rand, tmp_n3); //génération d'un nombre aléatoire entre 0 et n-3
		mpz_add_ui(rand_num, rand_num, 2);  // on ajoute 2 pour revenir entre 2 et n-1
		mpz_set(tmp_r,rand_num);
		r = jacobi(tmp_r, tmp_n); // r <- symbole de jacobi   
		square_and_mult_mod(sqr, rand_num, n, e); //sqr <- resultat de l'exponentation modulaire
		// si r vaut 0  ou r =/= sqr mod n ie (r=1 et sqr = 1)  ou (r = -1 et sqr = n-1)
		if(r == 0 ||    (r==1 && (mpz_cmp_ui(sqr, 1) != 0)) || (r==-1 &&(mpz_cmp(sqr, tmp_n1) != 0))){
			mpz_clears(rand_num, sqr, e, tmp_n, tmp_n1, tmp_n3, tmp_r, NULL);
			gmp_randclear(rand);
		       	return 0; // composé
		}
	}
	mpz_clears(rand_num, sqr, e, tmp_n, tmp_n1, tmp_n3, tmp_r, NULL);
	gmp_randclear(rand);
	return 1; // premier
}

int main(int argc, char** argv){
	//Initialisation des variables pour la récupération des options
	int k = 10, optch, optindex = 0;
	char* nb;
	char* e = NULL;
	char* short_option = "n:k:ht:";
	const struct option long_option[] = {
		{"number", 1, NULL, 'n'},
		{"itteration", 1, NULL, 'k'},
		{"help", 0, NULL, 'h'},
		{"two",1,NULL,'t'}
	};
	//récupération des options passés par l'utilisatieur
	while((optch = getopt_long(argc, argv, short_option, long_option, &optindex)) != -1){
		switch(optch){
			case 'n':
				nb = optarg;
				break;
			case 'k':
				k = atoi(optarg);
				break;
			case 'h':
				help();
				return 0;
				break;
			case '?':
				help();
				return 0;
				break;
			case 't':
				e=optarg;
				break;
		}
	}

	
	if(e != NULL){
		//Initialisation des variables 	
		mpz_t pow,n,two;
		mpz_inits(pow, n, two, NULL);
		mpz_set_ui(two,2);
		if (mpz_set_str(pow, e , 10)){
			mpz_clears(pow,n,two, NULL);
			return fprintf(stderr,"Nombre invalide\n"), -1;
		}
		// calcul de (n²)-1
		square_and_mult(n,two,pow);
		mpz_sub_ui(n,n,1);
		//Appel de l'algorithme de Solovay-Strassen
		if(solovay_strassen(n, k))
			printf("Le nombre est premier\n");
		else
			printf("Le nombre n'est pas premier\n");
		mpz_clears(pow,two,n, NULL);
		return 0; 
			
	}
	

	else{
		//Initialisation de la variable gmp
		mpz_t n;
		mpz_init(n);

		//Appel de l'agorithme de Solovay-Strassen
		if(mpz_set_str(n, nb , 10)){
			mpz_clear(n);
			return fprintf(stderr,"Nombre invalide\n"), -1;
		}
		if(solovay_strassen(n, k))
			printf("Le nombre est premier\n");
		else
			printf("Le nombre n'est pas premier\n");
		mpz_clear(n);
		return 0;
	}
}
	
