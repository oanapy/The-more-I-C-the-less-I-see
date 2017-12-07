#include <stdio.h>


int main(void){
	char nume_fisier[256], c;
	printf("numele fisierului: ");
	scanf("%s", nume_fisier);

	FILE *fp;
	fp=fopen(nume_fisier, "w");

 	if (fp){
            do{
            c=getchar();
            //fputc(c, fp);
        }while(c !='\\' && fputc (c, fp));
        fclose(fp);
 	}
 	else printf("fisierul nu a putut fi deschis");
}
