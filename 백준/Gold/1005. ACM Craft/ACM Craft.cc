#include<iostream>
#include<vector>
using namespace std;

int t,n,k,d,w;

int times[1001];
vector<int> graph[1001];
int dp[1001];

int f(int w){
    if (dp[w]!=-1) return dp[w];
    if(graph[w].empty()) return dp[w] = times[w];
    //cout << w << " 방문" << endl;
    int max = 0, time=0;  
    for (int prev : graph[w]) {
        time = f(prev);
        if(time > max) max = time;
        // max = max(max, f(prev));
    }
    //cout << w << "의 max: "<< max << endl;
    dp[w] = max + times[w];
    return dp[w];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            dp[i]=-1;
            graph[i].clear();
        }
        for(int i=1;i<=n;i++){cin>>d;times[i]=d;}
        while(k--){
            int x,y;
            cin >> x >> y;
            graph[y].push_back(x);
        }
        cin >> w;
        cout << f(w) << endl;
    }
    
}