/*Scrieți un program prin care i se cere utilizatorului să
introducă un număr întreg (în baza 10). Se vor afișa
valorile corespunzătoare in bazele 8 și 16.*/

#include <stdio.h>

void main(){
	int nr;

	printf("Introduceti un numar.\n");
	scanf("%d", &nr);

	printf("numarul %d = %o (in baza 8) si = 0x%x (in baza 16) \n", nr, nr, nr);
}