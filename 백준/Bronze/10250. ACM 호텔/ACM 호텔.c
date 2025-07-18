// n = (x-1)*h + y
#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int h,w,n;
        scanf("%d %d %d", &h,&w,&n);
        int x = n%h == 0 ? n/h : n/h+1;
        int y = n%h == 0 ? h : n%h;
        if(x/10 == 0) printf("%d0%d\n",y,x);
        else printf("%d%d\n",y,x);
    }
}