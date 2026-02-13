#include <iostream>
#include <set>
using namespace std;
int T, k, n;
char c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        multiset<int> s;
        cin >> k;
        while(k--){
            cin >> c >> n;
            if (s.empty() && c == 'D') continue;
            if (c == 'I'){
                s.insert(n);
            }
            else{
                if (n==1) {
                    s.erase(prev(s.end()));
                }
                else{
                    s.erase(s.begin());
                }
            }
        }
        if (s.empty()) cout << "EMPTY\n";
        else cout << *prev(s.end()) << " " << *s.begin() << '\n';
    }
    return 0;
}