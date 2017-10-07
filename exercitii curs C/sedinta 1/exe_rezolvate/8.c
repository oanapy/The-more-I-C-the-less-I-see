#include <stdio.h>

int main(){
    //declaratie doua variabile numere intregi
    int a, b;
    //declaratie doua variabile numere cu zecimale
    float c, d;

    //introducerea numerelor de la tastatura
    printf("introduceti un numar intreg: "); //afisare mesaj astfel incat utilizatorul sa stie ce trebuie sa introduca de la tastatura
    scanf("%d", &a);
    printf("introduceti inca un numar intreg: ");
    scanf("%d", &b);
    printf("introduceti doua numere reale: ");
    scanf("%f %f", &c, &d); //functia scanf poate fi citita pentru a citi valori in mai multe variabile la un singur apel al functiei

    //afisarea celor 4 numere pe cate un rand
    printf("numerele sunt:\n a=%d\n b=%d\n c=%f\n d=%f\n", a, b, c, d);

    //afisare cele doua numere intregi pe un rand, cele doua numere cu zecimale doua randuri mai jos
    printf("numerele intregi: a=%d, b=%d\n\nnumerele reale: c=%f, d=%f\n", a, b, c, d);

    int suma, dif, produs, rest;
    //calcul valori cerute de cerinta
    suma=a+b+c+d;
    dif=a-b;
    rest=a%b;

    //afisare rezultate
    printf("suma numerelor: %d\n", suma);
    printf("diferenta numerelor intregi: %d\n", dif);
    printf("restul impartirii numerelor intregi: %d\n", rest);
}
