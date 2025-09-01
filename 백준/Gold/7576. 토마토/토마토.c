#include <stdio.h>

int m,n;
int graph[1001][1001];
int q[1000001];
int front = -1, rear = -1;

int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};

int main() {
    scanf("%d %d",&m, &n);
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            scanf("%d", &graph[r][c]);
            if(graph[r][c]==1){
                q[++rear] = r*m+c;
                if(front==-1) front=0;
            }
        }
    }

    while(front!=-1 && front <= rear){
        int temp = q[front++];
        int r = temp / m;
        int c = temp % m;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(graph[nr][nc] != 0) continue;
            q[++rear] = nr*m+nc;
            if(front==-1) front = 0;
            graph[nr][nc] = graph[r][c]+1;
        }
    }
    int max_date = 0;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(graph[r][c] == 0){
                printf("-1");
                return 0;
            }
            if(graph[r][c] > max_date) max_date = graph[r][c];
        }
    }
    printf("%d", max_date-1);
    return 0;
}