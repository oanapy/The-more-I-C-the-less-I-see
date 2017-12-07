#include <stdio.h>

int main(void){
    FILE *f;
    f=fopen("7.txt", "r");

    int a, e, i, o, u;
    a=e=i=o=u=0;
    char c;
    if (f){
        while ( (c=fgetc(f)) != EOF){
            switch (c){
                case 'a': a++; break;
                case 'e': e++; break;
                case 'i': i++; break;
                case 'o': o++; break;
                case 'u': u++; break;
            }
        }
        printf("aparitiile vocalelor: a: %d, e: %d, i: %d, o: %d, u: %d\n", a, e, i, o , u);
    }
     else printf("fisierul nu a putut fi deschis\n");

}
