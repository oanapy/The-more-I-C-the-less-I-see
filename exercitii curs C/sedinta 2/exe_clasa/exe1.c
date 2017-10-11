#include <stdio.h>

int main() {
	int a, b;
	float c, d;

	printf("Introduceti un numar intreg: ");
	scanf("%d", &a);

	printf("Introduceti al doilea numar intreg: ");
	scanf("%d", &b);

	printf("Introduceti doua numere cu zecimala: ");
	scanf("%f %f", &c, &d);

	printf("Am citit numerele: \n%d %d\n\n%.2f %.2f\n", a, b, c, d);
	printf("Suma celor patru numere este: %.2f\n", a+b+c+d);
	printf("Diferenta numerelor intregi este: %d\n", a -b);
	printf("Restul impartirii dintre cele doua numere intregi este: %d\n", a % b);
}