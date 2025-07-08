#include <stdio.h>
int graph[101][101]={0,};
int visited[200]={0,};
int count=0;

void DFS(int n, int root){
    for(int i=1;i<=n;i++){
        if(i==root) continue;
        if(graph[root][i] && !visited[i]){
            visited[i] = 1;
            count++;
            DFS(n, i);
        }
    }
}

int main() {
    int n,m, x,y;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    visited[1]=1;
    DFS(n, 1);

    printf("%d", count);
    return 0;
}