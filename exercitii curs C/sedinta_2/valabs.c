/*Scrieți un program care calculează valoarea absolută a
unui număr introdus de la tastatură.*/

#include <stdio.h>

void main(){
	float valoare;

	printf("Introduceti un numar\n");
	scanf("%f", &valoare);

	printf("Valoarea introdusa este: %d\n",  (int) valoare);
	
}