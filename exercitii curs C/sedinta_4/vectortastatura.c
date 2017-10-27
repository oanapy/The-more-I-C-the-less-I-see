/*Se da un sir de numere citite de la tastatura

afisati - elementele vectorului;
- elementele pare din sir
- elementele impare ale vect
- suma elementelor pozitive
- produsul elementelor negative de pe pozitiile impare
- numarul elemenetleor divizibile cu 5
- daca elementul de pe pozitia p este par;*/


#include <stdio.h>

void main(){
	int length, i, nr_elem, pozitie, suma, produs;
	printf("Cat enumere vreti sa introduceti?\n");
	scanf("%d", &length);
	char sir[length + 1];
	suma = 0;
	produs = 1;
	nr_elem = 0;

	printf("Introduceti elementele din sir.\n");
	for (i = 0; i < length; i++){
		printf("Elementul %d este: \n", i + 1);
		scanf("%d", &sir[i]);
	}

	printf("Elementele sirului sunt\n");

	for (i = 0; i < length; i++){
		printf("%d ", sir[i]);
	}

	printf("Elementele pare din sir sunt\n");

	for (i = 0; i < length; i++){
		if (sir[i] % 2 == 0) {
			printf("%d ", sir[i]);
		}
	}

	printf("Elementele impare din sir sunt\n");

	for (i = 0; i < length; i++){
		if (sir[i] % 2 != 0) {
			printf("%d ", sir[i]);
		}
	}

	printf("Suma elementelor pozitive din sir este\n");

	for (i = 0; i < length; i++){
		if (sir[i] > 0) {
			suma += sir[i];	
		}
	}
	printf("%d \n", suma);


	for (i = 0; i < length; i++){
		if (sir[i] < 0) {
			if (sir[i] < 0 && i % 2 != 0) {
				produs *= sir[i];	
			}
		printf("Produsul elementelor negative de pe pozitiile impare este\n");
		}
	}
	printf("%d \n", produs);

	printf("Numarul elementelor divizibile cu 5 este: \n");

	for (i = 0; i < length; i++){
		if (sir[i] % 5 == 0) {
			nr_elem +=1;	
		}
	}
	printf("%d \n", nr_elem);

	printf("Introduceti un numar pentru a afla daca cel ce se afla pe aceasta pozitie este par sau nu: ");
	scanf("%d", &pozitie);

	if (pozitie < length) {
		if (sir[pozitie] % 2 == 0){
			printf("Numarul de pe pozitia %d care este reprezentat de valoarea %d  este par.\n", pozitie, sir[pozitie]);
		} else {
			printf("Numarul este impar. \n");
		}
	} else {
		printf("Pozitia nu este una valida!\n");
	};
}