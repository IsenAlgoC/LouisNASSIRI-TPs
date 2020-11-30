#include <stdlib.h>
#include <stdio.h>

#define TAB2SIZE 100
#define TAILLEAJOUT 5

int main() {
	//******** 1 - Fonction avec passage d'un tableau en argument *********//
	//Tableau 1
	int myTab1[10];
	initTab(myTab1, 10);
	printf("Tableau 1 de taille 10 avec des 0: ");
	afficheTab(myTab1, 10, 5);
	
	//Tableau 2
	int* myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));		//création d'un tableau à taille dynamique
	if (myTab2 != NULL) {
		initTab(myTab2, TAB2SIZE);
		printf("Tableau 2 de taille TAB2SIZE avec des 0: ");
		afficheTab(myTab2, TAB2SIZE, 10);
	}
	else {
		printf("memoire insuffisante");
		return -1;
	}
	unavingtTab(myTab2, TAB2SIZE, 20);
	printf("Tableau 2 avec ses 20 premieres valeurs allant de 1 a 20:");
	afficheTab(myTab2, TAB2SIZE, 100);


	//******** 2 - Agrandissement d'un tableau alloué dynamiquement *********//
	int taille = TAB2SIZE;
	int nbElts = 20;
	printf("Dernier element du tableau 2 avant l'ajout : %d\n", *(myTab2 + nbElts - 1));
	printf("Taille du tableau 2 avant l'ajout : %d\n", taille);
	printf("Nombre d'elements du tableau 2 avant l'ajout : %d\n", nbElts);
	ajoutElementDansTableau(myTab2, &taille, &nbElts, 3);
	printf("Dernier element du tableau 2 apres l'ajout : %d\n", *(myTab2 + nbElts - 1));
	printf("Nouvelle taille du tableau 2 apres l'ajout :%d\n", taille);
	printf("Nombre d'elements du tableau 2 apres l'ajout : %d\n", nbElts);
	printf("Nouveau tableau 2 apres ajout :");
	afficheTab(myTab2, taille, taille);
	ajoutElementDansTableau(myTab2, &taille, &nbElts, 5);
	afficheTab(myTab2, taille, taille);
	free(myTab2);							//restitution au système de la mémoire devenue inutile
	printf("\nTableau 2 detruit : ");
	afficheTab(myTab2, TAB2SIZE, 20);		//permet de vérifier que la restitution de la mémoire a bien été effectuée
}