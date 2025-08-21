#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node {
    int index;
    int operator<(const Node& b) const{
        return index > b.index;
    };
} Node;

int n,m,u,v;
vector<int> graph[32001];
int arr[32001]={0,};
bool visited[32001];

priority_queue<Node> pq;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        graph[u].push_back(v);
        arr[v]++;
    }
    
    for(int i=1;i<=n;i++){
        if(!arr[i] && !visited[i]){
            pq.push({i});
        }
    }
    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();
        if(visited[cur.index]) continue;
        cout << cur.index << " ";
        visited[cur.index] = true;
        for(auto a : graph[cur.index]){
            arr[a]--;
            if(arr[a]==0){
                pq.push({a});
            }
        }
    }
    
    return 0;
}