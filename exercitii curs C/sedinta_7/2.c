#include <stdio.h>

int main(void){
	FILE *f_in, *f_out;
	char c;

	f_in=fopen("1.txt", "r");
	f_out=fopen("copie.txt", "w");

	if (f_in != NULL && f_out !=NULL ){
		while( 	(c=fgetc(f_in)) != EOF)
			fputc(c, f_out);
		
		fclose(f_in);
		fclose(f_out);
	}
	else printf("\nUnul dintre fisiere nu a putut fi deschis\n");
	
}
