/*1. Sa se scrie un program in C care gestioneaza cartile unei biblioteci.
Pentru aceasta, creati un fisier text care contine urmatoarele date despre 20 de carti:
- titlul,
- numele si prenumele autorului,
- domeniul (tehnic/literar la cererea utilizatorului),
- pretul si numarul de pagini.

Se va realiza un meniu prin care:

a) Se vor citi datele din fisier intr-un vector de structuri de date cu campuri corespunzatoare informatiilor de retinut despre fiecare carte.
b) Se pot introduce carti noi.
c) Se vor lista datele despre carti, in ordine alfabetica, dupa numelui autorului.
d) Se vor lista cartile din domeniul tehnic in ordinea crescatoare a pretului.
e) Se va afisa titlul fiecarei carti si numarul total al cartilor cu un pret mai mic decat o suma indicata de utilizator.
f) Se vor afisa titlurile cartilor scrise de autori ai caror nume incepe cu o litera introdusa de utilizator.
g) Se poate opri execuția programului.

Pentru rezolvarea fiecarei cerintelor a)-f) se va folosin (cel puțin) câte o funcție definită de programator.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct BIBLIOTECA { //declaratie structura Biblioteca
	char titlu[200];
	char nume_autor[25];
	char prenume_autor[25];
	char domeniu[10];
	float pret;
	int nr_pagini;
};

int optiuni_meniu(); //introduce optiunile din meniu
void incarcare_date(struct BIBLIOTECA *b, int nr_carti, FILE * fisier_biblioteca); //incarca datele in structura
void afisare_date(struct BIBLIOTECA *b, int nr_carti); //afiseaza datele din structura
void adaugare_carte(); //adauga elemente noi in structura
void sortare_alfabetica(struct BIBLIOTECA *b, int nr_carti); //sorteaza alfabetic elementele din structura
void sortare_pret(struct BIBLIOTECA *b, int nr_carti); //sorteaza dupa pret elementele din structura
void mai_mic_decat(struct BIBLIOTECA *b, int nr_carti); //filtreaza elementele din structura dupa un criteriu de pret
void autori_litera(struct BIBLIOTECA *b, int nr_carti); //filtreaza elementele din structura dupa un criteriu de litera

void main() {
	int alegere, nr;
	alegere = optiuni_meniu(); //retine numarul asociat optiunii alese de utilizator
	nr = 0; //initializare nr de carti
	FILE *fisier_biblioteca = fopen("carti.txt", "r"); //deschide fisierul si il mentine disponibil la o adresa intuitiva
	int i; //initializare contor
	if (!fisier_biblioteca) {
		printf("Nu s-a putut deschide fisierul inregistari \n");
	}
	else {

		fscanf(fisier_biblioteca, "%d", &nr); //muta cursorul dupa primul rand
		//printf("Nr de carti este %d\n", nr);
		struct BIBLIOTECA *b = malloc(nr * sizeof(struct BIBLIOTECA)); //aloca memorie variabilei care pointeaza catre o structura
		printf("Ai ales optiunea %d\n", alegere);
		incarcare_date(b, nr, fisier_biblioteca);
		switch (alegere) {
		case 1:
			printf("Se incarca datele din fisier...\n");
			printf("Datele au fost incarcate\n");
			afisare_date(b, nr);
			break;
		case 2:
			printf("Se introduc carti noi. Urmariti instructiunile de mai jos.\n");
			adaugare_carte();
			printf("Cartea a fost introdusa\n");
			break;
		case 3:
			printf("Se citeste fisierul...\n");
			sortare_alfabetica(b, nr);
			afisare_date(b, nr);
			break;
		case 4:
			printf("Cartile se sorteaza...\n");
			sortare_pret(b, nr);
			printf("Cartile au fost sortate dupa pret\n");
			break;
		case 5:
			printf("Datele au fost incarcate...\n");
			mai_mic_decat(b, nr);
			break;
		case 6:
			printf("Datele au fost incarcate...\n");
			autori_litera(b, nr);
			break;
		case 7:
			printf("Ati iesit din biblioteca\n");
			break;
		default:
			printf("Ati introdus un numar gresit\n");
			break;
		}
	}
}

int optiuni_meniu() {
	int n;
	printf("Bun venit in Bilbioteca. Alege de mai jos o optiune: \n 1. Incarcare date din fisier. \n 2. Introducere carti noi.\n 3. Ordonare carti in ordine alfabetica, dupa numele autorului. \n 4. Ordonare carti din domeniul tehnic in ordinea crescatoare a pretului. \n 5. Afisare titlu al fiecarei carti si numarul total al cartilor cu un pret mai mic decat o suma indicata de utilizator. \n 6. Afisare titluri ale cartilor scrise de autori ai caror nume incepe cu o litera introdusa de utilizator. \n 7. Iesire din Bilbioteca.\n");
	scanf("%d", &n);
	return n;
}

void incarcare_date(struct BIBLIOTECA * b, int nr_carti, FILE * fisier_biblioteca) {
	int i;
	fscanf(fisier_biblioteca, "%d", &i);
	for (i = 0; i < nr_carti - 1; i++) {
		fscanf(fisier_biblioteca, "%s", b[i].titlu);
		fscanf(fisier_biblioteca, "%s", b[i].nume_autor);
		fscanf(fisier_biblioteca, "%s", b[i].prenume_autor);
		fscanf(fisier_biblioteca, "%s", b[i].domeniu);
		fscanf(fisier_biblioteca, "%f", &b[i].pret);
		fscanf(fisier_biblioteca, "%d", &b[i].nr_pagini);
	}
	fclose(fisier_biblioteca);
}

void afisare_date(struct BIBLIOTECA *b, int nr_carti) {

	int optiune, i;
	char *aux_s;
	printf("Din ce domeniu vrei sa fie afisate cartile? alege 1. pentru domeniu tehnic sau 2. pentru domeniu literar\n");
	scanf("%d", &optiune);
	switch (optiune) {
	case (1):
		printf("Se afiseaza cartile din domeniul tehnic.\n");

		for (i = 0; i < nr_carti - 1; i++) {
			aux_s = strstr(b[i].domeniu, "tehnic");
			if (aux_s != NULL) {
				printf("Titlu: %s \n", b[i].titlu);
				printf("Nume autor: %s \n", b[i].nume_autor);
				printf("Prenume autor: %s \n", b[i].prenume_autor);
				printf("Pret: %0.2f\n", b[i].pret);
				printf("Pagini: %d\n", b[i].nr_pagini);
				printf("\n");
			}
		}
		break;
	case (2) :
		printf("Se afiseaza cartile din domeniul literar.\n");

		for (i = 0; i < nr_carti - 1; i++) {
			aux_s = strstr(b[i].domeniu, "literar");
			if (aux_s != NULL) {
				printf("Titlu: %s \n", b[i].titlu);
				printf("Nume autor: %s \n", b[i].nume_autor);
				printf("Prenume autor: %s \n", b[i].prenume_autor);
				printf("Pret: %f\n", b[i].pret);
				printf("Pagini: %d\n", b[i].nr_pagini);
				printf("\n");
			}
		}
		break;
	}
}

void adaugare_carte() {
	FILE *fisier_biblioteca;
	struct BIBLIOTECA carte_noua;
	fisier_biblioteca = fopen("carti.txt", "r+");
	if (!fisier_biblioteca) {
		printf("Nu exista fisierul.\n");
	} else {
		int n;
		fscanf(fisier_biblioteca, "%d", &n);
		n++;
		fseek(fisier_biblioteca, 0, SEEK_SET);
		fprintf(fisier_biblioteca, "%d\n", n);
		fseek(fisier_biblioteca, 0, SEEK_END);
		printf("Introducere date carte noua: \n");
		printf("Titlu: ");
		scanf("%s", &carte_noua.titlu);
		fprintf(fisier_biblioteca, "%s\n", carte_noua.titlu);
		printf("Numele autorului: ");
		scanf("%s", &carte_noua.nume_autor);
		fprintf(fisier_biblioteca, "%s\n", carte_noua.nume_autor);
		printf("Prenumele autorului: ");
		scanf("%s", &carte_noua.prenume_autor);
		fprintf(fisier_biblioteca, "%s\n", carte_noua.prenume_autor);
		printf("Domeniu (literar/tehnic): ");
		scanf("%s", &carte_noua.domeniu);
		fprintf(fisier_biblioteca, "%s\n", carte_noua.domeniu);
		printf("Pret: ");
		scanf("%f", &carte_noua.pret);
		fprintf(fisier_biblioteca, "%0.2f\n", carte_noua.pret);
		printf("Nr pagini: ");
		scanf("%d", &carte_noua.nr_pagini);
		fprintf(fisier_biblioteca, "%d\n", carte_noua.nr_pagini);
		fclose(fisier_biblioteca);
	}
}

void sortare_alfabetica(struct BIBLIOTECA * b, int nr_carti) {
	int gasit;
	gasit = 0;
	int i;
	do {
		gasit = 0;
		for (i = 0; i < nr_carti - 1; i++) {
			if (strcmp(b[i].nume_autor, b[i + 1].nume_autor) > 0) {
				gasit = 1;
				struct BIBLIOTECA aux = b[i];
				b[i] = b[i + 1];
				b[i + 1] = aux;
			}
		}
	} while (gasit);
}

void sortare_pret(struct BIBLIOTECA * b, int nr_carti) {
	int gasit;
	gasit = 0;
	char *aux_s;
	int i;
	do {
		gasit = 0;
		for (i = 0; i < nr_carti - 1; i++) {
			if (b[i].pret > b[i + 1].pret) {
				gasit = 1;
				struct BIBLIOTECA aux = b[i];
				b[i] = b[i + 1];
				b[i + 1] = aux;
			}
		}
	} while (gasit);

	for (i = 0; i < nr_carti - 1; i++) {
		aux_s = strstr(b[i].domeniu, "tehnic");
		if (aux_s != NULL) {
			printf("Titlu: %s \n", b[i].titlu);
			printf("Nume autor: %s \n", b[i].nume_autor);
			printf("Prenume autor: %s \n", b[i].prenume_autor);
			printf("Domeniul:%s\n", b[i].domeniu);
			printf("Pret: %f\n", b[i].pret);
			printf("Pagini: %d\n", b[i].nr_pagini);
			printf("\n");
		}
	}
	printf("\n");
}

void mai_mic_decat(struct BIBLIOTECA *b, int nr_carti) {
	float n;
	int i, total;
	total = 0;
	printf("Introdu un pret de comparatie: \n");
	scanf("%f", &n);
	for (i = 0; i < nr_carti - 1; i++) {
		if (b[i].pret < n) {
			printf("%s\n", b[i].titlu);
			total++;
		}
	}
	printf("Totalul cartilor cu pret mai mic decat %0.2f este %d \n", n, total);
}

void autori_litera(struct BIBLIOTECA *b, int nr_carti) {
	char litera;
	printf("Introdu o litera dupa care doresti filtrarea: \n");
	scanf("%s", &litera);
	int i;
	for (i = 0; i < nr_carti; i++) {
		if (b[i].nume_autor[0] == toupper(litera)) {
			printf("%s\n", b[i].titlu);
		}
	}
}