/*Scrieți un program care calculează suma cifrelor impare
ale unui număr introdus de utilizator.*/

#include <stdio.h>

void main() {
	int n, u, suma;
	suma = 0;
	printf("Introduceti un numar: \n");
	scanf("%d", &n);

	do {
		u = n % 10;
		n /= 10;
		if (u % 2 != 0) {
			suma += u;
		}
	} while(n > 0); 

	printf("Suma cifrelor impare ale numarului introdus este: %d\n", suma);

}