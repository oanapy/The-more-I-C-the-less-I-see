/*Creați o structură denumită Angajat, care să rețină:
-Numele și prenumele fiecărui angajat;
-CNP-ul,
-Numărul de ani vechime,
-Plata pe oră
-Numărul de ore lucrate
-Remunerația (calculată ca plata pe oră * nr-ul orelor
lucrate).


Cu structura creată anterior:
- Introduceți și afișați datele unui angajat;
- Introduceți un număr de n angajați;
- Afișați numele angajatului care câștigă cel mai mult;
- Afișati numele angajatului care lucrează cel mai mult;
- Afișați numărul angajaților de sex feminin;
- Afișați numele angajaților sortate alfabetic;
- Afișati numele angajaților sortate descrescător în funcție
de plata pe oră.


Cu structura creată anterior:
- Introduceți un nou câmp în structură, de tip struct, care să
conțină data angajării. Verificați că toate cerințele
anterioare pot fi realizate după modificare.
- Afișați numele angajaților angajați după anul 2005;
- Afișați angajații care au lucrat peste 40 de ore și vechimea
acestora*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

struct ANGAJAT {
	char nume[26];
	char prenume[26];
	int CNP[13];
	int ani_vechime;
	float plata_ora;
	float nr_ore;
	float remuneratie;
	struct {
		int zi, luna, an;
	} da;
} angajat1;

	printf("numele angajatului: "); scanf("%s", angajat1.nume);
	printf("prenumele angajatului: "); scanf("%s", angajat1.prenume);
	printf("cnp: "); scanf("%s", angajat1.CNP);
	printf("vechime: "); scanf("%d", &angajat1.ani_vechime);
	printf("tarif orar: "); scanf("%f", &angajat1.plata_ora);
	printf("ore lucrate: "); scanf("%f", &angajat1.nr_ore);
   	angajat1.remuneratie = angajat1.plata_ora * angajat1.nr_ore;
   	printf("data angajarii\n");
	printf("ziua: "); scanf("%d", &angajat1.da.zi);
	printf("luna: "); scanf("%d", &angajat1.da.luna);
	printf("anul: :"); scanf("%d", &angajat1.da.an);

	

	//afisarea datelor angajatului
	puts("\nati introdus: ");
	printf("numele angajatului: %s\n", angajat1.nume);
	printf("prenumele angajatului: %s\n", angajat1.prenume);
	printf("cnp: %s\n", angajat1.CNP);
	printf("vechime: %d ani\n", angajat1.ani_vechime);
	printf("tarif orar: %f lei\n", angajat1.plata_ora);
	printf("ore lucrate: %f\n", angajat1.nr_ore);
	printf("venit realizat: %f lei\n", angajat1.remuneratie);
	printf("data angajarii: %d-%d-%d\n", angajat1.da.zi, angajat1.da.luna, angajat1.da.an);
	printf("\n");

	//alocare memorie pentru o serie de n angajati
	struct ANGAJAT *angajat;
	int n;
	printf("cati angajati se introduc? ");
	scanf("%d", &n);
	angajat = malloc(n * sizeof(struct ANGAJAT));

	//introducere date
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("\ndatele angajatului: %d\n", i+1);
		printf("numele angajatului: "); 
		scanf("%s", angajat[i].nume);
		printf("prenumele angajatului: "); 
		scanf("%s", angajat[i].prenume);
		printf("cnp: "); 
		scanf("%s", angajat[i].CNP);
		printf("vechime: "); 
		scanf("%d", &angajat[i].ani_vechime);
		printf("tarif orar: "); 
		scanf("%f", &angajat[i].nr_ore);
		printf("ore lucrate: "); 
		scanf("%d", &angajat[i].plata_ora);
	   	angajat[i].remuneratie = angajat[i].plata_ora * angajat[i].nr_ore;
	   	printf("data angajarii\n");
		printf("ziua: "); scanf("%d", &angajat[i].da.zi);
		printf("luna: "); scanf("%d", &angajat[i].da.luna);
		printf("anul: :"); scanf("%d", &angajat[i].da.an);
	}

	//afisarea datelor celor n angajati
	for (i = 0; i < n; i++) {
		printf("\ndatele angajatului: %d\n", i+1);
		printf("numele angajatului: %s\n", angajat[i].nume);
		printf("prenumele angajatului: %s\n", angajat[i].prenume);
		printf("cnp: %s\n", angajat[i].CNP);
		printf("vechime: %d ani\n", angajat[i].ani_vechime);
		printf("tarif orar: %f lei\n", angajat[i].plata_ora);
		printf("ore lucrate: %d\n", angajat[i].nr_ore);
		printf("venit realizat: %f lei\n", angajat[i].remuneratie);
		printf("data angajarii: %d-%d-%d\n", angajat[i].da.zi, angajat[i].da.luna, angajat[i].da.an);

		printf("\n");
	}

	//numele angajatului care munceste cel mai mult;
	int max = 0;
	for (i = 1; i < n; i++)
		if (angajat[max].nr_ore < angajat[i].nr_ore)
				max = i;

	printf("\ncel mai mult a lucrat angajatul %s, %s\n", angajat[max].nume, angajat[max].prenume);

	//numele angajatului care castiga cel mai mult;
	max = 0;
	for (i = 1; i < n; i++)
		if (angajat[max].plata_ora < angajat[i].plata_ora)
				max=i;

	printf("\ncel mai mult castiga angajatul %s, %s\n", angajat[max].nume, angajat[max].prenume);

	//numarul angajatilor de sex femini
	int nr = 0;
	for (i = 0; i < n; i++)
			if (angajat[i].CNP[0] == '2')
					nr++;

	printf("\nnumarul femeilor angajate este: %d\n", nr);

	int swapped = 0;
	struct ANGAJAT aux;

	do{
		swapped = 0;
		for (i = 0; i < n-1; i++)
			if (strcmp(angajat[i].nume, angajat[i+1].nume) > 0){
				aux = angajat[i];
				angajat[i] = angajat[i+1];
				angajat[i+1] = aux;
				swapped = 1;
			}
	} while(swapped);

	printf("\nnumele angajatilor sortate alfabetic\n");
	for (i = 0; i < n; i++)
		printf("%s\t", angajat[i].nume);
	printf("\n");

	//sortarea angajatilor descrescator functie de tariful orar
	swapped = 0;
	do{
		swapped = 0;
		for (i = 0; i < n-1; i++)
			if (angajat[i].plata_ora < angajat[i+1].plata_ora){
				aux=angajat[i];
				angajat[i]  =angajat[i+1];
				angajat[i+1] = aux;
				swapped = 1;
			}
	}while(swapped);

	printf("\nnumele angajatilor sortati descrescator in functie de tariful orar\n");
	for (i = 0; i < n; i++)
		printf("%s\t", angajat[i].nume);
	printf("\n");

	//numele angajatilor angajati dupa 2005
	printf("\nnumele persoanelor angajate incepand cu 2005\n");
	for(i = 0; i < n; i++)
		if(angajat[i].da.an>=2005)
			printf("%s %s\n", angajat[i].nume, angajat[i].prenume);
	printf("\n");

	//angajatii care au lucrat >40 ore si vechimea lor
	printf("\nangajatii care au lucrat peste 40 de ore si vechimea lor:\n");
	for(i = 0; i < n; i++)
		if (angajat[i].nr_ore > 40)
			printf("%s, %d\n", angajat[i].nume, angajat[i].ani_vechime);
	printf("\n");
}