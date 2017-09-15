/*Adaptați programul de mai sus pentru a afișa un dreptunghi gol.*/

#include <stdio.h>

int main(){
	int L =  0, l = 0, i, j;
	printf("Introdu L: \n");
	scanf("%d", &L);
	printf("Introdu l: \n");
	scanf("%d", &l);
	for (i = 0; i < l; i ++)
		{
			for (j = 0; j <= L; j++)
			{
				
				if (i == 0 || i == (l - 1)){
					printf("*");
				} 
				else if (j == 0 || j == L){
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
	return 0;
}