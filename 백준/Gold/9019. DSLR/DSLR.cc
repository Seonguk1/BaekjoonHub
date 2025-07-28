#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int t, a, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        queue<pair<int, string>> q;
        bool visited[10000] = {false};

        q.push({a, ""});
        visited[a] = true;

        while(!q.empty()) {
            auto [x, cmd] = q.front(); q.pop();
            if(x == b) {
                cout << cmd << '\n';
                break;
            }

            int nx;

            // D
            nx = (x * 2) % 10000;
            if(!visited[nx]) { visited[nx] = true; q.push({nx, cmd + "D"}); }

            // S
            nx = (x == 0 ? 9999 : x - 1);
            if(!visited[nx]) { visited[nx] = true; q.push({nx, cmd + "S"}); }

            // L
            nx = (x % 1000) * 10 + x / 1000;
            if(!visited[nx]) { visited[nx] = true; q.push({nx, cmd + "L"}); }

            // R
            nx = (x % 10) * 1000 + x / 10;
            if(!visited[nx]) { visited[nx] = true; q.push({nx, cmd + "R"}); }
        }
    }
}
