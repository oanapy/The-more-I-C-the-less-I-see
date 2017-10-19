/*Scrieți un program care afișează numerele de la 1 la x,
unde x este un număr întreg citit de la tastatură. Scrieți
programul utilizând pe rând o instrucțiune de tip while,
do{}while și for.*/

#include <stdio.h>

void main(){
 	int nr, n, i;
 	n = 1;

 	printf("Introdu un numar:\n");
 	scanf("%d", &nr);
 	printf("Numerele de la 1 la %d in ordine crescatoare sunt: \n", nr);

 	// do {
 	// 	printf("%d \t", n++);
 	// } while (n <= nr);
 	// printf("\n");

 	// while (n <= nr) {
 	// 	printf("%d \t", n++);
 	// } 
 	// printf("\n");
 	// 
 	for (i = 0; i <= nr; i++) {
 		printf("%d\t", i);
 	}
 	printf("\n");
}

