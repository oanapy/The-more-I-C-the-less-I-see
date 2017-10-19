/*Scrieți un program care verifică dacă un număr introdus
de la tastatură este par sau impar.*/

#include <stdio.h>

void main(){
	int nr;
	printf("Introduceti un numar:");
	scanf("%d", &nr);

	if (nr % 2 == 0) {
		printf("Numarul introdus este par\n");
	} else {
		printf("Numarul este impar\n");
	}
}