/*Print a full rectangle with * depending on the input*/

#include <stdio.h>

int main(){
	int L =  0, l = 0, i, j;
	printf("Introdu L: \n");
	scanf("%d", &L);
	printf("Introdu l: \n");
	scanf("%d", &l);
	//the first for loop will print the horizontal lines, one by one, 
	//until the desired length l (latimea) is reached
	for (i = 0; i < l; i ++)
		{
			//the second for loop will print an horizontal character, one by one, 
			//depending on the desired L (lungimea) 
			for (j = 0; j <= L; j++)
			{
				printf("*");
			}
			//it prints newline and you can go further in length l (latime)
			printf("\n");
		}
	return 0;
}