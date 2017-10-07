#include <stdio.h>

int main(void){
	float C, F;

	printf("temperatura in grade Celsius: ");
	scanf("%f", &C);

	F=C*9/5 + 32;

	printf("temperatura in grade Fahrenheit este: %f\n", F);

	printf("temperatura in grade Fahrenheit: ");
	scanf("%f", &F);

	C=5.0/9 *(F-32);

	printf("temperatura in grade Celsius este: %f\n", C);

}
