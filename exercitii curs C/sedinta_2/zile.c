/*.Scrieți un program care afișează o dată, primită prin 3
valori numere întregi (zi, lună și an) în formatele:
- YYYY-MM-DD
- MM-DD-YYYY
- DD-MM-YYYY
- D-M-Y*/

#include <stdio.h>

void main(){
	int zi, luna, an;
	printf("Introduceti data de azi ca zi, luna, an (20 10 2017).\n");
	scanf("%d %d %d", &zi, &luna, &an);

	printf("data in format YYYY-MM-DD este: %04d - %02d - %02d \n", an, luna, zi);
	printf("data in format MM-DD-YYY este: %02d - %02d - %04d \n", luna, zi, an);
	printf("data in format DD-MM-YYYY este: %02d - %02d - %04d \n", zi, luna, an);
	printf("data in format D-M-Y este: %d - %d - %d \n", zi, luna, an);
}