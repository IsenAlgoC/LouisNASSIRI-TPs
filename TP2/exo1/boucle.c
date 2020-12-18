#include <stdlib.h>
#include <stdio.h>

//Somme des n entiers naturels

//fonction principale
int main() {
	fctfor();
	//fctwhile();
	//fctwhiledo();
	depassement();
	//demande();
}



//boucle for 
int fctfor() {
	int n = 200;
	int S = 0;
	for (int i = 1; i <= n; i++) {
		//i++ =on incrémente de 1 la variable i à chq boucle
		S += i;
	}
	printf("Avec le FOR, la valeur de n est %d, et la valeur de la somme des n premiers entiers positifs est %d\n", n, S);
}


//boucle while 
int fctwhile() {
	unsigned short int S = 0;
	int n = 361;
	int i = 1;
	while (i <= n) {
		S += i;
		i++;
	}
	printf("Avec le WHILE, la valeur de n est %d, et la valeur de la somme des n premiers entiers positifs est %d\n", n, S);
}

//boucle do... while
int fctwhiledo() {
	int S = 0;
	int n = 100;
	int i = 1;
	do {
		S += i;
		i++;
	} 
	while (i <= n);
	printf("Avec le DO WHILE, la valeur de n est %d, et la valeur de la somme des n premiers entiers positifs est %d\n", n, S);
}


//Valeur max de n sans dépassement de capacité
int depassement() {
	unsigned short int S = 0;
	unsigned short int n = 0;
	unsigned short int L = 400;
	while ((n <= L)&&(USHRT_MAX-S>=n)) {		//S+i<=65535 = 65535-S>=i
		S += n;
		n+=1;
	}
	//if ((n = L) & (USHRT_MAX - S >= n)) {
		//S += n;
	//}
	printf("la valeur de S est %d et la valeur maximale de n est %d", S,n);
}


//demander valeur de n à l'utilisateur
int demande() {
	unsigned short int n = 0;
	unsigned short int S = 0;
	printf("rentrer une valeur de n\n");
	scanf_s("%hu", &n);
	for (int i = 1; i <= n; i++) {
		S += i;
		if USHRT_MAX - S >= i; //S+i<=USHRT_MAXUSHRT_MAX-S>=i
	}
	printf("Avec le FOR, la valeur de n est %d, et la valeur de la somme des n premiers entiers positifs est %d\n", n, S);
}