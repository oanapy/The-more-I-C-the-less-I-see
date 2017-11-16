/*
1. Scrieti o functie care calculeaza numarul de cifre ale unui numar intreg dat ca parametru. Apelati corespunzator functia creata din functia main() pentru cateva numere.*/


#include <stdio.h>


int cate_cifre(long long int numar);

void main () {
	printf ("Numar de cifre %li \n", cate_cifre(344353));
	printf ("Numar de cifre %li \n", cate_cifre(0));
	printf ("Numar de cifre %li \n", cate_cifre(53736273682768726));

}

int cate_cifre(long long int numar){
	int cifre;
	cifre = 0;

	if (numar == 0) {
		cifre = 0;
	}
	
	do {
		numar /= 10;
		cifre += 1;
	} while (numar > 0); 

	return cifre;

}