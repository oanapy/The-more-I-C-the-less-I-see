/*Scrieți un program care rezolvă ecuația de gradul 2,
utilizatorul introduce de la tastatură parametrii a, b și c ai
ecuației de forma: ax2+bx+c=0*/

#include <stdio.h>
#include <math.h>

void main(){
	int a, b, c;
	float delta, x1, x2;

	printf("Introduceti parametrii a, b, c pentru a rezolva ecuatia: ");
	scanf("%d %d %d", &a, &b, &c);

	delta = b * b - (4 * a * c);

	if (a == 0) {
		if (b == 0) {
			printf("Nu este ecuatie. \n");
		} else {
			printf("Este ecuatie de gradul I. Radacina este:");
			x1 = (float)-c / b;
			printf("%f\n", x1);
		}
	} else {
		if (delta > 0) {
			x1 = -b + sqrt(delta)/(2 * a);
			x2 = -b - sqrt(delta)/(2 * a);
			printf("Exista doua radacini reale: %f si %f\n", x1, x2);
		} else if (delta == 0) {
			x1 = -b / (2 * a);
			printf("Radacinile au valori egale si acestea sunt: %f\n", x1);

		} else {
			printf("Ecuatia are radacini complexe!\n");
		}
	}
}