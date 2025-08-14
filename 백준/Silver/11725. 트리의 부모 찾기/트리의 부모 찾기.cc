#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[100001];
int parents[100001];
bool visitied[100001];

int main(){
    int n,a,b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visitied[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int i : v[cur]){
            if(!visitied[i]){
                parents[i] = cur;
                visitied[i] = true;
                q.push(i);
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout << parents[i] << "\n";
    }
}