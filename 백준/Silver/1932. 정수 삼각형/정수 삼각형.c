#include <stdio.h>

int n,temp, dp[501][501];

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%d", &temp);
            if(i==0){
                dp[i][j] = temp;
            }
            else if(j==0){
                dp[i][j] = temp + dp[i-1][j];
            }
            else if(j==i){
                dp[i][j] = temp + dp[i-1][j-1];
            }
            else{
                dp[i][j] = temp + (dp[i-1][j] > dp[i-1][j-1] ? dp[i-1][j] : dp[i-1][j-1]);
            }
        }
    }
    int mx  = -1;
    for(int i=0;i<n;i++){
        if(dp[n-1][i] > mx) mx = dp[n-1][i];
    }
    printf("%d", mx);
    return 0;
}

//      0
//     1 2
//    3 4 5
//   6 7 8 9
// 10 11 12 13 14