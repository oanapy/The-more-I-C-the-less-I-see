/*Declați un array de 30 elemente de tip int;
Folosiți o buclă și funcția printf pentru a afișa valoarea tuturor elementelor array-ului;
Modificați decarația array-ului astfel încât să initializați toate elementele acestuia cu valoarea 0;
Asignați celui de-al treilea element valoarea 55;
Folosiți funcția „scanf” pentru a prelua de la tastatură o valoare introdusă de utilizator și folosiți ultimul element al array-ului pentru a o stoca;
Afișați din nou valoarea tuturor elementelor array-ului.*/


#include <stdio.h>
#include <stdlib.h>

int main(){
	int exe_1[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1};
	int exe[30] = {0};
	int i, r;
	for( i = 0; i < 30; i ++) {
		printf("%d ", exe[i]);
	}
	exe[2] = 55;
	printf("Introdu o valoare in array: \n");
	scanf("%d", &r);
	exe[29] = r;
	for( i = 0; i < 30; i ++) {
		printf("Noile elemenete din array sunt: %d \n ", exe[i]);
	}
	
}