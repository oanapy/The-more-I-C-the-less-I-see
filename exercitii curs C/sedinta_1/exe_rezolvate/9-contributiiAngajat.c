#include <stdio.h>

int main(){

    double salariu;

    printf("Salariul brut: ");
    scanf("%lf", &salariu); //se foloseste specificatorul de format lf pentru double

    double asanatate, impozit, pensii, somaj;
    double net;

    pensii =  10.5/100 * salariu;
    asanatate = 5.5*salariu/100;
    impozit = 0.16 * salariu;
    somaj = 0.005 * salariu;

    net= salariu - pensii - asanatate - impozit - somaj;
    printf("contributiile datorate sunt: \n");
    printf("contributii sanatate: %5.3f\n", asanatate);
    printf("impozit pe venit: %5.3f\n", impozit);
    printf("contributii pensii: %5.3f\n", pensii);
    printf("contributii somaj: %5.3f\n", somaj);

    printf("Salariul net este: %5.3f\n", net);


}
