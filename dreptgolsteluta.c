/*Adaptați programul de mai sus pentru a afișa un dreptunghi gol.*/

#include <stdio.h>

int main(){

	int L, l, i, j;
	printf("Introdu L: \n");
	scanf("%d", &L);
	printf("Introdu l: \n");
	scanf("%d", &l);
	//primul for va printa liniile orizontale, una cate una, pana se ajunge la latimea dorita
	for (i = 0; i < l; i ++)
		{
			//al doilea for va printa cate un caracter orizontal, unul cate unul, in functie de lungimea dorita
			for (j = 0; j <= L; j++)
			{
				
				if (i == 0 || i == (l - 1)){
					//printeaza * daca ne aflam in primul rand al latimii sau daca ne aflam in ultimul rand al latimii
					//sa arate ca o rama cu margine sus si margine jos
					printf("*");
				} 
				else if (j == 0 || j == L){
					//printeaza * daca te aflii a inceputul unui nou rand din latime sau la sfarsitul unui rand din latime
					//sa inceapa sa arate ca o rama adevarata
					printf("*");
				}
				else {
					//printeaza cate un spatiu gol de cate ori nu ne aflam in conditiile de mai sus
					printf(" ");
				}
			}
			//printeaza newline sa poti trece mai departe la urmatorul rand de latime
			printf("\n");
		}
	return 0;
}