#include <stdio.h>

int main(void) {
    int numbers[5];
    int i, aux;
    int swapped;
  /* cerem utilizatorului să introducă cinci valori */
    for (i = 0; i < 5; i++) {
        printf("\nIntroduceți valoarea #%i\n",i + 1);
        scanf("%d", &numbers[i]);
    }
  /* să le sortăm */
     do {
         swapped = 0;
       for(i = 0; i < 4; i++) {
             if(numbers[i] > numbers[i + 1]) {
                 swapped = 1;
                 aux = numbers[i];
                 numbers[i] = numbers[i + 1];
                 numbers[i + 1] = aux;
             }
         }
     } while(swapped);
   /* afișăm rezultatele */
     printf("\nMatrice sortată: ");
   for(i = 0; i < 5; i++)
         printf("%d ",numbers[i]);
   printf("\n");
   return 0;
}