/*Scrieți un program care vă cere să vă introduceți inițiala
numelui, o salveză în variabila nume și apoi afișează
mesajul Salut, nume! 
 */

#include <stdio.h>

void main(){
	char nume[2];
	printf("Introdu initiala numelui, apoi apasa Enter: ");
	scanf("%s", &nume);
	printf("Salut, %s!\n", nume);

}