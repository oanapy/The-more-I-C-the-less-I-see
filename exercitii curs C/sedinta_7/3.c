#include <stdio.h>

int main(void){

	FILE *f_in, *f_out;
	char* f_in_name = "1.txt", *f_out_name="3.txt";

	f_in=fopen(f_in_name, "r");
	f_out=fopen(f_out_name, "w");

	char line[100];
	if (f_in && f_out){
		int i=1;
		while (fgets(line, 100, f_in)){
			printf("linia %d: %s", i, line);
			fprintf(f_out, "linia %d: %s\n", i , line);
			i++;
		}
	}
	else printf("\nnu am putut deschide fisierele\n");

}
