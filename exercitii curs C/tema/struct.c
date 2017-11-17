/*4. Creati un array de structuri de date de tipul urmator:
struct Persoana{ char nume[15]; char prenume[10], char CNP[14]
};
Creati: o functie care sorteaza persoanele alfabetic dupa nume; o functie care afiseaza numele persoanelor nascute inainte de 1990, o functie care afiseaza numele si persoanelor care incep cu 'C'.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSOANA {
	char nume[25];
	char prenume[10];
	int CNP[13];
};

void sortare_alfabetica(struct PERSOANA* persoana, int n);
void inainte_1990(struct PERSOANA* persoana, int n);
void persoaneC(struct PERSOANA* persoana, int n);

void main() {

	int n;
	printf("Cate persoane se introduc? ");
	scanf("%d", &n);
	struct PERSOANA *persoana = malloc(n * sizeof(struct PERSOANA));

	int i = 0;
	for (i = 0; i < n; i++) {
		printf("\ndatele personalului: %d\n", i+1);
		printf("numele personalului: "); 
		scanf("%s", persoana[i].nume);
		printf("prenumele personalului: "); 
		scanf("%s", persoana[i].prenume);
		printf("cnp: "); 
		scanf("%s", persoana[i].CNP);
	}

	for (i = 0; i < n; i++) {
		printf("\ndatele personalului: %d\n", i+1);
		printf("numele personalului: %s\n", persoana[i].nume);
		printf("prenumele personalului: %s\n", persoana[i].prenume);
		printf("cnp: %s\n", persoana[i].CNP);
		
		}

	printf("Persoanele sortate in ordine alfabetica dupa nume sunt: \n");
	sortare_alfabetica(persoana, n);

	printf("Persoanele nascute dupa 1990 sunt: \n");
	inainte_1990(persoana, n);

	printf("Persoanele ale caror nume incep cu C: \n");
	persoaneC(persoana, n);
}

void sortare_alfabetica(struct PERSOANA* persoana, int n){
	int i;
	for (i = 0; i < n; i++) {
 		printf("%s\t", persoana[i].nume);
	}
 	printf("\n");
}

void inainte_1990(struct PERSOANA* persoana, int n){ //to do - de cautat cum se printeaza anul din CNP
	int i;
	for(i = 0; i < n; i++) {
		printf("%s %s %i\n", persoana[i].nume, persoana[i].prenume, persoana[i].CNP[1]);
	}
}

void persoaneC(struct PERSOANA* persoana, int n){ 
	int i;
	for(i = 0; i < n; i++) {
		if (persoana[i].nume[0] == 'C') {
			printf("%s\n", persoana[i].nume);
		}
	}
}

