/*Realizați un program care să conțină:
- O funcție care primește drept parametri două numere întregi și
returnează maximul acestora;
- O funcție care primește drept parametri două numere întregi și
returnează suma acestora;
- O funcție care returnează pătratul unui număr primit ca parametru;
- O funcție care primește două numere ca parametri și realizează
interschimbarea celor două numere (hint: parametrii trebuie trimiși
prin referință)
- Apelați corespunzător funcțiile create din funcția main. */

#include<stdio.h>

int max (int nr1, int nr2);
int suma(int nr1, int nr2);
int square(int nr1);
void address(int *nr1, int *nr2);

void main(){
	int nr1, nr2, m, s, sq, addr;

	printf("Primul nr este : ");
	scanf("%d", &nr1);
	printf("Al doilea nr este : ");
	scanf("%d", &nr2);

	m = max(nr1, nr2);
	printf("Maximul este %d\n",m);

	s = suma(nr1, nr2);
	printf("Suma este %d\n",s);

	sq = square(nr1);
	printf("Patratul nr 1 este %d\n",sq);

	
	address(&nr1, &nr2);
	printf("Nr 1 este acum %d, iar nr 2 este %d.\n", nr1, nr2);

}


int max(int nr1, int nr2){
	int max;
	if (nr1 > nr2) {
		max = nr1;
	}
	else {
		max = nr2;
	}
	return max;
}

int suma(int nr1, int nr2){
	int suma;
	suma = nr1 + nr2;
	return suma;
}

int square(int nr1){
	int square;
	square = nr1 * nr1;
	return square;
}

void address(int *nr1 , int *nr2){
	int interm;
	interm = *nr1;
	*nr1 = *nr2;
	*nr2 = interm;
}
