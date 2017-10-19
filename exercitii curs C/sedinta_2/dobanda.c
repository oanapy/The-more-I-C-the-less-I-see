/*Calculați valoarea de bani strânsă într-un cont care
pornește de la suma de 100 RON cu o dobândă anuală
de 1.5%. Calculați și scrieți valoarea strânsă după 1, 2 și
3 ani. (rezultate: 101.5, 103.022, 104.567)*/

#include <stdio.h>

void main(){

	float dobanda, cont, ani;


	dobanda = 1.5/100;
	cont = 100;

	printf("Introdu anii dupa care se doreste calculcul sumei din cont:\n");
	scanf("%f", &ani);

	cont = cont + dobanda * cont * ani;

	printf("Suma finala e: %f\n", cont);






}