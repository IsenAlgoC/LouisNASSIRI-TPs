#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


#define carre(x) x*x

int main() {
	setlocale(LC_ALL, "fr-FR");
	int Nb = 5;
	int a = 0;
	a = carre((Nb+1));
	//n+1 * n+1 = n+n+1 = 11
	printf("La racine carrée de %d est %d", (Nb+1), a);
}
