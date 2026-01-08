#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,m;
set<string> s;
set<string> s1;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string name;
    cin >> n >> m;
    while(n--){
        cin >> name;
        s.insert(name);
    }
    while(m--){
        cin >> name;
        if(s.find(name) != s.end()){
            s1.insert(name);
        }
    }
    cout << s1.size() << "\n";
    for(string s : s1) cout << s << "\n";
    return 0;
}