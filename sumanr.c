/*Scrieți un program care calculează suma cifrelor unui număr introdus de la tastatură*/

#include <stdio.h>
int main(){
	int nr =  0, suma = 0;
	printf("Introdu un numar: \n");
	scanf("%d", &nr);
	do {
		suma += nr%10;
		nr /= 10;
	} while (nr > 0);
	printf("Suma cifrelor numarului introdus este: %d\n", suma);
	return 0;
}