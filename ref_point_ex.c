#include <stdio.h>

void main(void) {

	int a = 10; // referinta &a => 0x7ffeb6f31074
	int b = 20; // referinta &b => 0x7ffeb6f3107c
	
	// cream o variabila locala, "temp"
	// adica in user land, care este si
	// va fi o copie decuplata a lui "a" 
	// deci va lua doar valoarea lui "a"
	int temp = a;

	// initializam pointerul ptr
	// ii punem sagetica catre adresa lui "b"
	// l-am legat pe viata de orice va contine "b"
	// acum si in viitor
	int *ptr = &b;
	
	// variabila locala "a" primeste pointerul dereferentiat *ptr
	// adica valoarea la care pointeaza *ptr
	// in cazul nostru, ptr -sagetica-sagetica-> b = 20
	a = *ptr; // a devine 20 in acest punct

	// b este in continuare 20, valoarea originala
	// dar acest lucru trebuie sa se schimbe
	// asa ca 
	// 1. luam adresa (REFERINTA!) catre memory land a lui temp care e de forma 0x7ffeb6f31074
	// 2. facem pe loc dereferinta, caci ne intereseaza doar valoarea, b nefiind pointer
	b = *(&temp); // b = 10 in acest punct

	printf("a: %i\n", a);
	printf("temp: %i\n", temp);
	printf("b: %i\n", b);



	// int a = 10; // a = 10, &a = fx01465468
	// int * ptr = &a;
	// *ptr = 20;
	// printf("%d\n", *ptr);
	// printf("%d\n", a);


	// char f[] = "mama";
 //    char *s = f;

 //    printf("print the bytes %d\n", *s);
 //    printf("print the contents %s\n", s);
 //    printf("hex address %p\n", s);

 //    printf("%s\n", f);

}
