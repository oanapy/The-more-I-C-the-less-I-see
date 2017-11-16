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

void main() {

	int n;
	printf("cati persoane se introduc? ");
	scanf("%d", &n);
	struct PERSOANA *persoana = malloc(n * sizeof(struct PERSOANA));

	//introducere date
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("\ndatele persoanaului: %d\n", i+1);
		printf("numele persoanaului: "); 
		scanf("%s", persoana[i].nume);
		printf("prenumele persoanaului: "); 
		scanf("%s", persoana[i].prenume);
		printf("cnp: "); 
		scanf("%s", persoana[i].CNP);
	}

	//afisarea datelor celor n persoanai
	for (i = 0; i < n; i++) {
		printf("\ndatele persoanaului: %d\n", i+1);
		printf("numele persoanaului: %s\n", persoana[i].nume);
		printf("prenumele persoanaului: %s\n", persoana[i].prenume);
		printf("cnp: %s\n", persoana[i].CNP);
		
		}

	printf("Persoanele sortate in ordine alfaetica dupa nume sunt: \n");
	sortare_alfabetica(persoana, n);

	printf("Persoanele nascute dupa 1990 sunt: \n");
	inainte_1990(persoana, n);
}

void sortare_alfabetica(struct PERSOANA* persoana, int n){
	int i;
	for (i = 0; i < n; i++) {
 		printf("%s\t", persoana[i].nume);
	}
 	printf("\n");
}

void inainte_1990(struct PERSOANA* persoana, int n){
	int i;
	for(i = 0; i < n; i++) {
		printf("%s %s\n", persoana[i].nume, persoana[i].prenume);
	}


}

//to do - de cautat cum se printeaza anul din CNP