#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n); 

    cin >> m;
    while (m--) {
        cin >> x;
        cout << binary_search(A, A + n, x) << '\n';
    }

    return 0;
}
