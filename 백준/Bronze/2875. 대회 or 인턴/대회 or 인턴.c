#include <stdio.h>

int main() {
    int n,m,k,c=0;
    scanf("%d %d %d",&n,&m,&k);
    while(1){
        if(n < 2 || m < 1) break;
        n-=2;
        m--;
        if(n+m < k) break;
        c++;
    }
    printf("%d",c);
    return 0;
}