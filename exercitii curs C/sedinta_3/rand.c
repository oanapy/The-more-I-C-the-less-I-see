/*Scrieți un program care generează un număr aleator
cuprins între 0 și 100 și apoi îi cere utilizatorului să
introducă numere până când ghicește numărul generat.
La fiecare greșeală, utilizatorul este informat dacă trebuie
să introducă un număr mai mare sau mai mic pentru a
ghici.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	srand(time(NULL)); //initializarea seedului pentru algoritmul de generare de numere aleatoare cu time(NULL) - timpul curent
	int nr;
	nr = 0;
	int n = rand()%101; //generarea unui numar aleator cuprins intre 0 si 100

	/*
	generarea unui numar aleator cuprins intre x si y
	nr = rand%(y-x) + x;
	*/

	do {

		printf("Introdu un numar:\n");
		scanf("%d", &nr);
		if (nr < n) {
			printf("Introdu un numar mai mic decat %d!\n", nr);
		}
		else if (nr > n) {
			printf("Introdu un numar mai mare decat %d!\n", nr);
		}

		else {
			printf("Ai ghicit numarul secret!\n");
		}
	} while (nr != n);

	

}