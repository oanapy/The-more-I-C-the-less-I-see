/*Adaptați programul de mai sus pentru a afișa un dreptunghi gol.*/

#include <stdio.h>

int main(){

	int L, l, i, j;
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
			for (j = 0; j < L; j++)
			{
				
				if (i == 0 || i == (l - 1)){
					//prints * if on the first or last row 
					//make it look like the rectangle has an upper and a lower starred margin
					printf("*");
				} 
				else if (j == 0 || j == L){
					//prints * if at the first or last position of a new row 
					//make it look like a real frame
					printf("*");
				}
				else {
					//it prints an empty space everytime the upper conditions are not met
					printf(" ");
				}
			}
			//it prints newline and you can go further in length l (latime)
			printf("\n");
		}
	return 0;
}