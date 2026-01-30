#include <iostream>
#include <math.h>
using namespace std;
int N, R, C, count=0;
void func(int n, int r, int c){
    if (r == R && c == C) {
        cout << count;
        return;
    }

    if (R >= r && R < r+n && C >= c && C < c+n){
        func(n/2, r, c);
        func(n/2, r, c+n/2);
        func(n/2, r+n/2, c);
        func(n/2, r+n/2, c+n/2);
    }
    else
        count += n*n;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> R >> C;
    func(pow(2,N),0,0);
    return 0;
}