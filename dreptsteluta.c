/*Afișati pe ecran nu dreptunghi „plin” format cu ajutorul caracterului *. 
Lungimea și lățimea dreptunghiului vor fi intruduse de la tastatură.*/

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
				printf("*");
			}
			printf("\n");
		}
	return 0;
}