/*Scrieți un program care afișează numerele pare cuprinse
între 1 și x, unde x este un număr întreg citit de la
tastatură.*/


#include <stdio.h>

void main() {
	int n, i;

	printf("Introdu un numar:\n");
	scanf("%d", &n);
	printf("Numerele pare in ordine crescatoare de la 1 la %d sunt: 1 \n", n);

	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			printf("%d \t", i);
		}
	}
	printf("\n");
}