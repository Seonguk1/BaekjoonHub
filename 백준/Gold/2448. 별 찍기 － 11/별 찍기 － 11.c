#include <stdio.h>

char arr[5000][6200];

void f(int n, int x, int y){
    if(n==3){
        for(int i=0;i<n;i++){
            for(int j=i;j<n*2-i-1;j++){
                arr[y-i-1][x+j] = i==1 && j==2 ? ' ' : '*';
            }
        }
    }
    else{
        f(n/2, x, y);
        f(n/2, x+n, y);
        f(n/2, x+n/2, y-n/2);
    }
}



int main() {
    int n;
    scanf("%d", &n);
    f(n,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n*2;j++){
            printf("%c", arr[i][j] ? arr[i][j] : ' ');
        }
        if(i!=n-1)printf("\n");
    }
    return 0;
}