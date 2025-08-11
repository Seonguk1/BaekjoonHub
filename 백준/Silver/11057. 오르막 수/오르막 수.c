#include <stdio.h>

int dp[1001][10];

int f(int n, int i){
    // printf("n: %d, i: %d\n",n,i);
    if(n==1) return dp[n][i];
    if(dp[n][i]) return dp[n][i];
    // if(i==0) dp[n][i] = 1;
    // else dp[n][i] = ((10-i)*f(n-1,i))%10007;
    dp[n][i]=0;
    for(int k=0;k<=i;k++) dp[n][i] = (dp[n][i] + f(n-1,k))%10007;
    
    // printf("dp[%d][%d] = %d\n", n,i,dp[n][i]);
    return dp[n][i];
}
// 22
int main(){
    int n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<10;i++) dp[1][i]=1;
    for(int i=0;i<10;i++) sum = (sum+f(n,i))%10007;
    printf("%lld", sum);
} 
//dp[2][0] = 00
//dp[2][1] = 01, 11
//dp[2][2] = 02, 12, 22 
//10+9+8+7+6+5+4+3+2+1

