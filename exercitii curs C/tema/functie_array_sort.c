/*2. Creati cate o functie pentru: citirea elementelor unui array unidimensional, afisarea elementelor array-ului, calcularea sumelor elementelor din array, selectarea elementelor negative, sortarea elementelor. Apelati corespunzator fiecare dintre aceste functii din functia main() pentru doua array-uri de diferite dimensiuni.*/


#include <stdio.h>
#include <stdlib.h>

int * ce_elemente(int *arr, int nr){
	int i;

	for(i = 0; i < nr; i++){
		printf("Introdu elementul din pozitia %d\n", i+1);
		scanf("%d", &arr[i]);
	}
	return arr;
}

void afisare_elemente(int *arr, int nr){
	int i;

	for (i = 0; i < nr; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void suma_elem_array(int *arr, int nr){
	int i, suma;
	suma = 0;

	for (i = 0; i < nr; i++) {
		suma += arr[i];
	}
	printf("Suma elementelor din array este: %d\n", suma);
}

void selectie_nr_negative(int *arr, int nr){
	int i, j, contor, elemente_neg[contor];
	contor = 0;

	for (i = 0; i < nr; i++) {
		if (arr[i] < 0) {
			elemente_neg[contor] = arr[i];
			contor += 1;
		}
	}

	printf("Elementele negative din array sunt: \n");
	for (j = 0; j < contor; j++){
		printf("%d\n", elemente_neg[j]);
	}

	printf("\n");
}


void sortare_cresc (int arr[], int a){

	int gasit, i, aux;
	gasit = 0;
	do {
		gasit = 0;
		for (i = 0; i < a-1; i++)
			if (arr[i] > arr[i+1]){
				gasit = 1;
				aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
			}
	} while (gasit);
}	


void main(){
	//int nr_el, *arr;
	int nr_el1, nr_el2;

	// printf("Cate elemente vrei: \n");
	// scanf("%d", &nr_el);


	// arr = malloc(nr_el * sizeof(int));
	// arr = ce_elemente(arr, nr_el);

	int arr1[5] = {2, -5, 7, 8, 9};
	nr_el1 = 5;
	int arr2[7] = {2, -5, 7, 8, -9, 12, 45};
	nr_el2 = 7;


	// afisare_elemente(arr, nr_el);
	// suma_elem_array(arr, nr_el);
	// selectie_nr_negative(arr, nr_el);
	// sortare_cresc(arr, nr_el);
	// printf("Elementele sortate crescator: \n");
	// afisare_elemente(arr, nr_el);
	// 
	printf("Pentru primul array -> \n");

	printf("Elementele din array sunt:\n");

	afisare_elemente(arr1, nr_el1);
	suma_elem_array(arr1, nr_el1);
	selectie_nr_negative(arr1, nr_el1);
	sortare_cresc(arr1, nr_el1);
	printf("Elementele sortate crescator: \n");
	afisare_elemente(arr1, nr_el1);

	printf("\n");

	printf("Pentru al doilea array->  \n");

	printf("Elementele din array sunt:\n");

	afisare_elemente(arr2, nr_el2);
	suma_elem_array(arr2, nr_el2);
	selectie_nr_negative(arr2, nr_el2);
	sortare_cresc(arr2, nr_el2);
	printf("Elementele sortate crescator: \n");
	afisare_elemente(arr2, nr_el2);

	//free(arr);

}

