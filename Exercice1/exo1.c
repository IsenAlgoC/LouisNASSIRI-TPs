#include <stdlib.h>
#include <stdio.h>
#include "tab.h"


#define TAB2SIZE 100
#define TAILLEAJOUT 5

//*************************  1 - Fonction avec passage d'un tableau en argument  *************************************//

//fonction qui cr�e d'un tableau compos� de 10 valeurs avec des 0 uniquement 
int initTab(int* tab, int size) {
	if ((tab == NULL) || (size<0)) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;		// on affecte 0 � la variable point�e par chaque adresse du tableau
		}
		return size;
	}
}

//fonction qui s'occupe d'afficher les nbElts premiers �l�ments du tableau
int afficheTab(int* tab, int size, int nbElts) {
	if ((tab == NULL) || (size < 0) || (size<nbElts)) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf(" %d ", *(tab + i));
		}
		printf("\n");
		return 0;
	}
}

//fonction qui remplit les nbElts (dans notre TP c'est 20) premi�res valeurs du tableau avec les nombres de 1 � 20
int unavingtTab(int* tab, int size, int nbElts) {
	for (int i = 0; i < nbElts; i++) {
		*(tab + i) = i + 1;
	}
	return nbElts;
}



//*************************  2 - Agrandissement d'un tableau allou� dynamiquement   *************************************//

//fonction qui ajoute un �l�ment � la suite dans le tableau
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if ((tab == NULL) || (*size < 0) || (*nbElts < 0)) {		//si pointeur NULL ou un probl�me de taille = renvoie NULL car erreur
		return NULL;
	}
	else if (*nbElts < *size) {				// dans le cas o� le tableau a d�j� une taille suffisante pour accueillir un �l�ment suppl�mentaire
		printf("il y a assez de place\n");
		*(tab + *nbElts) = element;		//ajout de l'�l�ment � la suite du dernier �l�ment du tableau
		(*nbElts)++;					//il y a maintenant un �l�ment de plus
		return nbElts;
	}
	else {
		printf("Il n'y a pas assez de place\n");
		int* tmp = tab;			//sauvegarde de tab au cas o� la r�alloc �choue
		int var = *size + TAILLEAJOUT;
		tab = (int*)realloc(tab, (var) * sizeof(int));		//permet de modifier la taille allou�e au tableau en m�moire
		if (tab == NULL) {		//cas o� la r�alloc �choue
			tab = tmp;
			printf("La r�allocation n'a pas correctement fonctionn�\n");
			return NULL;
		}
		else {
			*(tab + *nbElts) = element;
			*size += TAILLEAJOUT;
			(*nbElts)++;
			return nbElts;
		}
	}
}


