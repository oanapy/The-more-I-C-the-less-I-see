#include <stdio.h>

int main(void){
	int n;
	printf("introduceti un numar intreg: "); scanf("%d", &n);

	FILE *f;
	f=fopen("1.txt", "r");
	if (f){
		//pozitionare la sfarsitul fisierului
		fseek(f, 0, SEEK_END); //fseek(f, 0, 2);

		//determinarea dimensiunii fisierului prin aflarea numarului octetului curent
		int file_size=-1;
		file_size = ftell(f);
		printf("dimensiunea fisierului este %d\n", file_size);


		char line[100];
		if (n<=file_size){
			fseek(f, n, SEEK_SET); //fseek(f, n, SEEK_SET);
	       		while( fgets( line, 100, f) )
                    printf("%s", line);
		}
		fclose(f);
		else printf("numarul introdus e mai mare ca dimensiunea fisierului\n");
	}
	else printf("nu se poate citi fisierul\n");

}
