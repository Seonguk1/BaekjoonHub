#include <bits/stdc++.h>
using namespace std;

int dp1[1001], dp2[1001], arr[1001], max_length=1;

int main() {
    int N;
    vector<int> v;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        dp1[i]=1;
        dp2[i]=1;
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if(arr[i] > arr[j]){
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }
    for (int i=N-1; i>=0; i--) {
        for (int j=N-1; j>i; j--) {
            if(arr[i] > arr[j]){
                dp2[i] = max(dp2[i], dp2[j]+1);
                max_length = max(max_length, dp1[i] + dp2[i] - 1);
            }
        }
    }
    cout << max_length;
    return 0;
}