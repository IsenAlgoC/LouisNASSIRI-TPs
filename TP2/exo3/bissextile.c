#include <stdlib.h>
#include <stdio.h>

int main() {
	int annee;
	int reponse;
	printf("Veuillez entrer l'annee :\n");
	scanf_s("%d", &annee);
	if (annee % 4 == 0) {			//possibilité que ce soit bissextile
		if (annee % 100 == 0) {		//possibilité d'exception avec années séculaires
			if (annee % 400 == 0) {		//exception annulée
				printf("L'annee %d est une annee bissextile\n", annee);
			}
			else {		//exception car année séculaire
				printf("L'annee %d n'est pas une annee bissextile car c'est une annee seculaire\n", annee);
			}
		}
		else {		//bissextile non séculaire
			printf("L'annee %d est une annee bissextile\n", annee);
		}
		
	}
	else {	//pas bissextile
		printf("L'annee %d n'est pas une annee bissextile\n", annee);
	}
	printf("Voulez vous entrer une autre année ?	0:non, 1:oui\n");
	scanf_s("%d", &reponse);
	if (reponse == 1) {
		main();
	}
}