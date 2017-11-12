/*
2. Realizați un program care prelucrează un array de
numere reale astfel:
- Se apelează o funcție pentru a introduce numărul de elemente și o
funcție pentru a introduce elementele vectorului;
- O funcție afișează elementele vectorului;
- O funcție selectează cele mai mari 5 numere;
- O funcție sortează crescător elementele vectorului;
- Apelați corespunzător funcțiile create din funcția main.
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


void main(){
	int nr_el, *arr, *max;

	arr = malloc(nr_el * sizeof(int));

	nr_el = nr_elem();
	arr = ce_elemente(arr, nr_el);
	afisare_elemente(arr, nr_el);

	if (nr_el >= 5) {
		max = malloc(5 * sizeof(int));
	} else {
		max = malloc(nr_el * sizeof(int));
	}
	max = max5(arr, nr_el, max);

	if(nr_el >= 5){	
		printf("cele mai mari 5 elemente: \n");
		afisare_elemente(max, 5);
	}
	else{
		printf("cele mai mari %d elemente: \n", nr_el);
		afisare_elemente(max, nr_el);
	}

//sortarea crescatoare a elementelor vectorului	
	sortare_cresc(arr, nr_el);
	printf("elementele sortate crescator: \n");
	afisare_elemente(arr, nr_el);

	//dealocarea spatiului rezervat pentru vectorul a
	free(max);
	free(arr);

}

