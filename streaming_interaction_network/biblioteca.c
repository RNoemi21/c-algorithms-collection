#include "biblioteca.h"

void initializareMatrice(int a[MAX][MAX], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = 0;
}

void afisareMatrice(int a[MAX][MAX], int n) {
  printf("Display adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}

void Random(int a[MAX][MAX], int utilizatori, int video) {
    int totalNoduri = utilizatori + video;
    int muchiiMAX = utilizatori * video;
    int muchii = muchiiMAX / 4; 

    int m = 0;
    while (m < muchii) {
        
        int esteInvalid = (rand() % 100) < 20;
        if (esteInvalid) {
            if (rand() % 2 == 0 && utilizatori > 1) {
                int u1 = rand() % utilizatori;
                int u2 = rand() % utilizatori;
                if (u1 != u2 && a[u1][u2] == 0) {
                    a[u1][u2] = 1; 
                    m++;
                }
            } else if (video > 1) {
                int v1 = utilizatori + (rand() % video);
                int v2 = utilizatori + (rand() % video);
                if (v1 != v2 && a[v1][v2] == 0) {
                    a[v1][v2] = 1; 
                    m++;
                }
            }
        } else {
            int u = rand() % utilizatori;
            int v = utilizatori + (rand() % video);

            if (rand() % 2 == 0) {
                if (a[u][v] == 0) {
                    a[u][v] = 1;
                    m++;
                }
            } else {
                if (a[v][u] == 0) {
                    a[v][u] = 1;
                    m++;
                }
            }
        }
    }

    printf("The graph has been generated and has %d edges.\n", m);
}

void creareGraf(int a[MAX][MAX], int n) {
  a[6][11] = 1;
  a[5][17] = 1;
  a[0][14] = 1;
  a[8][11] = 1;

  a[11][5] = 1;
  a[17][0] = 1;
  a[12][0] = 1;
  a[14][8] = 1;
}

void recomandare(int a[MAX][MAX], int u, int v) {

  printf("Recommendations for users:\n");
  for (int i = 0; i < u; i++) {
    int exista = 0;
    printf("For user %d, the following is recommended: ", i);

    for (int j = u; j < u + v; j++) {
      if (a[i][j] == 1) {
        printf("movie %d ", j);
        exista = 1;
      }
    }

    if (exista == 0) {
      printf("We have no recommendation.");
    }
    printf("\n");
  }
}

int DFS(int a[MAX][MAX], int n, int nod, int culoare[]) {
  for (int j = 0; j < n; j++) {
    if (a[nod][j] == 1 || a[j][nod] == 1) {
      if (culoare[j] == -1) {
        culoare[j] = 1 - culoare[nod];
        if (DFS(a, n, j, culoare) == 0)
          return 0;
      } else if (culoare[j] == culoare[nod]) {
        return 0;
      }
    }
  }
  return 1;
}

int esteBipartit(int a[MAX][MAX], int n) {
  int culoare[MAX];
  int i;

  for (i = 0; i < n; i++)
    culoare[i] = -1;

  for (i = 0; i < n; i++) {
    if (culoare[i] == -1) {
      culoare[i] = 0;
      if (DFS(a, n, i, culoare) == 0)
        return 0;
    }
  }
  return 1;
}