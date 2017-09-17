/*Print a full triangle with *, depending on the input*/

#include <stdio.h>

int main()
{
	int L, i, j, k;

 	printf("Introdu L: \n");

 	scanf("%d", &L);

 	for (i = L; i > 0; i--)
 		{
 			for (j = 1; j < i + 1; j++)
 			{
 				printf(" ");
 						
 			}
 			
 			for (k = i; k <= L; k++)
 			{
 				printf("* ");
 						
 			}
 		printf("\n");

 		} 
 	return 0;
 }