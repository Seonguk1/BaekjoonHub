#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N,M, arr[9][9], max_safe_size=0;
vector<pair<int,int>> vir_idx;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void virus(int arr[9][9], int r, int c){
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
        if (arr[nr][nc] != 0) continue;
        arr[nr][nc] = 2;
        virus(arr, nr, nc);
    }
}

void wall(int arr[9][9], int depth){
    if (depth==3) {
        for(pair<int,int> v : vir_idx){
            int r = v.first;
            int c = v.second;
            virus(arr, r, c);
        }
        int count=0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++){
                if (arr[i][j]==0) {
                    count++;
                }
            }
        }
        max_safe_size = max(max_safe_size, count);
        return;
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j]==0) {
                int temp[9][9];
                for (int i=0; i<N; i++) for (int j=0; j<M; j++) 
                    temp[i][j] = arr[i][j];
                temp[i][j] = 1;
                wall(temp, depth+1);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j]==2)  vir_idx.push_back({i,j});
        }
    }

    wall(arr,0);

    cout << max_safe_size;
    return 0;
}