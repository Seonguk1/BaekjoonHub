#include <iostream>
#include <vector>
using namespace std;

int n,r,q,u,v,a;
vector<int> graph[100001];
bool visited[100001] = {false,};
int dp[100001] = {0,};

int dfs(int n){
    // cout << "dfs : " << n << endl;
    if(dp[n]) return dp[n];
    if(graph[n].size()==0){
        dp[n] = 1;
        return dp[n];
    }
    for(auto a : graph[n]){
        if(visited[a]) continue;
        visited[a] = true;
        dp[n] += dfs(a);
        visited[a] = false;
    }// 5 4 3 1 2
    dp[n]++;
    // cout << "dp "<< n <<": " << dp[n] << endl;
    return dp[n];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> r >> q;
    for(int i=1;i<n;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // cout << " fdg " << graph[5].size() << endl;
    visited[r] = true;
    dfs(r);
    while(q--){
        cin >> a;
        cout << dp[a] << "\n";
    }
    return 0;
}