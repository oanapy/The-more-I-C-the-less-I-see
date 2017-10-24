/*Scrieți un program care afișează codurile ascii ale literelor
cuprinse între 'a' și 'h‘*/

#include <stdio.h>

void main(){
	int i;
	for (i = 97; i <= 104; i++) {
		printf("Codul ascii al literei %c este %d \n", i, i);
	}
}