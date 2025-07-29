#include<iostream>
using namespace std;

int n,m, maxs=0;
int arr[501][501];
bool visited[501][501];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int x, int y, int num, int sum){
    if(num==4) return sum;
    visited[y][x] = true;
    int max_x = 0, max_y = 0, max_n=0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if(arr[ny][nx] > max_n && !visited[ny][nx]){
            max_x = nx;
            max_y = ny;
            max_n = arr[ny][nx];    
        } 
    }
    sum += max_n;
    return dfs(max_x, max_y, ++num, sum);
    
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int x=0;x<n;x++){
                for(int y=0;y<m;y++){
                    visited[x][y]=false;
                }
            }
            int temp = dfs(j,i,0,0);
            if(temp > maxs) maxs = temp;
            int mins = 1000, count=0, sum = arr[i][j];
            for(int k=0;k<4;k++){
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                count++;
                sum+= arr[ny][nx];
                if(arr[ny][nx] < mins) mins = arr[ny][nx];
            }
            if(count==4) sum -= mins;
            if(count>2 && sum > maxs) maxs = sum;
        }
    }
    cout << maxs;
}