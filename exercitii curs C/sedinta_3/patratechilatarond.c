/*Scrieți un program care afișează un pătrat cu latura n,
construit din simbolul @. n este un număr natural
introdus de la tastatură. Construiți un triunghi echilateral
de latură n, utilizând același simbol. Construiți pătratul,
marcând cu simbolul @ doar laturile acestuia (centrul
este gol).*/

#include <stdio.h>


void main(void){

	int n;
	printf("Introdu lungimea laturii: "); 
	scanf("%d", &n);


	//patrat plin format din @
	int i, j;
	printf("\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			printf("@ ");
		printf("\n");
	}

	//laturile unui patrat desenate cu @
	printf("\n");
	for (i = 1; i <= n; i++){
		for(j = 1; j <= n; j++)
			if ( i == 1 || i == n || j == 1 || j == n)
				printf("@ ");
			else
				printf("  ");
		printf("\n");
	}

	//laturile unui patrat desenate cu @
	printf("\nprin alta metoda:\n");
	for(i = 1; i <= n; i++)
        printf("@ ");
    printf("\n");

	for (i = 1; i <=n-2; i++){
		printf("@ ");
		for(j = 1; j <= n-2; j++)
			printf("  ");
        printf("@\n");
    }
    for(i = 1; i <= n; i++)
        printf("@ ");
    printf("\n");

	//un triunghi echilateral format din @
	printf("\n");
	for (i = 1; i <= n; i++){
		for(j = 1; j <= n; j++)
			if (j <= i)
				printf("@ ");
		printf("\n");
	}
}