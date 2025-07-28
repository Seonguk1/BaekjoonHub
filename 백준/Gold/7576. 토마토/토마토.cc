#include<bits/stdc++.h>
using namespace std;

int m,n;
int g[1001][1001];
queue<pair<int,int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
            if(g[i][j]==1) q.push(make_pair(i,j));
        }
    }

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.second;
        int y = p.first;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(g[ny][nx] != 0 || nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            g[ny][nx] = g[y][x]+1;
            q.push(make_pair(ny,nx));
            //cout <<nx <<", "<<ny <<" : "<< g[ny][nx] << endl;
        }
    }

    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==0){
                cout << -1;
                return 0;
            }
            if(g[i][j] > max) max = g[i][j];
        }
    }
    cout << max-1;
}