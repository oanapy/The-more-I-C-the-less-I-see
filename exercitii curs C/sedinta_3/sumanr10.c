/*Scrieți un program care calculează suma numerelor de
la 1 la 10. Scrieți programul utilizând pe rând o
instrucțiune de tip while, do{}while și for.*/

#include <stdio.h>

void main () {
	int n, suma, i;
	n = 1;
	suma = 0;

	// while (n <= 10) {
	// 	suma += n;
	// 	n ++;

	// }
	// printf("suma este %d \n", suma);

	// do {
	// 	suma += n;
	// 	n ++;
	// } while (n <= 10);
	// printf("suma este %d \n", suma);

	for ( i = 0; i <= 10; i++) {
		suma += i;
	}
	printf("suma este %d \n", suma);


}