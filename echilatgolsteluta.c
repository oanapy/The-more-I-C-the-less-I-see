/*Adaptați programul de mai sus pentru a afișa un triunghi echilateral „gol”.*/
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
 				if(i == L || j == 1 || j == (2*i-1))
            	{
                	printf("*");
            	}
            	else
            	{
                	printf(" ");
            	}	
 						
 			}
 		printf("\n");

 		}
 	return 0;
 }
