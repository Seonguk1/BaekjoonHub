#include <stdio.h>
char str[200001], a, prev;
int q,l,r, dp['z'-'a'+1][200001];
int main(){
    scanf("%s %d ", str, &q);
    
    for(int i=0;i<'z'-'a'+1;i++){
        dp[i][0]=0;
        for(int j=1;str[j-1];j++){   
            dp[i][j] = dp[i][j-1] + (str[j-1] == 'a'+i ? 1 : 0);
        }
    }
    
    for(int i=0;i<q;i++){
        scanf("%c %d %d ",&a,&l,&r);
        printf("%d\n", dp[a-'a'][r+1] - dp[a-'a'][l]);
    }
    
    return 0;
}