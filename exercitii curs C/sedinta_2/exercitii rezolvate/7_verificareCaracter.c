#include <stdio.h>

int main(){
    char c;
    printf("introduceti un caracter: "); scanf("%c", &c);
    if(c>='0' && c<='9')
        printf("ati introdus o cifra");
    else if(c>='a' && c<='Z')
        printf("ati introdus o litera");
    else printf("ati introdus un caracter special");
}
