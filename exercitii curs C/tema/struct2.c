/*Scrieti o aplicatie care faciliteaza gestiunea unui lot de automobile. 
Pentru fiecare automobil se vor retine informatiile:  
- nr. de locuri, 
- puterea (in cai putere),
- producator,
- culoare, 
- an fabricatie.
Aplicatia trebuie sa permita:
- introducerea informatiilor pentru n autoturisme,
- afisarea autoturismelor introduse,
- afisarea automobilelor care au 5 locuri,
- afisarea automobilelor ordonate dupa putere,
- afisarea automobilelor fabricate intr-un anumit an, ales de catre utilizator.
Rezolvati fiecare dintre cerintele anterioare utilizand functii definite de utilizator.
Apelati corespunzator functiile create din main().

Pentru a exersa, alocati dinamic spatiul necesar celor n masini (functia malloc din stdlib.h)
Folositi functia free atunci cand nu mai este necesar array-ul de n masini.

De asemenea, pentru a exersa, rezolvati cerintele o data folosind pe cat posibil operatorul de indexare - [] 
si apoi folosind pointeri (si aritmetica pointerilor - ex: a[i] scris ca *(a+i) ).  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AUTOMOBIL {
	int nr_locuri;
	int putere;
	char producator[30];
	char culoare[10];
	int an_fabricatie;
};

void auto_5locuri(struct AUTOMOBIL* automobil, int n);
void auto_sortare_putere(struct AUTOMOBIL* automobil, int n);
void auto_an(struct AUTOMOBIL* automobil, int n, int an);


void main() {

	int n, an;
	printf("Cate automobile se introduc? ");
	scanf("%d", &n);
	struct AUTOMOBIL *automobil = malloc(n * sizeof(struct AUTOMOBIL));

	int i = 0;

	for (i = 0; i < n; i++) {
		printf("\ndatele automobilului: %d\n", i+1);
		printf("numar locuri: "); 
		scanf("%d", &automobil[i].nr_locuri);
		printf("putere (cai putere): "); 
		scanf("%d", &automobil[i].putere);
		printf("producator: "); 
		scanf("%s", (automobil+i)->producator);
		printf("culoare: "); 
		scanf("%s", (automobil+i)->culoare);
		printf("an de fabricatie: "); 
		scanf("%d", &automobil[i].an_fabricatie);
	}

	for (i = 0; i < n; i++) {
		printf("\ndatele automobilului: %d\n", i+1);
		printf("numar locuri: %d\t", automobil[i].nr_locuri);
		printf("putere (cai putere): %d\t", automobil[i].putere);
		printf("producator: %s\t", (automobil+i)->producator);
		printf("culoare: %s\t", (automobil+i)->culoare);
		printf("an de fabricatie: %d\n", automobil[i].an_fabricatie);
		}

	printf("Automobilele cu 5 locuri sunt: \n");
	auto_5locuri(automobil, n);

	printf("Automobilele sortate dupa putere sunt: \n");
	auto_sortare_putere(automobil, n);

	printf("Introduceti un an format din patru cifre: ");
	scanf("%d", &an);

	printf("Automobilele fabricate in sau dupa anul introdus: \n");
	auto_an(automobil, n, an);

	free(automobil);
}

void auto_5locuri(struct AUTOMOBIL *automobil, int n){
	int i;
	for(i = 0; i < n; i++) {
		if (automobil[i].nr_locuri == 5) {
			printf("producator: %s\n", (automobil+i)->producator);
		}
	 }
}


void auto_sortare_putere(struct AUTOMOBIL* automobil, int n){
	int i;
	struct AUTOMOBIL aux;
	
	int gasit = 0;
	do{
		gasit = 0;
		for(i = 0; i < n-1; i++)
			if (automobil[i].putere < automobil[i+1].putere){
				aux = *(automobil + i);
				*(automobil + i) = * (automobil + i + 1);
				*(automobil + i + 1) = aux;
				gasit = 1;
			}
	}while (gasit);	


	for (i = 0; i < n; i++) {
 		printf("producator: %s\t", (automobil + i) ->producator);
	}
 	printf("\n");
}


void auto_an(struct AUTOMOBIL* automobil, int n, int an){ 
	int i;
	
	for(i = 0; i < n; i++) {
		if (automobil[i].an_fabricatie >= an) {
			printf("producator: %s\n", (automobil + i) ->producator);
		}
	}
}
