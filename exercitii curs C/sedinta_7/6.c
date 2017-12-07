#include <stdio.h>

int main(void){

    FILE *f;
    f=fopen("6.txt", "r");
    int x, suma = 0;
    printf("numerele din fisier: \n");
    if (f){
        do {
            fscanf(f, "%d", &x);
            suma+=x;
            printf("%d\t", x);
        }while(!feof(f));
        printf("suma numerelor este: %d\n", suma);
        printf("\n");
    }
    else printf("\n fisierul nu a putut fi deschis\n");
}
