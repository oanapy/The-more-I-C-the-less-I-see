/*Scrieți un program care calculează suma cifrelor unui
număr citit de la tastatură.*/

#include <stdio.h>

void main() {
	int n, u, suma;
	suma = 0;
	printf("Introduceti un numar: \n");
	scanf("%d", &n);

	do {
		u = n % 10;
		n /= 10;
		suma += u;
	} while(n > 0); 

	printf("Suma cifrelor numarului introdus este: %d\n", suma);

}