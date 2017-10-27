/*Se da un numar de 8 cifre. Salvati cifrele intr-un vector si afisati:

- numarul compus din cifrele pare ale nr initial
- numarul compus din cifrele impare ale nr initial, inlcouind cu 0 cu pozitiile pe care se afla cifre pare
- cea mai mica cifra a numarului
- cea mai mare cifra a numarului
- numarul initial cu prima cifra interschimbata cu ultima
- numarul cu cifrele ordonate descrescator*/

#include <stdio.h>

 void main(){
 	int x, i;
 	int cifre[8];
 	x = 12345678;

	//citirea cifrelor numarului intr-un vector
	i = 1;
	while (x) {
		cifre [8-i] = x % 10;
		x = x / 10;
		i++;
	}

	//afisarea cifrelor citite
	puts("numarul este compus din cifrele:");
	for(i=0; i<8; i++)
		printf("\t%d", cifre[i]);
	printf("\n");	

	//numarul compus din cifrele pare ale numarului initial
	int cifre_pare=0;
	for (i=0; i<8; i++){
		if (cifre[i]%2==0)
			cifre_pare=cifre_pare*10 + cifre[i];
	}	
	puts("numarul compus din cifrele pare:");
	printf("%d\n", cifre_pare);

	//numarul compus din cifrele impare ale numarului initial, inlocuind cu 0 pozitiile pe care se aflau cifre pare
	int cifre_impare=0;
	for (i=0; i<8; i++)
		if ( cifre[i]%2 )
			cifre_impare=cifre_impare*10+cifre[i];
		else 
			cifre_impare*=10;
	puts("numarul compus din cifrele impare: ");
	printf("%d\n", cifre_impare);

	//cea mai mica cifra a numarului
	int min=cifre[0];
	for (i=1; i<8; i++)
		if(min>cifre[i])
			min=cifre[i];

	//cea mai mare cifra a numarului
	int max=cifre[0];
	for(i=1; i<8; i++)
		if (max<cifre[i])
			max=cifre[i];

	printf("minimul si maximul cifrelor din numar sunt: minimul %d si maximul %d \n", min, max);


	printf("numarul initial cu prima cifra interschimbata cu ultima: ");
	//numarul initial cu prima cifra interschimbata cu ultima
	printf("%d", cifre[7]);
	for (int i=1; i<7; i++)
		printf("%d", cifre[i]);
	printf("%d", cifre[0]);
	printf("\n");

	//numarul cu cifrele ordonate descrescator 
	int swapped=0, aux=0;
	do{
		swapped=0;
		for (i=0; i<7; i++)
			if (cifre[i]<cifre[i+1]){
				swapped=1;
				aux=cifre[i];
				cifre[i]=cifre[i+1];
				cifre[i+1]=aux;
			}
	}while(swapped);
	
	//construirea numarului cu cifrele sortate
	puts("numarul cu cifrele sortate: ");
	for(i=0; i<8; i++){
		printf("%d", cifre[i]);
	}
	printf("\n");
 }