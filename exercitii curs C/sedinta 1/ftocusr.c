/*
Scrieți un program care declară două variabile care
rețin numere reale (float sau double): variabila F și
variabila C. Variabila C va fi inițializată cu valoarea 0.
Se va calcula în variabila F valoarea temperaturii în
grade Fahrenheit pornind de la valoarea reținută în C
utilizând formula: F = C x 9/5 + 32. 
C introdus de la tastatura
 */
#include <stdio.h>


void main(){
	float F, C;
	printf("Introdu valoarea temperaturii in grade Celsius: ");
	scanf("%f", &C);
	F = C * 9/5 + 32;
	printf("Temperatura in grade Fahrenheit este %f\n", F);
}