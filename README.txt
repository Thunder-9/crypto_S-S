Ce programme a pour but de tester la primalité d'un nombre à l'aide de l'algorithme de
Solovay-Strassen.
Il a été réalisé par Claire Baskevitch et Tristan Bessac.

Pour compiler:
	make, make compil

Pour executer:
	./crypto_s-s [Options]

Les options sont:
	-h, --help : afficher l'aide
	-n, --number : le nombre à tester
	-k, --itteration : le nomre d'ittérations pour l'algorithme de Solovay-Strassen
		l'option -k est optionnelle et est initialisée à 10 sinon.
