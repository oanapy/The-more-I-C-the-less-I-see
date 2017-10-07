#include <stdio.h>
#include <string.h>

int main(void) {
  	char *protagonist = "Maria";
  	protagonist = "Vasile"; 
  	strcpy(protagonist, "Pipin");
    puts(protagonist);
  	//strlen(protagonist);//numara caracterele dintr-un string, fara ultimul /0
    //printf("%s", protagonist);
  	char string;
	//strcpy(string, "Alice are o pisica");//va cauza array-ul string să conţină fraza ”Alice are o pisică” împreună cu caracterul nul de la încheiere.
  	//strncpy(string, "Alice are o pisica", 5); //va popula array-ul string cu stringul ”Alice” şi cu caracterul nul de încheiere.  
  	//strcpy (string, "Alice"); //va popula array-ul string cu ”Alice nu are Computer”.
	//strcat (string, "nu are");
	//strcat (string, protagonist);

  	return 0;
}