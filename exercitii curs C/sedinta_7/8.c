#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *f;
    char * nume="7_binar.bin";
    fopen(nume, "wb");

    srand(time(NULL));

    int n=0;
    printf("numarul de elemente de salvat in fisier: ");
    scanf("%d", &n);
    int nr=0;

    while (n){
        n--;
        nr=rand();
        fwrite(&nr, sizeof(int), 1, f);
    }

    fclose(f);
}
