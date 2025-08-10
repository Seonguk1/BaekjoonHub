#include <stdio.h>

int dp[1000001];

int f(int x){
    if(x==1||x==2) return dp[x];
    if(dp[x]) return dp[x];

    dp[x] = (f(x-1) + f(x-2)*2)%10007;
    
    return dp[x];
}

int main(){
    int n;
    dp[1]=1;
    dp[2]=3;
    scanf("%d",&n);
    printf("%d",f(n));
}