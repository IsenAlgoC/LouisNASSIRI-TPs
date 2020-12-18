#include <stdlib.h>
#include <stdio.h>


//les 2 fonctions ci-dessous permettent de trier correctement les valeurs entrées par l'utilisateur afin de les avoir dans l'ordre décroissant
void echanger(float* a, float* b) {
	float c;
	c = *a;
	*a = *b;
	*b = c;
}

void tri(float* a, float* b, float* c) {
	if (*a < *b) { echanger(a, b); }
	if (*b < *c) { echanger(b, c); }
	if (*a < *b) { echanger(a, b); }
}

int main() {
	float a = 200;
	float b = 0;
	float c = 0;

	while (a > 150 || b > 150 || c > 150 || a <= 0 || b <= 0 || c <= 0) {
		printf("\nEntrer a : ");
		scanf_s("%f", &a);
		printf("Entrer b : ");
		scanf_s("%f", &b);
		printf("Entrer c : ");
		scanf_s("%f", &c);
	}
	tri(&a, &b, &c);

	if (a > 55 || b > 35 || c > 25) {
		printf("\nBAGAGE NON VALIDE ");
	}
	printf("BAGAGE VALIDE");
}