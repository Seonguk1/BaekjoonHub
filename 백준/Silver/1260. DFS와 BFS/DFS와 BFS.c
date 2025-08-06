#include <stdio.h>

int n,m,v;
int graph[1001][1001]={0,};
int visited[1001]={0,};

void dfs(int v){
    visited[v]=1;
    printf("%d ", v);
    for(int i=1;i<=n;i++){
        if(!visited[i] && graph[v][i]){
            dfs(i);
        }
    }
}

void bfs(int v){
    int q[1001];
    int front=-1, rear=-1;
    q[++rear] = v; front++;
    while(front <= rear){
        int temp = q[front++];
        visited[temp]=1;
        printf("%d ", temp);
        for(int i=1;i<=n;i++){
            if(!visited[i] && graph[temp][i]){
                q[++rear] = i;
                visited[i]=1;
            }
        }
    }
}

int main() {

    scanf("%d %d %d",&n, &m, &v);

    while(m--){
        int a,b;
        scanf("%d %d",&a, &b);
        graph[a][b]=1;
        graph[b][a]=1;
    }

    dfs(v);
    printf("\n");
    for(int i=1;i<=n;i++) visited[i]=0;
    bfs(v);
    
    return 0;
}