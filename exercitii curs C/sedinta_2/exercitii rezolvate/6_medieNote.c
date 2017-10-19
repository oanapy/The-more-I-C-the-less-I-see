#include <stdio.h>

int main(){
    int n_partial, n_seminar, n_examen;

    //citire note
    printf("nota partial: "); scanf("%d", &n_partial);
    printf("nota seminar: "); scanf("%d", &n_seminar);
    printf("nota examen: "); scanf("%d", &n_examen);

    float medie = n_partial*0.3 + n_seminar*0.2+ n_examen*0.5;
    printf("media obtinuta: %f\n", medie);
    if (medie >= 5)
        if (n_partial >= 5)
            printf("promovat\n");
        else printf("nota in partial nu este peste 5\n");
    else printf("nota in examen nu este peste 5\n");
}
