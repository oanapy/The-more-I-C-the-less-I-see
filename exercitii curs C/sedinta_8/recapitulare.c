#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define DEBUG

int errno;

struct Cursant
{
    char nume[20];
    char prenume[20];
    char CNP[14];
    char email[25];
    int n1;
    int n2;
};

void citire_cursanti(struct Cursant *cursanti, int n, FILE * f_in);
void afisare_cursanti(struct Cursant *cursanti, int n);
void sortare_nume_alfabetic(struct Cursant *cursanti, int n);
void data_nasterii(char * CNP,  char * data);
void scriere_date_noi(struct Cursant*cursanti, int n);
void adaugare_student();
int calcul_varsta(struct Cursant c);

int main(void)
{
    //pointer catre tipul de date struct Cursant
    struct Cursant *cursanti;

    int n=0;
    FILE * f_in;
    f_in=fopen("inregistrari.txt", "r");


    if (f_in==NULL)
    {
        printf("nu s-a putut deschide fisierul pentru citire\n");
        printf("eroarea este: %s", strerror(errno));
    }
    else
    {
        rewind(f_in);
        fscanf(f_in, "%d", &n);
#ifdef DEBUG
        printf("numarul de cursanti din fisier: %d\n", n);
#endif // DEBUG
        //daca am citit un numar diferit de zero
        if (n)
        {
            cursanti=malloc(n*sizeof(struct Cursant));
            //daca am putut aloca spatiul necesar arrayului de cursanti
            if (cursanti)
            {
                //citire cursanti
                citire_cursanti(cursanti, n, f_in);
                fclose(f_in);
                //afisare cursanti
                afisare_cursanti(cursanti, n);

                sortare_nume_alfabetic(cursanti, n);

                printf("\n\nAfisarea cursantilor in ordine alfabetica\n");
                afisare_cursanti(cursanti, n);

                printf("afisarea datelor de nastere ale cursantilor:\n");
                //declarare array de n elemente de tip char * - pentru memorarea datelor de nastere

                char data[n][11];
                int i;
                for (i=0; i<n; i++){
                    data_nasterii(cursanti[i].CNP, data[i]);
                }
                //afisare nume si data nasterii pentru fiecare cursant
                for(i=0; i<n; i++){
                    printf("Cursantul %d: nume %s, data nasterii %s\n", i+1, cursanti[i].nume, data[i]);
                }

                scriere_date_noi(cursanti, n);

                //adaugare_student();

                printf("\n\nVarsta fiecarui cursant: \n");
                for(i=0; i<n; i++)
                    printf("%s: %d\n", cursanti[i].nume, calcul_varsta(cursanti[i]));
            }
        }
    }
}

void citire_cursanti(struct Cursant *cursanti, int n, FILE * f_in)
{
    int i;
    for(i=0; i<n; i++)
    {
        fscanf(f_in, "%s", cursanti[i].nume);
        fscanf(f_in, "%s", cursanti[i].prenume);
        fscanf(f_in, "%s", cursanti[i].CNP);
        fscanf(f_in, "%s", cursanti[i].email);
        fscanf(f_in, "%d", &(cursanti[i].n1));
        fscanf(f_in, "%d", &cursanti[i].n2);
    }
}

void afisare_cursanti(struct Cursant *cursanti, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nDatele cursantului %d\n", i+1);
        printf("nume: %s\n", cursanti[i].nume);
        printf("prenume: %s\n", cursanti[i].prenume);
        printf("CNP: %s\n", cursanti[i].CNP);
        printf("email: %s\n", cursanti[i].email);
        printf("nota 1: %d\n", cursanti[i].n1);
        printf("nota 2: %d\n", cursanti[i].n2);
    }
}

void sortare_nume_alfabetic(struct Cursant *cursanti, int n)
{
    int i;
    int gasit=0;
    int swapped;
    struct Cursant aux;
    do
    {
        gasit=0;
        for(i=0; i<n-1; i++)
        {
            if(strcmp(cursanti[i].nume, cursanti[i+1].nume)>0)
            {
                gasit=1;
                aux=cursanti[i];
                cursanti[i]=cursanti[i+1];
                cursanti[i+1]=aux;
            }
        }
    }
    while(gasit);
}

void data_nasterii(char * CNP, char * data)
{
    char an_p[3], an[5];
    strncpy(an_p, CNP+1, 2);
    an_p[3]='\0';
    if (strcmp(an_p, "17")>0)
        strcpy(an, "19");
    else strcpy(an, "20");
    strcat(an, an_p);
    an[4]='\0';
    //extragere subsir de caractere din alt sir de caractere
    // strncpy - nu aloca spatiu - trebuie sa aloc manual spatiu + nu introduce caracterul de sfarsit '\0' - trebuie adaugat manual
    char luna[3];
    strncpy(luna, CNP+3, 2);
    luna[2]='\0';

    char zi[3];
    strncpy(zi, CNP+5, 2);
    zi[2]='\0';
    //concatenare componente data nastere
    strcpy(data, zi);
    strcat(data, "-");
    strcat(data, luna);
    strcat(data, "-");
    strcat(data, an);
    data[11]='\0';
    #ifdef DEBUG
        printf("%s-%s-%s\n", zi, luna, an);
    #endif
}

void scriere_date_noi(struct Cursant*cursanti, int n){
    FILE *f_out;
    f_out=fopen("procesate.txt", "w");
    char data[n][11];
    if (f_out){
        int i;
        for (i=0; i<n; i++){
            fprintf(f_out, "%s\n", cursanti[i].nume);
            fprintf(f_out, "%s\n", cursanti[i].prenume);
            fprintf(f_out, "%s\n", cursanti[i].CNP);
            fprintf(f_out, "%s\n", cursanti[i].email);
            data_nasterii(cursanti[i].CNP, data[i]);
            fprintf(f_out, "%s\n", data[i]);
            float medie=(cursanti[i].n1+cursanti[i].n2)/2;
            fprintf(f_out, "%f\n", medie);
            fprintf(f_out, "%s\n", medie>=5?"ADMIS":"RESPINS");
        }
        fclose(f_out);
    }
    else{
        printf("Nu s-a putut deschide fisierul pentru scriere\n");
        printf("Eroarea este: %s\n", strerror(errno));
    }
}

void adaugare_student(){
    FILE *f_out;
    struct Cursant c_nou;
    f_out = fopen("inregistrari.txt", "r+");
    if (f_out){
        int n; fscanf(f_out, "%d", &n);
        n++;
        fseek(f_out, 0, SEEK_SET);
        fprintf(f_out, "%d\n", n);
        fseek(f_out, 0, SEEK_END);
        printf("Introducere date cursant nou: \n");
        printf("Nume: "); scanf("%s", &c_nou.nume); fprintf(f_out, "%s\n", c_nou.nume);
        printf("Prenume: "); scanf("%s", &c_nou.prenume); fprintf(f_out, "%s\n", c_nou.prenume);
        printf("CNP: "); scanf("%s", &c_nou.CNP); fprintf(f_out, "%s\n", c_nou.CNP);
        printf("Email: "); scanf("%s", &c_nou.email); fprintf(f_out, "%s\n", c_nou.email);
        printf("Nota 1: "); scanf("%d", &c_nou.n1); fprintf(f_out, "%d\n", c_nou.n1);
        printf("Nota 2: "); scanf("%d", &c_nou.n2); fprintf(f_out, "%d\n", c_nou.n2);
        fclose(f_out);
    }
}

int calcul_varsta(struct Cursant c){
    char an[3];
    strncpy(an, c.CNP+1, 2);
    an[3]='\0';

    int an_n=atoi(an);
    if (an_n<=17)
        an_n+=100;
    #ifdef DEBUG
        printf("an nastere: %s\n", an);
        printf("an nastere: %d\n", an_n);
    #endif // DEBUG

    int an_curent;
    time_t timp = time(NULL);
    struct tm tm =*localtime(&timp);
    an_curent = tm.tm_year;

    #ifdef DEBUG
        printf("an curent: %d\n", an_curent);
    #endif // DEBUG

    int varsta=an_curent-an_n;
    return varsta;
}




