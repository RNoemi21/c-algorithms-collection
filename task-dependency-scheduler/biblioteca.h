#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct NOD{
    int val;
    struct NOD *next;
};
typedef struct NOD Nod;

struct GRAF{
    int V;
    Nod* lista[MAX];
};
typedef struct GRAF Graf;

struct COADA{
    int v[MAX];
    int front, rear;
};
typedef struct COADA Coada;

struct heap{
    int v[MAX];
    int size;
};
typedef struct heap MINHEAP;

void initCoada(Coada *c);
int isEmpty(Coada *c);
void push(Coada *c, int x);
int pop(Coada *c);
Graf* creareGraf(int v);
void adauga_muchie(Graf *g, int src, int dest);
void initHeap(MINHEAP *h);
void swap(int *a, int *b);
void heapPush(MINHEAP *h, int x);
int heapPop(MINHEAP *h);
void sortareTopologica(Graf *g);
void sortareTopologicaHeap(Graf *g);
void afiseazaTaskuri();
void eliberareGraf(Graf *g);