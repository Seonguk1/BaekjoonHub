#include <stdio.h>
#include <math.h>

char arr[600000];

void f(int n, int x, int c){
    if(n==1){
        arr[x] = '-';
    }
    else if(n==3){
        arr[x] = c ? '-' : ' ';
        arr[x+1] = ' ';
        arr[x+2] = c ? '-' : ' ';
    } else{
        f(n/3, x, c);
        f(n/3, x+n/3, 0);
        f(n/3, x+n*2/3, c);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != -1){
        int m = pow(3,n);
        f(m, 0, 1);
        for(int i=0;i<m;i++){
            printf("%c", arr[i] ? arr[i] : ' ');
        }
        printf("\n");
    }
}