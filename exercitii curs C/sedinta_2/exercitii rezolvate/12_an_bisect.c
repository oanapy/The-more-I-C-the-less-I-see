#include <stdio.h>
int main()
{
    int an;
    printf("introduceti un an de verificat: "); scanf("%d", &an);
    if (an%400 == 0)
        printf("anul %d este bisect\n", an);
    else if (an%100 == 0)
        printf("anul %d nu este bisect\n", an);
    else if (an%4 == 0)
        printf("anul %d este bisect\n", an);
    else printf ("anul %d nu este bisect\n", an);
    return 0;
}
