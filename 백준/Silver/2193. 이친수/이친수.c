#include <stdio.h>

long long dp[91][2],n;

long long f(int n, int i){
    if(n==1 || n==2) return dp[n][i];
    if(dp[n][i] != -1) return dp[n][i];
    if(i==0) dp[n][i] = f(n-1,0) + f(n-1,1);
    else dp[n][i] = f(n-1,0);
        
    return dp[n][i];
}

int main() {
    for(int i=0;i<91;i++){dp[i][0]=-1; dp[i][1]=-1;}
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 0;
    scanf("%lld",&n);
    printf("%lld", f(n,0) + f(n,1));
    return 0;
}

// 1
// 10
// 101, 100