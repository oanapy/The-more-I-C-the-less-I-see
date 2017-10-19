#include <stdio.h>

int main(){

    int a, b, c;
    printf("parametrul a: "); scanf("%d", &a);
    printf("parametrul b: "); scanf("%d", &b);
    printf("parametrul c: "); scanf("%d", &c);

    printf("se va rezolva ecuatia: <%d>x^2 + <%d>x + <%d>\n", a, b, c);
    if(a==0)
        if(b!=0)
            printf("ecuatie de gradul I. soluatia este %f", (float)(-c)/b);
        else
            printf("nu ati introdus parametrii unei ecuatii\n");
    else{
        float delta = b*b - 4*a*c;
        float x1, x2;
        if (delta>0){
            x1 = (-b + sqrt(delta))/(2*a);
            x2 = (-b - sqrt(delta))/(2*a);
            printf("x1 = %f\nx2 = %f\n", x1, x2);
        }
        else if (delta == 0){
            x1= -b/(2.0*a);
            printf("x1 = x2 = %f\n", x1);
        }
        else printf("ecuatia are solutii numere complexe");
    }
}
