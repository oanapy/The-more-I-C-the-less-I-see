/*Vă rugăm să afișați pe ecran un triunghi dreptunghic isoscel (un unghi drept si două laturi egale)*/

#include <stdio.h>

int main()
{
	int L =  0, i, j;

 	printf("Introdu L: \n");

 	scanf("%d", &L);

 	for (i = 0; i < L; i ++)
 		{
 			for (j = 0; j < L; j++)
 			{
 				if (i >= j) 
 				{

 				printf("*");
 				}
 				else
 					printf(" ");

 			}
		
 			printf("\n");
 		}
 	return 0;
 }
