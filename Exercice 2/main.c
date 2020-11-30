#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAILLEINITIALE 10

int main() {
	TABLEAU tab = newArray();

	displayElement(&tab, 1, 10);	//On affiche tout le tableau initial
	printf("\nLe nombre d'elements : %d\n", tab.eltsCount);
	printf("La taille : %d\n", tab.size);


	//on ajoute un 7 � la position 1, un 10 � la position 5 et un 5 � la position 14
	setElement(&tab, 1, 7);
	setElement(&tab, 5, 10);
	setElement(&tab, 14, 5);	//position 14 sup�rieure � la taille initiale du tableau donc fonction incrementarraysize utilis�e dans cete fonction
	displayElement(&tab, 1, 14); // on a ajout� les 3 valeurs et on affiche le tableau
	printf("\nle nombre d'elements : %d\n", tab.eltsCount);
	printf("la nouvelle taille : %d\n", tab.size);


	//on change la valeur de la position 1, et on ajoute d'autres �l�ments
	setElement(&tab, 1, 18);
	setElement(&tab, 13, 4);
	setElement(&tab, 3, 5);
	setElement(&tab, 7, 2);
	setElement(&tab, 9, 9);
	setElement(&tab, 20, 7);
	displayElement(&tab, 1, 20);
	printf("\nle nombre d'elements : %d\n", tab.eltsCount);
	printf("la nouvelle taille : %d\n", tab.size);

	//on supprime les �l�ments situ�s entre la position 4 et 11
	deleteElements(&tab, 4, 7);
	displayElement(&tab, 1, tab.size);
	printf("\nle nombre d'elements apres supression : %d\n", tab.eltsCount);
	printf("La nouvelle taille apres suppression : %d\n", tab.size);

	//on r�ins�re un �l�ment apr�s avoir supprim� des �l�ments du tableau pour v�rifier que cela fonctionne toujours normalement
	setElement(&tab, 22, 6);
	displayElement(&tab, 1, tab.size);
	printf("\nle nombre d'elements apres supression : %d\n", tab.eltsCount);
	printf("La nouvelle taille apres suppression : %d\n", tab.size);

	//on supprime des valeurs mais avec des bornes invers�es cette fois-ci (entre la 10e et la 16e valeur)
	deleteElements(&tab, 16, 10); 
	displayElement(&tab, 1, tab.size);
	printf("\nle nombre d'elements apres supression : %d\n", tab.eltsCount);
	printf("La nouvelle taille apres suppression : %d\n", tab.size);
}
