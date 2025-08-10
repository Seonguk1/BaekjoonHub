#include <stdio.h>

int dp[1000001];

int f(int x){
    if(x==1||x==2||x==3) return dp[x];
    if(dp[x]) return dp[x];
    int a = x%3==0 ? f(x/3) : 1000001;
    int b = x%2==0 ? f(x/2) : 1000001;
    int c = f(x-1);
    if(a<=b && a<=c) dp[x] = a+1;
    else if(b<=a && b<=c) dp[x] = b+1;
    else dp[x] = c+1;
    return dp[x];
}

int main(){
    int x;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    scanf("%d",&x);
    printf("%d",f(x));
}