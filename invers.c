/*Scrieți un program care inversează cifrele unui număr intrus de la tastatură 
(e.q. numărul 2345 indrodus de la tastaruă va deveni 5432)*/

#include <stdio.h>

int main(){
	int nr =  0, temp = 0;
	printf("Introdu un numar: \n");
	scanf("%d", &nr);
	do {
		temp = temp * 10 + nr % 10;
		nr /= 10;
	} while (nr > 0);
	printf("Inversul numarului introdus este: %d\n", temp);
	return 0;
}