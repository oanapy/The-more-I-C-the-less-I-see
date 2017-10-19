#include <stdio.h>

int main(){
    int n;
    printf("introduceti un numar intreg: "); scanf("%d", &n);

    printf("%d in baza 8: %o\n", n, n);
    printf("%d in baza 16: %x\n", n, n);
}
