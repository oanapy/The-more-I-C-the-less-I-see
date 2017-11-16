/*3. Creati cate o functie pentru: citirea elementelor unui array bidimensional, afisarea elementelor array-ului, selectarea elementelor de pe margine, selectarea elementului aflat la intersectia diagonalelor (daca matricea este patratica),  calculeaza suma a doua array-uri bidimensionale (daca au aceleasi dimensiuni: nr egal de linii si numar egal de coloane). Apelati corespunzator functiile din functia main().*/

#include <stdio.h>
#include <stdlib.h>

int ce_numar(){
	int nr;
	scanf("%d", &nr);
	return nr;
}

void citire_elemente(int linii, int coloane, float arr[linii][coloane]){
	int i, j;
	for(i = 0; i < linii; i++)
		for(j = 0; j < coloane; j++){
			printf("a[%d][%d]: ", i+1, j+1);
			scanf("%f", &arr[i][j]);
		}
}

void afisare_elemente(int linii, int coloane, float arr[linii][coloane]){
	int i, j;
	for(i = 0; i < linii; i++){
		for(j = 0; j < coloane; j++){
			printf("%f\t", arr[i][j]);
		}
		printf("\n");
	}
}

void elemente_margine(int linii, int coloane, float arr[linii][coloane]){
	int i, j;
    /* Row iterator for loop */
    for(i = 0; i < linii; i++){
     /* Column iterator for loop */
        for(j = 0; j < coloane; j++){
            if (i == 0) {
                printf("%f\t", arr[0][j]); //it prints the first line
            }
            else if (i==linii-1) {
                printf("%f\t", arr[linii - 1][j]); //it prints the last line
            }
            else if (j == 0) {
            	printf("%f\t", arr[i][0]); //it prints the first column
            }
            else if (j == coloane-1) {
            	printf("%f\t", arr[i][coloane-1]); //it prints the first column
            }
            else {
                printf("        \t");
            }
        }
        printf("\n");
	}
}

void element_intersectie(int linii, int coloane, float arr[linii][coloane]){
	if (linii == coloane){
		printf("%f\n", arr[linii/2][coloane/2]);

	}

}

void suma_douamatrici(int linii, int linii2, int coloane, int coloane2, float arr[linii][coloane], float arr2[linii2][coloane2]){
	int i, j;
	if ((linii == linii2) && (coloane == coloane2)){
		for(i = 0; i < linii; i++){
			for(j = 0; j < coloane; j++){
				printf("%f\t", arr[i][j] + arr2[i][j]);
			}
		printf("\n");
		}

	} else {
		printf("Cele doua matrici au dimensiuni diferite.\n");
	}

}

int main(void){
	int linii, linii2, coloane, coloane2, x;
	

	printf("Introduceti nr. de linii: ");
	linii = ce_numar();
	printf("Introduceti nr. de coloane: "); 
	coloane = ce_numar();

	float arr[linii][coloane];
	
	citire_elemente(linii, coloane, arr);

	printf("Matricea introdusa este :\n");
	afisare_elemente(linii, coloane, arr);

	printf("Elementele din margine sunt :\n");
	elemente_margine(linii, coloane, arr);

	printf("Elementul de la intersectia diagonalelor este: \n");
	element_intersectie(linii, coloane, arr);

	printf("Introduceti nr. de linii pentru a doua matrice: ");
	linii2 = ce_numar();
	printf("Introduceti nr. de coloane pentru a doua matrice: "); 
	coloane2 = ce_numar();

	float arr2[linii2][coloane2];

	citire_elemente(linii2, coloane2, arr2);

	printf("Matricea a doua introdusa este :\n");
	afisare_elemente(linii2, coloane2, arr2);

	printf("Suma a doua matrici de aceeasi dimensiune este: \n");
	suma_douamatrici(linii, linii2, coloane, coloane2, arr, arr2);

}