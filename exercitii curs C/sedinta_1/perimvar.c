/*Scrieți un program care declară trei variabile care rețin
numere reale (float sau double): variabila raza, variabila
perimetru si variabila arie. Variabila raza va fi inițializată
cu valoarea 2. Se vor calcula aria și perimetrul cercului
corespunzător în variabilele definite anterior și apoi se
vor afișa valorile acestora.
*/

#include <stdio.h>
#include <math.h>

void main(){
	float raza, perimetru, arie;
	raza = 2;
	perimetru = 2 * M_PI * raza;
	arie = M_PI * raza * raza;
	printf("perimetrul este %f\n", perimetru);
	printf("aria este %f\n", arie);
}