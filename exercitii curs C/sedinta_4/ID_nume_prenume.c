/*nume si prenume de la tastatura. creeaza ID cu primele 3 caractere din nume si primele 5 caractere din prenume



-----CEVA E GRESIT CA NU ORINTEAZA CUM TREBUIE!!!!!------


*/



#include <stdio.h>
#include <string.h>

void main(){
	char nume[256], prenume[256];

	printf("Introdu numele de familie: \n");
	scanf("%s", &nume);
	printf("Introdu prenumele: \n");
	scanf("%s", &prenume);
	puts("Numele este ");
	puts(nume);
	puts("Prenumele este ");
	puts(prenume);

	char ID[8];
	char destnume[3];
	char destprenume[5];

	strncpy(destnume, nume, 3);
	puts(destnume);
	strncpy(destprenume, prenume, 5);
	puts(destprenume);

	strcat(ID, destnume);
	puts(ID);

	strcat(ID, destprenume);
	puts(ID);


	puts("Idul format este: ");
	puts(ID);


}