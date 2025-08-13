#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, arr[1001], dp[1001], max_len=1;
    cin >> n;
    for(int i=0;i<=n;i++){
        cin >> arr[i];
        dp[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], 1+dp[j]);
                if(dp[i] > max_len) max_len = dp[i];
            }
        }
    }
    cout << max_len;
    
    return 0;
}