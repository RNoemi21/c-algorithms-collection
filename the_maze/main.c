#include "biblioteca.h"

int main() {
    bool visited[ROW][COL]={false};
    printf("Arbitrary path (X - traversed, . - untraversed, # - wall)\nTime complexity O(4^v); v = number of white cells\nSpace complexity O(v) + O(n × m)\n");
    if(backtracking(startX, startY, visited)){
        print_path(visited);
    }else{
        printf("No road was found.\n");
    }

    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            visited[i][j]=false;
    
    printf("The shortest path.\n");
    backtracking_optim(startX, startY, 1,  visited);
    if(min_pasi!=9999){
        printf("Minimum length of: %d steps.\n", min_pasi);
        print_path(best_path);
    }else{
        printf("No road was found.\n");
    }

    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            visited[i][j]=false;
    
    printf("The path that, at every moment in time, remains as close as possible to the destination.\n");
   if(backtracking_euristic(startX, startY, visited)){
    print_path(visited);
   }


    return 0;
}
