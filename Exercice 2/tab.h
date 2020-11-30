#pragma once

#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt; //le tableau d'entiers 
	int size; //la taille de ce tableau d'entiers
	int eltsCount; //le nombre d'�l�ments dans le tableau
}TABLEAU;


//prototypes des fonctions utilis�es dans l'exercice 2
TABLEAU newArray();

int incrementArraySize(TABLEAU* tab, int incrementValue);

int setElement(TABLEAU* tab, int pos, int element);

int displayElement(TABLEAU* tab, int startPos, int endPos);

int deleteElements(TABLEAU* tab, int startPos, int endPos);
