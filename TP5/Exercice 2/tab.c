#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAILLEINITIALE 10

// 1 - cr�e un nouveau TABLEAU en allouant une taille initiale pour les donn�es
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
		int* tmp = tab->elt;				//sauvegarde du tableau dans le cas o� la realloc ne fonctionne pas
		int variable = tab->size + incrementValue;		//cr�ation de cette variable car lorsque je mettais (tab->size+incrementValue)*sizeof dans mon realloc cela cr�ait un bug assez cons�quent...
		tab->elt = (int*)realloc(tab->elt, (variable)* sizeof(int));
		if (tab->elt == NULL) {		//cas o� la realloc n'a pas correctement fonctionn�
			tab->elt = tmp;			//restitution du pointeur pr�c�dent
			return -1;
		}
		else {
			tab->size += incrementValue;	//valeur de la taille mise � jour
			return tab->size;
		}
	}
}


//3 - �crit un �l�ment � une position donn�e sans insertion
int setElement(TABLEAU* tab, int pos, int element) {
	int anciennetaille = tab->size;
	if ((pos < 0) || (tab==NULL)) {			//cas d'erreur 
		return 0;
	}
	if (pos <= tab->size) {		//1er cas : taille du tableau assez grande pour ins�rer l'element � la position pos
		if (*(tab->elt + pos - 1) == 0) {		//permet de mettre � jour le nombre d'�l�ments si la valeur initiale � la position pos est un 0
			tab->eltsCount++;
		}
		*(tab->elt + pos - 1) = element;		//element envoy� � la position pos du tableau
		return (pos);		//position de l'�l�ment ins�r�
	}
	else {
		if (incrementArraySize(tab, pos - tab->size) == -1) {	//agrandissement du tableau et si celui-ci �choue on renvoie 0
			return 0;
		}
		for (int i = 0; i < pos-anciennetaille; i++) {		//boucle qui s'occupe d'ins�rer les 0 dans les nouvelles cases du tableau
			*(tab->elt + anciennetaille + i) = 0;
		}
		*(tab->elt + pos - 1) = element;		//element envoy� � la position pos du tableau
		tab->eltsCount++;					//on met � jour le nombre d'�l�ments du tableau
		return (pos);
	}
}



//4 - Affiche une portion du tableau de l'indice d�but � l'indice fin
int displayElement(TABLEAU* tab, int startPos, int endPos) {
	if ((tab == NULL) || (startPos < 1) || (endPos < 1) || (endPos > tab->size) || (startPos > tab->size)) {
		return -1;
	}
	else {
		if (startPos > endPos) {		//cas o� l'utilisateur a rentr� une borne de d�part sup�rieure � la borne de fin= on inverse les deux
			int tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		printf("\nLe tableau actuel de la position %d a la position %d :",startPos,endPos);
		for (int i = startPos - 1; i < endPos; i++) {		//on affiche les �l�ments de startPos-1 (car le premier �l�ment est � la position 1) � endPos
			printf(" %d ", *(tab->elt + i));
		}
		return 0;
	}
}


//5 - Supprime des �l�ments avec compactage du tableau
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if ((tab == NULL) || (startPos < 1) || (endPos < 1) || (endPos > tab->size) || (startPos > tab->size)) {	//erreur si position n�gative ou en dehors de la taille du tableau
		return -1;
	}
	if (startPos > endPos) {		//cas o� l'utilisateur a rentr� une borne de d�part sup�rieure � la borne de fin= on inverse les deux
		int tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}
	printf("\nOn va supprimer les elements de la position %d a la position %d : ", startPos, endPos);
	int nbEltsdeleted = endPos - startPos + 1;		//va aider � d�terminer le nombre d'�l�ments � supprimer du tableau
	for (int i = 0; i < nbEltsdeleted; i++) {		//boucle qui permet de recalculer le nouveau nombre d'�l�ments que contient le tab 
		if (*(tab->elt + startPos-1 + i) != 0) {		//si �l�ment supprim� diff�rent de 0, on d�cr�mente le nombre d'�l�ments
			tab->eltsCount--;
		}

	}
	for (int i = 0; i < tab->size - endPos; i++) {		//boucle qui permet de d�caler les valeurs de nbEltsdeleted vers la gauche pour remplacer les valeurs supprim�es
		*(tab->elt + startPos - 1 + i) = *(tab->elt + startPos - 1 + nbEltsdeleted + i); 
	}
	int* tmp2 = tab->elt;		//on sauvegarde le tableau actuel dans tmp2 au cas o� la realloc ne fonctionne pas
	int newsize = tab->size - nbEltsdeleted;
	tab->elt = (int*)realloc((*tab).elt, (newsize) * sizeof(int));
	if (tab->elt == NULL) {
		tab->elt = tmp2;		//restitution du pointeur pr�c�dent
		return -1;
	}
	else {
		tab->size -= nbEltsdeleted;	//mise � jour de la taille apr�s que la suppresion et la r�allocation aient correctement fonctionn�es
		return tab->size;
	}
}