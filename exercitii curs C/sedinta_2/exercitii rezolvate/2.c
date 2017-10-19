#include <stdio.h>

int main()
{
    int a, b, c;
    printf("introduceti trei numere:");
    scanf("%d %d %d", &a, &b, &c);

    if(a>b)
        if (a>c)
            printf("numarul %d este maximul", a);
        else
            printf("numarul %d este maximul", c);
    else if(b>c)
        printf("numarul %d este maximul", b);
    else
        printf("numarul %d este maximul", c);
}
