// 2^15 * 2^15 = 32768
// 2^2n 
#include<stdio.h>
#include<math.h>
int r,c,m=0, isFind=0;
int dx[4] = {0,1,0,1};
int dy[4] = {0,0,1,1};

void f(int n, int x, int y){
    if(isFind) return;
    if(r > y+pow(2,n) || c > x+pow(2,n)){
        m += pow(2,2*n);
        return;
    }
    if(n==1){
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            m++;
            if(nx == c && ny == r){
                isFind = 1;
                return;
            }
        }
    }
    else{
        for(int i=0;i<4;i++){
            int nx = x + dx[i]*(pow(2,n-1));
            int ny = y + dy[i]*(pow(2,n-1));
            f(n-1,nx,ny);
        }
    }
}

int main(){
    int n;
    scanf("%d %d %d",&n,&r,&c);
    
    f(n,0,0);
    printf("%d",m-1);
}