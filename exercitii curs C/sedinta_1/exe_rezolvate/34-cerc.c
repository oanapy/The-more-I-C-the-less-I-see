#include <stdio.h>

int main(void){
	float raza, arie, perimetru;

	printf("introduceti o valoare pentru raza: ");
	scanf("%f", &raza);

	arie=2*3.14*raza;
	perimetru=3.14*raza*raza;

	printf("pentru un cerc cu raza %f, aria este %f si perimetrul este %f\n", raza, arie, perimetru);

}
