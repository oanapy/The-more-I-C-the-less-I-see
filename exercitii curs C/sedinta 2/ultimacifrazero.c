/* Scrieți un program care verifică dacă un număr introdus
de la tastatură are ultima cifră 0.*/

#include <stdio.h>

void main(){
	int nr;
	printf("Introduceti un numar: \n");
	scanf("%d", &nr);

	if(nr % 10 == 0) {
		printf("Numarul are ultima cifra 0.\n");
	} else {
		printf("Numarul nu are ultima cifra 0.\n");
	}

}