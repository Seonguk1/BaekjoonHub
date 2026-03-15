#include <bits/stdc++.h>
using namespace std;
int N, W;
bool visited[301];
vector<pair<int,int>> adj[302];
priority_queue<tuple<int, int, int>,
                vector<tuple<int, int, int>>,
                greater<tuple<int, int, int>>> pq;

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> W;
        adj[i].push_back({W, N+1});
        adj[N+1].push_back({W, i});
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> W;
            adj[i].push_back({W, j});
            adj[j].push_back({W, i});
        }
    }
    visited[0] = true;
    for (auto next : adj[0]) {
        pq.push({next.first, 0, next.second});
    }
    int cnt=0, min_cost=0;
    while(cnt < N){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (visited[b]) continue;
        visited[b] = true;
        cnt++;
        min_cost += cost;
        for (auto next : adj[b]) {
            pq.push({next.first, b, next.second});
        }
    }
    cout << min_cost;
    return 0;
}