#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 2000000

int V,E,K;

typedef struct Node {
    int index;
    int weight;
    bool operator<(const Node& b) const {
        return weight > b.weight;
    }
} Node;

vector<Node> graph[20001];
int dist[20001];

void dijkstra(int start){
    priority_queue<Node> pq;
    for(int i=1;i<=V;i++) dist[i] = INF;
    dist[start] = 0;
    pq.push({start,0});
    while(!pq.empty()){
        Node temp = pq.top(); pq.pop();
        for(auto nextNode : graph[temp.index]){
            if(dist[temp.index]+ nextNode.weight < dist[nextNode.index]){
                dist[nextNode.index] = dist[temp.index]+ nextNode.weight;
                pq.push({nextNode.index, dist[nextNode.index]});
            }
        }
    }
}

int main() {
    cin >> V >> E >> K;
    while(E--){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    dijkstra(K);
    for(int i=1;i<=V;i++){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] <<endl;
    }
    return 0;
}