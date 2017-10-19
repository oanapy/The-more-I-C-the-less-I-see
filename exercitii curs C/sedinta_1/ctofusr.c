/*
Scrieți un program care cere utilizatorului să introducă o
valoare pentru temperatura măsurată în grade
Fahrenheit (F) și apoi realizează conversia către grade
Celsius (C) folosind formula: C = (5 / 9) * (F - 32).
 */

#include <stdio.h>

void main(){
	float F, C;
	printf("Introdu valoarea temperaturii in grade Fahrenheit: ");
	scanf("%f", &F);
	printf("%f\n", F);
	C = (float)5/9 * (F - 32);
	printf("Temperatura in grade Celsius este %f\n", C);
}