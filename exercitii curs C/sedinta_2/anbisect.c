/*Scrieți un program care verifică dacă un an introdus de la
tastatură este un an bisect. (un an este bisect dacă
numărul este divizibil cu 4, nu este divizibil cu 100, dar
este divizibil cu 400)*/

#include <stdio.h>

void main(){
	int an;

	printf("Introduceti un an: \n");
	scanf("%d", &an);

	if ((an % 4 == 0) | (an % 100 == 0) | (an % 400 == 0)) {
		printf("Anul %d este bisect\n", an);
	} else {
		printf("Anul %d nu este bisect \n", an);
	}

}