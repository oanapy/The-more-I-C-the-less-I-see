/*cum vă rugăm să afișati pe ecran nu triunghi echilateral „plin” format cu ajutorul caracterului *. Lungimea laturii triunghiului va fi introdusă de la tastatură.*/
#include <stdio.h>

int main()
{
	int L =  0, i, j;

 	printf("Introdu L: \n");

 	scanf("%d", &L);

 	for (i = 1; i <= L; i ++)
 		{
 			for (j = i; j < L; j++)
 			{
 				printf(" ");
 						
 			}
 			for (j = 1; j <= (2 * i -1) ; j++)
 			{
 				printf("*");
 						
 			}
 		printf("\n");

 		}
 	return 0;
 }
