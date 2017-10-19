/*Scrieți un program care acceptă la intrare notele (numere
întregi) unui student pentru o materie: notă parțial
(pondere 30%), notă seminar (pondere 20%) și notă
examen (pondere 50%). Calculați și afișați media
acestora. Pentru a putea fi considerat promovat, trebuie
ca nota obținută în parțial și media notelor să fie mai mari
decât 5. Afișați un mesaj corespunzător pentru a
specifica dacă studentul a promovat sau nu.*/

#include <stdio.h>

void main(){
	float notap, notas, notae, medie;
	printf("Introduceti, in ordine, urmatoarele note: nota partial, nota seminar, nota examen:");
	scanf("%f %f %f", &notap, &notas, &notae);

	medie = 0.3 * notap + 0.2 * notas + 0.5 * notae;
	printf("Media este %f\n", medie);

	if (notap > 5){
		if (medie > 5) {
			printf("Ati promovat!\n");
		}
		else {
			printf("Nu ati promovat!\n");
		}
	}
	else {
		printf("Nu ati promovat!\n");
	}
}