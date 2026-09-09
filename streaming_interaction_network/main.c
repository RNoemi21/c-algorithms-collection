#include "biblioteca.h"

int main() {
    srand(time(NULL));
    
    int grafR[MAX][MAX];
    int graf[MAX][MAX];
    
    int video=10;
    int utilizatori=10;
    int total=video+utilizatori;

    initializareMatrice(grafR, total);
    initializareMatrice(graf, total);
    
    //cerinta 1
    Random(grafR, utilizatori, video);
    printf("The random graph\n");
    afisareMatrice(grafR, total);

    //cerinta 2
    creareGraf(graf, total);
    printf("The graph\n");
    afisareMatrice(graf, total);

    //cerinta 3
    recomandare(graf, utilizatori, video);

    //cerinta 4
    if(esteBipartit(grafR, total)==1)
        printf("The random graph is bipartite.\n");
    else printf("The random graph is not bipartite.\n");

    if(esteBipartit(graf, total)==1)
        printf("The graph is bipartite.\n");
    else printf("The graph is not bipartite.\n");

    return 0;
}
