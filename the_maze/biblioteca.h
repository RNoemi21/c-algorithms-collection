#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

typedef struct{
    int nx, ny, dist;
}Move;

extern bool visited[ROW][COL];
extern int dx[];
extern int dy[];
extern int startX;
extern int startY;
extern int endX;
extern int endY;
extern int min_pasi;
extern bool best_path[ROW][COL];

bool is_Valid(int x, int y, bool visited[ROW][COL]);
void print_path(bool path[ROW][COL]);
bool backtracking(int x, int y, bool visited[ROW][COL]);
void backtracking_optim(int x, int y, int pasi, bool visited[ROW][COL]);
int comparare_move(const void *a, const void *b);
int abs(int x) ;
bool backtracking_euristic(int x, int y, bool visited[ROW][COL]);
