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
	char CNP[14];
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
	//citire date n angajati	
	for (i = 0; i < n; i++) {
		printf("\ndatele personalului: %d\n", i+1);
		printf("numele personalului: "); 
		scanf("%s", persoana[i].nume);
		printf("prenumele personalului: "); 
		scanf("%s", persoana[i].prenume);
		printf("cnp: "); 
		scanf("%s", persoana[i].CNP);
	}
	//afisare date n angajati
	for (i = 0; i < n; i++) {
		printf("\ndatele personalului: %d\n", i+1);
		printf("numele personalului: %s\n", persoana[i].nume);
		printf("prenumele personalului: %s\n", persoana[i].prenume);
		printf("cnp: %s\n", persoana[i].CNP);
		
		}

	printf("Persoanele sortate in ordine alfabetica dupa nume sunt: \n");
	sortare_alfabetica(persoana, n);

	printf("Persoanele nascute inainte de 1990 sunt: \n");
	inainte_1990(persoana, n);

	printf("Persoanele ale caror nume incep cu C: \n");
	persoaneC(persoana, n);
}

void sortare_alfabetica(struct PERSOANA* persoana, int n){
	int i;
	struct PERSOANA aux;
	//pentru sortare se va aplica algoritmul de sortare invatat, sortarea prin interschimbare
	int gasit = 0;
	do{
		gasit = 0;
		for(i = 0; i < n-1; i++)
			if(strcmp(persoana[i].nume, persoana[i+1].nume)>0){
				aux = persoana[i];
				persoana[i] = persoana[i+1];
				persoana[i+1] = aux;
				gasit = 1;
			}
	}while (gasit);	


	for (i = 0; i < n; i++) {
 		printf("%s\t", persoana[i].nume);
	}
 	printf("\n");
}

/* explicatie CNP
Codul numeric personal - SAALLZZJJNNNC, unde :
S = sexul si secolul in care s-a nascut persoana (vezi explicatiile de mai jos)
AA = anul nasterii
LL = luna nasterii
ZZ= ziua nasterii
JJ = codul judetului sau sectorului in care s-a nascut persoana
NNN = este un nr.format din 3 cifre situate intre 001 si 999.

S - Prima cifră a C.N.P.-ului este: (sex bărbătesc / sex femeiesc)

    1 / 2 - născuți între 1 ianuarie 1900 și 31 decembrie 1999
    3 / 4 - născuți între 1 ianuarie 1800 și 31 decembrie 1899
    5 / 6 - născuți între 1 ianuarie 2000 și 31 decembrie 2099

De accea pentru a afla anul nasterii trebuie preluate caracterele 2 și 3 și corelate cu primul caracter care determina secolul
*/
void inainte_1990(struct PERSOANA *persoana, int n){
	int i;
	for(i = 0; i < n; i++) {
		char an_char[3];
		int an = atoi(strncpy(an_char, persoana[i].CNP+1, 2));
		char secol = persoana[i].CNP[0];	
		if (secol == '1' || secol == '2')
			an = 1900 + an;
		else
			an = 2000 + an;		
		//printf("an: %d\n", an); //doar pentru verificare, afisam anul calculat
		if ( an <= 1990 ) {
			printf("%s %s\n", persoana[i].nume, persoana[i].prenume);
		}
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

