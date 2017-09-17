/*Print all the numbers divisible by 3 and less than the input number*/

#include <stdio.h>

int main(){

	int nr, i;
	printf("Introdu un numar: \n");
	scanf("%d", &nr);
	printf("Numerele divizbile cu 3 mai mici decat %d sunt: ", nr);
	for (i = 0; 3 * i <= nr; i ++)
	{
		printf(" %d", 3 * i);
	}
	printf("\n");
	return 0;
}