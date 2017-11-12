
#include <stdio.h>
#include <stdlib.h>
#include "2.h"


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