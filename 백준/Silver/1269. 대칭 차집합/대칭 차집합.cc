#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n,m;
unordered_set<int> s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int num;
    cin >> n >> m;
    while(n--){
        cin >> num;
        s.insert(num);
    }
    while(m--){
        cin >> num;
        if(s.find(num) != s.end()) s.erase(num);
        else s.insert(num);
    }

    cout << s.size() << "\n";
    return 0;
}