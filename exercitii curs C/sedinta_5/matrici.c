/*Se introduc de la tastatură elementele unei matrice de
n*m elemente. Scrieți un program care:
(a) alocă dinamic spațiul necesar matricei;
(b) afișează elementele matricei;
(c) afișează elementele de deasupra diagonalei principale
(dacă matricea este pătratică);
(d) afișează suma elementelor de pe fiecare linie;
(e) afișează suma elementelor negative și impare;
(f) elementele de pe diagonala secundara (daca n==m).*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n,m;
	printf("nr-ul de linii: "); scanf("%d", &n);
	printf("nr-ul de coloane: ");scanf("%d", &m);

	//declararea vectorului;
	int **mat;

	//alocarea liniilor
	mat=(int**)malloc(n*sizeof(int*));
	//alocarea coloanelor
	int i=0;
	for(i=0; i<n; i++)
		mat[i]=malloc(m*sizeof(int));

	//citirea elementelor matricei
	printf("\nelementele matricei:\n");
	int j=0;
	for(i=0; i<n; i++){
		for (j=0; j<m; j++){
			printf("mat[%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}

	//afisarea elementelor matricei
	printf("\nelementele matricei:\n");
	for(i=0; i<n; i++){
		for (j=0; j<m; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}

	printf("\nelementele de deasupra diagonalei principale:\t");
	if (n==m){
		for(i=0;i<n; i++){
			for(j=i; j<n; j++)
				printf("%d\t", mat[i][j]);
		}
	}
	else printf("matricea nu este patratica");
	printf("\n");

	//suma elementelor de pe fiecare linie;
	printf("\nsuma elementelor de pe fiecare linie: \n");
	int suma[n];
	for(i=0; i<n; i++){
		suma[i]=0;
		for(j=0; j<m; j++)
			suma[i]+=mat[i][j];
		printf("suma pe linia %d: %d\n", i, suma[i]);
	}

	//suma elementelor <0 si impare
	int s=0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(mat[i][j]<0 && mat[i][j]%2)
				s+=mat[i][j];

	printf("\nsuma elementelor negative si impare: %d\n", s);

	//elementele de pe diagonala secundara ( i+j = n-1 )
	printf("\nelementele de pe diagonala secundara:\t");
	if(n==m){
		for(i=0; i<n; i++)
			printf("\t%d", mat[i][n-1-i]);
	}
	else printf("matricea nu este patratica");
	printf("\n");

	for(i=0; i<m; i++)
        free(mat[i]);
    free(mat);
}
