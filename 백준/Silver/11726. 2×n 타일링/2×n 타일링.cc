#include <iostream>
using namespace std;

int arr[1001];

int f(int n){
    if(n==1||n==2) return n;
    if(arr[n]) return arr[n];
    arr[n] = (f(n-1)+f(n-2))%10007;
    return arr[n];
}

int main() {
    int m;
    cin >> m;
    cout << f(m);
    return 0;
}
// 2 : 2 -> 1C1 + 1C1
// 3 : 3 -> 1C1 + 2C1
// 4 : 5 -> 1C1 + 3C1 + 2C2
// 5 : 8 -> 1C1 + 4C1 + 3C2
// 6 : 13-> 1C1 + 5C1 + 4C2 + 3C3