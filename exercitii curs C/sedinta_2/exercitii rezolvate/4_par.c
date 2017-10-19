#include <stdio.h>

int main(){
    int a;
    printf("introduceti numarul de verificat: ");
    scanf("%d", &a);
    if(a%10 == 0)
        printf("numarul este par");
    else printf("numarul este impar");
}
