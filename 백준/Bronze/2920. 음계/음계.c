#include<stdio.h>
int main(){
    int c, n;
    scanf("%d", &n);
    if(n==1 || n==8) c = n==1 ? 1 : 0;
    else{
        printf("mixed");
        return 0;
    }
    int prev = n;
    for(int i=0;i<7;i++){
        scanf("%d", &n);
        if(!(c && n == prev+1 || !c && n==prev-1)){
            printf("mixed");
            return 0;
        }
        prev = n;
    }
    if(c) printf("ascending");
    else printf("descending");
}