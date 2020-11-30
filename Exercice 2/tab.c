#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAILLEINITIALE 10

// 1 - crée un nouveau TABLEAU en allouant une taille initiale pour les données
TABLEAU newArray() {
	TABLEAU tableau;
	tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	if (tableau.elt != NULL) {
		for (int i = 0; i < TAILLEINITIALE; i++) {
			*(tableau.elt + i) = 0;
		}
	}
	tableau.size = TAILLEINITIALE;
	tableau.eltsCount = 0;
	return tableau;
}


//2 - modifie la taille du tableau
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if (((*tab).elt == NULL) || (incrementValue < 0)) {
		return -1;
	}
	else {
		int* tmp = tab->elt;				//sauvegarde du tableau dans le cas où la realloc ne fonctionne pas
		int variable = tab->size + incrementValue;		//création de cette variable car lorsque je mettais (tab->size+incrementValue)*sizeof dans mon realloc cela créait un bug assez conséquent...
		tab->elt = (int*)realloc(tab->elt, (variable)* sizeof(int));
		if (tab->elt == NULL) {		//cas où la realloc n'a pas correctement fonctionné
			tab->elt = tmp;			//restitution du pointeur précédent
			return -1;
		}
		else {
			tab->size += incrementValue;	//valeur de la taille mise à jour
			return tab->size;
		}
	}
}


//3 - écrit un élément à une position donnée sans insertion
int setElement(TABLEAU* tab, int pos, int element) {
	int anciennetaille = tab->size;
	if ((pos < 0) || (tab==NULL)) {			//cas d'erreur 
		return 0;
	}
	if (pos <= tab->size) {		//1er cas : taille du tableau assez grande pour insérer l'element à la position pos
		if (*(tab->elt + pos - 1) == 0) {		//permet de mettre à jour le nombre d'éléments si la valeur initiale à la position pos est un 0
			tab->eltsCount++;
		}
		*(tab->elt + pos - 1) = element;		//element envoyé à la position pos du tableau
		return (pos);		//position de l'élément inséré
	}
	else {
		if (incrementArraySize(tab, pos - tab->size) == -1) {	//agrandissement du tableau et si celui-ci échoue on renvoie 0
			return 0;
		}
		for (int i = 0; i < pos-anciennetaille; i++) {		//boucle qui s'occupe d'insérer les 0 dans les nouvelles cases du tableau
			*(tab->elt + anciennetaille + i) = 0;
		}
		*(tab->elt + pos - 1) = element;		//element envoyé à la position pos du tableau
		tab->eltsCount++;					//on met à jour le nombre d'éléments du tableau
		return (pos);
	}
}



//4 - Affiche une portion du tableau de l'indice début à l'indice fin
int displayElement(TABLEAU* tab, int startPos, int endPos) {
	if ((tab == NULL) || (startPos < 1) || (endPos < 1) || (endPos > tab->size) || (startPos > tab->size)) {
		return -1;
	}
	else {
		if (startPos > endPos) {		//cas où l'utilisateur a rentré une borne de départ supérieure à la borne de fin= on inverse les deux
			int tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		printf("\nLe tableau actuel de la position %d a la position %d :",startPos,endPos);
		for (int i = startPos - 1; i < endPos; i++) {		//on affiche les éléments de startPos-1 (car le premier élément est à la position 1) à endPos
			printf(" %d ", *(tab->elt + i));
		}
		return 0;
	}
}


//5 - Supprime des éléments avec compactage du tableau
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if ((tab == NULL) || (startPos < 1) || (endPos < 1) || (endPos > tab->size) || (startPos > tab->size)) {	//erreur si position négative ou en dehors de la taille du tableau
		return -1;
	}
	if (startPos > endPos) {		//cas où l'utilisateur a rentré une borne de départ supérieure à la borne de fin= on inverse les deux
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}
	printf("\nOn va supprimer les elements de la position %d a la position %d : ", startPos, endPos);
	int nbEltsdeleted = endPos - startPos + 1;		//va aider à déterminer le nombre d'éléments à supprimer du tableau
	for (int i = 0; i < nbEltsdeleted; i++) {		//boucle qui permet de recalculer le nouveau nombre d'éléments que contient le tab 
		if (*(tab->elt + startPos-1 + i) != 0) {		//si élément supprimé différent de 0, on décrémente le nombre d'éléments
			tab->eltsCount--;
		}

	}
	for (int i = 0; i < tab->size - endPos; i++) {		//boucle qui permet de décaler les valeurs de nbEltsdeleted vers la gauche pour remplacer les valeurs supprimées
		*(tab->elt + startPos - 1 + i) = *(tab->elt + startPos - 1 + nbEltsdeleted + i); 
	}
	int* tmp2 = tab->elt;		//on sauvegarde le tableau actuel dans tmp2 au cas où la realloc ne fonctionne pas
	int newsize = tab->size - nbEltsdeleted;
	tab->elt = (int*)realloc((*tab).elt, (newsize) * sizeof(int));
	if (tab->elt == NULL) {
		tab->elt = tmp2;		//restitution du pointeur précédent
		return -1;
	}
	else {
		tab->size -= nbEltsdeleted;	//mise à jour de la taille après que la suppresion et la réallocation aient correctement fonctionnées
		return tab->size;
	}
}