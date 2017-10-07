/*Scrieți un program care citește mai multe numere naturale strict mai mari ca 0 introduse de la tastatură. Citirea se oprește atunci când este introdus numărul 0. Programul stochează numerele într-un array și apoi le afișează în ordine inversă.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int stoc[15];
	int i, r, j, k, auxiliary;
	
	for(i = 0; i < 15; i++){
		printf("Introdu un numar: ");
		scanf(" %d ", &r);
		
		if (r > 0){
			stoc[i] = r;
		}
		else if(r == 0) {
			printf("Ai introdus 0, programul s-a oprit.");
			break;
		}
		
	}
	printf("Numerele din stoc in ordine inversa sunt: ");
	
	for (j = 0; j < 8; j++) {
		auxiliary = stoc[j];
		stoc[j] = stoc[14 - j];
		stoc[14 - j] = auxiliary;
    }

    for (k = 0; k < 100; k++) {
       printf("%d ", stoc[k]);
    }
	
	return 0;
}

