/*Realizați un program care prelucrează un array cu două
dimensiuni numere reale astfel:
- Se apelează o funcție pentru a introduce numărul de linii și coloane
și o funcție pentru a introduce elementele array-ului;
- O funcție afișează elementele array-ului;
- O funcție primește ca parametru un număr cuprins între 1 și l (l –
numărul de linii) și afișează elementele de pe linia selectată;
- O funcție primește ca parametri două numere întregi, și dacă
acestea sunt mai mici decât numărul de linii, respectiv coloane,
afișează matricea trunchiată folosind noul număr de linii și coloane;
- Apelați corespunzător funcțiile create din funcția main. */


#include <stdio.h>
#include <stdlib.h>

int citire_numar(){
	int x;
	scanf("%d", &x);
	return x;
}

void citire_elemente(int l, int c, float a[l][c]);
void afisare_elemente(int l, int c, float a[l][c]);

/* returneaza linia p a matricei a */
float* selectare_linie(int p, int l, int c, float a[l][c], float linie[c]);

/*nu returneaza nimic - void
afiseaza matricea dedimensiuni p*q inclusa in matricea a
*/
void sub_array(int p, int q, int l, int c, float a[l][c]);

int main(void){
	int l, c;
	printf("nr. de linii: "); l=citire_numar();
	printf("nr. de coloane: "); c=citire_numar();

	float a[l][c];
	citire_elemente(l, c, a);
	printf("matricea introdusa:\n");
	afisare_elemente(l, c, a);

	//selectare si afisare linia p
	int p;
	do{
		printf("linia pe care doriti sa o selectati: ");
		p=citire_numar();
	}while(p-1>l);
	
	float *linie;
	linie=malloc(c*sizeof(float));
	linie=selectare_linie(p-1, l, c, a, linie);
	
	//afisarea liniei p;
	printf("linia %d\n", p);
	for(p=0; p<c; p++)
		printf("%f\t",linie[p]);
	printf("\n");

	//afisare submatrice de dimensiuni p*q inclusa in matricea a
	int q;
	//citire numar de linii pentru submatrice pana cand utilizatorul introduce un numar cel mult egal cu numarul de linii al matricei
	do{
		printf("nr-ul de linii al submatrcei: "); p=citire_numar();
	}while(p>l);
	//citire numar de coloane pentru submatrice pana cand utilizatorul introduce un numar cel mult egal cu numarul de coloane al matricei
	do{
		printf("n-rul de coloane al submatricei: "); q=citire_numar();
	}while(q>c);
	printf("submatricea de dimensiuni %d x %d\n", p, q);
	sub_array(p, q, l, c, a);  
}

void citire_elemente(int l, int c, float a[l][c]){
	int i, j;
	for(i=0; i<l; i++)
		for(j=0; j<c; j++){
			printf("a[%d][%d]: ", i+1, j+1);
			scanf("%f", &a[i][j]);
		}

}

void afisare_elemente(int l, int c, float a[l][c]){
	int i, j;
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			printf("%f\t",  a[i][j]);
		}
		printf("\n");
	}
}

float * selectare_linie(int p, int l, int c, float a[l][c], float linie[c]){
	int j;
	for (j=0; j<c; j++)
		linie[j]=a[p][j];
	return linie;
}

void  sub_array(int p, int q, int l, int c, float a[l][c]){
	int i, j;
	for(i=0; i<p; i++){
		for(j=0; j<q; j++)
			printf("%f\t", a[i][j]);
		printf("\n");
	}
}
