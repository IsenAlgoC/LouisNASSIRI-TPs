#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

unsigned nombre = 2868838400;

int main() {
	setlocale(LC_ALL, "fr-FR");
	//nboctets();
	//nbbits();
	onoff();
}

int nboctets() {
	int a = sizeof(nombre);		//sizeof = affiche le nombre d'octets utilisés
	printf("%d octets sont utilisés pour représenter %u\n", a, nombre);
}

int nbbits() {
	int b = 8 * sizeof(nombre);
	printf("%d bits sont utilisés pour représenter %u", b, nombre);
}

int onoff() {
	for (int i = 0; i <= 8 * sizeof(nombre)-1; i++) {
		if (((nombre >> i) & 1) == 0) {
			printf("bit %d : OFF\n", i);
		}
		else {
			printf("bit %d : ON\n", i);
		}
	}
	printf("Bye !");
}


