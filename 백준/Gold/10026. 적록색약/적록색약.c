#include <stdio.h>

char grid[101][101];
int n;
int visited1[101][101]={0,};
int visited2[101][101]={0,};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void f(int j, int i){
    visited1[i][j]=1;
    for(int k=0;k<4;k++){
        int nx = j + dx[k];
        int ny = i + dy[k];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(!visited1[ny][nx] && (grid[ny][nx] == grid[i][j])){
            f(nx,ny);
        }
    }
}

void f2(int j, int i){
    visited2[i][j]=1;
    for(int k=0;k<4;k++){
        int nx = j + dx[k];
        int ny = i + dy[k];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(!visited2[ny][nx] && 
            (
            (grid[ny][nx] == grid[i][j]) || 
            (grid[ny][nx] == 'R' && grid[i][j] == 'G') ||
            (grid[ny][nx] == 'G' && grid[i][j] == 'R')
            )
            ){
            f2(nx,ny);
        }
    }
}

int main(){
    int count1=0,count2=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c", &grid[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited1[i][j]){
                f(j,i);
                count1++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited2[i][j]){
                f2(j,i);
                count2++;
            }
        }
    }
    printf("%d %d", count1, count2);
}