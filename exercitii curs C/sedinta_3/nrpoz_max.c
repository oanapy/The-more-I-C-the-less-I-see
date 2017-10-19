/*Scrieți un program care îi cere utilizatorului să introducă
numere pozitive. Atunci când utilizatorul introduce valoarea -
1, se va afișa maximul numerelor introduse până atunci. */

#include <stdio.h>

void main(){
	int nr = 0;
	int max = -1;

	do {
		printf("introduceti un numar: "); 
		scanf("%d", &nr);
		if(nr > max)
			max = nr;
	} while (nr != -1);

	printf("maximul este: %d", max);
}
