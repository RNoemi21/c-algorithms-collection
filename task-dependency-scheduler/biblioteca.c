#include "biblioteca.h"

void initCoada(Coada *c){
    c->front=0;
    c->rear=-1;
}

int isEmpty(Coada *c){
    return c->front > c->rear;
}

void push(Coada *c, int x){
    c->rear++;
    c->v[c->rear]=x;
}

int pop(Coada *c){
    int x=c->v[c->front];
    c->front++;
    return x;
}

Graf* creareGraf(int v){
    Graf *g=malloc(sizeof(Graf));
    if(g==NULL){
        printf("Allocation failed!");
        exit(1);
    }
    g->V=v;
    for(int i=0; i<v; i++){
        g->lista[i]=NULL;
    }
    return g;
}

void adauga_muchie(Graf *g, int src, int dest){
    Nod * nou=malloc(sizeof(Nod));
    if(nou==NULL){
        printf("Allocation failed!");
        exit(1);
    }
    nou->val=dest;
    nou->next=g->lista[src];
    g->lista[src]=nou;
}

void calculeazaGrad( Graf *g, int grad[]){ 
    Nod *p;
    for(int i=0; i<g->V; i++)
        grad[i]=0;
     for(int i=0; i<g->V; i++){
        p=g->lista[i];
        while (p){
            grad[p->val]++;
            p=p->next;
        }
     }   
}

void initHeap(MINHEAP *h){
    h->size=0;
}
void swap(int *a, int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}
void heapPush(MINHEAP *h, int x){
    int i;
    h->size++;
    i=h->size;
    h->v[i]=x;

    while(i>1 && h->v[i]<h->v[i/2]){
        swap(&h->v[i], &h->v[i/2]);
        i/=2;
    }
}

int heapPop(MINHEAP *h){
    int i=1, st, dr, min;
    int val=h->v[1];
    h->v[1]=h->v[h->size];
    h->size--;
    while(1){
        st=2*i;
        dr=2*i+1;
        min=i;
    if(st<=h->size && h->v[st]<h->v[min])
        min=st;
    if(dr<=h->size && h->v[dr]<h->v[min])
        min=dr;
    
    if(min !=i){
            swap(&h->v[i], &h->v[min]);
            i=min;
        }
    else    break;
    }
    return val;
}

void sortareTopologica(Graf *g){
    int grad[MAX];
    int rezultat[MAX];
    int k=0;
    int i, nod;
    Nod *p;
    Coada c;

    initCoada(&c);
    calculeazaGrad(g, grad);
    for(i =0; i<g->V; i++){
        if(grad[i]==0)
            push(&c, i);
    }
    while (!isEmpty(&c))
    {
        nod=pop(&c);
        rezultat[k++]=nod;
        p=g->lista[nod];
        while(p){
            grad[p->val]--;
        if(grad[p->val]==0)
            push(&c, p->val);
        p=p->next;
    }
    }
    if(k!=g->V){
        printf("The vertex is part of a cycle!\n");
        return;
    }
    printf("Topological sort (queue): \n");
    for(i=0; i<k; i++)
        printf("S%d ", rezultat[i]);
    printf("\n");
}

void sortareTopologicaHeap(Graf *g){
    int grad[MAX];
    int rezultat[MAX];
    int k=0;
    int i, nod;
    Nod *p;
    MINHEAP h;

    initHeap(&h);
    calculeazaGrad(g, grad);
    for(i =0; i<g->V; i++){
        if(grad[i]==0)
            heapPush(&h, i);
    }
    while (h.size>0)
    {
        nod=heapPop(&h);
        rezultat[k++]=nod;
        p=g->lista[nod];
        while(p){
            grad[p->val]--;
        if(grad[p->val]==0)
            heapPush(&h, p->val);
        p=p->next;
    }
    }
    if(k!=g->V){
        printf("The vertex is part of a cycle!\n");
        return;
    }
    printf("Topological sort (min-heap): \n");
    for(i=0; i<k; i++)
        printf("S%d ", rezultat[i]);
    printf("\n");
}

void afiseazaTaskuri(){
    printf("S0: configured project\n");
    printf("S1: implemented list\n");
    printf("S2: deleted items from the list\n");
    printf("S3: queued elements\n");
    printf("S4: inserted elements into stacks\n");
    printf("S5: creating a ranking of the bottom 8 teams in the BST\n");
    printf("S6: AVL tree balancing\n");
    printf("S7: sent the project\n");
}

void eliberareGraf(Graf *g){
    if (g == NULL) {
        return;
    }
    for (int i = 0; i < g->V; i++) {
        Nod *curent = g->lista[i];
        while (curent != NULL) {
            Nod *aux = curent;
            curent = curent->next;
            free(aux);
        }
        g->lista[i] = NULL;
    }

    free(g);
}