#include <stdio.h>

int main(void){
    //citirea si afisarea unui numar intreg
    int nr_intreg;
    printf("Introduceti un numar intreg si apoi apasati tasta Enter: ");
    scanf("%d", &nr_intreg);
    printf("Ati introdus numarul: %d", nr_intreg);

    //citirea si afisarea unui numar real
    float nr_real;
    printf("\n");
    printf("Introduceti un numar real: ");
    scanf("%f", &nr_real);
    printf("Ati introdus numarul: %f", nr_real);

    //citirea si afisarea unui caracter
    char caracter;
    printf("\nIntroduceti un caracter: ");
    scanf(" %c", &caracter);
    printf("Ati introdus caracterul: %c", caracter);
    printf("\n");
    getchar();

}
