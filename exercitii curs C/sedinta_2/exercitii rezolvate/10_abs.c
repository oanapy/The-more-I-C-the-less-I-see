#include <stdio.h>
int main()
{
    int nr;
    printf("introduceti un numar: "); scanf("%d", &nr);
    if (nr<0)
        nr=-nr;
    printf("valoarea absoluta este: %d\n", nr);
    return 0;
}
