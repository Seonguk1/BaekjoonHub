#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    set<string, greater<string>> log;
    string name, state;
    int n;
    cin >> n;
    while(n--){
        cin >> name >> state;
        if (state=="enter") log.insert(name);
        else log.erase(name);
    }
    for(string name : log) cout << name << "\n";
    return 0;
}