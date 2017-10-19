/*Scrieți un program prin care i se cere utilizatorului să
introducă un caracter. Apoi, acesta este informat dacă a
introdus o literă, o cifră sau un caracter special.*/

#include <stdio.h>

void main(){
	char c;
	printf("Introduceti un caracter:\n");
	scanf("%c", &c);

	printf("Ati introdus caracter %c cu cod ASCII %d \n", c, c);

	if (c >= '0' && c <= '9'){
		printf("Ati introdus o cifra.\n");
	} else if (c >= 'a' && c <= 'z' || c >= 'A' && c >= 'Z') {
		printf("Ati introdus o litera\n");
	} else {
		printf("Ati introdus caracter special\n");
	}
}