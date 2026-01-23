#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int R,C, visited[1000001]={0,};
char arr[1000001];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
queue<pair<int,int>> qj,qf;
int main() {
    cin >> R >> C;
    for (int r=0; r<R; r++) {
        for (int c=0; c<C; c++) {
            cin >> arr[r*C + c];
            if(arr[r*C+c] == 'J'){
                qj.push({r,c});
                visited[r*C+c]=1;
                if (r==0 || r==R-1 || c==0 || c==C-1) {
                    cout << visited[r*C+c];
                    return 0;
                }
            }
            else if(arr[r*C+c] == 'F'){
                qf.push({r,c});
            } 
        }
    }
    pair<int,int> cur;
    int r,c,qf_size,qj_size;
    while(!qj.empty()){
        qf_size = qf.size();
        for (int k=0; k<qf_size; k++) {
            cur = qf.front(); qf.pop();
            r = cur.first;
            c = cur.second;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr<0||nc<0||nr>=R||nc>=C) continue;
                if (arr[nr*C+nc]=='#' || arr[nr*C+nc]=='F') continue;
                arr[nr*C+nc] = 'F';
                qf.push({nr,nc});
            }
        }
        qj_size = qj.size();
        for (int k=0; k<qj_size; k++) {
            cur = qj.front(); qj.pop();
            r = cur.first;
            c = cur.second;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr<0||nc<0||nr>=R||nc>=C) continue;
                if (arr[nr*C+nc]!='.' || visited[nr*C+nc]) continue;
                qj.push({nr,nc});
                visited[nr*C+nc]=visited[r*C+c]+1;
                if (nr==0 || nr==R-1 || nc==0 || nc==C-1) {
                    cout << visited[nr*C+nc];
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}