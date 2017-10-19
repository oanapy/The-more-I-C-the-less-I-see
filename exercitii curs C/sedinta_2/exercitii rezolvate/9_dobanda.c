#include <stdio.h>
int main()
{
    float depozit=100;
    float dobanda=0.015;
    //dupa 1 an
    depozit+=depozit*dobanda;
    printf("dupa 1 an: %f\n", depozit);
    //dupa 2 ani
    depozit+=depozit*dobanda;
    printf("dupa 2 ani: %f\n", depozit);
    //dupa 3 ani
    depozit+=depozit*dobanda;
    printf("dupa 3 ani: %f\n", depozit);

    return 0;
}
