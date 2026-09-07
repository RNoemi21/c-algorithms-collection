#include "biblioteca.h"

bool labirint[10][10] = {{0,0,1,1,1,1,1,1,1,1},
{1,0,0,1,0,0,0,0,0,1},
{0,0,1,0,1,1,1,1,0,1},
{1,0,0,0,1,0,0,1,0,1},
{1,1,1,0,1,0,1,1,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,1,1,1,1,1,0,1,1},
{1,0,0,0,0,0,0,0,1,1},
{1,1,1,1,1,1,1,0,1,1},
{1,1,1,1,1,1,1,0,1,1}};

bool visited[ROW][COL];
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, -1, 1};
int startX=0, startY=0;
int endX=9, endY=7;
int min_pasi=9999;
bool best_path[ROW][COL];
bool is_Valid(int x, int y, bool visited[ROW][COL]){
    return ( x>=0 && x<ROW && y>=0 && y<COL && labirint[x][y]==0 && !visited[x][y]);
}

void print_path(bool path[ROW][COL]){
    int i, j;
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
            if(path[i][j]){
                 printf(" x ");
            }else if(labirint[i][j] ==1){
                printf(" # ");
            }else{
                printf(" . ");
            }
        }
       
    printf("\n");
    }
    printf("\n");
}

bool backtracking(int x, int y, bool visited[ROW][COL]){
    visited[x][y]=true;
    if(x==endX && y==endY){
        return true;
    }
    for(int i=0; i<4; i++){
        int nx= x +dx[i];
        int ny=y+dy[i];
        if(is_Valid(nx, ny, visited)){
            if(backtracking(nx, ny, visited)){
                return true;
            }
        }
    }
    visited[x][y]=false;
    return false;
}


void backtracking_optim(int x, int y, int pasi, bool visited[ROW][COL]){
    visited[x][y]=true;
    if(x==endX && y==endY){
        if(pasi<min_pasi){
            min_pasi=pasi;
        for(int i=0; i< ROW; i++)
            for(int j=0; j<COL; j++)
                best_path[i][j]=visited[i][j];    
        }
    } else {
        if(pasi<min_pasi){
            for(int i=0; i<4; i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(is_Valid(nx, ny, visited))
                    backtracking_optim(nx,ny, pasi+1, visited);
            }
        }
    }
    
    visited[x][y]=false;
}

int comparare_move(const void *a, const void *b){
    return ((Move*)a)->dist - ((Move*)b)->dist;
}

int abs(int x) {
    if (x < 0)
        return -x;
    return x;
}
bool backtracking_euristic(int x, int y, bool visited[ROW][COL]){
    visited[x][y]=true;
    if(x==endX && y==endY){
        return true;
    }
    Move moves[4];
    int valid_moves=0;

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(is_Valid(nx, ny, visited)){
            moves[valid_moves].nx=nx;
            moves[valid_moves].ny=ny;
            //distanta manhatan, cel cu distanta cea mai mica este cel mai bun
            moves[valid_moves].dist=abs(nx-endX)+abs(ny-endY);
            valid_moves++;
        }
    }
    qsort(moves, valid_moves, sizeof(Move), comparare_move);
    for(int i=0; i<valid_moves; i++){
        if(backtracking_euristic(moves[i].nx, moves[i].ny, visited)){
            return true;
        }
    }
       visited[x][y]=false;
       return false;
}
