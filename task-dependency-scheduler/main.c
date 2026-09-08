#include "biblioteca.h"

int main() {
    Graf *g=NULL;
/*
    S2 depinde de S1
• S3 depinde de S1, S0
• S4 depinde de S3, S2
• S5 depinde de S4
• S6 depinde de S4, S5
• S7 depinde de S4, S5, S6*/
    g=creareGraf(8);
    adauga_muchie(g, 1, 2);
    adauga_muchie(g, 1, 3);
    adauga_muchie(g, 0, 3);
    adauga_muchie(g, 2, 4);
    adauga_muchie(g, 3, 4);
    adauga_muchie(g, 4, 5);
    adauga_muchie(g, 4, 6);
    adauga_muchie(g, 5, 6);
    adauga_muchie(g, 4, 7);
    adauga_muchie(g, 5, 7);
    adauga_muchie(g, 6, 7);

    printf("The tasks to be completed are:\n");
    
    afiseazaTaskuri();
    printf("\n");
    sortareTopologica(g);
    sortareTopologicaHeap(g);

    printf("\nCycle test: add edge S7 -> S5\n");
    adauga_muchie(g, 7, 5);
    sortareTopologica(g);
    eliberareGraf(g);
    return 0;
}