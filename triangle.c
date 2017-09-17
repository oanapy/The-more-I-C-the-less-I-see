/*Print a full triangle with *, depending on the input*/

#include <stdio.h>

int main()
{
	int L, i, j;

 	printf("Introdu L: \n");

 	scanf("%d", &L);

 	for (i = 0; i <= L; i ++)
 		{
 			//micsorez segmentul de spatiu gol printat si maresc segmentul de steluta
 			//artificiu la j = 1 sa ajung mai usor la max L --> sa printez elegant mai putine spatii
 			for (j = i; j < L; j++)
 			{
 				printf(" ");
 						
 			}
 			//artifiuciu smart de calcul sa ajunga sa printeze stelele dependent de ceva palpabil, care la noi e i
 			for (j = 0; j < (2 * i - 1) ; j++)
 			{
 				printf("*");
 						
 			}
 		printf("\n");

 		} 
 	return 0;
 }
