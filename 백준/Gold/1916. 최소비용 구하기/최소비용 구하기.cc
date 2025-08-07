#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000000000
using namespace std;

typedef struct Node {
    int index;
    int weight;
    int operator<(const Node& b) const{
        return weight > b.weight;
    }
} Node;

int n,m,u,v,w,s,e;
vector<Node> graph[1001];
int dist[1001];

void dijkstra(){
    priority_queue<Node> pq;
    for(int i=1;i<=n;i++) dist[i] = MAX;
    dist[s] = 0;
    pq.push({s,0});
    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();

        if (dist[cur.index] < cur.weight) continue;
        
        for(Node next : graph[cur.index]){
            if(dist[cur.index] + next.weight < dist[next.index]){
                dist[next.index] = dist[cur.index] + next.weight;
                pq.push({next.index,dist[next.index]});
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    while(m--){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    cin >> s >> e;
    dijkstra();
    cout << dist[e];
    return 0;
}