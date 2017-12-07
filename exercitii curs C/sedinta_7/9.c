#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f_in, *f_out;
    f_in=fopen("9.txt", "r");
    f_out = fopen("9copie.txt", "w");

    int n;
    if (f_in != NULL)
        fscanf(f_in, "%d", &n);
    else{
        printf("nu s-a putut deschide fisierul de citire\n");
        return 0;
    }
    int *v;
    v=malloc(n*sizeof(int));

    if ((f_in != NULL) && (f_out !=NULL)){
        int i=0;
        for (i=0; i<n; i++){
            fscanf(f_in, "%d", &v[i]);
        }

        for (i=0; i<n; i++){
            if (v[i]%2 == 0)
		if (v[i]<0)
            fprintf(f_out, "%d\t", 0);
		else
     		    fprintf(f_out, "%d\t", v[i]*2);
            else if (v[i]<0)
                fprintf(f_out, "%d\t", 0);
            else
                fprintf(f_out, "%d\t", v[i]);
        }
        fclose(f_in);
        fclose(f_out);
    }
    else printf("nu s-a deschis un fisier\n");
    free(v);
}
