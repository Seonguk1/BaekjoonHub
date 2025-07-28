#include<bits/stdc++.h>
using namespace std;

int m,n,h;
int g[101][101][101];
queue<tuple<int,int,int>> q;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> m >> n >> h;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){        
                cin >> g[k][i][j];
                if(g[k][i][j]==1) q.push(make_tuple(j,i,k));
            }
        }
    }

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int x = get<0>(t);
        int y = get<1>(t);
        int z = get<2>(t);
        for(int i=0;i<6;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            if (g[nz][ny][nx] != 0) continue;

            g[nz][ny][nx] = g[z][y][x]+1;
            q.push(make_tuple(nx,ny,nz));
            //cout <<nx <<", "<<ny <<", "<<nz<<" : "<< g[nz][ny][nx] << endl;
        }
    }

    int max = 0;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[k][i][j]==0){
                    cout << -1;
                    return 0;
                }
                if(g[k][i][j] > max) max = g[k][i][j];  
            }
        }
    }
    cout << max-1;
}