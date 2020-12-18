#include <stdlib.h>
#include <stdio.h>

int main() {
	int annee;
	int reponse;
	printf("Veuillez entrer l'annee :\n");
	scanf_s("%d", &annee);
	if (annee % 4 == 0) {			//possibilit� que ce soit bissextile
		if (annee % 100 == 0) {		//possibilit� d'exception avec ann�es s�culaires
			if (annee % 400 == 0) {		//exception annul�e
				printf("L'annee %d est une annee bissextile\n", annee);
			}
			else {		//exception car ann�e s�culaire
				printf("L'annee %d n'est pas une annee bissextile car c'est une annee seculaire\n", annee);
			}
		}
		else {		//bissextile non s�culaire
			printf("L'annee %d est une annee bissextile\n", annee);
		}
		
	}
	else {	//pas bissextile
		printf("L'annee %d n'est pas une annee bissextile\n", annee);
	}
	printf("Voulez vous entrer une autre ann�e ?	0:non, 1:oui\n");
	scanf_s("%d", &reponse);
	if (reponse == 1) {
		main();
	}
}