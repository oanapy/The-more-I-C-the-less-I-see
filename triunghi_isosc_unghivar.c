#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, j, l, p;
	printf("Introduceti lungimea unei laturi:");
	scanf("%d", &l);
	printf("Alege pozitia unghiului drept: \n 1. stanga jos\n 2. stanga sus\n 3. dreapta jos\n 4. dreapta sus.\n Introdu numarul alegerii: ");
	scanf("%d", &p);
	switch(p) {
		case 1: 
			for(i = 0; i < l; i++) {
				for(j =1; j < i +1; j++){
					printf("* ");
				}
			printf("\n");
			break;
			}
			
		case 2: 
			for(i = l; i > 0; i--) {
				for(j =1; j < i +1; j++){
					printf("* ");
				}
			printf("\n");
			break;
			}
		
		case 3: 
			for(i = l; i <= l; i++) {
				for(j =1; j <= l; j++){
					if (j >= i) {
						printf("* ");
					}
					else {
						printf(" ");
					}
					printf("* ");
				}
			printf("\n");
			break;
			}
			
		case 4: 
			for(i = 1; i <= l; i++) {
				for(j =l; j > 0; j--){
					if (j <= i) {
						printf("* ");
					}
					else {
						printf(" ");
					}
					printf("* ");
				}
			printf("\n");
			break;
			}
		default:
			printf("Nu ati introdus  o optiune valida");
	}

}