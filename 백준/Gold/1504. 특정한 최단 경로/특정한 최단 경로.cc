// dijkstra(1) -> dist[2], dist[3]
// dijkstra(2) -> dist[3], dist[4]
// dijkstra(3) -> dist[2], dist[4]
// 1 -> 2 -> 3 -> 4
// 1 -> 3 -> 2 -> 4

#include <iostream>
#include <vector>
#include <queue>
#define MAX 200000000
using namespace std;

int n,e,a,b,c,v1,v2;

typedef struct Node{
    int index;
    int weight;
    bool operator<(const Node& b) const {
        return weight > b.weight;
    };
} Node;

vector<Node> graph[801];
int dist[3][801];

void dijkstra(int idx, int start){
    priority_queue<Node> pq;
    for(int i=1;i<=n;i++) dist[idx][i] = MAX;
    dist[idx][start]=0;
    pq.push({start,0});
    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();
        for(auto next : graph[cur.index]){
            if(dist[idx][cur.index] + next.weight < dist[idx][next.index]){
                dist[idx][next.index] = dist[idx][cur.index] + next.weight;
                pq.push({next.index, dist[idx][next.index]});
            }
        }
    }
}

int main(){
    cin >> n >> e;
    while(e--){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin >> v1 >> v2;
    
    dijkstra(0,1);
    dijkstra(1,v1);
    dijkstra(2,v2);

    int min1 = dist[0][v1] + dist[1][v2] + dist[2][n];
    int min2 = dist[0][v2] + dist[2][v1] + dist[1][n];
    if(min1 >= MAX && min2 >= MAX) cout << -1 << endl;
    else cout << (min1 < min2 ? min1 : min2) << endl;
    
}