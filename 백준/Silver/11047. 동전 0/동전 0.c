#include <stdio.h>

int main(){
    int n,k, coins[11], count = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &coins[i]);
    for(int i = n-1; i >= 0; i--){
        while(coins[i] <= k){
            k -= coins[i];
            count++;
        }
    }
    printf("%d", count);
}