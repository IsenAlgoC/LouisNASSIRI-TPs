#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "fr-FR");
	//enter();
	fctswitch();
}

int enter() {
	int i = 1;
	float n = 0.00;
	while ((n >= 0.00) && (n <= 20.00)) {
		printf("Entrez la note num�ro %d :\n", i);
		scanf_s("%f", &n);
		i++;
	}
	if ((n < 0.00) || (n > 20.00)) {
		printf("El�ve absent ? ou voulez-vous arr�ter la saisie des notes ?");
	}
}


//int moyenne() {
//	float S = 0.0;
//	float A = 0.0;
//	float i = 0.0;
//	float M = 0.0;
//
//	printf("Entrez les valeurs voulues pour calculer la moyenne, et valider la saisie en entrant -1 :\n");
//	while (1) { //boucle infinie
//		scanf_s("%f", &A);
//		if (A == -1.0)break;
//		S += A;
//		i++;
//	}
//	M = S / i;
//	printf("La valeur de la moyenne vaut %.1f, et il y avait %.0f valeurs entr�es", M, i);
//}


int fctswitch() {
	int notes[100]; // tableau � cr�er
	int i = 1;
	float n=0.0;
	char rep = 'B';
	int absent = 0;
	float moyenne = 0.0;
	while ((i<=30)&&(rep!='O')) {
		//while ((n >= 0.00) && (n <= 20.00)) {
		printf("Entrez la note num�ro %d :\n", i);
		scanf_s("%f", &n);
		i++;
		if ((n < 0.00) || (n > 20.00)) {
			i--;
			printf("El�ve absent ? ou voulez-vous arr�ter la saisie des notes ? A/O/N");
			//scanf_s("%c", &rep); = ne marche pas
			rep = (char)_getch(); //�a normalement �a marche
			switch (rep)
			{
			case 'A': {
				absent++;
				break;
			}
			case 'O':
				moyenne=
				printf("Il y a %d notes prises en compte pour %d absences, avec une moyenne �gale � %f", i, absent, moyenne);
				break;
			case 'N':
				printf("Entrez la note num�ro %d :\n", i);
				scanf_s("%.f", &n);
				i++;
				break;
			default:
				break;
			}
		}
		
	}
}
