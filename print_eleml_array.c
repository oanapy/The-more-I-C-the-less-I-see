/*Următorul program trebuie să afișeze elementele unui tablou, dar conține o greșeală. Vă rugăm să o identificați și să o corectați.

Varianta corectata mai jos*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
        int i, a[]={1,2,3,4,5};
        for(i = 0; i < 5; i++) {
			printf("%d",a[i]);
		} 
        return 0;
}