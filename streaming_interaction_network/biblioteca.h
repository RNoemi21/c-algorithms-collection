#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 25

void initializareMatrice(int a[MAX][MAX], int n);
void afisareMatrice(int a[MAX][MAX], int n);
void Random(int a[MAX][MAX], int u, int v);
void creareGraf(int a[MAX][MAX], int n);
void recomandare(int a[MAX][MAX], int u, int v);
int DFS(int a[MAX][MAX], int n, int nod, int culoare[]);
int esteBipartit(int a[MAX][MAX], int n);
