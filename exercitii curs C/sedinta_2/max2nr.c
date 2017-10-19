/*Scrieți un program care cere utilizatorului să introducă
două numere și afișează valoarea celui mai mare dintre
acestea.*/

#include <stdio.h>

void main(){
	int nr1, nr2;
	printf("Introdu primul numar: \n");
	scanf("%d", &nr1);
	printf("Introdu al doilea numar: \n");
	scanf("%d", &nr2);
	if (nr1 > nr2) {
		printf("Numarul cel mai mare este: %d\n", nr1);
	} else {
		printf("Numarul cel mai mare este: %d\n", nr2);
	}

} 
