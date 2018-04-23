Ce programme a pour but de tester la primalité d'un nombre à l'aide de l'algorithme de
Solovay-Strassen.
Il a été réalisé par Claire Baskevitch et Tristan Bessac.

Pour compiler:
	make, make compil

Pour executer:
	./crypto_s-s [Options]

Les options sont:
	-h ou --help : afficher l'aide
	-n ou --number, suivie du nombre à tester
	-k ou --itteration, suivie du nombre d'ittérations pour l'algorithme de Solovay-Strassen
		l'option -k est optionnelle et est initialisée à 10 sinon.
	-t ou --two, suivie d'un nombre x : calcul (2^x)-1 et vérifie sa primalité (utile pour les très grands nombres), 
		l'option -t écrase l'option -n si utilisé en même temps
