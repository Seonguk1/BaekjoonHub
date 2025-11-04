#include <stdio.h>
char str[200001], a;
int q,l,r, dp[200001];
int main(){
    scanf("%s %d ", str, &q);
    dp[0]=0;
    for(int i=0;i<q;i++){
        scanf("%c %d %d ",&a,&l,&r);
        for(int i=1;str[i-1];i++){   
            dp[i] = dp[i-1] + (str[i-1]==a ? 1 : 0);
        }
        printf("%d\n", dp[r+1] - dp[l]);
    }
    
    return 0;
}