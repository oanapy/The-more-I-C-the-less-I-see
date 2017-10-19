#include <stdio.h>

int main()
{
    int a, b;
    printf("introduceti doua numere:");
    scanf("%d %d", &a, &b);

    if(a==b)
        printf("numerele sunt egale");
    else if(a>b)
        printf("numarul %d este mai mare", a);
    else
        printf("numarul %d este mai mare", b);

}
