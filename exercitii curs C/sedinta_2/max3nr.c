/*Modificați programul anterior astfel încât să accepte 3
numere ca date de intrare și să afișeze minimul și
maximul dintre acestea. Afișați valoarea media a celor 3
numere. */

#include <stdio.h>

void main(){
	int nr1, nr2, nr3;
	printf("Introdu primul numar: \n");
	scanf("%d", &nr1);
	printf("Introdu al doilea numar: \n");
	scanf("%d", &nr2);
	printf("Introdu al treilea numar: \n");
	scanf("%d", &nr3);
	if (nr1 > nr2) {
		if (nr1 > nr3) {
			printf("Numarul cel mai mare este: %d\n", nr1);
		}
		else {
			printf("Numarul cel mai mare este: %d\n", nr3);
		}
	} else if (nr2 > nr3) {
		printf("Numarul cel mai mare este: %d\n", nr2);
	} else {
		printf("Numarul cel mai mare este: %d\n", nr3 );
	}

	if (nr1 < nr2) {
		if (nr1 < nr3) {
			printf("Numarul cel mai mic este: %d\n", nr1);
		} else {
			printf("Numarul cel mai mic este: %d\n", nr3);
		}
	} else if (nr2 < nr3) {
		printf("Numarul cel mai mic este: %d\n", nr2);
	} else {
		printf("Numarul cel mai mic este: %d\n", nr3);
	}

	printf("Media valorilor introduse este: %.2f\n", (float)(nr1 + nr2 + nr3)/3);

} 