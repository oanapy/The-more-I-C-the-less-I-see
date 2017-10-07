/*Modificați codul de mai jos astfel încât acesta să afișeze pe ecran array-ul numbers inversat.*/

#include <stdio.h>

int main() {
   int numbers[100], i, auxiliary;
   
  for (i = 0; i < 100; i++) {
       numbers[i] = i + 1;
   }

   // Modificati de aici ...
   for (i = 0; i < 50; i++) {
      auxiliary = numbers[i];
      numbers[i] = numbers[99 - i];
      numbers[99 - i] = auxiliary;
   }
   // ... pana aici

   for (i = 0; i < 100; i++) {
       printf("%d ", numbers[i]);
   }
}