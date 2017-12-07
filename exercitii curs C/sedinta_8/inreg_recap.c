/*Se dă fișierul inregistrari.txt. Fisierul are pe primul rand
un număr întreg n care definește numărul de cursanți
înscriși la curs. Pe baza acestui fișier:
a. Se definește o structură de date cu numele cursant
corespunzătoare datelor conținute în fișier.
b. Creați o funcție pentru salvarea datelor din fișier într-un
array cu n elemente de tipul structurii definite anterior.
c. Creați o funcție pentru afișarea datelor din array-ul de
structuri.
d. Creați o funcție care permite afișarea datelor cursanților
în ordine alfabetică după nume.
e. Creați o funcție care, pe baza informațiilor din CNP
extrage data nașterii.
f. Creați o funcție care scrie într-un fișier numit
procesate.txt datele din array-ul de structuri, adăugând
data nașterii, media celor două note și textul ADMIS/
RESPINS comparând media cu 5.
gCreați o funcție care permite adăugarea unui cursant la
sfârșitul fișierului inregistrari.txt. (!trebuie modificat si
numarul de cursanti scris pe prima linie)
h. Creați o funcție care permite calcularea vârstei unui
cursant pe baza informațiilor din CNP.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define DEBUG

//definire structura
struct CURSANT {
	char nume[15];
	char prenume[15];
	char CNP[14];
	char email[20];
	int n1, n2;
};

void citire_cursanti(struct CURSANT *c, int nr, FILE * file);
void afisare_cursanti(struct CURSANT *c, int nr);
void sortare_alfabetica(struct CURSANT *c, int nr);
void data_nasterii(char * CNP, char * data);
void procesate(struct CURSANT *c, int nr);
void adaugare_student();
int calcul_varsta(struct CURSANT c);


void main() {
	int nr;
	nr = 0;
	FILE *file = fopen("inregistrari.txt", "r");
	int i;
	if (!file) {
		printf("Nu s-a putut deschide fisierul inregistari \n");
	}
	else {

		fscanf(file, "%d", &nr); //citire nr cursanti
#ifdef DEBUG
		printf("nr de cursanti este %d\n", nr);
#endif
		struct CURSANT *c = malloc(nr * sizeof(struct CURSANT));
		citire_cursanti(c, nr, file);
		afisare_cursanti(c, nr);
		printf("Persoanele sortate in ordine alfabetica dupa nume sunt: \n");
		sortare_alfabetica(c, nr);
		afisare_cursanti(c, nr);

		char data[nr][11];
		for ( i = 0; i < nr ; i++) {
			data_nasterii(c[i].CNP, data[i]);
		}
		for (i = 0; i < nr; i++) {
			printf("Cursantul %d: nume %s, data nasterii %s\n", i + 1, c[i].nume, data[i]);
		}
		procesate(c, nr);
		//adaugare_student();
		printf("\n\nVarsta fiecarui cursant: \n");
		for (i = 0; i < nr; i++) {
			printf("%s %s: %d ani\n", c[i].nume,c[i].prenume, calcul_varsta(c[i]));
		}
	}

}

void citire_cursanti(struct CURSANT * c, int nr, FILE * file) {
	int i;

	fscanf(file, "%d", &i);//sa mute cursorul dupa nr de elemente din fisier
	for ( i = 0; i < nr; i++) {
		fscanf(file, "%s", c[i].nume);
		fscanf(file, "%s", c[i].prenume);
		fscanf(file, "%s", c[i].CNP);
		fscanf(file, "%s", c[i].email);
		fscanf(file, "%d", &c[i].n1);
		fscanf(file, "%d", &c[i].n2);
	}
	fclose(file);
}

void afisare_cursanti(struct CURSANT * c, int nr) {
	int i;
	for ( i = 0; i < nr; i++) {
		printf("numele studentului %d este %s \n", i + 1, c[i].nume);
		printf("prenumele este %s \n", c[i].prenume);
		printf("CNP este %s\n", c[i].CNP);
		printf("email este %s\n", c[i].email);
		printf("nota 1 este %d\n", c[i].n1);
		printf("nota 2 este %d\n", c[i].n2);
		printf("\n");
	}
}

void sortare_alfabetica(struct CURSANT * c, int nr) {

	int gasit;
	gasit = 0;
	int i;
	do {
		gasit = 0;
		for (i = 0; i < nr - 1; i++) {
			if (strcmp(c[i].nume, c[i + 1].nume) > 0) {
				gasit = 1;
				struct CURSANT aux = c[i];
				c[i] = c[i + 1];
				c[i + 1] = aux;

			}
		}
	} while (gasit);
}

void data_nasterii(char * CNP, char * data) {
	char an[5], an_p[3], zi[3], luna[3];
	strncpy(an_p, CNP + 1, 2);
	an_p[2] = '\0';
	if ((CNP[0] == '1') || (CNP[0] == '2')) {
		strcpy(an, "19");
		strcat(an, an_p);
	} else {
		strcpy(an, "20");
		strcpy(an, an_p);
	}
	strncpy(zi, CNP + 5, 2);
	zi[2] = '\0';
	strncpy(luna, CNP + 3, 2);
	luna[2] = '\0';
	strcpy(data, zi);
	strcat(data, "/");
	strcat(data, luna);
	strcat(data, "/");
	strcat(data, an);
	data[10] = '\0';
}

void procesate(struct CURSANT *c, int nr) {

	FILE *file_out = fopen("procesate.txt", "w");

	char data[nr][11];

	if (!file_out) {
		printf("Nu s-a putut deschide fisierul inregistari \n");
	}
	else {
		int i;
		for (i = 0; i < nr; i++) {
			fprintf(file_out, "%s\n", c[i].nume);
			fprintf(file_out, "%s\n", c[i].prenume);
			fprintf(file_out, "%s\n", c[i].CNP);
			fprintf(file_out, "%s\n", c[i].email);
			data_nasterii(c[i].CNP, data[i]);
			fprintf(file_out, "%s\n", data[i]);
			float medie = (c[i].n1 + c[i].n2) / 2;
			fprintf(file_out, "%f\n", medie);
			fprintf(file_out, "%s\n", medie >= 5 ? "ADMIS" : "RESPINS");
		}
		fclose(file_out);
	}
}


void adaugare_student() {
	FILE *f_out;
	struct CURSANT c_nou;
	f_out = fopen("inregistrari.txt", "r+");
	if (f_out) {
		int n;
		fscanf(f_out, "%d", &n);
		n++;
		fseek(f_out, 0, SEEK_SET);
		fprintf(f_out, "%d\n", n);
		fseek(f_out, 0, SEEK_END);
		printf("Introducere date cursant nou: \n");
		printf("Nume: ");
		scanf("%s", &c_nou.nume);
		fprintf(f_out, "%s\n", c_nou.nume);
		printf("Prenume: ");
		scanf("%s", &c_nou.prenume);
		fprintf(f_out, "%s\n", c_nou.prenume);
		printf("CNP: ");
		scanf("%s", &c_nou.CNP);
		fprintf(f_out, "%s\n", c_nou.CNP);
		printf("Email: ");
		scanf("%s", &c_nou.email);
		fprintf(f_out, "%s\n", c_nou.email);
		printf("Nota 1: ");
		scanf("%d", &c_nou.n1);
		fprintf(f_out, "%d\n", c_nou.n1);
		printf("Nota 2: ");
		scanf("%d", &c_nou.n2);
		fprintf(f_out, "%d\n", c_nou.n2);
		fclose(f_out);
	}
}

int calcul_varsta(struct CURSANT c) {
	char an[3];
	strncpy(an, c.CNP + 1, 2);
	an[2] = '\0';

	int an_n = atoi(an);
	if (an_n <= 17)
		an_n += 100;
// #ifdef DEBUG
// 	printf("an nastere: %s\n", an);
// 	printf("an nastere: %d\n", an_n);
// #endif // DEBUG

	int an_curent;
	time_t timp = time(NULL);
	struct tm tm = *localtime(&timp);
	an_curent = tm.tm_year;

// #ifdef DEBUG
// 	printf("an curent: %d\n", an_curent);
// #endif // DEBUG

	int varsta = an_curent - an_n;
	return varsta;
}