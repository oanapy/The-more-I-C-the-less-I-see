/*Scrieti un program care roaga utilizatorul sa introduca doua numere si apoi sa apese
- s - suma
- p - produs
- r - radical primul numar
 - n - reintroducere numere
 - x - exit. Meniul se afiseaza dupa fiecare calcul pana la iesirea din program*/

#include <stdio.h>
#include <math.h>

void main(){

	char letter;
	double numar1, numar2, suma, produs, radical;

	printf("Introduceti doua numere: ");
	scanf("%lf %lf", &numar1, &numar2);

	do {
		printf("Ce doriti sa se intmaple acum cu cele doua numere? Alegeti din meniul de mai jos o optiune tastand litera corespunzatoare: - s - suma \t - p - produs \t - r - radical primul numar \t  - n - reintroducere numere \t  - x - exit \n");
		do {
			scanf("%c", &letter);
		} while (letter == '\n');

		printf("Ati introdus litera %c\n", letter);


		switch(letter) {
			case 's':
				printf("\nAti ales suma numerelor. ");
				suma = numar1 + numar2;
				printf("Asadar suma este %lf\n", suma);
				break;

			case 'p':
				printf("Ati ales produsul numerelor.");
				produs = numar1 * numar2;
				printf("Asadar produsul este %lf\n", produs);
				break;

			case 'r':
				printf("Ati ales radicalul primului numar. ");
				radical = sqrt(numar1);
				printf("Asadar radicalul este %lf\n", radical);
				break;

			case 'n':
				printf("Ati ales sa introduceti alte numere. Introduceti cele doua numere noi: ");
				scanf("%lf %lf", &numar1, &numar2);
				printf("Asadar cele doua numere sunt %lf si %lf\n", numar1, numar2);
				break;
		}
		
	}while (letter != 'x');
}