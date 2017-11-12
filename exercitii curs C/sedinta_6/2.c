/* Creați un nou proiect. În acesta, salvați programul
anterior cu numele 2.c. Creați un fișier numit 2.h care să
conțină declarațiile funcțiilor definite în 2.c. În alt fișier, 2a.c
implementați funcția main din 2.c (ștergeți-o din 2.c). În
fișierul 2.c trebuie să rămână doar definițiile funcțiilor. Rulați
programul astfel creat.

compilare cu gcc 2.c 2a.c -o 2 

*/

#include <stdio.h>
#include <stdlib.h>

int nr_elem(){
	int nr;
	printf("Cate elemente vrei: \n");
	scanf("%d", &nr);
	return nr;
}

int * ce_elemente(int *arr, int a){
	int i;

	for(i = 0; i < a; i++){
		printf("Introdu elementul din pozitia %d\n", i+1);
		scanf("%d", &arr[i]);
	}
	return arr;
}

void afisare_elemente(int *arr, int a){
	int i;

	for (i = 0; i < a; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

int* max5(int arr[], int a, int max[]){
	int gasit, i, aux;
	gasit = 0;
	do {
		gasit = 0;
		for(i = 0; i < a-1; i++)
			if(arr[i] < arr[i+1]){
				gasit = 1;
				aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
			}
	} while (gasit);

	if (a >= 5) {
		for(i = 0; i < 5; i++) {
			max[i] = arr[i];
		}
	}
	else {
		for(i = 0; i < a; i++) {
			max[i] = arr[i];
		}
	}

	return max;
}

void sortare_cresc(int arr[], int a){

	//sortare crescatoare
	int gasit, i, aux;
	gasit = 0;
	do {
		gasit = 0;
		for(i = 0; i < a-1; i++)
			if(arr[i] > arr[i+1]){
				gasit = 1;
				aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
			}
	}while (gasit);
}	






