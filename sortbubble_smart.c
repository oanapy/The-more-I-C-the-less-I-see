#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int *numbers, how_many_numbers;
   int i, aux;
   int swapped;

   printf("Câte numere vei sorta?");
   scanf("%d", &how_many_numbers);
   if( how_many_numbers <= 0 || how_many_numbers > 1000000) {
       printf("Glumești?\n");
       return 1;
   }
   numbers = (int *) malloc(how_many_numbers * sizeof(int));
   if(numbers == NULL) {
       printf("Alocare esuată - sorry.\n");
       return 1;
   }
   for(i = 0; i < how_many_numbers; i++) {
       printf("\nTe rog sa introduci numărul #%i:\n",i + 1);
       scanf("%d",numbers + i);
   }
   do {
       swapped = 0;
       for(i = 0; i < how_many_numbers - 1; i++)
           if(numbers[i] > numbers[i + 1]) {
               swapped = 1;
               aux = numbers[i];
               numbers[i] = numbers[i + 1];
               numbers[i + 1] = aux;
           }
   } while(swapped);
   printf("\nArray-ul sortat:\n");
   for(i = 0; i < how_many_numbers; i++)
       printf("%d ",numbers[i]);
   printf("\n");
   free(numbers);
   return 0;
}