#include <stdio.h>

int main(){
	int nr_programe, pret_program;
	int salariu = 5000;
	printf("Introdu numarul de programe: \n");
	scanf("%i", &nr_programe);
	printf("Introdu pretul total al programului: \n");
	scanf("%i", &pret_program);
	if(salariu < (2000 + 500 * nr_programe)){
		printf("Baga-te la schema 2! \n");
	}
	else if(salariu < (500 * nr_programe + 10/100 * pret_program)){
		printf("Baga-te la schema 3! \n");
	}
	else {
		printf("Ramai la schema 1! \n");
	}
	return 0;
}