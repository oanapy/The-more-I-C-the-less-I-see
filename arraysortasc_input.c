/*
Scrieți un program care citește mai multe numere naturale strict mai mari ca 0 introduse de la tastatură. Citirea se oprește atunci când este introdus numărul 0. Programul stochează numerele într-un array și apoi le afișează în ordine inversă.
Modificați programul anterior astfel incât să afișeze array-ul sortat crescător. Metoda bulelor este descrisă in curs.
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
  int stoc[15];
  int i, r, j, k, auxiliary;
  
  for(i = 0; i < 15; i++){
    printf("Introdu numarul #%d: ", i);
    scanf("%d", &stoc[i]);
    
    if(stoc[i] == 0) {
      printf("Ai introdus 0, programul s-a oprit.");
      break;
    }
    
  }
  printf("Numerele din stoc in ordine crescatoare sunt: ");
  for (r = 0; r < i - 1; i++) {
    for (j = 0; j < i - r - 1; j++) {
        if(stoc[j] > stoc[j + 1]) {
            auxiliary = stoc[j];
            stoc[j] = stoc[j + 1];
            stoc[j + 1] = auxiliary;
        }
      }
    }

    for (k = 0; k < 15; k++) {
       printf("%d\n ", stoc[k]);
    }
  
  return 0;
}