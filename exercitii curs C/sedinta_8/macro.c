/*Realizați un program care definește:
a. un macro – o directivă define cu parametrii pentru a
calcula maximul a două numere.
b. un macro care afișează conținutul unui parametru.
c. într-o funcție o variabilă statică; la fiecare apelare a
funcției, se va incrementa valoarea variabilei statice.
Apelați funcția din main, din interiorul unei instrucțiuni
repetitive, afișând valoarea variabilei statice.*/

#include <stdio.h>

//#define DEBUG

#define MAX(X, Y) X>Y?X:Y
#define PRINT_INT(X) printf("variabila "#X" este %d\n", X);

int var_static(){
	static int x;
}

int var(){
	int x = 0;
	return x++;
}

int main(){
	int a, b;
	a = 4;
	b = 5;
	#ifdef DEBUG
	PRINT_INT(a);
	PRINT_INT(b);
	#endif 
	printf("Maximul este %d\n", MAX(a,b));

	int x, i;

	for (i = 0; i< 10; i++){
		printf("Variabila statica %d\n", var_static());
	}

	for (i = 0; i< 10; i++){
		printf("Variabila non-statica %d\n", var());
	}
}

//output Maximul este 5
// Variabila statica 0
// Variabila statica 1
// Variabila statica 2
// Variabila statica 3                                                                  
// Variabila statica 4                                                                  
// Variabila statica 5                                                                  
// Variabila statica 6
// Variabila statica 7
// Variabila statica 8
// Variabila statica 9
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
// Variabila non-statica 0
